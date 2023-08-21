#include"generator.hpp"

//暴力解法用于验证，时间复杂度O(N^2)
void Force_(int *a,int l){
    int sum=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                sum+=a[j];
            }
        }
    }
    cout<<"the small sum is:"<<sum<<"\n";
}

int process(int *a,int l,int m,int r){
    int partsum=0;
    int *b=new int[r-l+1];
    int indb=0;
    int indl=l;
    int indr=m+1;
    while(indl<=m&&indr<=r){
        partsum+=a[indl]<a[indr]?(r-indr+1)*a[indl]:0;
        b[indb++]=a[indl]<a[indr]?a[indl++]:a[indr++];
    }
    while(indl<=m){
        b[indb++]=a[indl++];
    }
    while(indr<=r){
        b[indb++]=a[indr++];
    }
    for(int i=0;i<(r-l+1);i++){
        a[l+i]=b[i];
    }
    return partsum;
}

int mergesort(int *a,int l,int r){
    if(l==r)
        return 0;
    int mid=l+((r-l)>>1);
    return mergesort(a,l,mid)+mergesort(a,mid+1,r)+process(a,l,mid,r);
}

int main(){
    int Maxsize=50;
    int Maxvalue=50;
    pair<int*,int> result=generator(Maxsize,Maxvalue);
    int* arr=result.first;
    int len=result.second;
    int test[5]={1,3,4,2,5};
    // Force_(test,5);
    Force_(arr,len);
    cout<<"small sum:"<<mergesort(arr,0,len-1)<<"\n";
    return 0;
}