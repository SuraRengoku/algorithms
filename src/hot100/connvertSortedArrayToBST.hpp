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
    TreeNode *sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> biDiv = [&](int left, int right) -> TreeNode* {
            if(left >= right)
                return nullptr;
            int mid = left + (right - left) / 2;
            return new TreeNode(nums[mid], biDiv(left, mid), biDiv(mid + 1, right));
        };
        return biDiv(0, nums.size());
    }
};