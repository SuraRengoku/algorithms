#include "../leetcodeheader.h"

class fileCombi {
public:
    // sliding window
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ans;
        int left = 1, right = 2, sum = 3;
        
        while(left < right) {
            if(sum == target) {
                vector<int> path;
                for(int i = left; i <= right; path.push_back(i++));
                ans.emplace_back(path);
            }
            if(sum >= target) 
                sum -= left++;
            else
                sum += ++right;
        }
        return ans;
    }
};