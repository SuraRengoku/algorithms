#include "leetcodeheader.h"

class Solution{
public:
    //选或不选
    vector<string> generateParenthesis1(int n) {
        vector<string> ans;
        string path(2 * n, '\0');
        /**
        * @param open 左括号的个数
        */
        function<void(int, int)> dfs = [&](int idx, int open) -> void {
            if(idx == 2 * n)
                ans.push_back(path);
            if(idx - open < open){
                path[idx] = ')';
                dfs(idx + 1, open);
            } //idx - open 为右括号的个数
            if(open < n){
                path[idx] = '(';
                dfs(idx + 1, open + 1);
            }
        };
        dfs(0, 0);
        return ans;
    }
    //枚举左括号的位置
    vector<string> generateParenthesis2(int n){
        vector<string> ans;
        vector<int> path;
        /**
        * @param balance 左括号个数 - 右括号个数
        */
        function<void(int, int)> dfs = [&](int idx, int balance) -> void {
            if(path.size() == n){
                string s(n * 2, ')');
                for(int j : path)
                    s[j] = '(';
                ans.push_back(s);
                return;
            }
            // -> git
            for(int close = 0; close <= balance; ++close){//还可以填入close个右括号
                path.push_back(idx + close);//在idx + close位置上填左括号
                //下一个左括号的枚举位置是idx + close + 1
                //空出的close个位置都要填入右括号，且刚刚填入了一个左括号，所以现在左括号和右括号的数量差为balance - close + 1
                dfs(idx + close + 1, balance - close + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};

int main(){
    return 0;
}