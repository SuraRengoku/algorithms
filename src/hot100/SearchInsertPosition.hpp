#include "../leetcodeheader.h"

class solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        if(target <= nums[l])
            return 0;
        if(target > nums[r])
            return r + 1;
        int mid = (l + r) / 2;
        while(l + 1 < r) {
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid]) {
                r = mid;
                mid = (l + r) / 2;
            }else {
                l = mid;
                mid = (l + r) / 2;
            }   
        }
        return l + 1;
    }
};