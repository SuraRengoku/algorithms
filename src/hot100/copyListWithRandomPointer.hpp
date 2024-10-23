#include "../leetcodeheader.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution1 {
public:
    Node *copyRandomList(Node *head) {
        if(head == nullptr)
            return head;
        Node *cur = head;
        unordered_map<Node*, Node*> map;
        while(cur) {
            map[cur] = new Node(cur -> val);
            cur = cur -> next;
        }
        cur = head;
        while(cur) {
            map[cur] -> next = map[cur -> next];
            map[cur] -> random = map[cur -> random];
            cur = cur -> next;
        }
        return map[head];
    }
};

class Solution1 {
public:
    Node *copyRandomList(Node *head) {
        if(head == nullptr)
            return head;
        Node *cur = head;
        while(cur) {
            Node *curn = new Node(cur -> val);
            curn -> next = cur -> next;
            cur -> next = curn;
            cur = curn -> next;
        }
        cur = head;
        while(cur) {
            if(cur -> random != nullptr)
                cur -> next -> random = cur -> random -> next;
            cur = cur -> next -> next;
        }
        cur = head -> next;
        Node *pre = head, *res = head -> next;
        while(cur -> next) {
            pre -> next = pre -> next -> next;
            cur -> next = cur -> next -> next;
            pre = pre -> next;
            cur = cur -> next;
        }
        pre -> next = nullptr;
        return res;
    }
};