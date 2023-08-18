#include "generator.cpp"

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* init_list(){
    Node* head=new Node;
    head->data=0;
    head->prev=nullptr;
    head->next=nullptr;
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
    newnode->prev=nullptr;
    Node* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    newnode->next=pos_node->next;
    pos_node->next=newnode;
    newnode->prev=pos_node;
    if(newnode->next!=nullptr)
        newnode->next->prev=newnode;
    head->data++;
    return head;
}

Node* remove(Node* head, int pos){
    if(head==nullptr||pos>head->data-1)
        return head;
    Node* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    pos_node->next=pos_node->next->next;
    pos_node->next->prev=pos_node;
    head->data--;
    return head;
}

Node* modify(Node* head, int pos, int data){
    if(head==nullptr||pos>head->data-1)
        return head;
    Node* pos_node=head;
    for(int i=0;i<=pos;i++)
        pos_node=pos_node->next;
    pos_node->data=data;
    return head;
}

int get(Node* head, int pos){
    if(head==nullptr||pos>head->data-1)
        return -1;
    Node* pos_node=head;
    for(int i=0;i<=pos;i++)
        pos_node=pos_node->next;
    return pos_node->data;
}

void printList(Node* head){
    if(head==nullptr)
        return;
    Node* pos_node=head->next;
    for(int i=0;i<head->data;i++){
        cout<<pos_node->data<<" ";
        pos_node=pos_node->next;
    }
    cout<<"\n";
}

void printListpoint(Node* head){
    try{
        if(head==nullptr)
            throw runtime_error("list does not exist");
        Node* pos_node=head->next;
        while(pos_node!=nullptr){
            cout<<pos_node->data<<" ";
            pos_node=pos_node->next;
        }
        cout<<"\n";
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
    }
}

Node* reverse(Node* head){
    if(head==nullptr)
        return head;
    Node* prev=nullptr;
    Node* cur=head->next;
    while(cur!=nullptr){
        Node* nexttemp=cur->next;
        cur->next=prev;
        cur->prev=nexttemp;
        prev=cur;
        cur=nexttemp;
    }
    head->next=prev;
    prev->prev=head;
    return head;
}

int main(){
    Node* head=init_list();
    for(int i=0;i<10;i++)
        head=insert(head,i,i);
    head=insert(head,9,11);
    head=insert(head,6,12);
    head=remove(head,4);
    printListpoint(head);
    // printList(head);
    // cout<<head->next->next->next->next->next->next->next->prev->data;
    head=reverse(head);
    printListpoint(head);
    // printList(head);
    return 0;
}