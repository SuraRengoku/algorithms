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

class solution { 
public:
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode *node) -> int {
            if(node == nullptr)
                return 0;
            int lres = dfs(node -> left);
            int rres = dfs(node -> right);
            ans = max(ans, node -> val + lres + rres);
            return max(max(lres, rres) + node -> val, 0);
        };
        dfs(root);
        return ans;
    }

};