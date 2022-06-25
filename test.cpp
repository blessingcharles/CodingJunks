#include <iostream>
#include <bits/stdc++.h>

using namespace std;


#include<bits/stdc++.h>

struct TrieNode{
    TrieNode* children[26] = {NULL};
    bool isEOF = false ;
};

class Trie{
public :
    TrieNode* root ;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string &str){
        TrieNode* crawler = root ;
        for(char ch : str){
            int val = ch - 'a' ;
            if(crawler->children[val] == NULL){
                crawler->children[val] = new TrieNode();
            }
            crawler = crawler->children[val];
        }
        crawler->isEOF = true ;
    }
    
    bool search(string &str){
        TrieNode* crawler = root ;
        
        for(char ch : str){
            int val = ch - 'a' ;
            if(crawler->children[val] == NULL){
                return false ;
            }
            crawler = crawler->children[val];
        }
        
        return crawler->isEOF ;
    }
};

vector<int> solve(string A, vector<string> &B) {
    
    stringstream ss(A);
    string temp ;
    Trie *tt = new Trie();
    
    while(getline(ss ,temp , '_')){
        tt->insert(temp) ;    
    }
    
    int N = B.size() ;
    vector<pair<int,int>> arr(N) ;
    
    for(int i = 0 ; i < N ; i++){
        stringstream ss(B[i]);
        int count  = 0 ;
        while(getline(ss , temp , '_')){
            if(tt->search(temp)){
                count++ ;
            }
        }
        cout << count << " " << i << endl ;
        arr[i] = {count , i};
    }
    
    sort(arr.begin() , arr.end() , [](pair<int,int>& a , pair<int,int>& b){
        if(a.first == b.first){
            return a.second < b.second ;
        }
        return a.first > b.first ;
    });
    vector<int> ans(N) ;
    for(int i = 0 ; i < N ; i++){
        ans[i] = arr[i].second ;
    }
    return ans ;
}


int main()
{
    string str = "cool_ice_wifi" ;
    vector<string> arr = { "water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
    for(int ele : solve(str , arr)){
        cout << ele << " " ;
    } 
    cout << endl ;

    return 0;
}