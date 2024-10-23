#include "../leetcodeheader.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> preSum(len + 1);
        for(int i = 0; i < len; ++i) 
            preSum[i + 1] = preSum[i] + nums[i];
        
        int ans = 0;
        unordered_map<int, int> cnt;
        for(const int ps : preSum){
            ans += cnt.contains(ps - k) ? cnt[ps - k] : 0;
            cnt[ps]++;
        }
        return ans;
    }
};