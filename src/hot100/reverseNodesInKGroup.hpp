#include "../leetcodeheader.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == nullptr)
            return head;
        int cnt = k - 1;
        ListNode *cur = head;
        while(cnt) {
            cur = cur -> next;
            cnt--;
            if(cur == nullptr && cnt >= 0)
                return head;
        }
        ListNode *pre = reverseKGroup(cur -> next, k);
        cur = head;
        cnt = k;
        while(cnt) {
            ListNode *nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
            cnt--;
        }
        return pre;
    }
};