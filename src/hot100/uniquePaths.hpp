#include "../leetcodeheader.h"

class uniquePaths {
public:
    int path1(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        auto dp = [&](this auto&& dp, int i, int j) -> int {
            if(i > m - 1 || j > n - 1)
                return 0;
            if(i == m - 1 && j == n - 1)
                return 1;
            int& res = cache[i][j];
            if(res != -1)
                return res;
            return res = dp(i + 1, j) + dp(i, j + 1);
        };
        return dp(0, 0);
    }

    int path2(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        cache[m - 1][n - 1] = 0;

        if(m == 1 || n == 1)
            return 1;
        
        for(int i = m - 2; i >= 0; --i)
            cache[i][n - 1] = 1;
        for(int j = n - 2; j >= 0; --j)
            cache[m - 1][j] = 1;

        for(int i = m - 2; i >= 0; --i) {
            for(int j = n - 2; j >= 0; --j)
                cache[i][j] = cache[i][j + 1] + cache[i + 1][j];
        }
        return cache[0][0];
    }
};