#include"generator.h"
//递归思想
//O(N*log(2,N))
//选择排序等O(N^2时间复杂度的排序在排序过程中浪费了大量了比较信息，重复工作数次
//但是归并排序保留了这些信息并向下传递，因此时间复杂度低
void mergeA(int *a,int l,int m,int r){
    int *b=new int[r-l+1];
    int indb=0;
    int indl=l;
    int indr=m+1;
    while(indl<=m&&indr<=r){
        b[indb++]=a[indl]<=a[indr]?a[indl++]:a[indr++];
    }
    while(indl<=m){
        b[indb++]=a[indl++];
    }
    while(indr<=r){
        b[indb++]=a[indr++];
    }
    // cout<<r-l+1<<" "<<sizeof(b)/sizeof(b[0])<<endl;
    //已知一个指向数组的指针并不能求出该数组的长度
    for(int i=0;i<(r-l+1);i++){
        a[l+i]=b[i];
    }
}

void mergesort(int *a,int l,int r){
    if(l==r)
        return;
    int mid=l+((r-l)>>1);//右移一位实现除二操作
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    mergeA(a,l,mid,r);
}

int main(){
    int Maxsize=50;
    int Maxvalue=50;
    pair<int*,int> result=generator(Maxsize,Maxvalue);
    int* arr=result.first;
    int len=result.second;
    mergesort(arr,0,len-1);
    bprint(arr,len);
    return 0;
}