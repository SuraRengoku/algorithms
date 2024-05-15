#ifndef generator_h
#define generator_h
#include<iostream>
#include<random>
#include<cstdlib>
#include<time.h>
#include<tuple>
//tuple可以使得函数返回至少三个返回值
//返回两个返回值时使用pair即可 不需要用tuple

#include"basics.hpp"
#include"singlelinkedlist.hpp"
using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::pair;

template<typename T>
auto ToSign(T a,bool s)->T{
    //需要保证T是数值类型
    //s=1,+;s=0,-
    if(s)
        return a>=0?a:-a;
    return a>=0?-a:a;
}

template<typename T1, typename T2>
auto generator(int Maxsize, T1 Maxvalue)->T2{
    try{
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T1> dis(-Maxvalue, Maxvalue);
        int len=(int)rand()%(Maxsize);
        T1 *arr=new T1[len];
        for(int i=0;i<len;i++)
            arr[i]=dis(gen);
        pair<T1*, int> result=std::make_pair(arr, len);
        return result;
    }catch(const std::runtime_error& err){
        cerr<<err.what()<<"\n";
        throw;
    }
}
//模板特化
template<>
auto generator(int Maxsize, int Maxvalue)->pair<int*, int>{
    try{
        srand(static_cast<unsigned>(time(nullptr)));
        int len=(int)rand()%(Maxsize);
        int *arr=new int[len];
        for(int i=0;i<len;i++)
            arr[i]=(int)rand()%Maxvalue-(int)rand()%Maxvalue;
        pair<int*,int> result=std::make_pair(arr,len);
        return result;
    }catch(const std::runtime_error& err){
        cerr<<err.what()<<"\n";
        throw;
    }
}

template<typename T>
auto generator(int Maxsize, int Maxvalue)->Node<T>*{
    try{
        srand(static_cast<unsigned>(time(nullptr)));
        int len=(int)rand()%(Maxsize);
        Node<T>* head=list_init<T>();
        for(int i=0;i<len;i++)
            head=insert(head,i,(int)rand()%Maxvalue-(int)rand()%Maxvalue);
        return head;
    }catch(const std::runtime_error& err){
        cerr<<err.what()<<"\n";
        throw;
    }
}

pair<int*,int> generator(int Maxsize,int Maxvalue){
    srand((unsigned)time(NULL));
    int len=(int)rand()%(Maxsize);
    int *arr=new int[len];
    for(int i=0;i<len;i++){
        arr[i]=(int)rand()%Maxvalue-(int)rand()%Maxvalue;
    }
    pair<int*,int> result=std::make_pair(arr,len);
    return result;
}

pair<int*,int> generator(int Maxsize,int Maxvalue,bool s){
    //s=1,仅生成正数数组,s=0,仅生成负数数组
    srand((unsigned)time(NULL));
    int len=(int)rand()%(Maxsize);
    int *arr=new int[len];
    for(int i=0;i<len;i++){
        if(s)
            arr[i]=ToSign((int)rand()%Maxvalue-(int)rand()%Maxvalue,s);
        else
            arr[i]=ToSign((int)rand()%Maxvalue-(int)rand()%Maxvalue,s);
    }
    pair<int*,int> result=std::make_pair(arr,len);
    return result;
}

pair<int*,int> generator(int Maxsize,int Maxvalue,int Minvalue){
    srand((unsigned)time(NULL));
    int len=(int)rand()%(Maxsize);
    int *arr=new int[len];
    int diff=Maxvalue-Minvalue;
    for(int i=0;i<len;i++){
        arr[i]=ToSign(((int)rand()%diff-(int)rand()%diff),1)+Minvalue;
    }
    pair<int*,int> result=std::make_pair(arr,len);
    return result;
}


int RandNumGene(pair<int,int> p){
    int rangel=p.first;
    int ranger=p.second;
    srand((unsigned)time(NULL));
    int randnum=(int)rand()%(ranger-rangel)+rangel;
    return randnum;
}
int RandNumGene(pair<int,int> p,int s){
    int rangel=p.first;
    int ranger=p.second;
    srand((unsigned)time(NULL));
    int randnum;
    if(s)
        randnum=ToSign((int)rand()%(ranger-rangel),s);
    else
        randnum=ToSign((int)rand()%(ranger-rangel),s);
    return randnum;
}
// int main(){
//     int Maxsize=1000;
//     int Maxvalue=100;
//     pair<int*,int> result=generator(Maxsize,Maxvalue);
//     int* arr=result.first;
//     int len=result.second;
//     bprint(arr,len);
//     return 0;
// }
#endif