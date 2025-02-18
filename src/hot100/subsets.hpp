#include "../leetcodeheader.h"

class solution {
public:
    vector<vector<int>> subsets1(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int len = nums.size();
        auto dfs = [&](auto&& dfs, int n) -> void {
            if(n == len) {
                ans.emplace_back(path);
                return;
            }
            dfs(dfs, n + 1);
            path.push_back(nums[n]);
            dfs(dfs, n + 1);
            path.pop_back();
        };
        return ans;
    }  

    vector<vector<int>> subsets2(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int len = nums.size();
        auto dfs = [&](auto&& dfs, int n) -> void {
            ans.emplace_back(path);
            for(int i = n; i < len; ++i) {
                path.push_back(nums[i]);
                dfs(dfs, i + 1);
                path.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
    
};