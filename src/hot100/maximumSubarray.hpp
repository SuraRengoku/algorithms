#include "../leetcodeheader.h"

class Solution1 {
public:
    int maxSubArray(vector<int>& nums){
        int res = INT_MIN;
        int preMin = 0;
        int preSum = 0;
        for(const int& num : nums) {
            preSum += num;
            res = max(res, preSum - preMin);
            preMin = min(preMin, preSum);
        }
        return res;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> cache(len);
        cache[0] = nums[0];
        for(int i = 1; i < len; ++i)
            cache[i] = max(cache[i - 1], 0) + nums[i];
        return *max_element(cache.begin(), cache.end());
    }
};