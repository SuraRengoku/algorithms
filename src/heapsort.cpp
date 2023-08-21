#include"generator.hpp"
//O(log(2,N))
//插入值时保证仍然是大根堆
void heapinsert(int *a,int index){
    while(a[index]>a[(index-1)/2]){
        bswap_nonzero(a,index,(index-1)/2);//与父节点坐标，若大于父节点则交换
        index=(index-1)/2;
    }
}
//O(log(2,N))
//去除原大根后调整堆再次成为大根堆
void heapify(int *a,int index,int heapsize){
    int left=2*index+1;
    while(left<heapsize){
        int largest=left+1<heapsize&&a[left+1]>a[left]?left+1:left;//两子比较
        largest=a[largest]>a[index]?largest:index;
        if(largest!=index){
            bswap_nonzero(a,largest,index);
            index=largest;
            left=2*index+1;
        }else
            break;
    }
}

void heapsort(int *a,int len){
    if(a==NULL||len<2){
        return;
    }
    for(int i=0;i<len;i++){
        heapinsert(a,i);
    }
    /*
    //用下面的方法生成原始大根堆更快
    for(int i=len-1;i>=0;i--){
        heapify(a,i,len);
    }*/
    int heapsize=len;
    do{
        bswap_nonzero(a,0,--heapsize);
        heapify(a,0,heapsize);
    }while(heapsize>0);
}

int main(){
    int Maxsize=10;
    int Maxvalue=10;
    pair<int*,int> result=generator(Maxsize,Maxvalue);
    int *arr=result.first;
    int len=result.second;
    int test[7]={4,4,2,-6,-6,3,6};
    bprint(arr,len);
    // bprint(test,7);
    heapsort(arr,len);
    // heapsort(test,7);
    bprint(arr,len);
    // bprint(test,7);
    return 0;
}