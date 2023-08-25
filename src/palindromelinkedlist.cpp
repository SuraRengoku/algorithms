#include "singlelinkedlist.hpp"
#include "_stack.hpp"
//判断一个非循环单链表是否是回文链表
//若一个链表除头节点外只有一个节点，则该链表一定是回文链表
//栈方法 空间复杂度O(N/2)
auto palindrome_not1(Node* head)->bool{
    bool flag=true;
    Stack<int> veri;
    //实际上本人实现的四种链表中，头节点都存储了该链表的节点数，因此可以直接获取
    //但为了普适情况，还是遍历获取
    try{
        if(head==nullptr)
            throw std::runtime_error("list does not exist");
    }catch(std::runtime_error err){
        cerr<<err.what()<<"\n";
    }

    Node* pos_node=head->next;
    int nodeNum=0;//链表节点数
    while(pos_node!=nullptr){
        nodeNum++;
        pos_node=pos_node->next;
    }

    bool odd_=nodeNum%2;
    pos_node=head->next;
    for(int i=0;i<nodeNum/2;i++){
        veri.push(pos_node->data);
        pos_node=pos_node->next;
    }
    if(odd_)//奇数节点
        pos_node=pos_node->next;
    while(pos_node!=nullptr){
        if(pos_node->data!=veri.pop_get())
            return !flag;
        pos_node=pos_node->next;
    }
    return flag;
}

//快指针回跑法 空间复杂度O(1)
auto palindrome_not2(Node* head)->bool{
    bool flag=true;
    try{
        if(head==nullptr)
            throw std::runtime_error("list does not exist");
    }catch(std::runtime_error err){
        cerr<<err.what()<<"\n";
    }
    int nodeNum=nodenum(head);
    bool odd_=nodeNum%2;
    Node* slow=head->next;
    Node* fast=head->next->next;

    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(odd_){
        Node* pre=nullptr;
        //if the recurrence stops, the slow pointer should now point to the middle element;
        while(slow!=nullptr){
            Node* nexttemp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=nexttemp;
        }//现在slow指向末尾节点
        Node* backward=pre;
        Node* forward=head->next;
        while(forward!=backward){
            if(forward->data!=backward->data)
                return !flag;
            forward=forward->next;
            backward=backward->next;
        }
        // 还原链表
        Node* _pre=nullptr;
        Node* cur=pre;
        while(cur!=nullptr){
            Node* nexttemp=cur->next;
            cur->next=_pre;
            _pre=cur;
            cur=nexttemp;
        }//此时_pre又是中点
    }else{
        //if the recurrence stops, the slow pointer should now pointer to the first element of the 2th-partition
        Node* pre=nullptr;
        while(slow!=nullptr){
            Node* nexttemp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=nexttemp;
        }//该算法在结束时，pre将指向第一个有效的节点
        Node* backward=pre;
        Node* forward=head->next;
        while(forward->next!=backward){
            if(forward->data!=backward->data)
                return !flag;
            forward=forward->next;
            backward=backward->next;
        }//停止循环时说明只剩最中间位置没有比对
        if(forward->data!=backward->data)
            return !flag;
        Node* _pre=nullptr;
        Node* cur=pre;
        while(cur!=nullptr){
            Node* nexttemp=cur->next;
            cur->next=_pre;
            _pre=cur;
            cur=nexttemp; 
        }
    }   
    return flag;
}

int main(){
    Node* head1=list_init();
    for(int i=0;i<10;i++)
        head1=insert(head1,i,i);
    Node* head2=list_init();
    Node* head3=list_init();
    for(int j=0;j<5;j++){
        head2=insert(head2,j,j);
        head3=insert(head3,j,j);
    }
    for(int k=5;k>=0;k--)
        head2=insert(head2,10-k,k);
    for(int m=4;m>=0;m--)
        head3=insert(head3,10-(m+1),m);
    Node* head4=list_init();
    for(int n=0;n<=10;n++)
        head4=insert(head4,n,n);
    printListpointer(head1);
    // cout<<(palindrome_not1(head1)?"true":"false")<<"\n";
    // cout<<(palindrome_not2(head1)?"true":"false")<<"\n";
    cout<<"复原性验证：";
    printListpointer(head1);
    printListpointer(head2);
    // cout<<(palindrome_not1(head2)?"true":"false")<<"\n";
    cout<<(palindrome_not2(head2)?"true":"false")<<"\n";
    cout<<"复原性验证：";
    printListpointer(head2);
    printListpointer(head3);
    // cout<<(palindrome_not1(head3)?"true":"false")<<"\n";
    cout<<(palindrome_not2(head3)?"true":"false")<<"\n";
    cout<<"复原性验证：";
    printListpointer(head3);
    printListpointer(head4);
    // cout<<(palindrome_not1(head4)?"true":"false")<<"\n";
    cout<<(palindrome_not2(head4)?"true":"false")<<"\n";
    cout<<"复原性验证：";
    printListpointer(head4);
    //对于只有一个或两个节点的链表鲁棒性良好
    // Node* head5=list_init();
    // head5=insert(head5,10,10);
    // head5=insert(head5,10,10);
    // cout<<(palindrome_not1(head5)?"true":"false")<<"\n";
    return 0;
}