#include "leetcodeheader.h"

class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = reduce(nums.begin(), nums.end());
        if(sum % 2)
            return false;
        int target = sum / 2;
        vector<vector<int>> cache(len, vector<int>(target + 1, - 1));
        function<bool(int, int)> dp = [&](int idx, int c) -> bool {
            if(idx < 0)
                return c == 0;
            int& res = cache[idx][c];
            if(res == -1)
                res = c >= nums[idx] && dp(idx - 1, c - nums[idx]) || dp(idx - 1, c);
            return res;
        };
        return dp(len - 1, target);
    }
};

class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = reduce(nums.begin(), nums.end());
        if(sum % 2)
            return false;
        int target = sum / 2;
        vector<vector<int>> cache(len + 1, vector<int>(target + 1, false));
        cache[0][0] = true;
        for(int i = 0; i < len; ++i){
            for(int j = 0; j <= target; ++j)
                cache[i + 1][j] = j >= nums[i] && cache[i][j - nums[i]] || cache[i][j];
        }
        return cache[len][target];
    }
};

class Solution3 {
public:
    bool canPartition(vector<int>& nums){
        int len = nums.size();
        int sum = reduce(nums.begin(), nums.end());
        if(sum % 2)
            return false;
        int target = sum / 2;
        vector<int> cache(target + 1, false);
        cache[0] = true;
        int sf = 0;
        for(int num : nums){
            sf = min(sf + num, target);
            for(int j = sf; j >= num; --j)
                cache[j] |= cache[j - num];
        }
        return cache[target];
    }
};

int main() {
    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;
    vector<int> testcase{100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
                        100,100,100,100,100,100,99,97};
    bool res1 = solution1.canPartition(testcase);
    printf("answer: %s\n", res1 ? "true" : "false");
    bool res2 = solution2.canPartition(testcase);
    printf("answer: %s\n", res2 ? "true" : "false");
    bool res3 = solution3.canPartition(testcase);
    printf("answer: %s\n", res3 ? "true" : "false");
    return 0;
}