#include "../leetcodeheader.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
    long long pre = LLONG_MIN;
public:
    bool isValidBST(TreeNode *root) {
        if(root == nullptr)
            return true;
        if(!isValidBST(root -> left))
            return false;
        if(pre >= root -> val)
            return false;
        pre = root -> val;
        return isValidBST(root -> right);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode *root, long long l = LLONG_MIN, long long r = LLONG_MAX) {
        if(root == nullptr)
            return true;
        return l < root -> val && r > root -> val && isValidBST(root -> left, l, root -> val) && isValidBST(root -> right, root -> val, r);
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode *root) {
        function<pair<long, long>(TreeNode*)> backt = [&](TreeNode *root) -> pair<long, long> {
            if(root == nullptr)
                return make_pair(LONG_MAX, LONG_MIN);
            auto [lmin, lmax] = backt(root -> left);
            auto [rmin, rmax] = backt(root -> right);
            long x = root -> val;
            if(x >= rmin || x <= lmax)
                return make_pair(LONG_MIN, LONG_MAX);
            return make_pair(min(lmin, x), max(rmax, x));
        };
        return backt(root).first != LONG_MIN;
    }
};