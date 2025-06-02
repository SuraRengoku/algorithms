#include "leetcodeheader.h"
#include <climits>
#include <cmath>

class Solution1 {
public:
    //超时
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int len = nums.size();
        int ans = -1;
        function<int(int, int, int)> dfs = [&](int idx, int c, int v) -> int {
            if(idx < 0){
                return c == 0 ? max(v, ans) : -1;
            }
            if(nums[idx] > c)
                return dfs(idx - 1, c, v);
            return max(dfs(idx - 1, c, v), dfs(idx - 1, c - nums[idx], v + 1));
        };
        return dfs(len - 1, target, 0);
    }
};

class Solution2 {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(target + 1, INT_MIN));
        dp[0][0] = 0;
        for(int i = 0; i < len; ++i){
            for(int j = 0; j <= target; ++j){
                if(j < nums[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - nums[i]] + 1);
            }
        }
        int ans = dp[len][target];
        return ans <= 0 ? -1 : ans;
    }
};

class Solution3 {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        int sum = 0;
        for(const int& num : nums){
            sum = min(sum + num, target);
            for(int i = sum; i >= num; --i)
                dp[i] = max(dp[i], dp[i - num] + 1);
        }
        return dp[target] > 0 ? dp[target] : -1;
    }
};

int main() {
    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;
    vector<int> testcase_1{3,7,6,7,2,2,2,10,7,10,8,7,7,10,7,3,1,2,8,3,5,1,5,8,4,8,8,7,6,2,4,8,10,9,5,9,2,3,1,7,4,10,7,5,2,8,6,5,1,3,5,9,9,10,6,10};
    int target_1 = 162;
    cout << solution3.lengthOfLongestSubsequence(testcase_1, target_1) << endl;
    cout << static_cast<int>(std::sqrt(5));
    return 0;
}