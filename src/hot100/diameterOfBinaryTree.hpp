#include "../leetcodeheader.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
    int ans;
    int depth(TreeNode *root) {
        if(root == nullptr)
            return 0;
        int lv = depth(root -> left); //左边穿过的节点数
        int rv = depth(root -> right); //右边穿过的节点数
        ans = max(ans, lv + rv + 1); //本节点作为线上节点时所穿过的节点数
        return max(lv, rv) + 1; //左右两边一条线上穿过最多的节点数 + 本节点
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        ans = 0;
        depth(root);
        return ans - 1; //最长直径等于最长节点数 - 1
    }
};

class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int ans = 0;
        auto dfs = [&](auto &&dfs, TreeNode *root) -> int {
            if(root = nullptr)
                return -1;
            int lv = dfs(dfs, root -> left) + 1;
            int rv = dfs(dfs, root -> right) + 1;
            ans = max(ans, lv + rv);
            return max(lv, rv);
        };
        dfs(dfs, root);
        return ans;
    }
};