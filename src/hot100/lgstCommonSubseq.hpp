#include "../leetcodeheader.h"

class longestCommonSubsequence {
public:
    int lgstCommonSubseq1(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> cache(len1, vector<int>(len2, -1));

        auto dp = [&](this auto&& dp, int i, int j) -> int {
            if(i < 0 || j < 0)
                return 0;
            int& res = cache[i][j];
            if(res != -1)
                return res;
            if(text1[i] == text2[j])
                return res = dp(i - 1, j - 1) + 1;
            return res = max(dp(i - 1, j), dp(i, j - 1));
        };
        return dp(len1 - 1, len2 - 1);
    }

    int lgstCommonSubseq2(string text1, string text2) {
        int len1 = text2.size(), len2 = text2.size();
        vector<vector<int>> cache(len1 + 1, vector<int>(len2 + 1));
        cache[0][0] = 0;
        
        for(int i = 0; i < len1; ++i) {
            for(int j = 0; j < len2; ++j) {
                cache[i + 1][j + 1] = text1[i] == text2[j] ? cache[i][j] + 1 : max(cache[i][j + 1], cache[i + 1][j]);
            }
        }
        
        return cache[len1][len2];
    }
};