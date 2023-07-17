#include<iostream>
using namespace std;
//O(n^2)
void swap(int *a,int m,int n){
    int temp=a[m];
    a[m]=a[n];
    a[n]=temp;
}

void selectionsort(int *a,int l){
    if(a==NULL||l<2)
        return;
    for(int i=0;i<l;i++){
        int minindex=i;
        for(int j=i+1;j<l;j++){
            minindex=a[minindex]>a[j]?j:minindex;
        }
        swap(a,i,minindex);
    }
}

void print(int *a,int l){
    for(int i=0;i<l;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int a[]={5,7,2,0,9,10,6,3};
    int len=sizeof(a)/sizeof(a[0]);
    selectionsort(a,len);
    print(a,len);
    return 1;
}