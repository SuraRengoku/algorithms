#include "../leetcodeheader.h"
#include<math.h>
#include<climits>

class perfectSquares {
public:
    int numSquares1(int n) {
         int x = static_cast<int>(std::sqrt(n));
        vector<vector<int>> cache(n + 1, vector<int>(x + 1, -1));
        function<int(int, int)> dfs = [&](int num, int idx) -> int {
            if(idx < 0)
                return num == 0 ? 0 : INT_MAX / 2;
            if(cache[num][idx] != -1)
                return cache[num][idx];
            if(num < idx * idx)
                return dfs(num, idx - 1);
            return cache[num][idx] = min(1 + dfs(num - idx * idx, idx), dfs(num, idx - 1));
        };
        return dfs(n, x);
    }

    int numSquares2(int n) {
        int x = static_cast<int>(std::sqrt(n));
        vector<vector<int>> cache(n + 1, vector<int>(x + 1, INT_MAX));
        
        for(int j = 0; j <= x; ++j)
            cache[0][j] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= x; ++j) {
                if(i < j * j)
                    cache[i][j] = cache[i][j - 1];
                else
                    cache[i][j] = min(cache[i][j - 1], cache[i - j * j][j] + 1);
            }
        }
        return cache[n][x];
    }

    int numSquares3(int n) {
        vector<int> cache(n + 1, INT_MAX);
        cache[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j * j <= i; ++j)
                cache[i] = min(cache[i], cache[i - j * j] + 1);
        }
        return cache[n];
    }
};