#include<iostream>
#include"BinarySearch.hpp"
using namespace std;

int main(){
    // int l=3,r=4;
    // int mid=l+((r-l)>>1);
    // cout<<mid<<"\n";
    // cout<<"可以输出中文"<<endl;
    vector<int> nums={6,6,7,8,8,9};
    int index=lower_bound1(nums, 8);
    return 0;
}