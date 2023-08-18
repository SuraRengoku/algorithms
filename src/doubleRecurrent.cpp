#include "generator.cpp"

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* init(){
    Node* head=new Node;
    head->prev=head;
    head->next=head;
    head->data=0;
    return head;
}

Node* insert(Node* head, int pos, int data){
    if(head==nullptr)
        pos=0;
    if(pos>head->data||pos<0)
        pos=head->data;
    // Node* new_node=new Node;
    Node* new_node=nullptr;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=nullptr;
    new_node->prev=nullptr;
    Node* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    new_node->next=pos_node->next;
    if(new_node->next==head)
        new_node->next->prev=new_node;
    new_node->prev=pos_node;       
    pos_node->next=new_node;
    head->data++;
    // free(new_node);
    // delete pos_node;
    return head;
}

Node* remove(Node* head, int pos){
    try{
        if(head==nullptr||pos>=head->data)
            // return head;
            throw runtime_error("list does not exist or no such a position");
        Node* pos_node=head;
        for(int i=0;i<pos;i++)
            pos_node=pos_node->next;
        pos_node->next=pos_node->next->next;
        free(pos_node->next);
        pos_node->next->prev=pos_node;
        head->data--;
        // delete pos_node;
        return head;
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
        return head;
    }
}

Node* modify(Node* head, int pos, int data){
    try{
        if(head==nullptr||pos>=head->data)
            throw runtime_error("list does not exist or no such a position");
        Node* pos_node=head;
        for(int i=0;i<=pos;i++)
            pos_node=pos_node->next;
        pos_node->data=data;
        // delete pos_node;
        return head;
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
        return head;
    }
}

auto get(Node* head, int pos)->int{
    try{
        if(head==nullptr||pos>=head->data)
            throw runtime_error("list does not exist or no such a postion");
        Node* pos_node=head;
        for(int i=0;i<=pos;i++)
            pos_node=pos_node->next;
        return pos_node->data;
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
        return -1;
    } 
}

void printlist(Node* head){
    if(head==nullptr)
        return;
    Node* pos_node=new Node;
    pos_node=head->next;
    for(int i=0;i<head->data;i++){
        cout<<pos_node->data<<" ";
        pos_node=pos_node->next;
    }
    cout<<"recurrent to head, amount of node: "<<pos_node->data;
    cout<<"\n";
    // delete pos_node;
}

void reversePrint(Node* head){
    if(head==nullptr)
        return;
    Node* pos_node=head->prev;
    for(int i=0;i<head->data;i++){
        cout<<pos_node->data<<" ";
        pos_node=pos_node->prev;
    }
    cout<<"recurrent to head, amount of node: "<<pos_node->data;
    cout<<"\n";
    // delete pos_node;
}

Node* reverse(Node* head){
    try{
        if(head==nullptr)
            throw runtime_error("list does not exist");
        Node* prev=head->prev;
        Node* cur=head;
        while(cur->next!=head){
            Node* nexttemp=cur->next;
            cur->next=prev;
            cur->prev=nexttemp;
            prev=cur;
            cur=nexttemp;
            // delete nexttemp;
        }
        cur->next=prev;
        cur->prev=head;
        return head;
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
        return head;
    }
}

int main(){
    Node* head=init();
    for(int i=0;i<10;i++)
        head=insert(head,i,i);
    printlist(head);
    head=remove(head,4);
    // reversePrint(head);
    printlist(head);
    head=reverse(head);
    printlist(head);
    reversePrint(head);
    return 0;
}