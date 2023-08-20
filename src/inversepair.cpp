#include"generator.h"
//打印所有逆序对的数量

//暴力解法用于验证
void Force_(int *a,int l){
    int count=0;
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(a[i]>a[j])
                count++;
        }
    }
    cout<<"the number of inverse pairs is:"<<count<<"\n";
}

int process(int *a,int l,int r,int mid){
    int partcount=0;
    int *tmp=new int[r-l+1];
    int indb=0;
    int indl=l;
    int indr=mid+1;
    while(indl<=mid&&indr<=r){
        partcount+=a[indl]>a[indr]?(r-indr+1):0;
        tmp[indb++]=a[indl]>a[indr]?a[indl++]:a[indr++];
    }
    while(indl<=mid){
        tmp[indb++]=a[indl++];
    }
    while(indr<=r){
        tmp[indb++]=a[indr++];
    }
    for(int i=0;i<(r-l+1);i++)
        a[l+i]=tmp[i];
    return partcount;
}

int merge(int *a,int l,int r){
    if(l==r)
        return 0;
    int mid=l+((r-l)>>1);
    return merge(a,l,mid)+merge(a,mid+1,r)+process(a,l,r,mid);
}

int main(){
    int Maxsize=50;
    int Maxvalue=50;
    pair<int*,int> result=generator(Maxsize,Maxvalue);
    int* arr=result.first;
    int len=result.second;
    Force_(arr,len);
    cout<<"the number of inverse pairs is:"<<merge(arr,0,len-1)<<"\n";
    return 0;
}