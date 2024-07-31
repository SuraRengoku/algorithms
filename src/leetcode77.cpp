#include "leetcodeheader.h"

//组合
class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&](int idx) -> void {
            int d = k - path.size();//距离组合完成还差d个元素
            // if(n < d)   return;
            if(path.size() == k){
                ans.push_back(path);
                return;
            }
            for(int i = idx; i >= d; --i){ //将剩下的d个元素放在之后的递归中选取
                path.push_back(i);
                dfs(i - 1);
                path.pop_back();
            }
        };
        dfs(n);
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&](int idx) -> void {
            if(idx == -1) return;
            if(path.size() == k){
                ans.emplace_back(path);
                return;
            }
            dfs(idx - 1);
            path.push_back(idx);
            dfs(idx - 1);
            path.pop_back();
        };
        dfs(n);
        return ans;
    }
};

//组合II
class Solution3 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int idx, int target) -> void {
            int d = k - path.size();
            if(target < 0 || target > (idx * 2 - d + 1) * d / 2)
                return;
            if(d == 0){
                ans.emplace_back(path);
                return;
            }
            if(idx > d) 
                dfs(idx - 1, target);
            path.push_back(idx);
            dfs(idx - 1, target - idx);
            path.pop_back();
        };
        dfs(9, n);
        return ans;
    }
};

class Solution4 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int idx, int target) -> void {
            int d = k - path.size();
            if(target < 0 || target > (idx * 2 - d + 1) * d / 2)
                return;
            if(d == 0){
                ans.emplace_back(path);
                return;
            }
            for(int i = idx; i >= d; --i){
                path.push_back(i);
                dfs(i - 1, target - i);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }
};


int main(){
    Solution2 solution2;
    vector<vector<int>> result2 = solution2.combine(4, 2);

    Solution3 solution3;
    vector<vector<int>> result3 = solution3.combinationSum3(3, 9);
    return 0;
}