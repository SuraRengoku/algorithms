#include "../leetcodeheader.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> match;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = match.find(target - nums[i]);
            if(it != match.end())
                return {it -> second, i};
            match[nums[i]] = i;          
        }
        return {};
    }
};

