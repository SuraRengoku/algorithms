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
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        int lenList = lists.size();

        auto mergeTwoLists = [&](ListNode *a, ListNode *b) {
            ListNode *dummy = new ListNode(-1);
            ListNode *cur = dummy;
            while(a && b) {
                if(a -> val < b -> val) {
                    cur -> next = a;
                    a = a -> next;
                } else {
                    cur -> next = b;
                    b = b -> next;
                }
                cur = cur -> next;
            }
            cur -> next = a ? a : b;
            return dummy -> next;
        };

        vector<ListNode*> await = lists;
        vector<ListNode*> addressed;
        for(int level = 1; level < lenList; level <<= 2) {
            addressed.clear();
            for(int i = 0; i < await.size(); i += 2) {
                ListNode *head1 = await[i];
                ListNode *head2 = i + 1 < await.size() ? await[i + 1] : nullptr;
                ListNode *merged = mergeTwoLists(head1, head2);
                addressed.push_back(merged);
            }
            await = addressed;
        }
        return addressed.empty() ? await[0] : addressed[0];
    }
};

class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) { //分治
        auto mergeTwoLists = [&](ListNode *a, ListNode *b) -> ListNode* {
            ListNode *dummy = new ListNode(-1);
            ListNode *cur = dummy;
            while(a && b) {
                if(a -> val < b -> val) {
                    cur -> next = a;
                    a = a -> next;
                } else {
                    cur -> next = b;
                    b = b -> next;
                }
                cur = cur -> next;
            }
            cur -> next = a ? a : b;
            return dummy -> next;
        };

        function<ListNode*(vector<ListNode*>&, int, int)> mergeLists = [&](vector<ListNode*>& ls, int i, int j) -> ListNode* {
            int m = j - i;
            if(m == 0)
                return nullptr;
            if(m == 1)
                return ls[i];
            ListNode *left = mergeLists(ls, i, i + m / 2);
            ListNode *right = mergeLists(ls, i + m / 2, j);
            return mergeTwoLists(left, right);
        };

        return mergeLists(lists, 0, lists.size());
    }
};

class Solution3 {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](ListNode *a, ListNode *b) -> bool {
            return a -> val > b -> val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for(auto head : lists) {
            if(head)
                pq.push(head);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            if(node -> next)
                pq.push(node -> next);
            cur -> next = node;
            cur = cur -> next;
        }
        return dummy -> next;
    }
};