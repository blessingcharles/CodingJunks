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

4. 