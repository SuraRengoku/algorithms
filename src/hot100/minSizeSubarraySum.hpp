#include "../leetcodeheader.h"

class minSizeSubarraySum {
public:
    int minSubarrayLen1(int target, vector<int>& nums) {
        int len = nums.size();
        int ans = len + 1;
        int left = 0, right = 0;
        int sum = 0; 
        while(right < len) {
            sum += nums[right];
            while(sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
            ++right;
        }
        return ans == len + 1 ? 0 : ans;
    }

    int minSubarrayLen2(int target, vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int ans = len + 1;
        int sum = 0;

        for(int i = 0; i < len; ++i) {
            sum += nums[i];
            while(sum - nums[left] >= target)
                sum -= nums[left++];
            if(sum >= target)
                ans = min(ans, i - left + 1);
        }
        return ans == len + 1 ? 0 : ans;
    }
};