#include "../leetcodeheader.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 1;
        while(i < nums.size()) {
            if(nums[i] == i + 1 || nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]){
                i++;
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};