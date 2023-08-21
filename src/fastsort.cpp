#include"generator.hpp"

//快速排序 空间复杂度O(log(2,N))，最差时O(N)
//分组，小于等于在左，大于在右
int partition1(int *a,int l,int r,int end){
    int indlore=l-1;
    int ind=l;
    while(ind<r){
        if(a[ind]<=end){
            bswap_nonzero(a,ind++,++indlore);
            continue;
        }else{
            ind++;
            continue;
        }
    }
    indlore++;
    bswap_nonzero(a,ind,indlore);
    return indlore;
}
//分组，荷兰国旗
int* partition2(int *a,int l,int r,int end){
    int indle=l-1;
    int indla=r;
    int ind=l;
    while(ind<indla){
        if(a[ind]<end){
            bswap_nonzero(a,ind++,++indle);
        }
        else if(a[ind]==end){
            ind++;
        }
        else if(a[ind]>end){
            bswap_nonzero(a,ind,--indla);
        }
    }
    bswap_nonzero(a,r,indla);
    static int *result=new int[2];
    result[0]=indle+1;
    result[1]=indla;
    return result;
}
//1.0版本 O(N^2)
void fastsort1(int *a,int l,int r){
    if(l<r){
        int end=a[r];//尾数
        int result=partition1(a,l,r,end);
        fastsort1(a,l,result-1);
        fastsort1(a,result+1,r);
    }
}
//2.0版本 O(N^2) 但比1.0版本稍微快一点
void fastsort2(int *a,int l,int r){
    if(l<r){
        int end=a[r];
        int *result=partition2(a,l,r,end);
        fastsort2(a,l,result[0]-1);
        fastsort2(a,result[1]+1,r);
    }
}
//3.0版本 O(N*log(2,N))
void fastsort3(int *a,int l,int r){
    if(l<r){
        pair<int,int> range(l,r);
        bswap(a,RandNumGene(range),r);
        int end=a[r];
        int *result=partition2(a,l,r,end);
        fastsort3(a,l,result[0]-1);
        fastsort3(a,result[1]+1,r);
    }
}
int main(){
    int Maxsize=20;
    int Maxvalue=20;
    pair<int*,int> result=generator(Maxsize,Maxvalue);
    int *arr=result.first;
    int len=result.second;
    int test[]={-6,-7,8,11,-5,13,-4,-5};
    // bprint(arr,len);
    bprint(test,8);
    // fastsort1(arr,0,len-1);
    // fastsort2(arr,0,len-1);
    // fastsort3(arr,0,len-1);
    // fastsort1(test,0,7);
    // fastsort2(test,0,7);
    fastsort3(test,0,7);
    // bprint(arr,len);
    bprint(test,8);
    return 0;
}