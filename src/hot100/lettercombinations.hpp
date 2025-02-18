#include "../leetcodeheader.h"

class solution {
    vector<string> mapping{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if(len == 0)
            return {};
        vector<string> ans;
        string path = "";
        auto dfs = [&] (auto&& dfs, int n) -> void {
            if(n == len) {
                ans.emplace_back(path);
                return;
            }
            for(char c : mapping[digits[n] - '0']){
                path.push_back(c);
                dfs(dfs, n + 1);
                path.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};