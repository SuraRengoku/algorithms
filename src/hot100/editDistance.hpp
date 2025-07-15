#include "../leetcodeheader.h"

class editDistance {
public:
    int Distance1(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> cache(len1, vector<int>(len2, -1));

        auto dp = [&](this auto&& dp, int i, int j) -> int {
            if(i < 0)
                return j + 1;
            if(j < 0)
                return i + 1;
            int& res = cache[i][j];
            if(res != -1)
                return res;
            if(word1[i] == word2[j])
                return res = dp(i - 1, j - 1);
            return res = min({dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1)}) + 1;
        };
        return dp(len1 - 1, len2 - 1);
    }

    int Distance2(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> cache(len1 + 1, vector<int>(len2 + 1));
        
        for(int i = 0; i < len1; cache[i + 1][0] = i + 1, ++i);
        for(int j = 0; j < len2; cache[0][j + 1] = j + 1, ++j);

        for(int i = 0; i < len1; ++i) {
            for(int j = 0; j < len2; ++j) {
                cache[i + 1][j + 1] = word1[i] == word2[j] ? cache[i][j] : min({cache[i][j + 1], cache[i + 1][j], cache[i][j]}) + 1;
            }
        }
        return cache[len1][len2];
    }
};