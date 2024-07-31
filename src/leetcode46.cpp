#include "leetcodeheader.h"

using std::remove;
using std::remove_copy_if;
using std::back_inserter;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        vector<int> path(len, 0);
        function<void(int, vector<int>)> dfs = [&](int idx, vector<int> left) -> void {
            if(idx == len){
                ans.emplace_back(path);
                return;
            }
            for(const int& num : left){
                path[idx] = num;
                vector<int> tmp;
                remove_copy_if(left.begin(), left.end(), back_inserter(tmp), [num](int x){ return x == num;});
                //不要直接在left上做文章，除非能精准还原，否则后面的循环都会受到影响
                dfs(idx + 1, tmp);
            }
        };
        dfs(0, nums);
        return ans;
    }
};

int main(){
    vector<int> test1 = {1, 2, 3, 4, 5};
    auto itr = remove(test1.begin(), test1.end(), 2);
    test1.erase(itr, test1.end());
    for(const int& num : test1)
        printf("%d, ", num);
    return 0;
}