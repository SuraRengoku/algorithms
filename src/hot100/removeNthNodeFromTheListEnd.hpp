#include "../leetcodeheader.h"

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class removeNthNodeFromTheListEnd {
public:
    ListNode *removeNthFromEnd1(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *left = dummy, *right = dummy;
        for(int i = 0; i < n; ++i, right = right -> next);
        while(right -> next != nullptr) {
            right = right -> next;
            left = left -> next;
        }
        left -> next = left -> next -> next;
        return dummy -> next;
    }  
        
    // alternative solution
    int cnt = 0;
    ListNode *removeNthFromEnd2(ListNode* head, int n) {
        if(!head)
            return nullptr;
        // 递
        head -> next = removeNthFromEnd2(head -> next, n);
        // 归
        cnt++;
        if(cnt == n)
            return head -> next;
        return head;
    }
};