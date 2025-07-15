#include "../leetcodeheader.h"
#include <unordered_set>

using std::unordered_set;

class WordBreak {
public:
    bool break1(string s, vector<string> wordDicts) {
        int slen = s.size();
        int maxLen = std::ranges::max(wordDicts, {}, &string::length).length();
        unordered_set<string> words(wordDicts.begin(), wordDicts.end());

        vector<int> cache(slen + 1, -1);
        auto dfs = [&](this auto&& dfs, int i) -> bool {
            if(i == 0)
                return true;
            int& res = cache[i];
            if(res != -1)
                return res;
            for(int k = i - 1; k >= max(i - maxLen, 0); --k) {
                if(words.count(s.substr(k, i - k)) && dfs(k))
                    return res = true;
            }
            return res = false;
        };
        return dfs(slen);
    }  

    bool break2(string s, vector<string> wordDicts) {
        int slen = s.size();
        int maxLen = std::ranges::max(wordDicts, {}, &string::length).length();
        unordered_set<string> words(wordDicts.begin(), wordDicts.end());
        
        vector<int> cache(slen + 1);
        cache[0] = true;
        
        for(int i = 1; i <= slen; ++i) {
            for(int k = i - 1; k >= max(i - maxLen, 0); --k) {
                if(words.count(s.substr(k, i - k)) && cache[k]){
                    cache[i] = true;
                    break;
                }
            }
        }
        return cache[slen];
    }

};
