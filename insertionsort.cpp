#include<iostream>
using namespace std;
//O(n^2)
void swap(int *a,int m,int n){
    a[m]^=a[n];
    a[n]^=a[m];
    a[m]^=a[n];
}

void insertionsort(int *a,int l){
    if(a==NULL||l<2)
        return;
    for(int i=0;i<l;i++){
        for(int j=i;j>0&&a[j]<a[j-1];j--){
                swap(a,j,j-1);
        }
    }
}

void print(int *a,int l){
    for(int i=0;i<l;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[]={4,2,6,4,1,5,9,7,3,2};
    int len=sizeof(a)/sizeof(a[0]);
    insertionsort(a,len);
    print(a,len);
    return 0;
}