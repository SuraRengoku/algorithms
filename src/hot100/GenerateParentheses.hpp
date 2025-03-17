#include "../leetcodeheader.h"

class solution1 {
    public:
        vector<string> generateParenthesis(int n){
            vector<string> ans;
            string path = "";
            int m = 2 * n;  
            // open stands for the number of left parenthesis
            auto dfs = [&](auto&& dfs, int i, int open) -> void {
                if(i == m){ // finish enumerating
                    ans.emplace_back(path);
                    return;
                }
                // we can still insert left parenthesis
                if(open < n) { 
                    path.push_back('(');
                    dfs(dfs, i + 1, open + 1);
                    path.pop_back();
                }
                // i - open stands for the number of right parenthesis, if it is less than open that means we can still insert right parenthesis
                if(i - open < open) { 
                    path.push_back(')');
                    dfs(dfs, i + 1, open);
                    path.pop_back();
                }
            };
            dfs(dfs, 0, 0);
            return ans;
        }
    };

    class solution2 {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            vector<int> path;
            // balance stands for the difference between the number of left and right parentheses
            auto dfs = [&](auto &&dfs, int i, int balance) -> void {
                if(path.size() == n) {
                    string s(2 * n, ')');
                    for(int j : path)
                        s[j] = '(';
                    ans.emplace_back(s);
                    return;
                }
                for(int close = 0; close <= balance; ++close) {
                    path.push_back(close + i);
                    dfs(dfs, i + close + 1, balance - close + 1);
                    path.pop_back();
                }
            };
            dfs(dfs, 0, 0);
            return ans;
        }
    };