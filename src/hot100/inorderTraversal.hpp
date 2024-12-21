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
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if(root == nullptr)
            return {};
        inorderTraversal(root -> left);
        res.push_back(root -> val);
        inorderTraversal(root -> right);
        return res;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root -> left;    
            }
            root = stk.top();
            res.push_back(root -> val);
            stk.pop();
            root = root -> right;
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        
    }
};