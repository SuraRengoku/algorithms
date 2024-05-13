#include<iostream>
#include<singlelinkedlist.hpp>
#include<vector>

using std::vector;

template<typename T>
class LinkedListQueue{
    private:
        Node<T> *front, *rear;
        int queSize=0;
    
    public:
        LinkedListQueue(){
            front=nullptr;
            rear=nullptr;
            queSize=0;
        }

        ~LinkedListQueue(){
            Node<T> *tmp=front;
            while(tmp!=nullptr){
                Node<T> *N=tmp->next;
                free(tmp);
                tmp=N;
            }
        }

        int size(){
            return queSize;
        }

        bool isEmpty(){
            return queSize==0;
        }

        void push(int num){
            Node<T> *node;
            node->data=num;
            node->next=nullptr;

            if(front==nullptr){
                front=node;
                rear=node;
            }else{
                rear->next=node;
                rear=node;
            }
            queSize++;
        }

        int pop(){
            int num=peek();
            Node<T> *tmp=front;
            front=front->next;
            delete tmp;
            queSize--;
            return num;
        }

        int peek(){
            if(size()==0)
                throw out_of_range("ques is empty");
            return front->data;
        }

        vector<T> toVector(){
            Node<T> *node=front;
            vector<T> res(size());
            for(int i=0;i<res.size();i++){
                res[i]=node->data;
                node=node->next;
            }
            return res;
        }
};


/* 基于环形数组实现的队列 */
class ArrayQueue {
  private:
    int *nums;       // 用于存储队列元素的数组
    int front;       // 队首指针，指向队首元素
    int queSize;     // 队列长度
    int queCapacity; // 队列容量

  public:
    ArrayQueue(int capacity) {
        // 初始化数组
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }

    ~ArrayQueue() {
        delete[] nums;
    }

    /* 获取队列的容量 */
    int capacity() {
        return queCapacity;
    }

    /* 获取队列的长度 */
    int size() {
        return queSize;
    }

    /* 判断队列是否为空 */
    bool isEmpty() {
        return size() == 0;
    }

    /* 入队 */
    void push(int num) {
        if (queSize == queCapacity) {
            cout << "队列已满" << endl;
            return;
        }
        // 计算队尾指针，指向队尾索引 + 1
        // 通过取余操作实现 rear 越过数组尾部后回到头部
        int rear = (front + queSize) % queCapacity;
        // 将 num 添加至队尾
        nums[rear] = num;
        queSize++;
    }

    /* 出队 */
    int pop() {
        int num = peek();
        // 队首指针向后移动一位，若越过尾部，则返回到数组头部
        front = (front + 1) % queCapacity;
        queSize--;
        return num;
    }

    /* 访问队首元素 */
    int peek() {
        if (isEmpty())
            throw out_of_range("队列为空");
        return nums[front];
    }

    /* 将数组转化为 Vector 并返回 */
    vector<int> toVector() {
        // 仅转换有效长度范围内的列表元素
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++) {
            arr[i] = nums[j % queCapacity];
        }
        return arr;
    }
};