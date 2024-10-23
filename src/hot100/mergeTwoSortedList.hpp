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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        ListNode *head = new ListNode();
        ListNode *cur = head;
        while(cur1 || cur2) {
            if(cur1 == nullptr){
                cur -> next = cur2;
                break;
            } else if(cur2 == nullptr) {
                cur -> next = cur1;
                break;
            } else if(cur1 -> val >= cur2 -> val) {
                ListNode *node = new ListNode(cur2 -> val);
                cur -> next = node;
                cur = cur -> next;
                cur2 = cur2 -> next;
            } else {
                ListNode *node = new ListNode(cur1 -> val);
                cur -> next = node;
                cur = cur -> next;
                cur1 = cur1 -> next;
            }
        }
        return head -> next;
    }
};

class Solution2 {
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        else if(list1 -> val >= list2 -> val) {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
        else {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
    }
};