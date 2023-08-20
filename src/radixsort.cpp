#include"generator.h"
//基排序不是比较排序，同计数排序一样，需要根据数据状况来使用
//时间复杂度O(N),额外空间复杂度O(M)
int findmax(int *a,int l){
    int max=INT_MIN;
    for(int i=0;i<l;i++){
        if(a[i]>=max){
            max=a[i];
        }
    }
    return max;
}//找数组最大数
int maxbits(int *a,int l){
    int max=findmax(a,l);
    int res=0;
    while(max!=0){
        max/=10;
        res++;
    }
    return res;
}//找数组最大数位数
int getbit(int num,int b,const int rd){
    for(int i=0;i<b-1;i++){
        num/=rd;
    }
    int result=num%rd;
    return result;
}
void radixsort(int *a,int l,int r,const int rd){
    int digit=maxbits(a,r-l+1);
    const int radix=rd;//基底
    int *bucket=new int[r-l+1];
    int *bit=new int;
    for(int i=1;i<=digit;i++){
        int *count=new int[rd]();
        for(int j=l;j<=r;j++){
            *bit=getbit(a[j],i,rd);
            count[*bit]++;
        }
        for(int j=1;j<rd;j++){
            count[j]+=count[j-1];
        }
        for(int j=r;j>=l;j--){
            *bit=getbit(a[j],i,rd);
            bucket[count[*bit]-1]=a[j];
            count[*bit]--;
        }
        for(int j=l,k=0;j<=r;j++,k++){
            a[j]=bucket[k];
        }
    }
    delete[] bucket;
    delete bit;
}
int main(){
    int Maxsize=20;
    int Maxvalue=20;
    pair<int*,int> result=generator(Maxsize,Maxvalue,1);
    int *arr=result.first;
    int len=result.second;
    //TODO 目前只对正数排序正确
    bprint(arr,len);
    radixsort(arr,0,len-1,10);
    bprint(arr,len);
    // int test[15]={24,105,17,26,5,170,0,503,73,1014,42,200,519,34,0};
    // cout<<maxbits(test,5)<<"\n";
    // cout<<getbit(7,1,10)<<"\n";
    // radixsort(test,0,14,10);
    // bprint(test,15);
    return 0;
}