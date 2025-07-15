#include "../leetcodeheader.h"

class Container {
public:
    int mostWater (vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            height[l] <= height[r] ? l++ : r--;
        }
        return ans;
    }
};