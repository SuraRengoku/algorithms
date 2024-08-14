#include "leetcodeheader.h"

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int row = frame.size(), col = frame[0].size();
        vector<vector<int>> cache(row, vector<int>(col, 0));
        cache[0][0] = frame[0][0];
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(i == 0 && j == 0)    continue;
                else if(j == 0)
                    cache[i][j] = cache[i - 1][j] + frame[i][j];
                else if(i == 0)
                    cache[i][j] = cache[i][j - 1] + frame[i][j];
                else
                    cache[i][j] = max(cache[i][j - 1], cache[i - 1][j]) + frame[i][j];
            }
        }
        return cache[row - 1][col - 1];
    }
};

int main(){
    vector<vector<int>> test1{{1,3,1},{1,5,1},{4,2,1}};
    Solution solution;
    int ans = solution.jewelleryValue(test1);
    printf("answer: %d", ans);
    return 0;
}