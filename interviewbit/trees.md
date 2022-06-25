# TREES

### BST TREE

1. [check-valid-bst]()
```cpp

```

2. [kth-smallest-ele](https://www.interviewbit.com/problems/kth-smallest-element-in-tree/)
```cpp
void inorder(TreeNode* root , vector<int> &order){
    if(not root){
        return ;
    }
    inorder(root->left , order);
    order.push_back(root->val);
    inorder(root->right , order);
}
int Solution::kthsmallest(TreeNode* A, int B) { 
    vector<int> order ;
    inorder(A , order);
    return order[B-1];
}   
```

3. [2-sum-bt](https://www.interviewbit.com/problems/2sum-binary-tree/)
```cpp
bool isExist(TreeNode* root , int target , unordered_set<int> &memo){
    if(not root){
        return false ;
    }
    int req = target - root->val ;
    if(memo.find(req) != memo.end()){
        return true ;
    }
    memo.insert(root->val);
    return isExist(root->left , target , memo) or isExist(root->right , target , memo);
}

int Solution::t2Sum(TreeNode* root, int B) {
    unordered_set<int> memo ;
    return isExist(root , B , memo );    
}
```

4. [bst-iterator](https://www.interviewbit.com/problems/bst-iterator/)
```cpp
stack<TreeNode *> st ;

void buildLeftSide(TreeNode* root){
    while(root){
        st.push(root);
        root = root->left ;
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    stack<TreeNode* > newone ;
    st = newone ;
    
    buildLeftSide(root);    
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return not st.empty() ;
}

/** @return the next smallest number */
int BSTIterator::next() {
    if(not hasNext()) return -1 ;
    TreeNode* top = st.top() ;
    st.pop() ;
    buildLeftSide(top->right) ;
    return top->val ;
}
```

5. [recover-bst](https://www.interviewbit.com/problems/recover-binary-search-tree/)
```cpp
void inorder(TreeNode* root , vector<int> &order , TreeNode* &prev){
    if(not root){
        return ;
    }
    inorder(root->left , order , prev) ;
    if(prev and prev->val > root->val){
        if(order.size() == 0){
            order.push_back(prev->val);
        }
        order.push_back(root->val);
        if(order.size() == 3){
            return ;
        }
    }
    prev = root ;
    inorder(root->right , order , prev) ;
    
}

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> order ;
    TreeNode* prev = NULL ;
    inorder(A , order , prev);

    sort(order.begin() , order.end());
    if(order.size() == 3){
        return {order[0] , order[2]};
    }
    return order ;
}
```

### Trie

1. [xor-between-two-arrays](https://www.interviewbit.com/problems/xor-between-two-arrays/)
```cpp
#include<bits/stdc++.h>

class TrieNode{
public:
    TrieNode* childrens[2] ;
    TrieNode(){
        childrens[0] = NULL ; childrens[1] = NULL ;
    }
};

class Trie{
public:
    TrieNode* root = new TrieNode() ;
    
    void insert(int val){
        
        bitset<32> bt(val) ;
        TrieNode* crawler = root ;
        
        for(int i = 31 ; i >= 0 ; i--){
            int cur_val = bt[i] ;
            if(crawler->childrens[cur_val] == NULL){
                crawler->childrens[cur_val] = new TrieNode() ;
            }
            crawler = crawler->childrens[cur_val] ;
        }        
    }
    
    int possible_max(int val){
        bitset<32> bt(val);
        int possible_max = 0 ;
        
        TrieNode* crawler = root ;
        for(int i = 31 ; i >= 0 ; i--){
            
            // can i have the opposite bit in the trie to maximize myself ;
            
            int req_bit = (bt[i] == 1)?0:1 ;
            
            if(crawler->childrens[req_bit] != NULL){
                // we got the req_bit 
                possible_max = possible_max | (1 << i) ;
                crawler = crawler->childrens[req_bit] ;
            }   
            else{
                crawler = crawler->childrens[bt[i]] ;
            }      
        }
        return possible_max ;
    }
    
}; 

int Solution::solve(vector<int> &A, vector<int> &B) {
    int maxvalue = 0 ;
    Trie *tt = new Trie() ;
    
    for(int i = 0 ; i < A.size() ; i++){
        tt->insert(A[i]);    
    }
    
    for(int i = 0 ; i < B.size() ; i++){
        maxvalue = max(maxvalue , tt->possible_max(B[i]));
    }
    
    return maxvalue ;
}
```

2. [hotel-reviews](https://www.interviewbit.com/problems/hotel-reviews/)

```cpp
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

vector<int> Solution::solve(string A, vector<string> &B) {
    
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
```

3. [shorted-unique-prefix](https://www.interviewbit.com/problems/shortest-unique-prefix/)
```cpp
class TrieNode{
public:
    TrieNode* childrens[26] = {NULL} ;
    int childrens_count[26] = {0} ;
    bool isEOF = false ;
};

class Trie{
public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string &str){
        TrieNode* crawler = root ;
        
        for(char ch : str){
            int val = ch - 'a';
            if(crawler->childrens[val] == NULL){
                crawler->childrens[val] = new TrieNode();
            }
            crawler->childrens_count[val]++ ;
            crawler = crawler->childrens[val];
        }
        crawler->isEOF = true ;
    }
    
    int smallestUniquePrefixLen(string &str){
        
        TrieNode* crawler = root ;
        int len = 0 ;
        for(char ch : str){
            len++ ;
            
            int val = ch - 'a' ;
            if(crawler->childrens_count[val] == 1){
                // I'm the one who have reached this TrieNode
                return len ;    
            }
            crawler = crawler->childrens[val];
        }
        return len ;
    }
    
};


vector<string> Solution::prefix(vector<string> &A) {
    Trie *tt = new Trie();
    for(string &str : A){
        tt->insert(str);
    }
    
    vector<string> res ;
    for(string &str : A){
        int len = tt->smallestUniquePrefixLen(str);
        res.push_back(str.substr(0,len));
    }
    return res ;
}
```

### Simple tree ops

1. [path-to-node](https://www.interviewbit.com/problems/path-to-given-node/)
```cpp
bool helper(TreeNode* root , int target , vector<int> &ans){
    if(root == NULL){
        return false ;    
    }
    ans.push_back(root->val);
    if(root->val == target){
        // we found it 
        return true ;
    }
    
    if(helper(root->left , target , ans)){
        return true ;
    }
    if(helper(root->right , target , ans)){
        return true ;
    }
    ans.pop_back() ;
    return false ;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans ;
    helper(A , B , ans);
    
    return ans ;
}
```

2. [Remove-half-nodes](https://www.interviewbit.com/problems/remove-half-nodes/)
```cpp
TreeNode* Solution::solve(TreeNode* root) {
    if(not root){
        return NULL ;
    }
    root->left = solve(root->left);
    root->right = solve(root->right);
    
    if(not root->left and not root->right){
        return root ;
    }
    if(not root->left){
        // I am having only one children
        return root->right ;
    }
    if(not root->right){
        return root->left ;
    }
    return root ;
}
```

3. [Node-at-k-distance](https://www.interviewbit.com/problems/nodes-at-distance-k/)
```cpp
bool findAncestors(TreeNode* root , int target , vector<TreeNode* > &ancestors ){
    if(not root){
        return false;
    }
    ancestors.push_back(root);
    if(root->val == target){
        return true ;
    }
    if(findAncestors(root->left , target , ancestors)){
        return true ;
    }
    if(findAncestors(root->right , target , ancestors)){
        return true ;
    }
    ancestors.pop_back();
    return false ;
}

void helper(TreeNode* root , int count ,TreeNode* stopper , vector<int> &ans){
    if(not root){
        return ;
    }
    if(root == stopper or count < 0){
        return ;
    }
    
    if(count == 0){
        ans.push_back(root->val);
        return ;
    }
    helper(root->left , count-1 ,stopper , ans);
    helper(root->right , count-1 ,stopper , ans);
}

vector<int> Solution::distanceK(TreeNode* root, int B, int C) {
    vector<TreeNode* > ancestors ;
    vector<int> ans ;
    findAncestors(root , B , ancestors);
    int idx = ancestors.size()-1 ;
    
    // for(TreeNode* rt : ancestors){
    //     ans.push_back(rt->val);
    // }
    reverse(ancestors.begin() , ancestors.end());
    
    for(int i = 0 ; i < ancestors.size() ; i++){
        helper(ancestors[i] , C-i , (i == 0)?NULL:ancestors[i-1] , ans);
    }
    
    return ans ;
}
```

4. [balances-bt](https://www.interviewbit.com/problems/balanced-binary-tree/)
```cpp
pair<bool,int> helper(TreeNode* root){
    if(not root){
        return {true , 0};
    }
    pair<int,int> leftSide = helper(root->left);
    if(leftSide.first == false){
        return {false , 0};
    }
    
    pair<int,int> rightSide = helper(root->right);
    if(rightSide.first == false){
        return {false , 0};
    }
    int diff = abs(leftSide.second - rightSide.second) ;
    if(diff > 1){
        return {false , 0};
    }
    
    return {true , 1 + max(leftSide.second , rightSide.second)};
}

int Solution::isBalanced(TreeNode* A) {
    return helper(A).first ;
}
```

5. [maximum-edge-removal](https://www.interviewbit.com/problems/maximum-edge-removal/)
```cpp
int removeEdges(int cur_node , int &count , vector<bool> &visited , vector<vector<int>> &graph){
    visited[cur_node] = true ;
    int nodes_count = 0 ;
    
    for(int neigh : graph[cur_node]){
        if(not visited[neigh]){
            int subcomponent = removeEdges(neigh , count , visited , graph);
            if(subcomponent%2 == 0){
                // even number of nodes in the subcomponent so we can remove  the edge
                count++ ;
            }
            else{
                nodes_count += subcomponent ;
            }
        }
    }
    return 1+nodes_count ;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int count = 0 ;
    vector<vector<int>> graph(A+1) ;
    
    for(vector<int>& edge : B){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(A+1 , false);
    removeEdges(1 , count , visited , graph);
    
    return count ;
}
```

6. 