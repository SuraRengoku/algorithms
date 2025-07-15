#include "../leetcodeheader.h"

class fib {
public:
    int calfib(int n) {
        if(n < 2)
            return n;
        vector<int> cache(n + 1);
        cache[0] = 0;
        cache[1] = 1;
        for(int i = 2; i <= n; ++i)
            cache[i] = (cache[i - 1] + cache[i - 2]) % 100000007;
        return cache[n];
    }
};