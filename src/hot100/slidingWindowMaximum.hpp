#include "../leetcodeheader.h"

// 降本增效
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        deque<int> window;
        for(int i = 0; i < len; ++i) {
            // insert
            while(!window.empty() && nums[i] > nums[window.back()])
                window.pop_back();
            window.push_back(i);
            // remove
            if(i - window.front() >= k)
                window.pop_front();
            // record
            if(i >= k - 1)
                res.push_back(nums[window.front()]);
        }
        return res;
    }
};