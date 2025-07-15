#include "../leetcodeheader.h"

class climbStairs {
public:
    int solution1(int n) {
        vector<int> cache(n + 1);
        function<int(int)> dfs = [&](int idx) -> int {
            if(idx <= 1)
                return 1;
            int& res = cache[idx];
            if(res)
                return res;
            return res = dfs(idx - 1) + dfs(idx - 2);
        };
        return dfs(n);
    }

    int solution2(int n) {
        vector<int> cache(n + 1);
        cache[0] = cache[1] = 1;
        for(int i = 2; i <= n; ++i)
            cache[i] = cache[i - 1] + cache[i - 2];
        return cache[n];
    }

    int solution3(int n) {
        int f0 = 1, f1 = 1, f;
        for(int i = 2; i <= n; ++i) {
            f = f0 + f1;
            f0 = f1;
            f1 = f;
        }
        return f1;
    }
};