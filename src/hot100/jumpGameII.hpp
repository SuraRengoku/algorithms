#include "../leetcodeheader.h"

class jumpGameII {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int Farthest = 0;
        int curFar = 0;
        int ans = 0;
        for(int i = 0; i < len - 1; ++i) {
            Farthest = max(Farthest, i + nums[i]);
            if(i == Farthest) {
                curFar = Farthest;
                ans++;
                if(Farthest >= len - 1)
                    break;
            }
        }
        return ans;
    }
};