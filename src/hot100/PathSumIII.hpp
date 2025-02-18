#include "../leetcodeheader.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> cnt{{0, 1}};
        function<void(TreeNode*, long long)> dfs = [&](TreeNode *node, long long sum) -> void {
            if(node == nullptr)
                return;
            sum += node -> val;
            ans += cnt.contains(sum - targetSum) ? cnt[sum - targetSum] : 0;
            cnt[sum]++;
            dfs(node -> left, sum);
            dfs(node -> right, sum);
            cnt[sum]--;
        };
        dfs(root, 0);
        return ans;
    }
};