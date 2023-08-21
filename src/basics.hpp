#ifndef BASICS_HPP
#define BASICS_HPP

#include<iostream>
#include<climits>
#include<unistd.h>
#include<vector>
#include<algorithm>

void bswap(int *a,int m,int n){
    a[m]^=a[n];
    a[n]^=a[m];
    a[m]^=a[n];
    //^异或运算
    //需要保证两个变量在内存中指向两块地址，否则会将同一地址的数据抹零
}
void bswap_nonzero(int *a,int m,int n){
    int tmp=a[m];
    a[m]=a[n];
    a[n]=tmp;
}
void bprint(int *a,int l){
    for(int i=0;i<l;i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}

#endif