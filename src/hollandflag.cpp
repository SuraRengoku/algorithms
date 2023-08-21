#include"generator.hpp"

//小于等于在左边，大于在右边
void arrange1(int *a,int l,int num){
    int indlore=-1;
    for(int i=0;i<l;i++){
        if(a[i]<=num){
            indlore++;
            bswap(a,i,indlore);
        }
        else
            continue;
    }
    bprint(a,l);
}
//小于在左边，等于在中间，大于在右边
void arrange2(int *a,int l,int num){
    int indle=-1;
    int indla=l;
    for(int i=0;i<l;i++){
        if(i==indla-1)
            break;//遍历地址与大于区域左侧相撞，跳出
        if(a[i]<num){
            indle++;
            bswap(a,i,indle);
        }
        else if(a[i]==num)
            continue;
        else if(a[i]>num){
            indla--;
            bswap(a,i,indla);
            i--;//新换过来的数还无法判定其相对于比较数的大小，需要原地再比
        }
    }
    bprint(a,l);
}

int main(){
    int Maxsize=20;
    int Maxvalue=20;
    pair<int*,int> result=generator(Maxsize,Maxvalue);
    int *arr=result.first;
    int *arrtmp=result.first;
    int len=result.second;
    int test[7]={7,5,4,2,5,4,3};
    pair<int,int> range(0,len-1);
    int randomnum=arr[RandNumGene(range)];
    cout<<"the random comparing number is:"<<randomnum<<"\n";
    cout<<"arrange1:";
    // arrange1(test,7,4);
    arrange1(arr,len,randomnum);
    cout<<"arrange2:";
    // arrange2(test,7,4);
    arrange2(arr,len,randomnum);
    return 0;
}