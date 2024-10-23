#include "../leetcodeheader.h"

class Solution {
public:
    /*
     * @param a t_map
     * @param b window_map
     */
    bool covering(unordered_map<char,int>& a, unordered_map<char, int>& b) {
        for(const auto& pair : a){
            if(b[pair.first] < pair.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int lens = s.size(), lent = t.size();
        unordered_map<char, int> tmap;
        for(const auto& c : t) 
            tmap[c]++;
        unordered_map<char, int> windowmap;
        string res = "";
        int left = 0;
        int left_ans = -1, right_ans = lens;
        for(int right = 0; right < lens; ++right) {
            windowmap[s[right]]++;
            while(covering(windowmap, tmap)) {
                if(right - left < right_ans - left_ans) {
                    right_ans = right;
                    left_ans = left;
                }
                windowmap[s[left++]]--;
            }
        }
        return left_ans < 0 ? "" : s.substr(left_ans, right_ans - left_ans + 1);
    }
};