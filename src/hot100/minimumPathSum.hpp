#include "../leetcodeheader.h"

class mininumPathSum {
public:
    int minPathSum1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache(m, vector<int>(n, -1));

        auto dp = [&](this auto&& dp, int i, int j) -> int {
            if(i < 0 || j < 0)
                return INT_MAX;
            if(i == 0 && j == 0)
                return grid[i][j];
            int& res = cache[i][j];
            if(res != -1)
                return res;
            return res = grid[i][j] + min(dp(i - 1, j), dp(i, j - 1));
        };
        return dp(m, n);
    }

    int minPathSum2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, INT_MAX));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0)
                    cache[i + 1][j + 1] = grid[i][i];
                else
                    cache[i + 1][j + 1] = grid[i][j] + min(cache[i][j + 1], cache[i + 1][j]);
            }
        }
        return cache[m][n];
    }
};