#include "leetcodeheader.h"

using std::remove_copy_if;

class Solution1 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        next_permutation(ans.begin(), ans.end());
        vector<int> col(n, 0);
        vector<string> result;
        vector<bool> on_path(n, false), digL(n, false), digR(n, false);
        function<void(int)> dfs = [&](int row) -> void {
            if(row == n){
                for(int i = 0; i < row; ++i){
                    string pre(col[i], '.');
                    string suf(n - col[i] - 1, '.');
                    result.emplace_back(pre + 'Q' + suf);
                };
                ans.emplace_back(result);
                result.clear();
                return;
            }
            for(int clm = 0; clm < n; ++clm){
                if(!on_path[clm] && !digL[row - clm + n - 1] && !digR[row + clm]){
                    col[row] = clm;
                    on_path[clm] = digL[row - clm + n - 1] = digR[row + clm] = true;
                    dfs(row + 1);
                    on_path[clm] = digL[row - clm + n - 1] = digR[row + clm] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<int> col(n, 0);
        vector<string> result;
        vector<int> init;
        for(int i = 0; i < n; ++i)
            init.push_back(i);
        function<bool(int, int)> valid = [&](int row, int clm) -> bool {
            for(int R = 0; R < row; ++R){
                if(col[R] + R == row + clm || R - col[R] == row - clm)
                    return false;
            }
            return true;
        };
        function<void(int, vector<int>)> dfs = [&](int row, vector<int> left) -> void {
            if(row == n){
                for(int i = 0; i < n; ++i){
                    string pre(col[i], '.');
                    string suf(n - col[i] -1, '.');
                    result.emplace_back(pre + 'Q' + suf);
                }
                ans.emplace_back(result);
                result.clear();
                return;
            }
            for(const int& clm : left){
                if(valid(row, clm)){
                    col[row] = clm;
                    vector<int> tmp;
                    remove_copy_if(left.begin(), left.end(), back_inserter(tmp), [clm](int x){ return x == clm;});
                    dfs(row + 1, tmp);
                }
            }
        };
        dfs(0, init);
        return ans;
    }
};

int main(){
    return 0;
}