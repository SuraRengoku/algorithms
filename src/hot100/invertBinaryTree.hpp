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

class Solution {
public:
    // TreeNode *invertTree(TreeNode *root) {
    //     function<void(TreeNode*)> invert = [&](TreeNode *root) mutable -> void {
    //         if(root == nullptr)
    //             return;
    //         TreeNode *rtmp = move(root -> right);
    //         root -> right = move(root -> left);
    //         root -> left = move(rtmp);
    //         invert(root -> right);
    //         invert(root -> left);
    //     };
    //     invert(root);
    //     return root;
    // }
    TreeNode *invertTree(TreeNode *root) {
        if(root == nullptr)
            return root;
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};