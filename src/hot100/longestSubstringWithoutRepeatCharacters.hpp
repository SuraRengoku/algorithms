#include "../leetcodeheader.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int ans = 0; 
        int left = 0;
        int len = s.size();
        unordered_map<char, int> count;
        for(int right = 0; right < len; ++right) {
            count[s[right]] += 1;
            while(count[s[right]] > 1)
                count[s[left++]] -= 1;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};