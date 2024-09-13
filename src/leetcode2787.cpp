#include "leetcodeheader.h"

class Solution1 {
    static const int M = 1000000007;
public:
//单纯回溯超时， 需要设置缓存
    static int numberOfWays(int n, int x) {
        int floor = pow(n, 1.0f / x);
        vector<vector<int>> cache(floor + 1, vector<int>(n + 1, -1));
        function<int(int, int)> dp = [&](int idx, int c) -> int {
            if(idx < 1)
                return c == 0;
            int& res = cache[idx][c];
            if(res != -1)
                return res;
            if(c < pow(idx, x)){
                res = dp(idx - 1, c) % M;
                return res;
            }
            res = (dp(idx - 1, c) + dp(idx - 1, c - pow(idx, x))) % M;
            return res;
        };
        return dp(floor, n) % M;
    }
};

class Solution2 {
    static const int M = 1000000007;
public:
    static int numberOfWays(int n, int x) {
        int floor = pow(n, 1.0f / x);
        vector<vector<int>> cache(floor + 1, vector<int>(n + 1, 0));
        cache[0][0] = 1;
        for(int i = 1; i <= floor; ++i){
            for(int j = 0; j <= n; ++j){
                if(j < pow(i, x))
                    cache[i][j] = cache[i - 1][j] % M;
                else
                    cache[i][j] = (cache[i - 1][j] + cache[i - 1][j - pow(i, x)]) % M;
            }
        }
        return cache[floor][n];
    }
};

class Solution3 {
    static const int M = 1000000007;
public:
    static int numberOfWays(int n, int x) {
        int floor = pow(n, 1.0f / x);
        vector<int> cache(n + 1, 0);
        cache[0] = 1;
        for(int i = 1; i <= floor; ++i){
            for(int j = n; j >= pow(i, x); --j)
                cache[j] = (cache[j] + cache[j - pow(i, x)]) % M;
        }
        return cache[n];
    }
};

int main() {
    cout << Solution1::numberOfWays(213, 1) << endl;
    cout << Solution2::numberOfWays(213, 1) << endl;
    cout << Solution3::numberOfWays(213, 1) << endl;
    return 0;
}