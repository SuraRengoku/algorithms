#include "../leetcodeheader.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        auto reverse = [&](int i, int j) {
            while(i < j)
                swap(nums[i++], nums[j--]);
        };
        reverse(0, len - 1);
        reverse(0, k - 1);
        reverse(k, len - 1);
    }
};