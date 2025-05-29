#include "..\leetcodeheader.h"

// choose or not
class solution1 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int idx, int target) -> void {
            int d = k - path.size();
            if(target < 0 || target > (idx * 2 - d + 1) * d / 2)
                return;
            if(!d) {
                ans.emplcace_back(path);
                return;
            }
            if(idx > d) 
                dfs(idx - 1, target);
            path.push_back(idx);
            dfs(idx - 1, target - idx);
            path.pop_back();
        };
        dfs(9, 0);
        return ans;
    }
};

// which one to choose
class solution2 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int idx, int target) -> void {]
            int d = k - path.size();
            if(target < 0 || target > (idx * 2 - d + 1) * d / 2)
                return;
            if(!d) {
                ans.emplace_back(path);
                return;
            }
            for(int i = idx; i >= d; --i) {
                path.push_back(i);
                dfs(i - 1, target - i);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }   
};