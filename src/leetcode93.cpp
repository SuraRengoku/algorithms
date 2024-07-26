#include "leetcodeheader.h"

class Solution {
    bool isIPAddress(vector<long long> path){
        if(path.size() != 4) return false;
        for(auto p : path){
            if(p < 0 || p > 255)
                return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> path;
        int len = s.size();
        if(len < 4 || len > 12) return {};
        function<void(int, int)> dfs = [&](int cnt, int index) -> void {
            if(index == len || cnt == 4){
                if(index == len && cnt == 4)
                    ans.emplace_back(path[0] + '.' 
                                + path[1] + '.' 
                                + path[2] + '.'
                                + path[3]);
                return;
            }
            for(int i = 1; i <= 3; ++i){
                if(index + i > len) return;
                if(len - index - i > (4 - cnt - 1) * 3) continue;
                if(s[index] == '0' && i != 1) return;
                if(i == 3 && s.substr(index, i) > "255") return; //字符串直接比较是按照顺序上的ascll码来比较的，不同位数的数字字符串比较并不安全
                path.emplace_back(s.substr(index, i));
                dfs(cnt + 1, index + i);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};

int main(){
    Solution solution;
    string testcase = "25525511135";
    vector<string> results = solution.restoreIpAddresses(testcase);
    for(const string& IPaddresss : results)
        cout << IPaddresss << endl;
    return 0;
}