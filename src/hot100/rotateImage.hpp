#include "../leetcodeheader.h"

class rotateImage {
public:
    //matrix n * n
    void rotate1(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i = 0; i < len - 1; ++i) {
            for(int j = i + 1; j < len; ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
        for(int i = 0; i < len; ++i) {
            int m = 0, n = len - 1;
            while(m < n) 
                swap(matrix[i][m++], matrix[i][n--]);
        }
        // alternative
        // for(int i = 0; i < len; ++i) {
        //     for(int j = 0; j < len / 2; ++j)
        //         swap(matrix[i][j], matrix[i][len - j - 1]);
        // }
    }

    void rotate2(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int collimit = len % 2 ? (len + 1) / 2 : len / 2;
        for(int i = 0; i < len / 2; ++i) {
            for(int j = 0; j < collimit; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[len - 1 - j][i];
                matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
                matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
                matrix[j][len - 1 - i] = tmp;
            }
        }
    }
};
