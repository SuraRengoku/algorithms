#include "../leetcodeheader.h"

class solutoin {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        vector<int> path(len), on_path(len);
        auto dfs = [&](auto&& dfs, int n) -> void {
            if(n == len) {
                ans.emplace_back(path);
                return;
            }
            for(int i = 0; i < len; ++i) {
                if(!on_path[i]){
                    path[n] = nums[i];
                    on_path[i] = true;
                    dfs(dfs, n + 1);
                    on_path[i] = false;
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};