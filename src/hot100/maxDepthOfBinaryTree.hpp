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
public:
    int maxDepth(TreeNode *root) {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode *root) {
        int res = 0;
        if(root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            res++;
            for(int i = q.size(); i--;) {
                TreeNode *node = q.front();
                q.pop();
                if(node -> left)    q.push(node -> left);
                if(node -> right)   q.push(node -> right);
            }
        }
        return res;
    }
};