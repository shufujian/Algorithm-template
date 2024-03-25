#include<bits/stdc++.h>
using namespace std;

/*
    字典树(前缀数) Trie

    快速检索字符串
*/

class Node {
public:
    Node* children[26]{};
    bool end=false;
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    // 插入字符串到字典树中
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for( char& x : word ){
            int k = x - 'a';
            if( ! node -> children[k] ) node -> children[k] = new Node();
            node = node -> children[k];
        }
        node->end=true;
    }
    
    // 查找字典树中是否存在改字符串
    bool search(string word) {
        Node* node = root;
        int n = word.size();
        int i = 0;
        for( ; i < n ; i++ ) {
            int k = word[i] - 'a';
            if( ! node -> children[k] ) break;
            node = node -> children[k];
        }
        return i==n&&node->end;
    }
    
    // 查找是否存在该前缀
    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.size();
        int i = 0;
        for( ; i < n ; i++ ) {
            int k = prefix[i] - 'a';
            if( ! node -> children[k] ) break;
            node = node -> children[k];
        }
        return i==n;
    }
};
