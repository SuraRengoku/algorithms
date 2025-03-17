#include "../leetcodeheader.h"

static bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    if(r == -1)
        return false;
    while(l < r) {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

static bool check(string s, int begin, int end) {
    if(begin == end)
        return true;
    while(begin < end) {
        if(s[begin] != s[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

class Solution1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int len = s.size();
        vector<string> path;
        auto dfs = [&](auto&& dfs, int i) -> void {
            if(i == len) {
                ans.emplace_back(path);
                return;
            }
            for(int j = i + 1; j <= len; ++j) {
                string tmp = s.substr(i, j - i);
                if(isPalindrome(tmp)) {
                    path.emplace_back(tmp);
                    dfs(dfs, j);
                    path.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int len = s.size();
        auto dfs = [&](auto&& dfs, int i, int start) -> void {
            if(i == len) {
                ans.emplace_back(path);
                return;
            }
            if(i < len - 1)
                dfs(dfs, i + 1, start);
            if(check(s, start, i)) {
                path.emplace_back(s.substr(start, i - start + 1));
                dfs(dfs, i + 1, i + 1);
                path.pop_back();
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};