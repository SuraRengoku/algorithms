#include "singlelinkedlist.hpp"
#include "_stack.hpp"
//判断一个单链表是否是回文链表

//栈方法 空间复杂度O(N/2)
auto palindrome_not1(Node* head)->bool{
    bool flag=true;

    return flag;
}

//快指针回跑法 空间复杂度O(1)
auto palindrome_not2(Node* head)->bool{
    bool flag=true;
    
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
    printList(head1);
    printList(head2);
    printList(head3);
    return 0;
}