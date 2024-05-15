#ifndef _vector_hpp
#define _vector_hpp

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using std::string;
using std::out_of_range;
using std::to_string;
using std::vector;

template<typename T>
class _Vector{
    private:
        T *arr;
        int arrCapacity=10;
        int arrSize=0;
        int extendRatio=2;

    public:
        _Vector(){
            arr=new int[arrCapacity];
        }

        ~_Vector(){
            delete[] arr;
        }

        int size(){
            return arrSize;
        }

        int capacity(){
            return arrCapacity;
        }

        void checkIndex(int index){
            if(index<0||index>=size()){
                string info=string("index ")+to_string(index)+" out of range";
                throw out_of_range(info);
            }
        }

        T get(int index){
            checkIndex(index);
            return arr[index];
        }

        void set(int index, int num){
            checkIndex(index);
            arr[index]=num;
        }

        void add(T num){
            if(size()==capacity())
                extendCapacity();
            arr[size()]=num;
            arrSize++;
        }

        void insert(int index, T num){
            checkIndex(index);
            if(size()==capacity())
                extendCapacity();
            
            for(int j=size()-1;j>=index;j--)
                arr[j+1]=arr[j];
            arr[index]=num;
            arrSize++;
        }
        
        T remove(int index){
            checkIndex(index);
            T num=arr[index];
            for(int j=index;j<size()-1;j++)
                arr[j]=arr[j+1];
            arrSize--;
            return num;
        }

        void extendCapacity(){
            int newCapacity=capacity()*extendRatio;
            T *tmp=arr;
            arr=new int[newCapacity];

            for(int i=0;i<size();i++)
                arr[i]=tmp[i];
            delete[] tmp;
            arrCapacity=newCapacity;
        }


        vector<T> toVector(){
            vector<T> vec(size());
            for(int i=0;i<size();i++){
                vec[i]=arr[i];
            }
            return vec;
        }
};

#endif