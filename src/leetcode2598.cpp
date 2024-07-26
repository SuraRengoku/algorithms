#include "leetcodeheader.h"

class Solution {
public:
    bool result[1001] = {false};
    void cal_result(int n){
        vector<string> subs;
        function<void(int, string, int)> dfs = [&](int index, string num, int i) -> void {
            if(index == num.size()){
                int sum = 0;
                for(const string& sub : subs)
                    sum += stoi(sub);
                if(sum == i)
                    result[i] = true;
                return;
            }
            for(int j = index; j < num.size(); ++j){
                subs.emplace_back(num.substr(index, j - index + 1));
                dfs(j + 1, num, i);
                subs.pop_back();
            }
        };
        for(int i = 1; i <= n; ++i){
            if(i == 91){
                subs.clear();
                string num = std::to_string(i * i);
                dfs(0, num, i);
            }
        }
    }
    int punishmentNumber(int n) {
        int ans = 0;
        this->cal_result(n);
        for(int i = 1; i <= n; ++i)
            printf("result %d: %d\n", i, result[i]);
        return ans;
    }
};

int main(){
    Solution sol;
    int ans = sol.punishmentNumber(91);
    printf("answer: %d", ans);
    return 0;
}