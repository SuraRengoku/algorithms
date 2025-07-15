#include "../leetcodeheader.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class addTwoNumbers {
public:
    ListNode* add1(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        int rest = 0;
        while(l1 && l2) {
            ListNode* nxt = new ListNode((l1 -> val + l2 -> val + rest) % 10);
            rest = (l1 -> val + l2 -> val + rest) / 10;
            cur -> next = nxt;
            cur = cur -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1) {
            ListNode* nxt = new ListNode((l1 -> val + rest) % 10);
            rest = (l1 -> val + rest) / 10;
            cur -> next = nxt;
            cur = cur -> next;
            l1 = l1 -> next;
        }
        while(l2) {
            ListNode* nxt = new ListNode((l2 -> val + rest) % 10);
            rest = (l2 -> val + rest) / 10;
            cur -> next = nxt;
            cur = cur -> next;
            l2 = l2 -> next;
        }
        if(rest) {
            ListNode* nxt = new ListNode(rest);
            cur -> next = nxt;
        }
        return dummy.next;
    }

    ListNode* add2(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int rest = 0, sum = 0;
        while(l1 || l2 || rest) {
            if(l1) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            cur -> next = new ListNode((sum + rest) % 10);
            rest = (sum + rest) / 10;
            sum = 0;
            cur = cur -> next;
        }
        return dummy -> next;
    }
};