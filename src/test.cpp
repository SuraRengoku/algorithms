#include<iostream>
#include"BinarySearch.hpp"
using namespace std;

int main(){
    // int l=3,r=4;
    // int mid=l+((r-l)>>1);
    // cout<<mid<<"\n";
    // cout<<"可以输出中文"<<endl;
    vector<int> nums={4,5,5,5,5,6,8,8,9,10,11,12};
    int index=lower_bound1(nums, 13);
    // printf("%d",index);
    vector<int> nums2={1};
    cout<<lower_bound1(nums2,2);
    return 0;
}