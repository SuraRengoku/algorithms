#include"generator.cpp"

struct Node{
    public:
        int data;//在头节点中data表示该链表的size
        Node* next;
};

Node* list_init(){
    Node* head=new Node;
    head->data=0;
    head->next=nullptr;
    return head;
}

Node* insert(Node* head, int pos, int data){
    if(head==nullptr)
        pos=0;
    if(pos>head->data||pos<0)
        pos=head->data;
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=nullptr;
    Node* pos_node=head;
    for(int i=0;i<pos;i++)
        pos_node=pos_node->next;
    new_node->next=pos_node->next;
    pos_node->next=new_node;
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
        return -1;//-1表示无效值
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

Node* reverse(Node* head){
    if(head==nullptr)
        return head;
    Node* pre=nullptr;
    Node* cur=head;
    while(cur!=nullptr){
        Node* nexttemp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nexttemp;
    }
    head->next=pre;
    return head;
}
/**
 * @brief make sure that both lists are in order
 * @param head1
 * @param head2
 * @return the head of common list
*/
auto findcommon(Node* head1, Node* head2)->Node*{
    Node* commonhead=list_init();
    int index=0;
    Node* pos_node1=head1->next;
    Node* pos_node2=head2->next;
    while(pos_node1->next!=nullptr&&pos_node2->next!=nullptr){
        if(pos_node1->data<pos_node2->data){
            cout<<"pos_node1.next"<<" ";
            pos_node1=pos_node1->next;
            continue;
        }
        if(pos_node1->data>pos_node2->data){
            pos_node2=pos_node2->next;
            continue;
        }
        if(pos_node1->data==pos_node2->data){
            pos_node1=pos_node1->next;
            pos_node2=pos_node2->next;
            cout<<pos_node1->data<<" ";
            commonhead=insert(commonhead,index++,pos_node1->data);
        }
    }
    return commonhead;
}

int main(){
    Node* head=list_init();
    for(int i=0;i<10;i++)
        head=insert(head,i,i);
    printList(head);
    Node* head1=reverse(head);
    printList(head1);
    Node* head2=list_init();
    for(int j=2;j<15;j++,j++)
        head2=insert(head2,j,j);
    printList(head2);
    // Node* commonhead=findcommon(head,head2);
    // printList(commonhead);
    return 0;
}