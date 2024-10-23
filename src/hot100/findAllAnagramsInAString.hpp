#include "../leetcodeheader.h"

class Solution {
    vector<int> findAnagrams(string s, string p) {
        int lens = s.size(), lenp = p.size();
        vector<int> ans;
        if(lens < lenp)
            return ans;

        vector<int> sCount(26), pCount(26);
        for(const auto& e : p)
            pCount[e - 'a']++;

        int left = 0;
        for(int right = 0; right < lens; ++right) {
            int curRidx = s[right] - 'a';
            sCount[curRidx]++;
            while(sCount[curRidx] > pCount[curRidx]){
                int curLidx = s[left] - 'a';
                sCount[curLidx]--;
                left++;
            }
            if(right - left + 1 == lenp)
                ans.push_back(left);
        }   
        return ans;
    }
};