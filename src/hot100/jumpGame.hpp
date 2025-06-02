#include "../leetcodeheader.h"

class jumpGame {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int farthest = 0;
        for(int i = 0; i < len - 1; ++i) {
            if(farthest < i) return false;
            farthest = max(farthest, i + nums[i]);
        }
        return farthest >= len - 1;
    }
};