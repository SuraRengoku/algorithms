#include "../leetcodeheader.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ml = 0, mr = m - 1;

        auto bs = [&](vector<int> &nums, int target) -> bool {
            int nl = 0, nr = n;
            while(nl < nr) {
                int nmid = nl + (nr - nl) / 2;
                if(nums[nmid] == target) 
                    return true;
                else if(nums[nmid] < target) 
                    nl = nmid + 1;
                else
                    nr = nmid;
            }
            return false;
        };

        while(ml <= mr) {
            int mmid = ml + (mr - ml) / 2;
            if(bs(matrix[mmid], target)) 
                return true;
            else if(matrix[mmid][0] > target) 
                mr = mmid - 1;
            else 
                mr = mmid + 1;
        }
        return false;
    }
};