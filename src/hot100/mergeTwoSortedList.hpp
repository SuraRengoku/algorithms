#include "../leetcodeheader.h"

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class mergeTwoSortedLists {
public:
    ListNode *mergeTwoLists1(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while(list1 && list2) {
            if(list1 -> val <= list2 -> val) {
                cur -> next = list1;
                list1 = list1 -> next;
            }else {
                cur -> next = list2;
                list2 = list2 -> next;
            }
            cur = cur -> next;
        }
        if(list1) 
            cur -> next = list1;
        else
            cur -> next = list2;

        return dummy.next;
    }
        
    ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2) {
        if(list1 == nullptr)    return list2;
        if(list2 == nullptr)   return list1;
        if(list1 -> val <= list2 -> val) {
            list1 -> next = mergeTwoLists2(list1 -> next, list2);
            return list1;
        }
        list2 -> next = mergeTwoLists2(list1, list2 -> next);
            return list2;
    }
};
