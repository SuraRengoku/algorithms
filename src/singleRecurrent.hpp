#ifndef singleRecurrent_hpp
#define singleRecurrent_hpp
#include "generator.hpp"
//有头节点的单循环链表
struct Node{
    int data;
    Node* next;
};

Node* init(){
    Node* head=new Node;
    head->data=0;
    head->next=head;
    return head;
}

Node* insert(Node* head, int pos, int data){
    if(head==nullptr)
        pos=0;
    if(pos>head->data||pos<0)
        pos=head->data;
    Node* newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
    Node* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    newnode->next=pos_node->next;
    pos_node->next=newnode;
    head->data++;
    return head;
}

Node* remove(Node* head, int pos){
    if(head==nullptr||pos>=head->data)
        return head;
    Node* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    pos_node->next=pos_node->next->next;
    head->data--;
    return head;
}

Node* modify(Node* head, int pos, int data){
    if(head==nullptr||pos>=head->data)
        return head;
    Node* pos_node=head;
    for(int i=0;i<=pos;i++)
        pos_node=pos_node->next;
    pos_node->data=data;
    return head;
}

int get(Node* head, int pos){
    if(head==nullptr||pos>=head->data)
        return -1;
    Node* pos_node=head;
    for(int i=0;i<=pos;i++)
        pos_node=pos_node->next;
    return pos_node->data;
}

Node* reverse(Node* head){
    if(head==nullptr||head->next==head)
        return head;
    Node* prev=nullptr;
    Node* cur=head;
    while(cur->next!=head){
        Node* nexttemp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nexttemp;
    }
    cur->next=prev;
    head->next=cur;
    return head;
}

void printlist(Node* head){
    if(head==nullptr)
        return;
    Node* pos_node=head->next;//跳过头节点从第一个节点开始遍历
    for(int i=0;i<head->data;i++){
        cout<<pos_node->data<<" ";
        pos_node=pos_node->next;
    }
    cout<<"recurrent to head, amount of data: "<<pos_node->data;
    cout<<'\n';
}

// int main(){
//     Node* head=init();
//     for(int i=0;i<10;i++)
//         head=insert(head,i,i);
//     printlist(head);
//     head=modify(head,6,8);
//     head=remove(head,4);
//     printlist(head);
//     head=reverse(head);
//     printlist(head);
//     return 0;
// }
#endif
