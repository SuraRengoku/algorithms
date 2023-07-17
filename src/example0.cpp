/*
给定int数组a
(1)a中有一个数只出现奇数次，其余数出现偶数次，求出该数
(2)a中有两个数只出现奇数次，其余数出现偶数次，求出两个数
要求时间复杂度O(n),空间额外复杂度O(1)
*/

#include<iostream>
using namespace std;

void solution1(int *a,int len){
    int eor=0;
    for(int i=0;i<len;i++){
        eor^=a[i];
    }
    cout<<eor<<endl;
}

void solution2(int *a,int len){
    int eor=0;
    for(int i=0;i<len;i++){
        eor^=a[i];
    }
    int rightone=eor&(~eor+1);//找出二进制表示下eor最右侧的1
    //～取反
    //+1最后一位加一
    int eorp=0;
    for(int i=0;i<len;i++){
        if((a[i]&rightone)==0){
            //只有该位置上1的数才能参与异或
            //出现偶数次的数在分类后仍然保持偶数次出现数
            eorp^=a[i];
        }
    }
    cout<<eorp<<" "<<(eorp^eor)<<endl;
}

int main(){
    int a[]={2,1,3,2,1,2,3,2,3};
    int len=sizeof(a)/sizeof(a[0]);
    solution1(a,len);
    int b[]={4,5,7,6,4,6,5,7,5,6,7,6};
    len=sizeof(b)/sizeof(b[0]);
    solution2(b,len);
    return 0;
}