#include "../leetcodeheader.h"

class LIS {
public:
    int lengthOfLIS1(vector<int>& nums) {
        int len = nums.size();
        vector<int> cache(len);
        
        auto dfs = [&](this auto&& dfs, int i) -> int {
            int& res = cache[i];
            if(res > 0)
                return res;
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    res = max(res, dfs(j));
            }
            return ++cache[i];
        };
        int ans = 0;
        for(int i = 0; i < len; ++i)
            ans = max(ans, dfs(i));
        return ans;
    }

    int lengthOfLIS2(vector<int>& nums) {   
        int len = nums.size();
        vector<int> cache(len);
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    cache[i] = max(cache[i], cache[j]);
            }
            cache[i]++;
        }
        return std::ranges::max(cache);
    }
};