#include "generator.hpp"
#include <unordered_map>

/**
 * rand指针是单链表节点结构中新增的指针，rand可能指向链表中的任意一个节点，也可能指向nullptr。
 * 给定一个由Node节点类型组成的无环单链表的头节点head,实现一个函数完成这个链表的复制，并返回复制的新链表的头节点
*/
namespace RLLR{
    template<typename T>
    class Node{
        public:
            T value;
            Node* next;
            Node* rand;
            Node(T value){
                this->value=value;
            }
            Node* list_init();
            Node* insert(Node* head, int pos, T val);
    };
}
typedef RLLR::Node<int> NodeInt;

template<typename T>
auto RLLR::Node<T>::list_init()->RLLR::Node<T>*{
    RLLR::Node<T>* head=new RLLR::Node<T>(0);
    head->next=nullptr;
    head->rand=nullptr;
    return head;
}
template<typename T>
auto RLLR::Node<T>::insert(RLLR::Node<T>* head, int pos, T val)->RLLR::Node<T>*{
    Exist<T>(head);
    if(pos>head->value||pos<0)
        pos=head->data;
    RLLR::Node<T>* new_node=new RLLR::Node<T>(val);
    new_node->next=nullptr;
    RLLR::Node<T>* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    new_node->next=pos_node->next;
    pos_node->next=new_node;
    head->value++;
    srand(static_cast<unsigned>(time(nullptr)));
    int randpos=(int)rand()%((head->value)+1);
    if(randpos<head->value&&randpos>=0){
        pos_node=head;
        for(int j=0;j<=randpos;j++)
            pos_node=pos_node->next;
        new_node->rand=pos_node;
    }else
        new_node->rand=nullptr;
    return head;
}

//该方法需要哈希表占用额外空间
auto reproduction1(NodeInt* head)->NodeInt*{
    Exist<NodeInt*>(head);
    unordered_map<NodeInt*,NodeInt*> map;
    NodeInt* pos_node=head->next;
    int elements=0;
    while(pos_node!=nullptr){
        elements++;
        map.insert(pos_node,new NodeInt(pos_node->value));
        pos_node=pos_node->next;
    }
    pos_node=head->next;
    while(pos_node!=nullptr){
        map.at(pos_node)->next=map.at(pos_node->next);
        map.at(pos_node)->rand=map.at(pos_node->rand);
        pos_node=pos_node->next;
    }
    NodeInt *headprime=new NodeInt(elements);
    headprime->next=map.at(head->next);
    return headprime;
}
//空间复杂度O(1)
auto reproduction2(NodeInt* head)->NodeInt*{
    Exist<NodeInt*>(head);
    NodeInt* pos_node=head->next;
    int elements=0;
    //复制节点,紧随原始节点后
    while(pos_node!=nullptr){
        elements++;
        NodeInt *pos_node_prime=new NodeInt(pos_node->value);
        pos_node_prime->next=pos_node->next;
        pos_node->next=pos_node_prime;
        pos_node=pos_node->next->next;//跳两步
    }
    pos_node=head->next;
    while(pos_node!=nullptr){
        pos_node->next->rand=pos_node->rand!=nullptr?pos_node->rand->next:nullptr;
        pos_node=pos_node->next->next;
    }
    pos_node=head->next;
    NodeInt* pos_node_prime=pos_node->next;
    NodeInt* headprime=new NodeInt(elements);
    headprime->next=pos_node_prime;
    while(pos_node!=nullptr){
        pos_node->next=pos_node->next->next;
        pos_node_prime->next=pos_node_prime->next==nullptr?pos_node_prime->next->next:nullptr;
        pos_node=pos_node->next;
        pos_node_prime=pos_node_prime->next;
    }
    return headprime;
}

int main(){
    //未验证
    return 0;
}