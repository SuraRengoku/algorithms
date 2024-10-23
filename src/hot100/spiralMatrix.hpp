#include "../leetcodeheader.h"

class Solution {
public:
    vector<int> spiralMatrix(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        int l = 0, t = 0, r = matrix[0].size(), b = matrix.size();
        while(true) {
            for(int i = l; i <= r; ++i) res.push_back(matrix[t][i]);
            if(++t > b) break;
            for(int i = t; i <= b; ++i) res.push_back(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i >= l; --i) res.push_back(matrix[b][i]);
            if(--b < t) break;
            for(int i = b; i >= t; --i) res.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        return res;
    }
};