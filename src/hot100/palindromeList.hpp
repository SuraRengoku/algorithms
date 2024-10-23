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
    bool isPalindrome(ListNode *head) {
        auto reverseList = [&](ListNode *head) -> ListNode* {
            ListNode *pre = nullptr, *cur = head;
            while(cur) {
                ListNode *nxt = cur -> next;
                cur -> next = pre;
                pre = cur;
                cur = nxt;
            }
            return pre;
        };

        ListNode *thead = new ListNode(head -> val), *cur = head;
        ListNode *tcur = thead;
        while(cur -> next) {
            ListNode *node = new ListNode(cur -> next -> val);
            tcur -> next = node;
            tcur = tcur -> next;
            cur = cur -> next; 
        }

        ListNode *rhead = reverseList(head);
        while(rhead) {
            if(rhead -> val != thead -> val)
                return false;
            rhead = rhead -> next;
            thead = thead -> next;
        }
        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(ListNode *head) {
        auto reverseList = [&](ListNode *head) -> ListNode* {
            ListNode *pre = nullptr, *cur = head;
            while(cur) {
                ListNode *nxt = cur -> next;
                cur -> next = pre;
                pre = cur;
                cur = nxt;
            }
            return pre;
        };

        ListNode *slow = head, *fast = head;
        while(fast != nullptr || fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *rhead = reverseList(slow);
        while(rhead) {
            if(rhead -> val != head -> val)
                return false;
            rhead = rhead -> next;
            head = head -> next;
        }
        return true;
    }   
};