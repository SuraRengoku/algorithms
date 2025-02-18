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


class Solution1 {
    TreeNode* dummy = nullptr;
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        flatten(root -> right);
        flatten(root -> left);
        root -> left = nullptr;
        root -> right = dummy;
        dummy = root;
    }
};

class Solution2 {
    TreeNode *dfs(TreeNode *node) {
        if(node == nullptr)
            return node;
        TreeNode *right_tail = dfs(node -> right);
        TreeNode *left_tail = dfs(node -> left);
        if(left_tail) {
            left_tail -> right = node -> right;
            node -> right = node -> left;
            node -> left = nullptr;
        }
        return right_tail ? right_tail : left_tail ? left_tail : node;
    }
public:
    void flatten(TreeNode *root) {
        dfs(root);
    }
};