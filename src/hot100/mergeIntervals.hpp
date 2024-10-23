#include "../leetcodeheader.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(const auto& interval : intervals){
            if(!res.empty() && res.back()[1] >= interval[0])
                res.back()[1] = max(res.back()[1], interval[1]);
            else 
                res.emplace_back(interval);
        }
        return res;
    }
};