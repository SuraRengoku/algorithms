#include "generator.cpp"
//希尔排序是插入排序的改进版本，也被称为缩小增量排序
//希尔排序不是一个稳定排序
void swap(int *a, int m, int n){
    a[m]^=a[n];//^异或运算
    a[n]^=a[m];
    a[m]^=a[n];
}

void partialinsertsort(int *a, int length){
    try{
        if(a==nullptr||length<2)
            throw runtime_error("array does not exist or array only have one element");
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
    }
    for(int i=0;i<length;i++){
        for(int j=i;j>0&&a[j]<a[j-1];j--)
            swap(a,j,j-1);
    }
}

void shellsort(int *a, int length){
    try{
        if(a==nullptr||length<2)
            throw runtime_error("array does not exist or array only have one element");
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
    }
    int gap=length/2;
    while(gap){
       for(int i=0;i<length;i+=gap){
            for(int j=i;j>0&&a[j]<a[j-gap];j-=gap)
                swap(a,j,j-1);
       }
       gap/=2;
    }
}

int main(){
    int Maxsize=20;
    int Maxvalue=20;
    pair<int*,int> result=generator(Maxsize,Maxvalue,1);
    int *arr=result.first;
    int len=result.second;
    bprint(arr, len);
    shellsort(arr,len);
    bprint(arr,len);
    return 0;
}