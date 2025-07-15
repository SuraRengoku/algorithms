#include "../leetcodeheader.h"

class houseRobber {
public:
    int robber1 (vector<int>& nums) {
        int len = nums.size();
        vector<int> cache(len, -1);
        function<int(int)> dfs = [&](int idx) -> int {
            if(idx < 0)
                return 0;
            else if(idx == 0)
                return nums[0];
            if(cache[idx] != -1)
                return cache[idx];
            return cache[idx] = max(nums[idx] + dfs(idx - 2), dfs(idx - 1));
        };
        return dfs(len - 1);
    }

    int robber2 (vector<int>& nums) {
        int len = nums.size();
        vector<int> cache(len + 2);
        for(int i = 0; i < len; ++i) 
            cache[i + 2] = max(cache[i] + nums[i], cache[i + 1]);
        return cache[len + 1];
    }

    int robber3(vector<int>& nums) {
        int len = nums.size();
        int f0 = 0, f1 = 0, f;
        for(int i = 0; i < len; ++i) {
            f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = f;
        }
        return f1;
    }
};