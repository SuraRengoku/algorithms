#ifndef stack_h
#define stack_h

#include "generator.hpp"

template<typename T>
struct StackNode{
    T data;
    StackNode<T>* next;

    StackNode(T item):data(item),next(nullptr){};
};

#endif