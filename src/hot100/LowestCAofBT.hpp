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
    TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode *lres = LowestCommonAncestor(root -> left, p, q);
        TreeNode *rres = LowestCommonAncestor(root -> right, p, q);
        return lres && rres ? root : (lres ? lres : (rres ? rres : nullptr));
    }
};