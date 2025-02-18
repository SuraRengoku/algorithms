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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0) 
            return nullptr;
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        vector<int> inl(inorder.begin(), it);
        vector<int> inr(it + 1, inorder.end());
        vector<int> prel(preorder.begin() + 1, preorder.begin() + inl.size() + 1);
        vector<int> prer(preorder.begin() + inl.size() + 1, preorder.end());
        TreeNode *node = new TreeNode(*it);
        node -> left = buildTree(prel, inl);
        node -> right = buildTree(prer, inr);
        return node;
    }
};

class Solution2 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int len = inorder.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < len; ++i) 
            hash[inorder[i]] = i;
        
        function<TreeNode *(int, int, int, int)> dfs = [&](int prel, int prer, int inl, int inr) -> TreeNode *{
            if(prel == prer)
                return nullptr;
            int sizeIn = hash[preorder[prel]] - inl;
            TreeNode *left = dfs(prel + 1, prel + 1 + sizeIn, inl, inl + sizeIn);
            TreeNode *right = dfs(prel + 1+ sizeIn, prer, inl + sizeIn + 1, inr);
            return new TreeNode(preorder[prel], left, right);
        };
        return dfs(0, len, 0, len);
    }
};