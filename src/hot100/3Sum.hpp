#include "../leetcodeheader.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < len - 2; ++i) {
            int num = nums[i];
            if(i && num == nums[i - 1])
                continue;
            if(num + nums[i + 1] + nums[i + 2] > 0)
                break;
            if(num + nums[len - 1] + nums[len - 2] < 0)
                continue;
            int l = 0, r = len - 1;
            while(l < r) {
                int sum = num + nums[l] + nums[r];
                if(sum > 0)
                    r--;
                else if(sum < 0)
                    l++;
                else{
                    ans.push_back({num, nums[l], nums[r]});
                    for(l++; l < r && nums[l] == nums[l - 1]; ++l);
                    for(r--; l < r && nums[r] == nums[r + 1]; --r);
                }
            }
        }
        return ans;
    }
};