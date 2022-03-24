#include <iostream>
#include <bits/stdc++.h>

#define ALPHABETS 26

using namespace std;

class TrieNode
{
public:
    TrieNode *children[ALPHABETS];
    int children_counts[ALPHABETS];
    bool isEndofWord;
    TrieNode()
    {
        for (int i = 0; i < ALPHABETS; i++)
        {
            this->children[i] = NULL;
            this->children_counts[i] = 0;
        }
        this->isEndofWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        this->root = new TrieNode();
    }
    bool search(string &input);
    void insert(string &input);
};

void Trie::insert(string &input)
{
    TrieNode *crawler = this->root;
    for (auto c : input)
    {
        int idx = c - 'a';
        if (crawler->children[idx] == NULL)
        {
            crawler->children[idx] = new TrieNode();
        }
        crawler->children_counts[idx]++;
        crawler = crawler->children[idx];
    }
    crawler->isEndofWord = true;
}

bool Trie::search(string &input)
{
    TrieNode *crawler = this->root;
    int idx;
    for (auto c : input)
    {
        idx = c - 'a';
        if (!crawler->children[idx])
            return false;
        crawler = crawler->children[idx];
    }
    return crawler->isEndofWord;
}

int main()
{
    string inputs[] = {
        "helloworld", "simpu", "pimpu", "cat", "bat", "helmet"};

    Trie *dict = new Trie();
    for (string &s : inputs)
    {
        dict->insert(s);
    }

    string expect[] = {
        "hello", "helloworld", "himpu", "pimp", "pimpup", "helmet"};

    for (string &s : expect)
    {
        cout << s << " --> " << dict->search(s) << endl;
    }

    return 0;
}