#ifndef _stack_h
#define _stack_h

#include "generator.hpp"

template<typename T>
struct StackNode{
    T data;
    StackNode<T>* next;

    StackNode(T item):data(item),next(nullptr){};
};

template<typename T>
struct Stack{
    StackNode<T>* topNode;

    //构造函数直接将栈指针指向一个空内存，此时表示栈存在但没有数据
    Stack():topNode(nullptr){};
    void push(T item){
        StackNode<T>* newNode=new StackNode<T>(item);
        newNode->next=this->topNode;
        this->topNode=newNode;
    };
    void pop(){
        try{
            if(!this->empty()){
                StackNode<T>* tempNode=this->topNode;
                //使用tempNode还可以操作即将被弹出的顶点
                this->topNode=this->topNode->next;
                delete tempNode;
            }else
                throw std::runtime_error("this stack is empty, cannot pop");
        }catch(std::runtime_error err){
            cerr<<err.what()<<"\n";
        }
    };
    auto top()->T const{    
        try{
            if(!this->empty())
                return this->topNode->data;
            else
                throw std::runtime_error("this stack is empty");
        }catch(std::runtime_error err){
            cerr<<err.what()<<"\n";
        }
    };
    auto empty()->bool const{
        return this->topNode==nullptr;
    }
    ~Stack(){
        while(!this->empty())
            this->pop();
    }
};

#endif