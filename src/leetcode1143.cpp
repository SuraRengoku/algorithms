#include "leetcodeheader.h"

class Solution1 {
public:
    static int longestCommonSequences(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> cache(len1, vector<int>(len2, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(i < 0 || j < 0)
                return 0;
            int& res = cache[i][j];
            if(res != -1)
                return res;
            if(text1[i] == text2[j]){
                res = dp(i - 1, j - 1) + 1;
                return res;
            }
            res = max(dp(i - 1, j), dp(i, j - 1));
            return res;
        };
        return dp(len1 - 1, len2 - 1);
    }
};

class Solution2 {
public:
    static int longestCommonSequences(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> cache(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                if(text1[i] == text2[j])
                    cache[i + 1][j + 1] = cache[i][j] + 1;
                else 
                    cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
        return cache[len1][len2];
    }
};

class Solution3 {
public:
    static int longestCommonSequences(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> cache(2, vector<int>(len2 + 1, 0));
        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                if(text1[i] == text2[j])
                    cache[(i + 1) % 2][j + 1] = cache[i % 2][j] + 1;
                else 
                    cache[(i + 1) % 2][j + 1] = max(cache[(i + 1) % 2][j], cache[i % 2][j + 1]);
            }
        }
        return cache[len1 % 2][len2];
    }
};

class Solution4 {
public:
    static int longestCommonSequences(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<int> cache(len2 + 1, 0);
        for(int i = 0; i < len1; ++i){
            for(int j = 0, pre = 0; j < len2; ++j){
                int tmp = cache[j + 1];
                cache[j + 1] = text1[i] == text1[j] ? cache[j] + 1 : max(cache[j], cache[j + 1]);
                pre = tmp;
            }
        }
        return cache[len2];
    }
};

int main() {
    cout << Solution1::longestCommonSequences("abcde", "ace") << endl;
    cout << Solution2::longestCommonSequences("abcde", "ace") << endl;
    cout << Solution3::longestCommonSequences("abcde", "ace") << endl;
    cout << Solution4::longestCommonSequences("abcde", "ace") << endl;
    return 0;
}