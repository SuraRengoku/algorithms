#include "leetcodeheader.h"

class Zero_One_KnapSack {
    Zero_One_KnapSack() = delete;
    int zero_one_knapSack(int capacity, vector<int> weights, vector<int> values) {
        int len = weights.size();
        function<int(int, int)> dfs = [&](int idx, int c) {
            if(idx < 0)
                return 0;
            if(c < weights[idx])
                return dfs(idx - 1, c);
            return max(dfs(idx - 1, c), dfs(idx - 1, c - weights[idx]) + values[idx]);
        };
        return dfs(len - 1, capacity);
    }
};

int main() {
    //TODO testcase
    return 0;
}