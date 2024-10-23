#include "../leetcodeheader.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> match;
        for(const auto& str : strs) {
            string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            match[tmp].emplace_back(str);
        }
        vector<vector<string>> ans;
        ans.reserve(match.size());
        for(const auto& pair : match)
            ans.emplace_back(pair.second);
    }
};
