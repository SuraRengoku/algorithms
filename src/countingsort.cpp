#include"generator.cpp"
//计数排序常应用于已知数据状况的情况下，比较有局限性
//时间复杂度O(N)
static int indexa=0;
void countingsort(int *a,int l,int Maxvalue, int Minvalue){
    int range=Maxvalue-Minvalue+1;
    int *freq=new int[range]();//括号用于初始化0
    for(int i=0;i<l;i++){
        freq[a[i]-Minvalue]++;
    }
    for(int j=0;j<range;j++){
        if(freq[j]){
            for(int k=0;k<freq[j];k++){
                a[indexa++]=j+Minvalue;
            }
        }
    }
}

int main(){
    int Maxsize=40;
    int Maxvalue=30;
    int Minvalue=-30;
    pair<int*,int> result=generator(Maxsize,Maxvalue,Minvalue);
    int *arr=result.first;
    int len=result.second;
    bprint(arr,len);
    countingsort(arr,len,Maxvalue,Minvalue);
    bprint(arr,len);
    return 0;
}