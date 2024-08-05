#include "leetcodeheader.h"

class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        function<int(int)> dfs = [&](int idx) -> int {
            if(idx == 0 || idx == 1)
                return idx + 1;
            if(cache[idx] != -1)
                return cache[idx];
            int res = dfs(idx - 1) + dfs(idx - 2);
            cache[idx] = res;
            return res;
        };
        return dfs(n - 1);
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int> s(n, 0);
        s[0] = 1; s[1] = 2;
        for(int i = 2; i < n; ++i)
            s[i] = s[i - 1] + s[i - 2];
        return s[n - 1];
    }
};

class Solution3 {
public:
    int climbStairs(int n) {
        int s1 = 1, s2 = 2, sn;
        for(int i = 3; i <= n; ++i){
            sn = s1 + s2;
            s1 = s2;
            s2 = sn;
        }
        return n == 1 ? s1 : s2;
    }
};

int main(){
    Solution1 sol;
    sol.climbStairs(3);
    return 1;
}