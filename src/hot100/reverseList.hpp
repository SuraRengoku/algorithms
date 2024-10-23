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
    ListNode *reverseList(ListNode *head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *cur = head, *pre = nullptr;
        while(cur) {
            ListNode *nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

class Solution2 {
public:
    ListNode *reverseList(ListNode *head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *newHead = reverseList(head -> next);//下探到最后一个元素 其作为反转后的链表头
        head -> next -> next = head;
        head -> next = nullptr;
        return newHead;
    }
};