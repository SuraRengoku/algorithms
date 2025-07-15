#include "../leetcodeheader.h"

class maxProSubarray {
public:
    int maxProduct1(vector<int>& nums) {
        int len = nums.size();
        vector<int> cacheMin(len), cacheMax(len);
        cacheMin[0] = cacheMax[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            int x = nums[i];
            cacheMin[i] = min({cacheMax[i - 1] * x, cacheMin[i - 1] * x, x});
            cacheMax[i] = max({cacheMax[i - 1] * x, cacheMin[i - 1] * x, x});
        }
        return std::ranges::max(cacheMax);
    }
    
    int maxProduct2(vector<int>& nums) {
        int len = nums.size();
        int cMin = 1, cMax = 1;
        int ans = INT_MIN;
        for(int x : nums) {
            int mn = cMin;
            cMin = min({cMin * x, cMax * x, x});
            cMax = max({mn * x, cMax * x, x});
            ans = max(ans, cMax);
        }
        return ans;
    }
};