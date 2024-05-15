#include<iostream>
#include<stdexcept>
#include "_vector.hpp"
#include "_queue.hpp"

template<typename T>
struct TreeNode{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x):val(x),left(nullptr),right(nullptr){};
};

template<typename T>
class Tree{
    // private:
        TreeNode<T> *root;

        void deleteTree(TreeNode<T>* node){
            if(node!=nullptr){
                deleteTree(node->left);
                deleteTree(node->right);
                delete node;
            }
        }

    public:
        Tree(T val){
            root=new TreeNode<T>(val);
        }

        ~Tree(){
            deleteTree(root);
        }


        T get() const{
            if(root!=nullptr)
                return root->val;
            else
                throw std::out_of_range("tree is empty");
        }

        _Vector<T> levelOrder(TreeNode<T>* rootNode){
            LinkedListQueue<TreeNode<T> *> queue;
            queue.push(rootNode);
            _Vector<T> vec;
            while(!queue.isEmpty()){
                TreeNode<T> *node=queue.front();
                queue.pop();
                vec.add(node->val);
                if(node->left!=nullptr) queue.push(node->left);
                if(node->right!=nullptr) queue.push(node->right);
            }
            return vec;
        }
};

int main(){
    Tree<int> *RootNode=new Tree(3);
    std::cout<<RootNode;
    // _Vector<int> order=RootNode->levelOrder(RootNode->root);
    return 0;
}