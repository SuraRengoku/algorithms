// #include<iostream>
// #include<stdexcept>
// #include "_vector.hpp"
// #include "_queue.hpp"
// #include<typeinfo>

// template<typename T>
// struct TreeNode{
//     T val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(T x):val(x),left(nullptr),right(nullptr){};
// };


// template<typename T>
// class Tree{
//     // private:
//     public:
//         TreeNode<T> *root;

//         void deleteTree(TreeNode<T>* node){
//             if(node!=nullptr){
//                 deleteTree(node->left);
//                 deleteTree(node->right);
//                 delete node;
//             }
//         }

//     public:
//         Tree(T val){
//             root=new TreeNode<T>(val);
//         }

//         ~Tree(){
//             deleteTree(root);
//         }


//         T get() const{
//             if(root!=nullptr)
//                 return root->val;
//             else
//                 throw std::out_of_range("tree is empty");
//         }

//         _Vector<T> levelOrder(TreeNode<T>* rootNode){
//             LinkedListQueue<TreeNode<T> *> queue;
//             queue.push(rootNode);
//             _Vector<T> vec;
//             while(!queue.isEmpty()){
//                 TreeNode<T> *node=queue.first();
//                 queue.pop();
//                 vec.add(node->val);
//                 if(node->left!=nullptr) queue.push(node->left);
//                 if(node->right!=nullptr) queue.push(node->right);
//             }
//             return vec;
//         }
// };

// int main(){
//     Tree<int> *RootNode=new Tree(3);
//     std::cout<<RootNode;
//     _Vector<int> order=RootNode->levelOrder(RootNode->root);
//     return 0;
// }

#ifndef _tree_hpp
#define _tree_hpp

#include<iostream>
#include<vector>
#include<queue>
#include<type_traits>

using std::vector;

template<typename T>
concept IsNumber = std::is_arithmetic<T>::value;

template<IsNumber T>
struct TreeNode{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x): val(x), left(nullptr), right(nullptr){}
};

//binary_tree_bfs 广度优先
template<IsNumber T>
vector<T> levelOrder(TreeNode<T> *root){
    queue<TreeNode<T> *> queue;
    queue.push(root);
    vector<T> vec;
    while(!queue.empty()){
        TreeNode<T> *node=queue.front();
        queue.pop();
        vec.push_back(node->val);
        if(node->left!=nullptr) queue.push(node->left);
        if(node->right!=nullptr) queue.push(node->right);
    }
}

//binary_tree_dfs 深度优先
//前序遍历
template<IsNumber T> 
vector<T> preOrder(TreeNode<T> *root){
    if(root==nullptr) return;
    vector<T> vec;
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}
//中序遍历
template<IsNumber T> 
vector<T> preOrder(TreeNode<T> *root){
    if(root==nullptr) return;
    vector<T> vec;
    preOrder(root->left);
    vec.push_back(root->val);
    preOrder(root->right);
}
//后序遍历
template<IsNumber T> 
vector<T> preOrder(TreeNode<T> *root){
    if(root==nullptr) return;
    vector<T> vec;
    preOrder(root->left);
    preOrder(root->right);
    vec.push_back(root->val);
}

//数组表示的tree
template<typename T> requires std::is_arithmetic_v<T> //std::is_arithmetic_v直接作为一个变量使用
class ArrayBinaryTree{
    private:
        vector<T> tree;

        /**
         * @param i index
         * 
        */
        void dfs(int i, string order, vector<T> &res){
            if(val(i)==INT_MAX) return;
            if(order=="pre") res.push_back(val(i));
            dfs(left(i),order,res);
            if(order=="in") res.push_back(val(i));
            dfs(right(i),order,res);
            if(order=="post") res.push_back(val(i));
        }

    public:
        ArrayBinaryTree(vector<T> arr){
            tree=arr;
        }

        int size(){
            return tree.size();
        }

        /**
         * @param i index
        */
        auto val(int i)->T{
            if(i<0||i>=size())  return INT_MAX;
            return tree[i];
        }

        int left(int i){
            return 2i+1;
        }
        int right(int i){
            return 2i+2;
        }

        int parent(int i){
            return (i-1)/2;
        }

        vector<T> preOrder(){
            vector<T> res;
            dfs(0,"pre",res);
            return res;
        }

        vector<T> inOrder(){
            vector<T> res;
            dfs(0,"in",res);
            return res;
        }

        vector<T> postOrder(){
            vector<T> res;
            dfs(0,"post",res);
            return res;
        }
};

#endif