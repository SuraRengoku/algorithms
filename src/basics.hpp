#ifndef BASICS_HPP
#define BASICS_HPP

#include<iostream>
#include<climits>
#include<unistd.h>
#include<vector>
#include<algorithm>

template<typename T>
void bswap(T *a,int m,int n){
    a[m]^=a[n];
    a[n]^=a[m];
    a[m]^=a[n];
    //^异或运算
    //需要保证两个变量在内存中指向两块地址，否则会将同一地址的数据抹零
}

template<typename T>
void bswap_nonzero(T *a,int m,int n){
    T tmp=a[m];
    a[m]=a[n];
    a[n]=tmp;
}

template<typename T>
void bprint(T *a,int l){
    for(int i=0;i<l;i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}

#endif