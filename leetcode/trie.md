1. [max xor of two elements in array]()
```cpp
#include<bits/stdc++.h>

class Node{
public:
    Node* children[2] ;
    Node(){
        memset(children , NULL , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(int num){
        Node* crawler = root ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            if(crawler->children[isSet] == NULL){
                crawler->children[isSet] = new Node() ;
            }
            crawler = crawler->children[isSet] ;
        }
    }
    int search(int num){
        Node* crawler = root ;
        int maxval = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            bool need = not isSet ;
            if(crawler->children[need] != NULL){
                maxval = maxval | (1 << i) ;
                crawler = crawler->children[need] ;
            }
            else{
                crawler = crawler->children[isSet] ;
            }
        }
        return maxval ;
    }
};
int maximumXor(vector<int> A)
{
    Trie* t = new Trie();
    for(int ele : A){
        t->insert(ele) ;
    }
    int maxval = 0 ;
    for(int ele : A){
        maxval = max(maxval , t->search(ele));
    }
    return maxval ; 
}
```

2. [Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/)
```cpp
class Node{
public:
    Node* children[26] ;
    bool isterminal ;
    Node(){
        isterminal = false ;
        memset(children , 0 , sizeof(children));
    }
};
class Trie {
public:
    Node* root ;
    Trie() {
        root = new Node() ;
    }
    void insert(string word) {
        Node* crawler = root ;
        
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch - 'a'] = new Node() ;
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->isterminal = true ;
    }
    bool search(string word) {
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch - 'a'] == NULL)
                return false ;
            crawler = crawler->children[ch - 'a'];
        }
        return crawler->isterminal ;
    }
    
    bool startsWith(string prefix) {
        Node* crawler = root ;
        for(char ch : prefix){
            if(crawler->children[ch - 'a'] == NULL)
                return false ;
            crawler = crawler->children[ch - 'a'];
        }
        return true ;
    }
};
```

3. [maximum genetic query difference](https://leetcode.com/problems/maximum-genetic-difference-query/)
```cpp
// O (32* (N+M))

class Node{
public:
    Node* children[2] ;
    int count ;
    Node(){
        count = 0 ;
        memset(children , NULL , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(int num , int op){
        Node* crawler = root ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            if(crawler->children[isSet] == NULL){
                crawler->children[isSet] = new Node() ;
            }
            crawler = crawler->children[isSet] ;
            crawler->count += op ;
        }
    }
    int search(int num){
        Node* crawler = root ;
        int maxval = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            bool need = not isSet ;
            if(crawler->children[need] != NULL and crawler->children[need]->count > 0){
                maxval = maxval | (1 << i) ;
                crawler = crawler->children[need] ;
            }
            else{
                crawler = crawler->children[isSet] ;
            }
        }
        return maxval ;
    }
};

class Solution {
public:
    Trie *t ;
    void dfs(int node , vector<vector<pair<int,int>>> &queries 
                , vector<vector<int>> &graph , vector<int> &ans){
        // insert this node into the trie with addition operation
        t->insert(node , 1) ;
        // find any queries are present in this
        for(pair<int,int> &q : queries[node]){
            int val = q.first ;
            int idx = q.second ;
            
            int maxval = t->search(val) ;
            ans[idx] = maxval ;
        }
        
        // find its childrens queries
        for(int neigh : graph[node]){
            dfs(neigh , queries , graph , ans);
        }
        t->insert(node , -1) ;
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& qs ) {
        t = new Trie() ;
        
        int N = parents.size() ;
        vector<vector<pair<int,int>>> queries(N);
        
        for(int i = 0 ; i < qs.size() ; i++){
            int node = qs[i][0] ;
            int val = qs[i][1] ;
            queries[node].push_back({val , i}) ;
        }
        int root = 0 ;
        vector<vector<int>> graph(N) ;
        for(int i = 0 ; i < N ; i++){
            if(parents[i] == -1){
                root = i ;
                continue ;
            }
            graph[parents[i]].push_back(i) ;
        }
        vector<int> ans(qs.size()) ;
        dfs(root , queries , graph , ans);
        return ans ;
    }
};
```

4. [Word Search 2](https://leetcode.com/problems/word-search-ii/)
```cpp
class Node{
public:
    Node* children[26] ;
    string *endWord ;
    Node(){
        endWord = NULL ;
        memset(children , 0 , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch - 'a'] = new Node() ;
            }
            crawler = crawler->children[ch-'a'] ;
        }
        crawler->endWord = &word ;
    }
};
class Solution {
    int M , N ;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
    
public:
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= M or col >= N ;
    }
    void helper(int row , int col , vector<vector<char>> &board , Node* root , vector<string> &ans){
        if(board[row][col] == '#')
            return ;
        char curChar = board[row][col] ;

        Node* nxt = root->children[curChar - 'a'] ;
        if(not nxt) return ;
        if(nxt->endWord != NULL){
            ans.push_back(*nxt->endWord);
            nxt->endWord = NULL ;
        }
        
        board[row][col] = '#' ;
        
        for(int i = 0 ; i < 4 ; i++){
            int neigh_r = row + dx[i] ;
            int neigh_c = col + dy[i] ;
            
            if(isInvalid(neigh_r , neigh_c)) continue ;
            helper(neigh_r , neigh_c , board , nxt , ans);
        }
        
        board[row][col] = curChar ;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        Trie *root = new Trie() ;
        for(string &w : words){
            root->insert(w);
        }
        M = board.size() ; N = board[0].size() ;
        vector<string> ans ;
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                helper(i , j , board , root->root , ans);
                if(ans.size() == words.size())
                    return ans ;
            }
        }
        return ans ;
    }
};
```

5. [Implement Magic dictionary](https://leetcode.com/problems/implement-magic-dictionary/)
```cpp
class Node{
public:
    Node* children[26] ;
    bool isTerminal ;
    Node(){
        isTerminal = false ;
        memset(children , 0 , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(string &word){
        Node* crawler = root ;
        
        for(char ch :word){
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch - 'a'] = new Node() ;
            }
            crawler = crawler->children[ch - 'a'] ;
        }
        crawler->isTerminal = true ;
    }
    
    bool exactlyOnce(int pos , string &word , Node* crawler , bool isused){
        if(not crawler)
            return false ;
        if(pos == word.size()){
            return crawler->isTerminal and isused ;
        }
        char ch = word[pos] ;        
        
        // if already used no way u need to match now
        if(isused){
            return exactlyOnce(pos+1 , word , crawler->children[word[pos] - 'a'] , true);
        }
        // use this chance to explore what are the other possibilites
        for(int i = 0 ; i < 26 ; i++){
            if(crawler->children[i]){
                if(i == ch-'a'){
                    if(exactlyOnce(pos+1 , word , crawler->children[i] , false)){
                        return true ;
                    }
                }
                else{
                    if(exactlyOnce(pos+1 , word , crawler->children[i] , true)){
                        return true ;
                    }
                }
            }
        }
        return false ;
    }
    
};
class MagicDictionary {
public:
    Trie *t ;
    MagicDictionary() {
        t = new Trie() ;
    }
    void buildDict(vector<string> dictionary) {
        for(string &w : dictionary){
            t->insert(w) ;
        }        
    }
    bool search(string searchWord) {
        return t->exactlyOnce(0 , searchWord , t->root , false)   ;
    }
};
```

6. [Map Sum pairs](https://leetcode.com/problems/map-sum-pairs/)
```cpp
class Node{
public:
    Node* children[26] ;
    int val ; 
    bool isTerminal ;
    Node(){
        isTerminal = false ;
        val = 0 ;
        memset(children , 0 , sizeof(children)) ;
    }
};
class Trie{
public:
    Node* root ;
    unordered_map<string , int> memo ;
    Trie(){
        root = new Node() ;
    }
    void insert(string &word , int val){
        
        if(memo.find(word) != memo.end()){
            int prev = memo[word] ;
            memo[word] = val ;
            val = val - prev ;
        }
        else{
            memo[word] = val        ;
        }
        // add these values all to the childrens
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch - 'a'] = new Node() ;
            }
            crawler = crawler->children[ch-'a'] ;
            crawler->val += val ;
        }
        crawler->isTerminal = true ;
    }
    
    int prefixSum(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                return 0 ;
            }
            crawler = crawler->children[ch-'a'] ;
        }
        return crawler->val ;
    }
};
class MapSum {
public:
    Trie* t ;
    
    MapSum() {
        t = new Trie() ;    
    }
    void insert(string key, int val) {
        t->insert(key , val);   
    }
    int sum(string prefix) {
        return t->prefixSum(prefix);   
    }
};
```

7. [Longest word in dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)
```cpp
class Node{
public:
    Node* children[26] ;
    bool isTerminal ;
    Node(){
        isTerminal = false ;
        memset(children , 0 ,sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    
    void insert(string &word){
        Node* crawler = root ;
        
        for(char ch : word){
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch - 'a'] = new Node() ;
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->isTerminal = true ;
    }
    string findMaxStr(){
        string res = "" ;
        string curr = "" ;
        
        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i] and root->children[i]->isTerminal ){
                curr.push_back('a'+i) ;
                dfs(root->children[i] , res , curr);
                curr.pop_back() ;                
            }
        }
        return res ;
    }
    void dfs(Node* node , string &res, string &curr){

        if(res.size() == curr.size()){
            res = min(res , curr);
        }
        else if(res.size() < curr.size()){
            res = curr ;
        }
        
        //explore my children who can build from me
        for(int i = 0 ; i < 26 ; i++){
            if(node->children[i] 
                and node->children[i]->isTerminal ){
                curr.push_back('a'+i);
                dfs(node->children[i] , res , curr);
                curr.pop_back() ;
            }
        }
    }
};
class Solution {
public:
    Trie* t ;
    string longestWord(vector<string>& words) {
        t = new Trie() ;
        for(string &w : words){
            t->insert(w) ;
        }
        return t->findMaxStr() ;
    }
};
```

8. [search suggestion system](https://leetcode.com/problems/search-suggestions-system/)
```cpp
class Node{
public:
    Node* children[26] ;
    bool isTerminal ;
    Node(){
        isTerminal = false ;
        memset(children , 0 , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    
    void insert(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch- 'a'] == NULL){
                crawler->children[ch-'a'] = new Node() ;
            }
            crawler = crawler->children[ch-'a'] ;
        }
        crawler->isTerminal = true ;
    }
    
    Node* search(string &word , Node* crawler){
        for(char ch : word){
            if(crawler->children[ch- 'a'] == NULL){
                return NULL ;
            }
            crawler = crawler->children[ch-'a'] ;
        }
        return crawler ;
    }
    
    bool dfs(Node* crawler , vector<string> &res , string &curr){
        if(not crawler)
            return false ;
        if(crawler->isTerminal){
            res.push_back(curr) ;
            if(res.size() == 3)
                return true ;
        }        
        for(int i = 0 ; i < 26 ; i++){
            if(crawler->children[i]){
                curr.push_back('a'+i) ;
                if(dfs(crawler->children[i] , res , curr)){
                    return true ;
                }
                curr.pop_back();
            }
        }
        return false ;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *t = new Trie() ;
        for(string &p : products){
            t->insert(p) ;
        }
        
        vector<vector<string>> res ;
        
        string temp = "" ;
        for(char ch : searchWord){
            temp.push_back(ch) ;
            Node* curr = t->search(temp , t->root) ;
            if(not curr){
                res.push_back({}) ;
            }
            else{
                string newone = temp ;
                vector<string> holder ;
                t->dfs(curr , holder , newone);
                res.push_back(holder) ;
            }
        }
        
        return res ;
    }
};
```

9. [Remove subfolders](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/)
```cpp
class Node{
public:
    bool isTerminal ;
    Node* children[128] ;
    Node(){
        isTerminal = false ;
        memset(children , 0 , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch] == NULL){
                crawler->children[ch] = new Node() ;
            }
            crawler = crawler->children[ch] ;
        }
        crawler->isTerminal = true ;
    }
    
    bool searchPrefix(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(ch == '/'){
                // check if someone actually ends here
                // then i'm a subfolder
                if(crawler->isTerminal)
                    return true ;
            }
            crawler = crawler->children[ch] ;
        }
        return false ;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res ;
        Trie* t = new Trie() ;
        
        for(string &w : folder){
            t->insert(w) ;
        }
        
        for(string &w : folder){
            if(not t->searchPrefix(w)){
                res.push_back(w) ;
            }
        }
        return res ;
    }
};
```

10. [short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)
```cpp
class Node{
public:
    Node* children[26] ;
    int count ;
    Node(){
        count = 0 ;
        memset(children , 0 , sizeof(children));
    }
};
class STrie{
public:
    Node* root ;
    STrie(){
        root = new Node() ;
    }
    void insert(string word){
        Node* crawler = root ;
        for(int i = word.size()-1 ; i >=0 ;i--){
            char ch = word[i] ;
            
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch- 'a'] = new Node() ;
            }
            crawler = crawler->children[ch - 'a'] ;
            crawler->count++ ;
        }
    }
    bool searchSuffix(string word){
        Node* crawler = root ;
        for(int i = word.size()-1 ; i >= 0 ; i--){
            char ch = word[i] ;
            
            crawler = crawler->children[ch - 'a'] ;
        }
        // cout << word << crawler->count << endl ;
        return (crawler->count != 1) ;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        STrie *t = new STrie() ;
        unordered_set<string> hh(words.begin() , words.end());
        
        for(auto it = hh.begin() ; it != hh.end() ; it++){
            t->insert(*it) ;
        }
        int count = 0 ;
        for(auto it = hh.begin() ; it != hh.end() ; it++){
            if(not t->searchSuffix(*it)){
                count = count + 1 + (*it).size() ; 
            }
        }
        return count ;
    }
};
```

11. []()
```cpp

```