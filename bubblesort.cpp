#include<iostream>
using namespace std;
//O(n^2)
void swap(int *a,int m,int n){
    a[m]^=a[n];
    a[n]^=a[m];
    a[m]^=a[n];
    //^异或运算
    //需要保证两个变量在内存中指向两块地址，否则会将同一地址的数据抹零
}

void bubblesort(int *a,int l){
    if(a==NULL||l<2)
        return;
    for(int i=l-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(a,j,j+1);
            }
        }
    }
}

void print(int *a,int l){
    for(int i=0;i<l;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[]={5,7,2,6,13,4,15,23,0,19,25,9,10,6,3};
    int len=sizeof(a)/sizeof(a[0]);
    bubblesort(a,len);
    print(a,len);
    return 1;
}