#include "../leetcodeheader.h"

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode *removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *left = dummy, *right = dummy;
        while(n) {
            right = right -> next;
            n--;
        }
        while(right -> next != nullptr) {
            right = right -> next;
            left = left -> next;
        }
        left -> next = left -> next -> next;
        return dummy -> next;
    }  
};

class Solution2 {
public:
    int cnt = 0;
    ListNode *removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        head -> next = removeNthFromEnd(head -> next, n);
        cnt++;
        if(cnt == n)
            return head -> next;
        return head;
    }
};