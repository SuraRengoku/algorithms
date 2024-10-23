#include "leetcodeheader.h"

class Solution1 {
public:
    bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] && a[1] < b[1];
    }
    int maxEnvelops(vector<vector<int>>& envelops) {
        int len = envelops.size();
        sort(envelops.begin(), envelops.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        function<int(int)> dfs = [&](int i) -> int {
            int res = 0;
            for(int j = 0; j < i; ++j){
                if(compare(envelops[j], envelops[i]))
                    res = max(res, dfs(j));
            }
            return res + 1;
        };
        int ans = 0;
        for(int i = 0; i < len; ++i) 
            ans = max(ans, dfs(i));
        return ans;
    }
};

class Solution2 {
public:
    int maxEnvelops(vector<vector<int>>& envelops) {
        int len = envelops.size();
        sort(envelops.begin(), envelops.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp(1, envelops[0][1]);
        for(int i = 1; i < len; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelops[i][1]);
            if(it == dp.end())
                dp.emplace_back(std::move(envelops[i][1]));
            else
                *it = envelops[i][1];
        }
        return dp.size();
    }
};

int main() {
    Solution1 solution1;
    Solution2 solution2;
    vector<vector<int>> testcase{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    std::cout << solution1.maxEnvelops(testcase) << std::endl;
    std::cout << solution2.maxEnvelops(testcase) << std::endl;
    return 0; 
}
