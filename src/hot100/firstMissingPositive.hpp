#include "../leetcodeheader.h"

class firstMissingPositive {
public:
    int first1(vector<int>& nums) {
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

    int first2(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            while(1 <= nums[i] && nums[i] <= len && nums[i] != nums[nums[i] - 1])
                swap(nums[nums[i] - 1], nums[i]);
        }
        
        for(int i = 0; i < len; ++i) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return len + 1;
    }
};