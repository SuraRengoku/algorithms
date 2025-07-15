#include "../leetcodeheader.h"

class findAnagrams {
    vector<int> indices1(string s, string p) {
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

    vector<int> indices(string s, string p) {
        int slen = s.size(), plen = p.size();
        
        unordered_map<char, int> pcount, count;
        for(auto c : p) pcount[c]++;
        for(int i = 0; i < plen; ++i) count[s[i]]++;

        vector<int> ans;
        int left = 0, right = plen - 1;
        while(right <= slen - 1) {
            if(pcount == count) 
                ans.push_back(left);
            count[s[++right]]++;
            if(--count[s[left]] == 0)
                count.erase(s[left]);
            left++;
        }
        return ans;
    }
};