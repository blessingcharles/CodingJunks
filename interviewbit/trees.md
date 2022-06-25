# TREES

## Example

1. [nxt-greater-bst](https://www.interviewbit.com/problems/next-greater-number-bst/)
```cpp

bool helper(TreeNode* root , int target ,bool &getnext , TreeNode* &greater){
    if(not root){
        return false ;
    }
    
    if(helper(root->left , target , getnext , greater)){
        return true ;   
    }
    
    if(getnext){
        greater = root ;
        getnext = false ;
        return true ;
    }
    if(root->val == target){
        getnext = true ;
    }
    
    if(helper(root->right , target , getnext , greater)){
        return true ;
    }
    return false ;
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    bool getnext = false ;
    TreeNode* greater = NULL ;
    
    helper(A , B , getnext , greater) ;
    return greater ;
}

```
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

### Root to Leaf

1. [Burn-a-tree](https://www.interviewbit.com/problems/burn-a-tree/)
```cpp
void buildGraph(TreeNode* root , TreeNode* parent , unordered_map<int , vector<int>> &graph , unordered_set<int> &nodes){
    if(not root){
        return ;
    }    
    if(parent){
        graph[root->val].push_back(parent->val);
    }
    
    nodes.insert(root->val);
    
    if(root->left){
        graph[root->val].push_back(root->left->val);
        buildGraph(root->left , root , graph , nodes );
    }
    if(root->right){
        graph[root->val].push_back(root->right->val);
        buildGraph(root->right , root , graph , nodes);
    }
}

int Solution::solve(TreeNode* A, int B) {
    unordered_map<int , vector<int>> graph ;
    unordered_set<int> nodes ;

    buildGraph(A , NULL , graph , nodes );
    queue<int> q ;
    q.push(B);
    int time = -1 ;

    nodes.erase(B);
    
    while(not q.empty()){
        int sz = q.size() ;
        time++ ;
        while(sz--){
            int curnode = q.front() ; q.pop() ;
            
            // add neighbours
            for(int neigh : graph[curnode]){
                if(nodes.find(neigh) != nodes.end()){
                    q.push(neigh);
                    nodes.erase(neigh);
                }    
            }
        }
    }
    
    return time ;
}
```

2. [maxdepth-of-bt](https://www.interviewbit.com/problems/max-depth-of-binary-tree/)
```cpp
int Solution::maxDepth(TreeNode* A) {
    if(not A){
        return 0 ;
    }
    
    return 1 + max(maxDepth(A->left) , maxDepth(A->right));
}
```

3. [sum-root-to-leaf](https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/)
```cpp
int mod = 1003 ;

void helper(TreeNode* root , string &container , long long &cursum){
    if(not root){
        return  ;
    }
    
    container.push_back(root->val+'0');
    string prev = container ;
    
    if(container.size() >= 7){
        int val = stoi(container);
        val = val%mod ;
        container = to_string(val) ;
    }
    
    // is leaf node ?
    if(not root->left and not root->right){
        cursum = (cursum + stoll(container)%mod)%mod ;
        // cout << container << endl ;
    }
    helper(root->left , container , cursum);
    helper(root->right , container , cursum);
    
    container = prev ;
    container.pop_back() ;    
}
int Solution::sumNumbers(TreeNode* A) {
    long long cursum = 0 ;
    string container = "" ;
    helper(A , container , cursum);
    return cursum ;
}
```

4. [Pathsum](https://www.interviewbit.com/problems/path-sum/)
```cpp
int Solution::hasPathSum(TreeNode* root, int B) {
    if(not root){
        return 0 ;
    }
    if(not root->left and not root->right){
        if(B-root->val == 0){
            return 1 ;
        }
        return 0 ;
    }
    if(hasPathSum(root->left , B-root->val)){
        return 1 ;
    }
    
    return hasPathSum(root->right , B - root->val) ;
    
}
```

5. [min-depth-of-bt](https://www.interviewbit.com/problems/min-depth-of-binary-tree/)
```cpp
int Solution::minDepth(TreeNode* A) {
    if(not A){
        return 0 ;
    }
    // is I'm a leaf
    if(not A->left and not A->right){
        return 1 ;
    }
    if(not A->right){
        return 1+minDepth(A->left) ;
    }
    if(not A->left){
        return 1+minDepth(A->right);
    }
    
    return 1+min(minDepth(A->left) , minDepth(A->right));
    
}
```

6. [root-leaf-pathsum](https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/)
```cpp
void helper(TreeNode* root , int target , int cursum , vector<int> &container , vector<vector<int>> &res){
    if(not root){
        return ;
    }    
    container.push_back(root->val);
    
    if(not root->left and not root->right){
        // leaf node 
        if(cursum + root->val == target){
            res.push_back(container);
        }
        container.pop_back();
        return ;
    }
    helper(root->left , target , cursum+root->val , container , res);
    helper(root->right , target , cursum+root->val , container , res);
    container.pop_back();
    return ;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res ;
    vector<int> container ;
    helper(A , B , 0 ,container , res);
    
    return res ;   
}
```

### Tree Construction

1. [inorder-cartesian-tree](https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/)
```cpp
int findGreater(vector<int> &arr , int left , int right){
    int max_idx= left ;
    
    for(int i = left+1 ; i <= right ; i++){
        if(arr[i] > arr[max_idx]){
            max_idx = i ;
        }
    }
    return max_idx ;
}

TreeNode* BuildCartesian(vector<int> &arr , int left , int right){
    if(left > right){
        return NULL ;
    }    
    
    int idx = findGreater(arr , left , right);
    TreeNode* root = new TreeNode(arr[idx]);
    root->left = BuildCartesian(arr , left , idx-1);
    root->right = BuildCartesian(arr , idx+1 , right);
    return root ;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return BuildCartesian(A , 0 , A.size()-1);
        
}
```

2. [sorted-arr-to-bst](https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/)
```cpp
TreeNode* buildBST(const vector<int> &arr , int left , int right){
    if(left > right){
        return NULL ;
    }
    int mid = left + (right-left)/2 ;
    
    TreeNode* root = new TreeNode(arr[mid]);
    
    root->left = buildBST(arr , left , mid-1);
    root->right = buildBST(arr , mid+1 , right);
    
    return root ; 
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return buildBST(A , 0 , A.size()-1);    
}
```

3. [construct-bt-from-inorder-pre](https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/)
```cpp
TreeNode* build(vector<int> &preorder , int &idx , vector<int> &inorder , int left , int right , unordered_map<int,int> &memo){
    if(left > right){
        return NULL ;
    }
    int rootVal = preorder[idx++] ;
    
    TreeNode* root = new TreeNode(rootVal);
    
    root->left = build(preorder,idx , inorder , left ,            memo[rootVal]-1 , memo);
    root->right = build(preorder,idx, inorder,  memo[rootVal]+1 , right , memo);
    return root ;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < B.size() ; i++){
        memo[B[i]] = i ;
    }
    int idx = 0 ;
    return build(A ,idx, B , 0 , A.size()-1 , memo);
}
```

4. [bt-from-inorder-postorder](https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/)
```cpp
TreeNode* build(vector<int> &postorder , int &idx , vector<int> &inorder , int left , int right , unordered_map<int,int> &memo){
    if(left > right){
        return NULL ;
    }
    int rootVal = postorder[idx--] ;
    TreeNode* root = new TreeNode(rootVal);
    
    root->right = build(postorder , idx , inorder , memo[rootVal]+1 , right , memo);
    root->left = build(postorder , idx , inorder , left , memo[rootVal]-1 , memo);
    
    return root ;
    
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < inorder.size() ; i++){
        memo[inorder[i]] = i ;
    }
    
    int idx = inorder.size()-1 ;
    return build(postorder ,idx, inorder , 0 , inorder.size()-1 , memo);
}
```

### Inplace

1. [invert-tree](https://www.interviewbit.com/problems/invert-the-binary-tree/)
```cpp
TreeNode* Solution::invertTree(TreeNode* root) {
    if(not root){
        return root ;
    }    
    TreeNode* temp = root->left ;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root ;
}
```

### Tree search
1. [lca](https://www.interviewbit.com/problems/least-common-ancestor/)
```cpp
TreeNode* findLCA(TreeNode* root , int b , int c , bool &b_found , bool &c_found){
    if(not root){
        return NULL ;
    }
    if(root->val == b){
        b_found = true ;
       return root ; 
    } 
    if(root->val == c){
        c_found = true ;
        return root ;
    }
    
    TreeNode* left = findLCA(root->left , b , c , b_found , c_found);
    TreeNode* right = findLCA(root->right , b , c , b_found , c_found);
    
    if(left and right){
        return root ;
    }
    if(not left and not right){
        return NULL ;
    }
    
    return (left != NULL)?left:right ;
}
bool find(TreeNode* root , int target){
    if(not root){
        return false ;
    }
    if(root->val == target){
        return true ;
    }
    
    return find(root->left , target) or find(root->right , target);
     
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool b_found = false , c_found = false ;
    
    TreeNode* ll = findLCA(A , B , C , b_found , c_found);
    
    if(not ll) return -1 ;
    if(b_found and c_found) return ll->val ;
    
    if(not b_found){
        b_found = find(ll , B);
        return (b_found)?ll->val:-1 ;
    }
    c_found = find(ll , C);
    
    return (c_found)?ll->val:-1 ;

}
```

### 2 trees

1. [merge-tree](https://www.interviewbit.com/problems/merge-two-binary-tree/)
```cpp
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    if(not root1 and not root2){
        return NULL ;
    }
    if(not root1){
        return root2 ;
    }
    if(not root2){
        return root1 ;
    }
    
    TreeNode* newroot = new TreeNode(root1->val + root2->val);
    
    newroot->left = solve(root1->left , root2->left);
    newroot->right = solve(root1->right , root2->right);
    return newroot ;  
}
```

2. [symmetric-bt](https://www.interviewbit.com/problems/symmetric-binary-tree/)
```cpp
bool isMirror(TreeNode* root1 , TreeNode* root2){
    if(not root1 and not root2){
        return true ;
    }
    if(not root1 or not root2 or root1->val != root2->val){
        return false ;
    }
    
    return isMirror(root1->left , root2->right) and isMirror(root1->right , root2->left);
}

int Solution::isSymmetric(TreeNode* A) {
    if(not A) return true ;
    
    return isMirror(A->left , A->right);
}
```

3. [same-tree](https://www.interviewbit.com/problems/identical-binary-trees/)
```cpp
int Solution::isSameTree(TreeNode* root1, TreeNode* root2) {
    if(not root1 and not root2){
        return true ;
    }
    if(not root1 or not root2 or root1->val != root2->val){
        return false ;
    }
    
    return isSameTree(root1->left , root2->left) and isSameTree(root1->right , root2->right);
}
```

### LinkedList Tree

1. [flatten-bt](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
```cpp
void solve(TreeNode* root){
    if(not root){
        return ;
    }
    solve(root->left);
    solve(root->right);
    
    if(root->left){
        TreeNode* temp = root->right ;
        root->right = root->left ;
        TreeNode* node = root ;
        
        while(root->right){
            root = root->right ;
        }
        root->right = temp ;
        node->left = NULL ;  
    } 
}

TreeNode* Solution::flatten(TreeNode* A) {
    solve(A);
    return A ;
}
```

2. 