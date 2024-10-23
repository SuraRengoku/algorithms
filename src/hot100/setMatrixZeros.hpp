#include "../leetcodeheader.h"

class Solution {
public:
    void setZeros(vector<vector<int>>& matrix) {
        int rowlen = matrix.size(), collen = matrix[0].size();
        int row0 = false, col0 = false;
        for(int j = 0; j < collen; ++j) {
            if(matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        for(int i = 0; i < rowlen; ++i) {
            if(matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for(int i = 1; i < rowlen; ++i) {
            for(int j = 1; j < collen; ++j) {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i = 1; i < rowlen; ++i) {
            for(int j = 1; j < collen; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(row0) {
            for(int j = 0; j < collen; ++j)
                matrix[0][j] = 0;
        }
        if(col0) {
            for(int i = 0; i < rowlen; ++i)
                matrix[i][0] = 0;
        }
    }
};