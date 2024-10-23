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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;
        while(cur -> next != nullptr) {
            if(cur -> next -> next == nullptr)
                break;
            ListNode *nnxt = cur -> next -> next;
            cur -> next -> next = nnxt -> next;
            nnxt -> next = cur -> next;
            cur -> next = nnxt; 
            cur = cur -> next -> next;
        }
        return dummy -> next;
    }
};

class Solution2 {
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr || head -> next == nullptr)
            return head;

        ListNode *cur = head;
        ListNode *nxt = cur -> next;
        ListNode *nnxt = nxt -> next;
        
        cur -> next = swapPairs(nnxt);
        nxt -> next = cur;
        return nxt;
    }
};