#include "../leetcodeheader.h"

class Solution1 {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> preMax(len);
        vector<int> sufMax(len);
        preMax[0] = height[0];
        for(int i = 1; i < len; ++i)
            preMax[i] = max(preMax[i - 1], height[i]);
        sufMax[len - 1] = height[len - 1];
        for(int i = len - 2; i >= 0; --i)
            sufMax[i] = max(sufMax[i + 1], height[i]);
        int ans = 0;
        for(int i = 0; i < len; ++i)
            ans += min(preMax[i], sufMax[i]) - height[i];
        return ans;
    }
};

class Solution2 {
    int trap(vector<int>& height) {
        int len = height.size();
        int preMax = 0, sufMax = 0;
        int l = 0, r = len - 1;
        int ans = 0;
        while(l < r) {
            //若preMax或者sufMax被当前高度取代， 则该处无法接雨水
            preMax = max(preMax, height[l]);
            sufMax = max(sufMax, height[r]);
            if(preMax < sufMax)
                ans += preMax - height[l++];
            else 
                ans += sufMax - height[r--];
        }
        return ans;
    }
};