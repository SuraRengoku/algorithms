#include "../leetcodeheader.h"

class rotateArray {
public:
    void rotate1(vector<int>& nums, int k) {
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

    void rotate2(vector<int>& nums, int k) {
        deque<int> dq(nums.begin(), nums.end());
        for(int i = 1; i <= k; ++i) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        nums = vector<int>(dq.begin(), dq.end());
    }
};