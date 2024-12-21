#include "../leetcodeheader.h"

//✅要求时间复杂度O(nlogn) 空间复杂度o(1)

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
    ListNode *sortList(ListNode *head) {
        vector<ListNode*> tmp;
        ListNode *cur = head;
        while(cur) {
            tmp.push_back(cur);
            cur = cur -> next;
        }
        sort(tmp.begin(), tmp.end(), [](ListNode *a, ListNode *b){
            return a -> val < b -> val;
        });
        for(int i = 0; i < tmp.size() - 1; ++i) 
            tmp[0] -> next = tmp[i + 1];
        tmp[tmp.size() - 1] -> next = nullptr;
        return tmp[0];
    }
};

class Solution2 {
public:
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *tmp = slow -> next;
        slow -> next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);
        ListNode *pre = new ListNode(0);
        ListNode *cur = pre;
        while(left && right) {
            if(left -> val < right -> val) {
                cur -> next = left;
                left = left -> next;
            } else {
                cur -> next = right;
                right = right -> next;
            }
            cur = cur -> next;
        }
        cur -> next = left ? left :right;
        return pre -> next;
    }
};

class Solution3 {
public:
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head -> next == nullptr) // 空表或只有一个节点的无需排序
            return head;
        int lenList = 0; //链表长度
        ListNode *cur = head;
        while(cur) {
            lenList++;
            cur = cur -> next;
        }

        auto mergeTwoLists = [&](ListNode *l1, ListNode *l2) -> ListNode* {
            ListNode *dummy = new ListNode(0);//哨兵节点
            ListNode *cur = dummy;
            while(l1 && l2) {
                if(l1 -> val < l2 -> val) {
                    cur -> next = l1;
                    l1 = l1 -> next;
                } else {
                    cur -> next = l2;
                    l2 = l2 -> next;
                }
                cur = cur -> next;
            }
            cur -> next = l1 ? l1 : l2; //链接剩余节点
            return dummy -> next;
        };//合并有序链表

        ListNode *dummy = new ListNode(-1, head); //外结果哨兵节点
        for(int sublen = 1; sublen < lenList; sublen <<= 1) { //分级
            ListNode *pre = dummy; //内结果哨兵节点
            ListNode *cur = pre -> next; //遍历开始节点
            while(cur) {
                ListNode *head1 = cur; //预合并链表1
                for(int i = 1; i < sublen && cur && cur -> next; ++i)
                    cur = cur -> next;
                ListNode *head2 = cur -> next;//预合并链表2
                cur -> next = nullptr;
                cur = head2;
                for(int i = 1; i < sublen && cur && cur -> next; ++i)
                    cur = cur -> next;
                ListNode *next = nullptr; //剩余链表节点起点
                if(cur){
                    next = cur -> next;
                    cur -> next = nullptr;
                }
                ListNode *mergeres = mergeTwoLists(head1, head2); //合并
                pre -> next = mergeres; //哨兵链接结果
                while(pre -> next)
                    pre = pre -> next; //内结果哨兵移到下次链接点前方
                cur = next;//下次分组节点
            }
        }
        return dummy -> next; 
    }
};