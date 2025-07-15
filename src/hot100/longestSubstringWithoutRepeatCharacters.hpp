#include "../leetcodeheader.h"

class lengthOfLongestSubstring {
public:
    int longest1(string s){
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

    int longes2(string s) {
        int len = s.size(), ans = 0, left = 0;
        unordered_set<char> count;
        for(int right = 0; right < len; ++right) {
            char c = s[right];
            while(count.contains(c))
                count.erase(s[left++]);
            count.insert(c);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};