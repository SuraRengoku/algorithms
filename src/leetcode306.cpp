#include "leetcodeheader.h"

using std::stoll;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        bool ans = false;
        int len = num.size();
        if(len < 3) return false;
        vector<long double> path;
        function<void(int, int)> dfs = [&](int index, int cnt) -> void {
            if(index == len){
                int nums = path.size();
                if(nums < 3)
                    return;
                for(int j = 2; j < nums; ++j){
                    if(path[j] != path[j - 1] + path[j - 2]) 
                        return;
                }
                ans = true;
                return;
            }
            for(int i = index; i < len; ++i){
                if(num[index] == '0' && i > index){
                    return;
                }else{
                    path.emplace_back(stold(num.substr(index, i - index + 1)));
                    dfs(i + 1, cnt + 1);
                }
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};

int main(){
    Solution solution;
    string digits1 = "101020305080130210";
    string digits2 = "0000";
    cout << solution.isAdditiveNumber(digits2) << endl;
    return 0;
}