#include<iostream>
#include <math.h>
#include"BinarySearch.hpp"
using namespace std;

int main(){
    // int l=3,r=4;
    // int mid=l+((r-l)>>1);
    // cout<<mid<<"\n";
    // cout<<"可以输出中文"<<endl;
    vector<int> nums={4,5,5,5,5,6,8,8,9,10,11,12};
    int index1=lower_bound1(nums, 8);
    cout<<"index1:"<<index1<<endl;
    int index2=lower_bound2(nums, 8);
    cout<<"index2:"<<index2<<endl;
    int index3=lower_bound3(nums, 11);
    cout<<"index3:"<<index3<<endl;
    int index4=lower_bound4(nums, 8);
    cout<<"index4:"<<index4<<endl;
    // printf("%d",index);
    vector<int> nums2={1};
    // cout<<lower_bound1(nums2,2);

    vector<int> nums3={0,0,0,0,0,0};
    // cout<<lower_bound3(nums3,1);

    vector<int> nums4={2,3,3,4,4,5};
    int index5=lower_bound3(nums4,3);
    cout<<"index5:"<<index5<<endl;

    int floor = sqrt(4);
    cout << floor << endl;
    floor = pow(64, 1.0f / 3);
    cout << floor << endl;
    return 0;
}