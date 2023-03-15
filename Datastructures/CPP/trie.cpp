/*
g++ Trie.cpp -std=c++17;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*>childs;
    bool isWord=false;    
    TrieNode() {}
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto cur=root;
        for(int i=0;i<word.size();i++){
            if (cur->childs.count(word[i])) {
                cur=cur->childs[word[i]];
            } else {
                auto newNode = new TrieNode();
                cur->childs[word[i]]=newNode;
                cur=cur->childs[word[i]];
            }
        }
        cur->isWord=true;
    }
    
    bool search(string word) {
        auto cur=root;
        for(int i=0;i<word.size();i++) {
            if (cur->childs.count(word[i])) {
                cur=cur->childs[word[i]];
            } else {
                return false;
            }
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        auto cur=root;
        for(int i=0;i<prefix.size();i++) {
            if (cur->childs.count(prefix[i])) {
                cur=cur->childs[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};


int main() {


    cout << endl << "-----------------------------" << endl;
    auto trie = new Trie();
    trie->insert("apple");
    cout << "search1 + " << trie->search("apple") << endl;      //  search1 + 1
    cout << "search2 + " << trie->search("app") << endl;        //  search2 + 0
    cout << "startWith + " << trie->startsWith("app") << endl;  //  startWith + 1
    trie->insert("app");
    cout << "search3 + " << trie->search("app") << endl;        //  search3 + 1


    return 0;
}