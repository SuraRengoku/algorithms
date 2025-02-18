#include "../leetcodeheader.h"

class Trie {
private:
    bool isEnd;
    Trie *next[26];
public:
    Trie() {
        this -> isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie *node = this;
        for(char c : word) {
            if(node -> next[c - 'a'] == nullptr)
                node -> next[c - 'a'] = new Trie();
            node = node -> next[c - 'a'];
        }
        node -> isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        for(char c : word) {
            if(node -> next[c - 'a'] == nullptr)
                return false;
            node = node -> next[c - 'a'];
        }
        return node -> isEnd;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for(char c : prefix) {
            if(node -> next[c - 'a'] == nullptr)
                return false;
            node = node -> next[c - 'a'];
        }
        return true;
    }
};