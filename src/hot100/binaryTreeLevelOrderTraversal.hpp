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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> level;
        vector<vector<int>> res;
        vector<int> tmp;
        level.push(root);
        while(!level.empty()) {
            tmp.clear();
            for(int i = level.size(); i--;){
                TreeNode *node = level.front();
                level.pop();
                tmp.push_back(node -> val);
                if(node -> left)    level.push(node -> left);
                if(node -> right)   level.push(node -> right);
            }        
            res.emplace_back(tmp);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> res;
        vector<TreeNode*> cur;
        cur.push_back(root);
        while(!cur.empty()) {
            vector<int> tmp;
            vector<TreeNode*> nxt;
            for(auto& node : cur) {
                tmp.push_back(node -> val);
                if(node -> left)    nxt.push_back(node -> left);
                if(node -> right)   nxt.push_back(node -> right);
            }
            res.emplace_back(tmp);
            cur = nxt;
        }
        return res;
    }
};