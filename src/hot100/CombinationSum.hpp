#include "../leetcodeheader.h"

class solution {
public:
    vector<vector<int>> combination(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int len = candidates.size();
        auto dfs = [&](auto&& dfs, int n) -> void {
            if(n == len)
                return;
            int sum = std::accumulate(path.begin(), path.end(), 0);
            if(sum == target) {
                ans.emplace_back(path);
                return;
            }else if(sum > target) 
                return;
            else{
                for(int i = n; i < len; ++i) {
                    path.push_back(candidates[i]);
                    dfs(dfs, i);
                    path.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};