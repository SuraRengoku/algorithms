#include "../leetcodeheader.h"

class solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> path(n, 0);
        vector<string> result;
        vector<bool> on_col(n, false), rigL(2 * n - 1, false), rigR(2 * n - 1, false);

        auto dfs = [&](auto&& dfs, int i) {
            if(i == n) {
                for(int j = 0; j < n; ++j) {
                    string pre(path[j], '.'), suf(n - path[j] - 1, '.');
                    result.emplace_back(pre + 'Q' + suf);
                }
                ans.emplace_back(result);
                result.clear();
                return;
            }

            for(int k = 0; k < n; ++k) {
                if(!on_col[k] && !rigL[i - k + n - 1] && !rigR[i + k]) {
                    path[i] = k;
                    on_col[k] = rigL[i - k + n - 1] = rigR[i + k] = true;
                    dfs(dfs, i + 1);
                    on_col[k] = rigL[i - k + n - 1] = rigR[i + k] = false;
                }
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};