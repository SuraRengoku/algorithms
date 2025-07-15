#include "../leetcodeheader.h"
#include <climits>

class coinChange {
public:
    int change1(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<vector<int>> cache(amount + 1, vector<int>(len + 1, -1));
        auto dfs = [&](this auto&& dfs, int value, int idx) -> int {
            if(idx < 0)
                return value == 0 ? 0 : INT_MAX / 2;
            int& res = cache[value][idx];
            if(res != -1)
                return res;
            if(value < coins[idx])
                return res = dfs(value, idx - 1);
            return res = min(dfs(value, idx - 1), dfs(value - coins[idx], idx) + 1);
        };
        int ans = dfs(amount, len - 1);
        return ans < INT_MAX / 2 ? ans : -1;
    }

    int change2(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<vector<int>> cache(amount + 1, vector<int>(len + 1, INT_MAX / 2));
        cache[0][0] = 0;
        for(int i = 0; i <= amount; ++i) {
            for(int j = 0; j < len; ++j) {
                if(coins[j] > i) 
                    cache[i][j + 1] = cache[i][j];
                else
                    cache[i][j + 1] = min(cache[i][j], cache[i - coins[j]][j + 1] + 1);
            }
        }
        return cache[amount][len] < INT_MAX / 2 ? cache[amount][len] : -1;
    }

    int change3(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> cache(amount + 1, INT_MAX / 2);
        cache[0] = 0;
        for(int i = 0; i <= amount; ++i) {
            for(int coin : coins) {
                if(coin <= i)
                    cache[i] = min(cache[i], cache[i - coin] + 1); 
            }
        }
        return cache[amount] < INT_MAX / 2 ? cache[amount] : -1;
    }
};