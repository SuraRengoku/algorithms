#include "../leetcodeheader.h"

class nextPermutation {
public:
    void solution(vector<int>& nums) {
        int len = nums.size();
        // step 1. find the number waiting to be swaped
        int i = len - 2;
        for(;i >= 0 && nums[i] >= nums[i + 1]; --i);
        // stp 2. if found, swap it with the smallest number in its right side, id not, skip step 2
        if(i >= 0) {
            int j = len - 1;
            for(; nums[j] <= nums[i]; --j);
            swap(nums[i], nums[j]);
        }
        // step 3. reverse numbers after the number, if step 2 is skipped, reverse all numbers
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};