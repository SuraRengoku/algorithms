#include "../leetcodeheader.h"

struct Node {
    int key, value;
    std::chrono::steady_clock::time_point expireTime;
    Node *pre, *next;
    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache {
private:
    int capacity;
    int ttl; //过期时间
    Node *dummy;
    unordered_map<int, Node*> key_to_node;

    void remove(Node *x) {
        x -> next -> pre = x -> pre;
        x -> pre -> next = x -> next;
    }

    void push_front(Node *x) {
        x -> next = dummy -> next;
        x -> pre = dummy;
        dummy -> next = x;
        x -> next -> pre = x;
    }

    Node *get_node(int key) {
        auto it = key_to_node.find(key);
        if(it == key_to_node.end())
            return nullptr;
        auto node = it -> second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity, int tTimeline) : capacity(capacity), ttl(tTimeline), dummy(new Node()) {
        dummy -> next = dummy;
        dummy -> pre = dummy;
    }

    int get(int key) {
        auto node = get_node(key);
        if(std::chrono::steady_clock::now() >= node -> expireTime) {
            remove(node);
            delete node;
            return -1;
        }
        return node ? node -> value : -1;
    }

    void put(int key, int value) {
        auto node = get_node(key);
        if(node) {
            node -> value = value;
            node -> expireTime = std::chrono::steady_clock::now() + std::chrono::seconds(ttl);
            return;
        }
        key_to_node[key] = node = new Node(key, value);
        push_front(node);
        if(key_to_node.size() > capacity) {
            auto back_node = dummy -> pre;
            key_to_node.erase(back_node -> key);
            remove(back_node);
            delete back_node;
        }
    }
};