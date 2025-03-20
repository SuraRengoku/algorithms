#include "../leetcodeheader.h"

class solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto bs = [&](vector<int> &arr, int target) -> bool {
            int l = 0, r = arr.size() - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(arr[mid] == target) 
                    return true;
                else if(arr[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            return false;
        };
        
        int start = bs(nums, target);
        if(start == nums.size() || nums[start] != target) 
            return { -1, -1 };
        int end = bs(nums, target + 1) - 1;
        return { start, end };
    }
};