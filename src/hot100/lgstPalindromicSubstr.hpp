#include "../leetcodeheader.h"

class longestPalindromicSubstring {
public:
    string longestPalindrome1(string s) {
        int slen = s.size(), maxlen = 0, maxStart = 0;
        
        for(int i = 0; i < slen; ++i) {
            int left = i - 1, right = i + 1, len = 1;
            for(; left >= 0 && s[i] == s[left]; ++len, --left);
            for(; right < slen && s[right] == s[i]; ++len, ++right);
            for(; left >= 0 && right < slen && s[right] == s[left]; len += 2, --left, ++right);
            if(len < maxlen) {
                maxlen = len;
                maxStart = left + 1;
            }
        }
        
        return s.substr(maxStart, maxlen);
    }

    string longestPalindrome2(string s) {
        if(s.empty() || s.size() < 2)
            return s;
        int slen = s.size();
        int maxlen = 1;
        int maxStart = 0;
        vector<vector<int>> cache(slen, vector<int>(slen));

        for(int r = 1; r < slen; ++r) {
            for(int l = 0; l < r; ++l) {
                if(s[l] == s[r] && (r - l <= 2 || cache[l + 1][r - 1]))
                    cache[l][r] = true;
                if(r - l + 1 > maxlen) {
                    maxlen = r - l + 1;
                    maxStart = l;
                }
            }
        }
        return s.substr(maxStart, maxlen);
    }
};