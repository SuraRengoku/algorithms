#include "../leetcodeheader.h"

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
    int kthSmallest(TreeNode *root, int k) {
        function<int(TreeNode*)> dfs = [&](TreeNode *node) -> int {
            if(node == nullptr)
                return -1;
            int left_res = dfs(node -> left);
            if(left_res != -1)
                return left_res;
            if(--k == 0)
                return node -> val;
            return dfs(node -> right);
        };
    }
};