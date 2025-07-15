#include "../leetcodeheader.h"
#include <numeric>

class partitionEqualSubsetSum {
public:
    bool canPartition1(vector<int>& nums) {
        int len = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        int hsum = sum / 2;
        vector<vector<int>> cache(len, vector<int>(hsum + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int rec) -> bool {
            if(i < 0)
                return rec == 0;
            int &res = cache[i][rec];
            if(rec != -1)
                return res;
            return res = rec > nums[i] && dfs(i - 1, rec - nums[i]) || dfs(i - 1, rec);
        };
        return dfs(len - 1, hsum);
    }
    
    bool canPartition2(vector<int>& nums) {
        int len = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        int hsum = sum / 2;
        vector<vector<int>> cache(len + 1, vector<int>(hsum + 1, -1));
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j <= hsum; ++j) 
                cache[i + 1][j] = j >= nums[i] && cache[i][j - nums[i]] || cache[i][j];
        }
        return cache[len][hsum];
    }

    bool canPartition3(vector<int>& nums) {
        int len = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        int hsum = sum / 2;
        vector<int> cache(hsum + 1, false);
        cache[0] = true;
        int sf = 0;
        for(int num : nums) {
            sf = min(sf + num, hsum);
            for(int j = sf; j >= num; --j) 
                cache[j] |= cache[j - num];   
        }
        return cache[hsum];
    }
};