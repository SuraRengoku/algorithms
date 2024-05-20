#ifndef BinarySearch_hpp
#define BinarySearch_hpp

#include<vector>
#include<limits>
#include<type_traits>
#include<concepts>

using std::vector;

template<typename T>
concept IsNumber = std::is_arithmetic<T>::value;

template<IsNumber T>
auto lower_bound1(const vector<T>& nums, T target)->int{
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2; //有效防止溢出
        if(nums[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return left; 
}//左闭右闭

// template<typename T> requires std::is_arithmetic_v<T>
// auto lower_bound2(const vector<T>& nums, T target)->int{
//     int left=0;
//     int right=nums.size();
//     while(){

//     }
//     return 
// }//左闭右开

// template<typename T> requires std::is_arithmetic_v<T>
// auto lower_bound3(const vector<T>& nums, T target)->int{
//     int left=-1;
//     int right=nums.size();
//     while(){

//     }
//     return 
// }//左开右开

#endif 
