#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

template<int TRIE_NODE_LEN>
struct TrieNode{
    TrieNode *node[TRIE_NODE_LEN] = {NULL};
};

class Trie{
public:
    TrieNode<26> *root ;
    Trie(){
    }
};

int main(){

    vector<int> a = {3,2,1,5,9,7};
    
    return 0;
}