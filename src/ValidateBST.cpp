#include<iostream>
#include<utility>
#include<algorithm>

namespace BTS{
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode():val(0),left(nullptr),right(nullptr){}
        TreeNode(int x):val(x),left(nullptr),right(nullptr){}
        TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
    };
};

using BTS::TreeNode;
using std::max,std::min;

class Solution{
    public:
    //前序遍历
    bool isValidBTSf(TreeNode *root, long l, long r){
        if(root==nullptr) return true;
        return root->val<r&&root->val>l&&isValidBTSf(root->left,l,root->val)&&isValidBTSf(root->right,root->val,r);
    }
    //中序遍历
    long pre=LONG_MIN;
    bool isValidBTSm(TreeNode *root){
        if(root==nullptr) return true;
        if(!isValidBTSm(root->left)) return false;
        if(root->val<=pre) return false;
        pre=root->val;
        return isValidBTSm(root->right);
    }
    //后序遍历
    std::pair<long,long> isValidBTSb(TreeNode *root){
        if(root==nullptr) return {LONG_MAX,LONG_MIN};
        auto [l_min,l_max]=isValidBTSb(root->left);
        auto [r_min,r_max]=isValidBTSb(root->right);
        long x=root->val;
        if(x>=r_min||x<=l_max) return {LONG_MIN,LONG_MAX};
        //当出现一个顶点不能满足BTS后，会使{LONG_MIN,LONG_MAX}一直传播到根节点
        //因为没有任何一个节点的val会大于LONG_MAX且小于LONG_MIN
        return {min(l_min,x),max(r_max,x)};
    }
    
    //Search in BTS
    //前序
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr||root->val==val) return root;
        else if(root->val<val) return searchBST(root->right,val); 
        else
            return searchBST(root->left,val);
    }
    //中序
    TreeNode* searchBST(TreeNode* root, int val){
        if(root==nullptr) return nullptr;
        TreeNode *leftn=searchBST(root->left,val);
        if(!leftn){
            if(root->val==val) return root;
            else
                return searchBST(root->right,val);
        }else
            return leftn;    
    }
    //后序
    TreeNode* searchBST(TreeNode* root, int val){
        if(root==nullptr) return nullptr;
        TreeNode *leftn=searchBST(root->left,val);
        TreeNode *rightn=searchBST(root->right,val);
        if(leftn==nullptr&&rightn==nullptr)
            return root->val==val?root:nullptr;
        if(leftn!=nullptr) return leftn;
        else return rightn;
    }
};

int main(){
    return 0;
}