#include "../leetcodeheader.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp = headA;
        while(tmp -> next != nullptr)
            tmp = tmp -> next;
        tmp -> next = headB;

        ListNode *slow = headA, *fast = headA;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                slow = headA;
                while(slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                tmp -> next = nullptr;
                return slow;
            }
        }
        tmp -> next = nullptr;
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pA = headA, *pB = headB;
        while(pA != pB) {
            pA = pA ? pA -> next : headB;
            pB = pB ? pB -> next : headA;
        }
        return pA;
    }
};