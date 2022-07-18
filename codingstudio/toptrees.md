1. [count univalue subtrees](https://www.codingninjas.com/codestudio/problems/unival-trees_697311?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool helper(BinaryTreeNode<int> *root , int &count , int val){
    if(not root) return true ;
    bool ls = helper(root->left , count , root->data);
    bool rs = helper(root->right , count , root->data);
    if(ls and rs){
        count++ ;
    }
    return (root->data == val) and ls and rs ;
}

int countUnivalTrees(BinaryTreeNode<int> *root)
{
    int count = 0 ;
    helper(root , count , 1e9);
    return count ;
}
```

2. [binary tree pruning](https://www.codingninjas.com/codestudio/problems/binary-tree-pruning_699987?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
TreeNode<int>* binaryTreePruning(TreeNode<int>* root)
{
    if(not root) return NULL ;
    root->left = binaryTreePruning(root->left);
    root->right = binaryTreePruning(root->right);
    if(not root->left and not root->right){
        //panic mode no childrens have 1 val did i have
        if(root->val == 1) return root ;
        return NULL ;
    }
    return root ;
}
```

3. [symmetric tree](https://www.codingninjas.com/codestudio/problems/tree-symmetricity_630426?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool helper(BinaryTreeNode<int>* r1 , BinaryTreeNode<int>* r2){
    if(not r1 and not r2) return true ;
    if(not r1 or  not r2) return false ;
    if(r1->data != r2->data) return false ;
    return helper(r1->left , r2->right) and helper(r1->right , r2->left) ;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(not root) return true ;
    return helper(root->left , root->right); 
}
```

4. [delete leaf nodes with x](https://www.codingninjas.com/codestudio/problems/delete-leaf-nodes-with-value-x_630465?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
BinaryTreeNode<int>* deleteLeafNodes(BinaryTreeNode<int> *root, int x)
{
    if(not root) return NULL ;
    root->left = deleteLeafNodes(root->left , x);
    root->right = deleteLeafNodes(root->right , x);
    if(not root->left and not root->right){
        if(root->data == x) return NULL ;
    }
    return root ;
}
```
5. [max width of bt](https://www.codingninjas.com/codestudio/problems/maximum-width-in-binary-tree_763671?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    if(not root) return 0 ;
    queue<TreeNode<int>* > q ;
    int maxwidth = 1 ;
    q.push(root);
    while(not q.empty()){
        int sz = q.size();
        maxwidth = max(maxwidth , sz);
        while(sz--){
            TreeNode<int> *curr = q.front() ; q.pop() ;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return maxwidth ;
}
```
6. [reverse level order](https://www.codingninjas.com/codestudio/problems/reverse-level-order-traversal_764339?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
vector<int> reverseLevelOrder(TreeNode<int> *root){
    vector<int> ans ;

    if(not root) return ans ;
    queue<TreeNode<int>* > q ;

    q.push(root);
    while(not q.empty()){
        int sz = q.size();
        vector<int> temp ;
        while(sz--){
            TreeNode<int> *curr = q.front() ; q.pop() ;
            temp.push_back(curr->val);
            if(curr->right){
                q.push(curr->right);
            }
            if(curr->left){
                q.push(curr->left);
            }
        }
        ans.insert(ans.begin() , temp.begin() , temp.end());
    }
    return ans ;
}
```
7. [right view](https://www.codingninjas.com/codestudio/problems/right-view_764605?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
vector<int> printRightView(BinaryTreeNode<int>* root) {
      vector<int> ans ;

    if(not root) return ans ;
    queue<BinaryTreeNode<int>* > q ;

    q.push(root);
    while(not q.empty()){
        int sz = q.size();
        while(sz--){
            BinaryTreeNode<int> *curr = q.front() ; q.pop() ;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            if(sz == 0){
                ans.push_back(curr->data);
            }
        }
    }
    return ans ;
}
```
8. [boundary traversal of bt](https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

void leftSide(TreeNode<int> *root  , vector<int> &arr){
    if(not root) return ;
    if(not root->left and not root->right) return ;
    arr.push_back(root->data);
    if(root->left){
        leftSide(root->left , arr);
    }
    else{
        leftSide(root->right , arr);
    }
}
void getLeaf(TreeNode<int> *root  , vector<int> &arr){
    if(not root) return ;
    if(not root->left and not root->right){
        arr.push_back(root->data);
        return ;
    }
    getLeaf(root->left , arr);
    getLeaf(root->right , arr);
}
void rightSide(TreeNode<int> *root  , vector<int> &arr){
    if(not root) return ;
    if(not root->left and not root->right) return ;
    arr.push_back(root->data);
    if(root->right){
        rightSide(root->right , arr);
    }
    else{
        rightSide(root->left , arr);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans ;
    /*
        1. get left side without leaf nodes
        2. get all leaf nodes
        3. reverse of right side without leaf nodes
    */
    if(not root){
        return ans ;
    }
    ans.push_back(root->data);
    leftSide(root->left , ans);
    getLeaf(root->left , ans);
    getLeaf(root->right , ans);
    
    vector<int> tt ;
    rightSide(root->right , tt);
    reverse(tt.begin() , tt.end());
    ans.insert(ans.end() , tt.begin() , tt.end());
    return ans ;
}
```

9. [level order]()
```cpp
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
          vector<int> ans ;

    if(not root) return ans ;
    queue<BinaryTreeNode<int>* > q ;

    q.push(root);
    while(not q.empty()){
        int sz = q.size();
        while(sz--){
            BinaryTreeNode<int> *curr = q.front() ; q.pop() ;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            ans.push_back(curr->val);
        }
    }
    return ans ;
}
```
10. [check identical trees](https://www.codingninjas.com/codestudio/problems/identical-trees_799364?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(not root1 and not root2) return true ;
    if(not root1 or not root2) return false ;
    if(root1->data != root2->data) return false ;
    return identicalTrees(root1->left , root2->left) and identicalTrees(root1->right , root2->right);
}
```
11. [distance between two nodes](https://www.codingninjas.com/codestudio/problems/distance-between-two-nodes-of-a-tree_800303?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
bool helper(TreeNode<int> *root , int target , vector<TreeNode<int> *> &path){
    if(not root) return false ;
    path.push_back(root);
    if(root->val == target){
        return true ;
    }
    if(helper(root->left , target , path)){
        return true ;
    }
    if(helper(root->right , target , path)){
        return true ;
    }
    path.pop_back();
    return false ;
}
int findlen(TreeNode<int> *root , int target){
    if(not root) return INT_MAX ;
    if(root->val == target) return 0 ;
    int ls = findlen(root->left , target);
    int rs = findlen(root->right , target);
    if(ls == INT_MAX and rs == INT_MAX) return ls ;
    
    return 1+min(ls , rs);
}
int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    vector<TreeNode<int>* > path1 , path2 ;
    if(not helper(root , node1 , path1) or not helper(root , node2 , path2)){
        return -1 ;
    }
    //find the common ancestor
    unordered_set<TreeNode<int> *> memo(path1.begin() , path1.end());
    int idx = 0 ;
    for(int i = path2.size()-1 ; i >= 0 ; i--){
        if(memo.find(path2[i]) != memo.end()){
            idx=i;
            break ;
        }
    }
    return findlen(path2[idx] , node1) + findlen(path2[idx] , node2);
}
```
12. [nodes at distance k](https://www.codingninjas.com/codestudio/problems/print-nodes-at-distance-k-from-a-given-node_842560?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool helper(BinaryTreeNode<int> *root ,vector<BinaryTreeNode<int>* > &lca ,BinaryTreeNode<int>* target){
    if(not root) return false ;
    lca.push_back(root);
    if(root == target){
        return true ;
    }
    if(helper(root->left , lca , target)){
        return true ;
    }
    if(helper(root->right , lca , target)){
        return true ;
    }
    lca.pop_back();
    return false ;
}
void findNodes(BinaryTreeNode<int> *root , int dist , BinaryTreeNode<int>* stopper, vector<BinaryTreeNode<int> *> &ans ){
    if(not root){
        return ;
    }
    if(root == stopper) return ;
    if(dist == 0){
        ans.push_back(root) ; return ;    
    }
    findNodes(root->left , dist-1 , stopper , ans);
    findNodes(root->right , dist-1 , stopper , ans);
}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    vector<BinaryTreeNode<int>* > lca ;
    bool flag1 = helper(root , lca , target);
    vector<BinaryTreeNode<int> *> ans ;
    if(not flag1) return ans ;
    findNodes(target , K , NULL , ans);
    K-- ;
    for(int i = lca.size()-2 ; i >= 0 and K >= 0 ; i-- , K--){
        findNodes(lca[i] , K , lca[i+1] , ans);
    }
    return ans ;
}
```
13. [max level sum](https://www.codingninjas.com/codestudio/problem-lists/top-trees-interview-questions)
```cpp
#include<bits/stdc++.h>
int maxLevelSum(TreeNode<int>* root){

    int maxval = INT_MIN ;
    if(not root) return 0 ;
    queue<TreeNode<int>* > q ;

    q.push(root);
    while(not q.empty()){
        int sz = q.size();
        int curlevel = 0 ;
        while(sz--){
            TreeNode<int> *curr = q.front() ; q.pop() ;
            curlevel += curr->val ; 
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        maxval = max(maxval , curlevel);
    }
    return maxval ;
}
```
14. [cousins in bt](https://www.codingninjas.com/codestudio/problems/cousins-of-given-node-in-binary-tree_873363?topList=top-trees-interview-questions&leftPanelTab=3)
```cpp
#include<bits/stdc++.h>
vector<int> cousinsOfNode(BinaryTreeNode<int> *root, int node)
{
    vector<int> ans ;
    if(not root) return {} ;
    
    queue<pair<BinaryTreeNode<int> * ,BinaryTreeNode<int>* >> q ;
    q.push({root,NULL});
    
    bool curr_level = false ;
    BinaryTreeNode<int> *parent ;
    pair<BinaryTreeNode<int> * ,BinaryTreeNode<int>* > curr ;
    while(not q.empty()){
        int sz = q.size() ;
        bool flag = false ;
        while(sz--){
            curr = q.front() ; q.pop() ;
            if(curr_level){
                if(curr.second == parent) continue ;
                ans.push_back(curr.first->data);
            }            
            else{
                if(curr.first->left){
                    if(curr.first->left->data == node){
                        flag = true ;
                        parent = curr.first ;
                    }
                    else
                        q.push({curr.first->left , curr.first});
                }
                if(curr.first->right){
                    if(curr.first->right->data == node){
                        flag = true ;
                        parent = curr.first ;
                    }
                    else
                        q.push({curr.first->right , curr.first});
                }
            }
        }
        curr_level = flag ;
    }
    sort(ans.begin() , ans.end());
    return ans ;
}
```
15. [issubtree](https://www.codingninjas.com/codestudio/problems/subtree-of-another-tree_893071?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool isSubtree(TreeNode<int> *T, TreeNode<int> *S)
{
    if(not T and not S) return true ;
    if(not T or not S) return false ;
    if(T->val != S->val){
        return isSubtree(T->left , S) or isSubtree(T->right , S);
    }
    return isSubtree(T->left , S->left) and isSubtree(T->right , S->right);
}
```
16. [size of largest bst in bt](https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
struct Myresult{
public:
    int minval = INT_MAX ;
    int maxval = INT_MIN ;
    bool isbst = false ;
    int curlen = 0 ;
};

Myresult helper(TreeNode<int> *root , int &maxlen){
    Myresult res ;
    if(not root){
        res.isbst = true ;
        return res ;
    }
    Myresult ls = helper(root->left , maxlen);
    Myresult rs = helper(root->right , maxlen);

    if(not ls.isbst or not rs.isbst) return res ;
    
    // can i join the leftside
    if(ls.maxval >= root->data or rs.minval <= root->data){
        
        return res ;
    }
    res.isbst = true ;
    res.curlen = 1 + ls.curlen + rs.curlen ;
    res.maxval = max(rs.maxval,root->data) ;
    res.minval = min(ls.minval,root->data);
    maxlen = max(maxlen , res.curlen) ;
    return res ;
}
int largestBST(TreeNode<int>* root) {
    int maxlen = 1 ;
    Myresult res = helper(root , maxlen);
    return max(maxlen , res.curlen);
}
```

17. [build bst from preorder](https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
BinaryTreeNode<int>* helper(vector<int> &preorder , int left , int right , vector<int> &greater_ele){
    if(left > right){
        return NULL ;
    }
    if(left == right){
        return new BinaryTreeNode<int>(preorder[left]) ;        
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[left]);
    
    root->left = helper(preorder , left+1 , greater_ele[left]-1 , greater_ele);
    root->right = helper(preorder , greater_ele[left] , right , greater_ele);
    
    return root ;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int N = preorder.size() ;
    vector<int> nearest_greater(N,N);
    stack<int> st ;
    st.push(N-1);
    for(int i = N-2 ; i >= 0 ; i--){
        while(not st.empty() and preorder[st.top()] < preorder[i]){
            st.pop() ;
        }
        if(not st.empty()){
            nearest_greater[i] = st.top() ;
        }
        st.push(i);
    }
    return helper(preorder , 0 , N-1 , nearest_greater);
}
```
18. [serialize and deserialize bt](https://www.codingninjas.com/codestudio/problems/serialise-deserialise-a-binary-tree_920328?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
char marker = '#' ;

void helper(TreeNode<int> *root , string &ss){
    ss.push_back(',');
    if(not root){
        ss.push_back(marker);
        return ;
    }
    ss = ss + to_string(root->data) ;
    helper(root->left , ss);
    helper(root->right , ss);
}
string serializeTree(TreeNode<int> *root)
{
    string ss = "" ;
    helper(root,ss);
    return ss.substr(1);
}
TreeNode<int>* buildTree(vector<string> &arr , int &pos){
    if(arr[pos] == "#"){
        pos++ ;
        return NULL ;
    }
    TreeNode<int>* root = new TreeNode<int>(stoi(arr[pos]));
    pos++ ;
    root->left = buildTree(arr , pos);
    root->right = buildTree(arr , pos);
    
    return root ;
}
TreeNode<int>* deserializeTree(string &serialized)
{
    vector<string> arr ;
    stringstream ss(serialized);
    string word ;
    while(getline(ss , word , ',')){
        arr.push_back(word);
    }
    int pos = 0 ;
    return buildTree(arr , pos);
}
```
19. [delete node in bst](https://www.codingninjas.com/codestudio/problems/delete-node-in-bst_920381?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    if(not root) return NULL ;
    if(root->data == key){
        if(not root->left){
            return root->right ;
        }
        else if(not root->right){
            return root->left ;
        }
        // both childs present
        // take the smaller node from the right side
        BinaryTreeNode<int>* curr = root->right ;
        BinaryTreeNode<int>* prev = NULL ;
        while(curr->left){
            prev = curr ;
            curr = curr->left ;
        }
        if(prev){
            prev->left = curr->right ;
        }
        else{
            root->right = curr->right ;
        }
        root->data = curr->data ;
        return root ;
    }
    root->left = deleteNode(root->left , key);
    root->right = deleteNode(root->right , key);
    return root ;    
}
```
20. [kth smallest node](https://www.codingninjas.com/codestudio/problems/kth-smallest-node-in-bst_920441?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool find(TreeNode<int> *root , int &k , int &target_val){
    if(not root) return false ;
  
    if(find(root->left ,k,target_val)){
        return true ;
    };
    if(k == 1){
        target_val = root->data ;
        return true ;
    }
    k-- ;
    if(find(root->right , k , target_val)){
        return true ;
    }
    return false ;
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int target = -1 ;
    find(root , k , target);
    return target ;
}
```

21. [closest bst value](https://www.codingninjas.com/codestudio/problems/closest-element-in-bst_920449?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
void helper(BinaryTreeNode<int>* root){
    if(not root) return ;
    if(abs(T - root->data) < mindiff){
        minele = root->data ;
        mindiff = abs(T - root->data);
    }
    else if(abs(T - root->data) == mindiff and root->data < minele){
        minele = root->data ;
    }
    
    if(root->data < T){
        helper(root->right);
    }
    else if(root->data > T){
        helper(root->left);
    }
}

int findClosestElement(BinaryTreeNode<int>* node, int k){
    mindiff = INT_MAX ; 
    minele = INT_MAX ;
    T = k ;
    helper(node);
    return minele ;
}
```

22. [count unique bst](https://www.codingninjas.com/codestudio/problems/construct-bsts_920468?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
unordered_map<int,long long> memo ;
long long mod = 1e9+7 ;

long long helper(int nums){
    if(nums <= 1) return 1 ;
    if(memo.find(nums) != memo.end()) return memo[nums] ;
    long long res = 0 ;
    for(int i = 0 ; i < nums ; i++){
        res += (helper(i)*helper(nums-i-1))%mod;
    }
    return memo[nums] = res%mod ;
}
long long totalTrees(int num){
    return helper(num) ;
}
```
23. [predecor and successor in bst](https://www.codingninjas.com/codestudio/problems/predecessor-and-successor_920476?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
void build(binaryTreeNode *root , vector<int> &arr){
    if(not root) return ;
    build(root->left , arr);
    arr.push_back(root->data);
    build(root->right , arr);
}
vector<int> findPreSuc(binaryTreeNode *root, int key)
{
    vector<int> arr ;
    build(root , arr);
    if(not root) return {-1,-1} ;
    int idx = 0 ;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] == key){
            idx = i ; break ;
        }
    }
    int ele1 = -1 ;
    int ele2 = -1 ;
    if(idx-1 >= 0) ele1 = arr[idx-1];
    if(idx+1 < arr.size()) ele2 = arr[idx+1] ;
    
    return {ele1 , ele2} ;
}
```

24. [find duplicate subtree](https://www.codingninjas.com/codestudio/problems/duplicate-subtrees_920530?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
class Solution {
    vector<TreeNode*> res ;
    unordered_map<string , int> memo ;
    
    string traversal(TreeNode* root){
        if(!root)
          return "" ;
        
        string subtree = to_string(root->val) + "," + traversal(root->left) + "," + traversal(root->right);
        
        if(memo[subtree]++ == 1)
            res.push_back(root);
        return subtree ;
        
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return res ;
    }
};
```
25. [zigzag levelorder]()
```cpp
#include<bits/stdc++.h>
vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    vector<int> res ; 
    
    bool isreverse = false ;
    queue<TreeNode<int>* > q ;
    q.push(root);
    TreeNode<int>* curr ;
    
    while(not q.empty()){
        int sz = q.size() ;
        deque<int> dq ;
        
        while(sz--){
            curr = q.front() ; q.pop() ;
            
            if(isreverse){
                dq.push_front(curr->data);
            }
            else{
                dq.push_back(curr->data) ;
            }
            
            if(curr->left){
                q.push(curr->left);
            }
            
            if(curr->right){
                q.push(curr->right);
            }
        }    
        isreverse = not isreverse ;
        res.insert(res.end(),dq.begin() , dq.end());
    } 
    return res ;
    //    Write your code here.
}
```
26. [binary tree cameras](https://www.codingninjas.com/codestudio/problems/binary-tree-cameras_1231013?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int has_camera = 2 ;
int covered = 1 , not_covered = 0 ;

int helper(TreeNode<int> *root , int &count){
    if(not root) return covered ;
    int ls = helper(root->left , count);
    int rs = helper(root->right , count);
    if(ls == not_covered or rs == not_covered){
        count++ ;
        return has_camera ;
    }
    if(ls == has_camera or rs == has_camera){
        return covered ;
    }
    return not_covered ;
}


int getMinCamera(TreeNode<int> *root)
{
    int count = 0 ;
    
    return (helper(root , count) == not_covered)?++count:count ;
}
```

27. [vertical order traversals](https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    unordered_map<int , vector<int>> memo ;
    int minval = 0 ;
    int maxval = 0 ;
    queue<pair<TreeNode<int> * ,int>> q ;
    q.push({root , 0});
    pair<TreeNode<int>* , int> curr ;
    
    while(not q.empty()){
        curr = q.front() ; q.pop() ;
        minval = min(minval , curr.second);
        maxval = max(maxval , curr.second);
        memo[curr.second].push_back(curr.first->data);
        if(curr.first->left){
            q.push({curr.first->left , curr.second-1});
        }
        
        if(curr.first->right){
            q.push({curr.first->right , curr.second+1});
        }
    }
    vector<int> res ;    
    for(int val = minval ; val <= maxval ; val++){
        for(int ele : memo[val]){
            res.push_back(ele) ;
        }
    }
    return res ;
}
```

28. [construct bt from inorder and preorder](https://www.codingninjas.com/codestudio/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
TreeNode<int> *build(int left , int right , int &pos , unordered_map<int , int> &memo , vector<int> &preorder){
    if(left == right){
        pos++ ;
        return new TreeNode<int>(preorder[pos-1]);
    }
    if(left > right) return NULL ;
    TreeNode<int> *root = new TreeNode<int>(preorder[pos++]) ;
    root->left = build(left , memo[root->data]-1 , pos , memo , preorder);
    root->right = build(memo[root->data]+1 , right , pos , memo , preorder);
    
    return root ;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < inorder.size() ; i++){
        memo[inorder[i]] = i ;
    }
    int pos = 0 ;
    return build(0 , preorder.size()-1 ,pos , memo , preorder);
}
```

29. [lca of binary tree](https://www.codingninjas.com/codestudio/problems/lca-of-binary-tree_920541?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
bool helper(TreeNode<int> *root ,vector<TreeNode<int>* > &lca ,int target){
    if(not root) return false ;
    lca.push_back(root);
    if(root->data == target){
        return true ;
    }
    if(helper(root->left , lca , target)){
        return true ;
    }
    if(helper(root->right , lca , target)){
        return true ;
    }
    lca.pop_back();
    return false ;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    vector<TreeNode<int> *> path1 , path2 ;
    if(not helper(root , path1 , x)) return -1;
    if(not helper(root , path2 , y)) return -1;
    unordered_set<TreeNode<int>* > memo(path1.begin() , path1.end());
    
    for(int i = path2.size()-1 ; i >= 0 ; i--){
        if(memo.find(path2[i]) != memo.end()) return path2[i]->data ;   
    }
    return -1 ;
}
```

30. [diameter of bt](https://www.codingninjas.com/codestudio/problems/diameter-of-the-binary-tree_920552?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int helper(TreeNode<int> *root , int &maxval){
    if(not root) return -1 ;
    
    int ls = 1+helper(root->left , maxval);
    int rs = 1+helper(root->right , maxval);
    maxval = max(maxval , ls+rs);
    return max(ls,rs);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxval = 0 ;
    if(not root) return 0 ;
    helper(root , maxval);
    return maxval ;
}
```
31. [is height balanced tree](https://www.codingninjas.com/codestudio/problems/is-height-balanced-binary-tree_975497?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
pair<bool , int> helper(BinaryTreeNode<int> *root){
    if(not root){
        return {true , 0} ;
    }
    pair<bool , int> ls = helper(root->left);
    if(not ls.first) return ls ;
    pair<bool , int> rs = helper(root->right);
    if(not rs.first) return rs ;
    int diff = abs(ls.second - rs.second);
    if(diff > 1) return {false , 0};
    
    return {true , 1+max(ls.second , rs.second)};
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return helper(root).first ;
}
```

32. [longest consecutive seq in bt](https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence-in-a-binary-tree_977251?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
pair<int , int> helper(BinaryTreeNode<int> *root , int &maxlen){
    if(not root){
        return {0 , INT_MAX}  ; // {len , element} 
    }
    pair<int,int> ls = helper(root->left , maxlen);
    pair<int,int> rs = helper(root->right , maxlen);
    if(ls.second == root->data+1 and rs.second == root->data+1){
        // nice thing both childrens are greater choose bigger one
        int localmax = max(ls.first , rs.first); 
        maxlen = max(maxlen , 1+localmax);
        return {1+localmax , root->data};
    }
    if(ls.second == root->data+1){
        maxlen = max(maxlen , 1+ls.first);
        return {1+ls.first , root->data};
    }
    if(rs.second == root->data+1){
        maxlen = max(maxlen , 1+rs.first);
        return {1+rs.first , root->data};
    }
    // Im larger than both of my child sad : ( no one will take me further
    return {1 , root->data} ;
}

int maxPath(BinaryTreeNode<int> *root) {
    if(not root) return 0 ;
    int maxlen = 1 ;
    helper(root , maxlen);
    return maxlen ;
}
```

33. [modify bst](https://www.codingninjas.com/codestudio/problems/modify-bst_1233278?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
BinaryTreeNode<int> *modifyTree(BinaryTreeNode<int> *root, int low, int high) {
    if(not root) return NULL ;
    if(root->data < low){
        // may be some of my right are valid 
        return modifyTree(root->right , low , high);
    }
    if(root->data > high){
        return modifyTree(root->left , low , high);
    }
    root->left = modifyTree(root->left , low , high);
    root->right = modifyTree(root->right , low , high);
    return root ;
}
```

34. [flip equivalent bt](https://www.codingninjas.com/codestudio/problems/flip-equivalent-binary-tree_1234687?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
bool flipEquivalent(TreeNode<int> *root1, TreeNode<int> *root2) {
    if(not root1 and not root2) return true ;
    if(not root1 or not root2) return false ;
    if(root1->data != root2->data) return false ;
    
    int op1 = flipEquivalent(root1->left , root2->left) and flipEquivalent(root1->right , root2->right);
    if(op1) return true ;
    int op2 = flipEquivalent(root1->right , root2->left) and flipEquivalent(root1->left , root2->right);
    return op2 ;
}
```

35. [max diff between node and ancestors](https://www.codingninjas.com/codestudio/problems/maximum-difference-between-node-and-ancestor_980227?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
void helper(BinaryTreeNode<int>* root , int maxval , int minval , int &maxdiff){
    if(not root) return ;
    maxdiff = max(maxdiff , abs(root->data - minval));
    maxdiff = max(maxdiff , abs(root->data - maxval));
    helper(root->left , max(maxval , root->data) , min(minval , root->data) , maxdiff);
     helper(root->right , max(maxval , root->data) , min(minval , root->data) , maxdiff);
    
}
int maxAncestorDiff(BinaryTreeNode<int>* root) {
    int maxdiff = 0 ;
    
    if(not root) return 0 ;
    helper(root->left ,root->data , root->data , maxdiff );
    helper(root->right ,root->data , root->data , maxdiff );
    return maxdiff ;
}
```

36. [count nodes](https://www.codingninjas.com/codestudio/problems/count-complete-binary-tree-nodes_982774?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int countNodes(TreeNode<int> *root)
{
    if(not root) return 0 ;
    return 1 + countNodes(root->left) + countNodes(root->right) ;
}
```

37. [corresponding node in bt](https://www.codingninjas.com/codestudio/problems/confusing-number_1235244?topList=top-trees-interview-questions)
```cpp
TreeNode<int>* helper(TreeNode<int> *root , int target){
    if(not root) return NULL ;
    if(root->val == target){
        return root ;
    }
    TreeNode<int>* ls = helper(root->left , target);
    if(ls) return ls ;
    return helper(root->right , target);
}
TreeNode<int>* getCloneNode(TreeNode<int>* original, TreeNode<int>* cloned, TreeNode<int>* node) {
    return helper(cloned , node->val) ;
}
```

38. [closest leaf](https://www.codingninjas.com/codestudio/problems/closest-leaf-to-given-node-in-binary-tree_983627?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
BinaryTreeNode<int> *start ;
void helper(BinaryTreeNode<int> *root, int target ,unordered_map<BinaryTreeNode<int> * ,BinaryTreeNode<int> *> &parents){
    queue<BinaryTreeNode<int> *> q ;
    q.push(root);
    while(not q.empty()){
        root = q.front() ; q.pop() ;
        if(root->data == target){
            start = root ;
        }
        if(root->left){
            parents[root->left] = root ;
            q.push(root->left);
        }
        if(root->right){
            parents[root->right] = root ; 
            q.push(root->right);
        }
    }
}
int findClosestLeafNodeDistance(BinaryTreeNode<int> *root, int x) {
    unordered_map<BinaryTreeNode<int> * ,BinaryTreeNode<int> *> parents ;
    start = NULL ;
    parents[root] = NULL ;
    helper(root , x , parents);
    queue<BinaryTreeNode<int> *> q ;
    q.push(start) ;
    int level = 0 ;
    unordered_set<BinaryTreeNode<int> *> visited ;
    if(not start) return -1 ;
    
    visited.insert(start) ;  
    BinaryTreeNode<int> *pp , *curr ;
    
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            curr = q.front() ; q.pop() ;
            if(not curr->left and not curr->right) return level ;
            if(curr->left and visited.find(curr->left) == visited.end()){
                q.push(curr->left);
                visited.insert(curr->left);
            }
            if(curr->right and visited.find(curr->right) == visited.end()){
                q.push(curr->right);
                visited.insert(curr->right);
            }
            pp = parents[curr];
            if(pp and visited.find(pp) == visited.end()){
                visited.insert(pp);
                q.push(pp);
            }
        }
        level++ ;
    }
    return -1 ;
}
```

39. [sum root to leaf](https://www.codingninjas.com/codestudio/problems/sum-root-to-leaf_1095657?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
long mod = 1e9+7 ;

void helper(BinaryTreeNode<int> *root , long cursum , long &totalsum){
    if(not root) return ;
    cursum = (cursum*10)%mod+root->data ;

    if(not root->left and not root->right){
        totalsum = (totalsum+cursum)%mod ;
        return ;    
    }
    helper(root->left , cursum , totalsum);
    helper(root->right , cursum , totalsum);
}
int rootToLeafSum( BinaryTreeNode<int>* root) {
    long totalsum = 0 ;
    helper(root , 0 , totalsum);
    return totalsum ;
}
```

40. [flatten bt to linked list](https://www.codingninjas.com/codestudio/problems/flatten-binary-tree-to-linked-list_1112615?topList=top-trees-interview-questions)
```cpp
void flatten(TreeNode<int> *root){
    if(not root) return ;
    flatten(root->left) ;
    flatten(root->right) ;
    while(root->left){
        TreeNode<int> *tt = root->right ;
        root->right = root->left ;
        while(root->right){
            root = root->right ;
        }
        root->right = tt ;
        root->left = NULL ;
    }
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    flatten(root);
    return root ;
}
```

41. [path sum 3](https://www.codingninjas.com/codestudio/problems/number-of-ways-for-the-sum-k_1164407?topList=top-trees-interview-questions)
```cpp
#include<bits/stdc++.h>
int target ;

void helper(TreeNode<int> *root , unordered_map<int,int> &memo , int &count , int cursum){
    if(not root) return ;
    cursum = cursum + root->data ;
    count += memo[cursum - target] ;
    memo[cursum]++ ;
    helper(root->left , memo , count , cursum);
    helper(root->right , memo , count , cursum);
    memo[cursum]-- ;
}
int noWays(TreeNode < int > * root, int k) {
    unordered_map<int , int> memo ;
    target = k ;
    memo[0] = 1 ;
    int count = 0 ;
    helper(root , memo , count , 0);
    return count ;
}
```

42. [range sum of bst](https://www.codingninjas.com/codestudio/problems/range-sum-of-bst_1262280?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int low , high ;
void helper(TreeNode<int> *root , int &totalsum){
    if(not root) return ;
    if(root->data > high){
        // may be left side
        helper(root->left , totalsum);
        return ;
    }
    if(root->data < low){
        helper(root->right , totalsum) ;
        return ;
    }
    totalsum += root->data ;
    helper(root->left , totalsum);
    helper(root->right , totalsum);
    
}
int rangeSum(TreeNode<int> *root, int l, int h)
{
    low = l ; high = h ;
    int totalsum = 0 ;
    helper(root , totalsum);
    return totalsum ;
}
```

43. [bst to sorted dll](https://www.codingninjas.com/codestudio/problems/bst-to-sorted-dll_1263694?topList=top-trees-interview-questions&leftPanelTab=0)

```cpp
void helper(TreeNode<int> *root , vector<TreeNode<int>* > &inorder){
    if(not root) return ;
    helper(root->left , inorder);
    inorder.push_back(root);
    helper(root->right ,inorder);
}
TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
    if(not root) return root ;
    vector<TreeNode<int>* > inorder ;
    helper(root , inorder);
    inorder[0]->left = NULL ;
    
    if(inorder.size() > 1){
        inorder[0]->right = inorder[1] ;
    }
    for(int i = 1 ; i < inorder.size()-1 ; i++){
        inorder[i]->left = inorder[i-1] ;
        inorder[i]->right = inorder[i+1] ;
    }
    if(inorder.size() > 1){
        inorder.back()->right = NULL ;
        inorder.back()->left = inorder[inorder.size()-2] ;
    }
    return inorder[0] ;
}

// OPTIMISATION
TreeNode<int> *head ;
void helper(TreeNode<int> *root , TreeNode<int>* &prev){
    if(not root) return ;
    helper(root->left , prev) ;
    if(not head){
        head = root ;
    }
    else{
        prev->right = root ;
        root->left = prev ;
    }
    prev = root ;
    helper(root->right , prev);
}
TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
    if(not root) return root ;
    head = NULL ;
    TreeNode<int> *prev = NULL ;
    helper(root , prev);
    return head ;
}
```

44. [populating next right ptr](https://www.codingninjas.com/codestudio/problems/populating-next-right-pointers-in-each-node_1263696?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
void connectNext(TreeNode<int> *root){
    if(not root) return ;
    queue<TreeNode<int> *> q ;
    q.push(root);
    TreeNode<int> *curr ;
    
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            curr = q.front() ; q.pop() ;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            if(sz != 0){
                curr->next = q.front() ;
            }
        }
    }
}
```

45. [merge bt](https://www.codingninjas.com/codestudio/problems/fasdf_1263729?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
BinaryTreeNode* mergeTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(not root2){
        return root1 ;
    }
    if(not root1){
        return root2 ;
    }
    root1->data += root2->data ;
    root1->left = mergeTrees(root1->left , root2->left) ;
    root1->right = mergeTrees(root1->right , root2->right) ;
    return root1 ;
}
```

46. [print bt](https://www.codingninjas.com/codestudio/problems/print-binary-tree_1266040?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int maxdepth(TreeNode<int> *root){
    if(not root) return 0 ;
    return 1+max(maxdepth(root->left) ,maxdepth(root->right));
}
void helper(int level , int left , int right , TreeNode<int> *root , vector<vector<string>> &mat){
    if(not root) return  ;
    int mid = left + (right - left)/2 ;
    mat[level][mid] = to_string(root->data) ;
    helper(level+1 , left , mid-1 , root->left , mat);
    helper(level+1 , mid+1 , right , root->right , mat);
}

vector<vector<string>> printTree(TreeNode<int> *root) {
    int R = maxdepth(root);
    int C = pow(2 , R) - 1 ;
    vector<vector<string>> mat(R , vector<string>(C , "")) ;
    helper(0 , 0 , C-1 , root , mat);    
    return mat ;
}
```

47. [min cost tree from leaf nodes]()
```cpp
#include<bits/stdc++.h>
int max_arr(vector<int> &arr , int l , int r){
    int max_ele = arr[l] ;
    for(int i = l+1 ; i <= r ; i++){
        max_ele = max(max_ele , arr[i]);
    }
    return max_ele ;
}

int helper(vector<int> &arr , int left , int right , vector<vector<int>> &memo){
    if(left >= right) return 0 ;
    if(memo[left][right] != -1) return memo[left][right] ;
    
    int res = INT_MAX ;
    for(int i = left ; i < right ; i++){
        int left_leaves = max_arr(arr , left , i);
        int right_leaves = max_arr(arr ,i+1 , right);
        
        res = min(res , left_leaves*right_leaves + helper(arr , left , i,memo) + helper(arr , i+1 , right , memo));
    }
    return memo[left][right] = res ;
}
int minimumCostTreeFromLeafNodes(vector<int> &arr){
    vector<vector<int>> memo(arr.size() , vector<int>(arr.size() , -1));
    return helper(arr , 0 , arr.size()-1 , memo);
}
```

48. [distributing coins](https://www.codingninjas.com/codestudio/problems/distributing-coins_1266092?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int moves = 0 ;
int helper(BinaryTreeNode* root){
    if(not root) return  0 ;
    int ls = helper(root->left) ;
    int rs = helper(root->right) ;
    moves += abs(ls) + abs(rs) ;
    return root->data + ls + rs - 1 ;
}
int distributeCoins(BinaryTreeNode* root)
{
    moves = 0 ;
    helper(root);
    return moves ;
}
```

49. [max bt](https://www.codingninjas.com/codestudio/problems/maximum-tree_1266104?topList=top-trees-interview-questions)
```cpp
int maxidx(vector<int> &arr , int l , int r){
    int max_idx = l ;
    for(int i = l+1 ; i <= r ; i++){
        if(arr[max_idx] < arr[i]){
            max_idx = i ;
        }
    }
    return max_idx ;
}
BinaryTreeNode<int> *helper(vector<int> &tree , int l , int r){
    if(l > r) return NULL ;
    if(l == r){
        return new BinaryTreeNode<int>(tree[l]);
    }
    int m_idx = maxidx(tree , l ,r);
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(tree[m_idx]) ;
    root->left = helper(tree , l , m_idx-1);
    root->right = helper(tree , m_idx+1 , r);
    return root ;
}
BinaryTreeNode<int> *constructMaximumBinaryTree(vector<int> &tree, int n) {
    return helper(tree , 0 , n-1);
}
```
50. [bt from inorder and postorder](https://www.codingninjas.com/codestudio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
TreeNode<int>* helper(int left , int right , int &pos , vector<int> &post , unordered_map<int,int> &memo){
    if(left > right) return NULL ;
    if(left == right){
        return new TreeNode<int>(post[pos--]);
    }
    int ele = post[pos--] ;
    TreeNode<int> *root = new TreeNode<int>(ele);
    root->right = helper(memo[ele]+1 , right , pos , post , memo );
    root->left = helper(left , memo[ele]-1 , pos , post , memo);
    return root ;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < inOrder.size() ; i++){
        memo[inOrder[i]] = i ;
    }
    
    int pos = postOrder.size()-1 ;
    return helper(0 , pos , pos , postOrder , memo) ;
}
```

51. [unique bst]()
```cpp
#include<bits/stdc++.h>
unordered_map<int,long long> memo ;

long long int numTrees(int n) 
{
    if(n <= 1) return 1 ;
    if(memo.find(n) != memo.end()) return memo[n] ;
    long long res = 0 ;
    for(int i = 0 ; i < n ; i++){
        res += numTrees(i)*numTrees(n-i-1) ;
    }
    
    return memo[n] = res ;
}
```

52. [ballons game](https://www.codingninjas.com/codestudio/problems/balloons-game_1279641?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int maxval = 0 ; 
int maxele ;
void traverse(Balloons<int> *root , unordered_map<int,int> &memo){
    if(not root) return ;
    memo[root->data]++ ;
    if(memo[root->data] > maxval){
        maxval = memo[root->data] ;
        maxele = root->data ;
    }
    else if(memo[root->data] == maxval){
        maxele = min(maxele , root->data);
    }
    traverse(root->left , memo);
    traverse(root->right , memo);
}

int balloonsGame(Balloons<int> *root)
{
    unordered_map<int,int> memo ;
    maxval = 0 ;
    traverse(root , memo);
    return maxele ;
}
```

53. [break the tree](https://www.codingninjas.com/codestudio/problems/break-the-tree_1279898?topList=top-trees-interview-questions&leftPanelTab=3)
```cpp
long long totalsum = 0 ;
long long maxproduct = 0 ;

void getsum(TreeNode<int> *root){
    if(not root) return ;
    totalsum += root->data ;
    getsum(root->left);
    getsum(root->right);
}

int findMax(TreeNode<int> *root){
    if(not root) return 0 ;
   
    int subtreesum = root->data + findMax(root->left) + findMax(root->right) ;
    long long rem = totalsum - subtreesum ;
    maxproduct = max(maxproduct , rem*(subtreesum));
    return subtreesum ;
}
int maxProduct(TreeNode<int> *root)
{
    totalsum = 0 ;
    maxproduct = 0 ;
    getsum(root);
    findMax(root);
    int mod = 1e9+7 ;
    return maxproduct%mod ;
}
```
54. [insertion in bst](https://www.codingninjas.com/codestudio/problems/insert-into-a-binary-search-tree_1279913?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    if(not root) return new TreeNode<int>(val) ;
    
    if(root->val < val){
        root->right = insertionInBST(root->right , val);
    }
    else{
        root->left = insertionInBST(root->left ,val);
    }
    return root ;
} 
```

55. [bt from pre and post](https://www.codingninjas.com/codestudio/problems/create-a-binary-tree-from-postorder-and-preorder-traversal_1279921?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
Node* build(int l1, int r1, vector<int> &preorder , vector<int> &postorder , unordered_map<int,int> &pre , unordered_map<int,int> &post){
    if(l1 > r1) return NULL ;
    if(l1 == r1) return new Node(preorder[l1]) ;
    
    Node* root = new Node(preorder[l1]) ;
    int middle = pre[postorder[post[preorder[l1]]-1]] ;
    root->left = build(l1+1 , middle-1 ,preorder , postorder , pre,post);
    root->right = build(middle , r1 , preorder , postorder , pre , post);
    return root ;
}
Node* createTreeFromPostPre(vector<int> postorder, vector<int> preorder, int n) {
    unordered_map<int , int> pre ;
    unordered_map<int,int> post ;
    for(int i = 0 ; i < postorder.size() ; i++){
        pre[preorder[i]] = i ;        
        post[postorder[i]] = i ;
    }
    
    return build(0 , n-1 , preorder , postorder , pre , post);
}
```

56. [lca of bt](https://www.codingninjas.com/codestudio/problems/lowest-common-ancestor-of-a-binary-tree-iii_1280134?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

BinaryTreeNode<int> *leastCommonAncestor(BinaryTreeNode<int> *n1, BinaryTreeNode<int> *n2)
{  
    unordered_set<BinaryTreeNode<int> *> arr ;
    while(n1){
        arr.insert(n1);
        n1 = n1->parent ;
    }
    while(n2){
        if(arr.find(n2) != arr.end()) return n2 ;
        n2 = n2->parent ;
    }
    return NULL ;
}
```

57. [equal tree partition](https://www.codingninjas.com/codestudio/problems/equal-tree-partition_1280137?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
long totalsum = 0 ;
long halfsum = 0 ;
void getsum(TreeNode<int> *root){
    if(not root) return ;
    totalsum += root->data ;
    getsum(root->left);
    getsum(root->right);
}
pair<int ,bool> helper(TreeNode<int> *root){
    if(not root) return {0,false} ;
    
    pair<int,bool> ls = helper(root->left);
    if(ls.second) return {0,true};
    pair<int,bool> rs = helper(root->right);
    if(rs.second) return {0 , true};
    int subtreesum = root->data + ls.first + rs.first ;
    if(subtreesum == halfsum) return {0,true};
    return {subtreesum , false};
}

bool checkEqualTree(TreeNode<int> *root) {
    totalsum = 0 ;
    getsum(root);
    if((totalsum&1) == 1) return false ;
    halfsum = totalsum/2 ;
    return helper(root).second ;
}
```

58. [house robber 3](https://www.codingninjas.com/codestudio/problems/amusement-park_1280139?topList=top-trees-interview-questions&leftPanelTab=1)
```cpp
// DP
int helper(BinaryTreeNode<int>* root , bool canIplay , unordered_map<BinaryTreeNode<int> * ,pair<bool , int>> &memo){
    if(not root) return 0 ;
    if(memo.find(root) != memo.end() and memo[root].first == canIplay){
        return memo[root].second ;
    }
    int res = 0 ;
    
    if(canIplay){
        res += root->data ;
        res += helper(root->left , false , memo) + helper(root->right ,false , memo);
    }
    // can't play now
    int notPlay = helper(root->left , true , memo) + helper(root->right , true , memo);
    res = max(res , notPlay);
    memo[root] = {canIplay , res};
    
    return res ;
}

int fun(BinaryTreeNode<int>* root)
{
    unordered_map<BinaryTreeNode<int> * ,pair<bool , int>> memo ;
    return helper(root , true , memo);    
}
// OPTIMISATION
pair<int,int> helper(BinaryTreeNode<int>* root){
    if(not root) return {0,0} ;
    
    pair<int,int> ls = helper(root->left);
    pair<int,int> rs = helper(root->right);
    
    int withRoot = root->data + ls.second + rs.second ;
    int withOutRoot = max(ls.first, ls.second) + max(rs.first , rs.second);
    
    return {withRoot , withOutRoot} ;
}

int fun(BinaryTreeNode<int>* root)
{
    pair<int,int> res = helper(root);
    return max(res.first , res.second);
}
```

59. [check if bt is complete](https://www.codingninjas.com/codestudio/problems/check-whether-binary-tree-is-complete_1280147?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int isCompleteBinaryTree(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q ;
    q.push(root);
    int req_nodes = 1 ;
    while(not q.empty()){
        int nodes_count = 0 ;
        int sz = q.size() ;
        bool null_occured = false ;
        while(sz--){
            TreeNode<int>* root = q.front() ; q.pop() ;
            nodes_count++ ;
            if(root->left){
                if(null_occured) return false ;
                q.push(root->left);
            }
            else null_occured = true ;
            if(root->right){
                if(null_occured) return false ;
                q.push(root->right) ;
            }
            else null_occured = true ;
        }
        if(not q.empty() and nodes_count != req_nodes) return false ;
        req_nodes = req_nodes << 1 ;        
    }
    return 1 ;
}
```

60. [collect leaves](https://www.codingninjas.com/codestudio/problems/collect-leaves_1281192?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
unordered_map<BinaryTreeNode<int> * , int > childcount ;
unordered_map<BinaryTreeNode<int> * ,BinaryTreeNode<int>*> parent ;

void findLeafs(BinaryTreeNode<int> *root , queue<BinaryTreeNode<int> *> &q){
    if(not root) return ;
    if(not root->left and not root->right){
        q.push(root);
        return ;
    }
    if(root->left){
        parent[root->left] = root ;
        childcount[root]++ ;
        findLeafs(root->left , q);        
    }
    if(root->right){
        parent[root->right] = root ;
        childcount[root]++ ;
        findLeafs(root->right , q);
    }
}

vector<vector<int>> collectLeaves(BinaryTreeNode<int> *root) {
    vector<vector<int>> res ;
    if(not root) return res ;
    queue<BinaryTreeNode<int> *> q ;
    childcount.clear() ;
    parent.clear() ;
    parent[root] = NULL ;
    
    findLeafs(root , q );
    while(not q.empty()){
        int sz = q.size() ;
        vector<int> temp ;
        while(sz--){
            root = q.front() ; q.pop() ;
            temp.push_back(root->data) ;
            
            BinaryTreeNode<int>* pp = parent[root] ; 
            if(not pp) continue ;
            childcount[pp]-- ;
            if(childcount[pp] == 0){
                q.push(pp);
            }
        }
        res.push_back(temp);
    }
    return res ;
}
```

61. [nodes in complete bt](https://www.codingninjas.com/codestudio/problems/nodes-in-complete-binary-tree_1281151?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int countNodes(BinaryTreeNode<int> *root) {
    if(not root) return 0 ;
    int ls = 0 , rs = 0 ;
    BinaryTreeNode<int> *l = root , *r = root ;
    while(l){
        ls++ ; l = l->left ;
    }
    while(r){
        rs++ ; r = r->right ;
    }
    if(ls==rs) return (1<<ls)-1 ;
    return 1+countNodes(root->left)+countNodes(root->right) ;
}
```

62. [reduntant connection](https://www.codingninjas.com/codestudio/problems/redundant-connection-i_1281198?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
class DSU{
public:
    vector<int> parent , rank ;
    
    DSU(int nodes){
        parent.resize(nodes,-1);
        rank.resize(nodes , 1);
    }
    
    int find_parent(int node){
        if(parent[node] == -1){
            return node ;
        }
        return parent[node] = find_parent(parent[node]);
    }
    bool union_set(int node1 , int node2){
        int p1 = find_parent(node1) ;
        int p2 = find_parent(node2) ;
        
        if(p1 == p2) return false ;
        
        if(rank[p1] > rank[p2]){
            parent[p2] = p1 ;
            rank[p1] += rank[p2] ;
        }
        else{
            parent[p1] = p2 ;
            rank[p2] += rank[p1] ;
        }
        return true; 
    }
};
vector<int> redundantConnection(vector<vector<int>> &arr)
{
    int nodes = arr.size()+1 ;
    vector<int> res ;
    DSU *obj = new DSU(nodes) ;
    
    for(vector<int>& edge : arr){
        if(not obj->union_set(edge[0] , edge[1])){
            res = edge ;
        }    
    }
    return res ;
}
```
63. [n-aaray level order](https://www.codingninjas.com/codestudio/problems/n-ary-tree-level-order-traversal_1281306?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> levelOrder(TreeNode<int> *root)
{
    vector<int> res ;
    queue<TreeNode<int>* > q ;
    q.push(root);
    
    while(not q.empty()){
            root = q.front() ; q.pop() ;
            res.push_back(root->data);
            for(TreeNode<int>* ch : root->child){
                q.push(ch);
            }
    }
    
    return res ;
}
```

64. [max average of subtree](https://www.codingninjas.com/codestudio/problems/maximum-average-value-of-a-subtree_1281431?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
double maxaverage = INT_MIN ;

pair<int,int> helper(TreeNode<int> *root){
    if(not root) return {0,0} ;
    pair<int,int> ls = helper(root->left);
    pair<int,int> rs = helper(root->right);
    int count = ls.first + rs.first + 1 ;
    
    double avg = (double )(ls.second + rs.second + root->data)/count ;
    maxaverage = max(maxaverage , avg) ;
    return {count,ls.second+rs.second+root->data} ;
}

double maxSubtreeAverage(TreeNode<int> *root) {
    maxaverage = INT_MIN ;
    helper(root);
    
    return maxaverage ;
}
```

65. [find k closest nodes](https://www.codingninjas.com/codestudio/problems/k-closest-values_1281852?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int last_min = 0 ;

void helper(TreeNode<int> *root , vector<int> &arr , int target){
    if(not root){
        return ;
    }
    helper(root->left , arr , target);
    arr.push_back(root->val);
    if(arr.back() < target){
        last_min = arr.size()-1 ;
    }
    helper(root->right , arr , target);
}
vector<int> kClosestValues(TreeNode<int> *root, double target, int k) {
    vector<int> arr ;
    last_min = -1 ;
    helper(root , arr , target);
    int left_ptr = last_min , right_ptr = last_min+1 ;
    
    vector<int> res ;
    while(k--){
        if(left_ptr == -1){
            res.push_back(arr[right_ptr++]);
        }
        else if(right_ptr == arr.size()){
            res.push_back(arr[left_ptr--]);
        }
        else{
            double diff1 = target - arr[left_ptr] ;
            double diff2 = arr[right_ptr] - target;
            
            if(diff1 <= diff2){
                res.push_back(arr[left_ptr--]);
            }
            else{
                res.push_back(arr[right_ptr++]) ;
            }
        }
    }
    sort(res.begin() , res.end());
    return res ;
}
```
66. [flip tree](https://www.codingninjas.com/codestudio/problems/upside-down-binary-tree_1281853?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
TreeNode<int>* flipTree(TreeNode<int> *root){
   if(not root) return NULL ;
    if(not root->left) return root ;
    TreeNode<int>* newRoot = flipTree(root->left) ;
    root->left->left = root->right ;
    root->left->right = root ;
    root->left = NULL ;
    root->right = NULL ;
    return newRoot ;
}
```
67. [build binary expression from infix](https://www.codingninjas.com/codestudio/problems/build-binary-expression-tree-from-infix-expression_1281854?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int prec(char ch){
    if(ch == '+' or ch == '-') return 1 ;
    if(ch == '*' or ch == '/') return 2 ;
    if(ch == '^' ) return 3 ;
    return 0 ;
}

string buildPost(string &infix){
    stack<char> operators ;
    string postfix = "" ;
    for(char ch : infix){
        if(isdigit(ch)){
            postfix.push_back(ch);
        }
        else if(ch == '('){
            operators.push('(');
        }
        else if(ch == ')'){
            while(operators.top() != '('){
                postfix.push_back(operators.top()) ; operators.pop() ;
            }
            operators.pop() ;
        }
        else{
            while(not operators.empty() and prec(ch) <= prec(operators.top())){
                postfix.push_back(operators.top()) ; operators.pop() ;
            }
            operators.push(ch);
        }
    }
    while(not operators.empty()){
         postfix.push_back(operators.top()) ; operators.pop() ;
    }
    return postfix ;
}
BinaryTreeNode<char> *binaryExpressionTree(string s)
{
    string postfix = buildPost(s);
    stack<BinaryTreeNode<char> *> st ;
    for(char ch : postfix){
        if(isdigit(ch)){
            st.push(new BinaryTreeNode<char>(ch));
        }
        else{
            BinaryTreeNode<char>* op = new BinaryTreeNode<char>(ch);
            op->right = st.top() ; st.pop() ;
            op->left = st.top() ; st.pop() ;
            st.push(op);
        }
    }
    return st.top() ;
}
```
68. [ntree to bt](https://www.codingninjas.com/codestudio/problems/encode-n-ary-tree-to-binary-tree_1281859?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp

BTreeNode < int > * encode(NTreeNode < int > * root) {
    if(not root) return NULL ;
    BTreeNode<int> *newroot = new BTreeNode<int>(root->val);
    if(root->child.size() == 0) return newroot ;
    
    newroot->left = encode(root->child[0]);
    BTreeNode<int>* curr = newroot->left ;
    for(int i = 1 ; i  < root->child.size() ; i++){
       curr->right = encode(root->child[i]);
       curr = curr->right ;
    }
    return newroot ;
}

NTreeNode < int > * decode(BTreeNode < int > * root) {
    if(not root) return NULL ;
    NTreeNode<int> *newroot = new NTreeNode<int>(root->val);
    BTreeNode<int> *curr = root->left ;
    while(curr){
        newroot->child.push_back(decode(curr));
        curr = curr->right ;
    }
    return newroot ;
}
```
69. [all bt](https://www.codingninjas.com/codestudio/problems/all-binary-trees_1354157?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
vector<BinaryTreeNode<int> *> build(int left , int right ,  vector<vector<vector<BinaryTreeNode<int>* >>> &memo){
    if(left > right) return {} ;
    if(left == right) return {new BinaryTreeNode<int>(0)};
    if(memo[left][right].size() != 0) return memo[left][right] ;
    
    vector<BinaryTreeNode<int>* > res ;
    
    for(int i = left+1 ; i <= right ; i += 2){
        vector<BinaryTreeNode<int>* > ls = build(left+1 , i , memo);
        vector<BinaryTreeNode<int>* > rs = build(i+1 , right , memo);
        for(BinaryTreeNode<int>* l1 : ls){
            for(BinaryTreeNode<int>* r1 : rs){
                BinaryTreeNode<int>* root = new BinaryTreeNode<int>(0) ;
                root->left = l1 ;
                root->right = r1 ;
                res.push_back(root);
            }
        }
    }
    return memo[left][right] = res ;
}
vector<BinaryTreeNode<int>*> findAllTrees(int n) {
    vector<vector<vector<BinaryTreeNode<int>* >>> memo(n , vector<vector<BinaryTreeNode<int>* >>(n) )  ;
    vector<BinaryTreeNode<int>*> res;
    return build(0 , n-1 , memo) ;
}

// OPTIMISATION
#include<bits/stdc++.h>
unordered_map<int , vector<BinaryTreeNode<int>*> > memo;
vector<BinaryTreeNode<int> *> build(int n){
    if(n == 1) return {new BinaryTreeNode<int>(0)};
    if(memo.find(n) != memo.end()) return memo[n] ;
    vector<BinaryTreeNode<int>* > res ;
    
    for(int i = 1 ; i < n ; i += 2){
       int right = n-i-1 ;
       for(BinaryTreeNode<int> *l1 : build(i)){
           for(BinaryTreeNode<int> *r1 : build(right)){
               BinaryTreeNode<int> *root= new BinaryTreeNode<int>(0);
               root->left = l1 ;
               root->right = r1 ;
               res.push_back(root) ;
           }
       }
    }
    return memo[n] = res ;
}
vector<BinaryTreeNode<int>*> findAllTrees(int n) {
    memo.clear();
    return build(n) ;
}
```

69. [grandparents](https://www.codingninjas.com/codestudio/problems/ninja-grandparents_1376418?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int totalsum = 0 ;
void helper(TreeNode<int>* root , int parent , int grandparent){
    if(not root) return ;
    if((grandparent&1) == 0){
        totalsum += root->data ;
    }
    helper(root->left , root->data , parent);
    helper(root->right , root->data, parent);
}
int ninjaGrandparents(TreeNode<int> *root)
{
    totalsum = 0 ;
    helper(root , 1 , 1) ;
    return totalsum ;
}
```

70. [ninja encryption 2](https://www.codingninjas.com/codestudio/problems/ninja-s-encryption_1376419?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int calc(char op , int ele1 , int ele2){
    if(op == '+') return ele1+ele2 ;
    if(op == '-') return ele1-ele2 ;
    if(op == '*') return ele1*ele2 ;
    if(op == '/') return ele1/ele2 ;
    return 0 ;
}
int ninjaEncryption(Encryption<string> *root) {
    if(not root) return 0 ;
    if(not root->left and not root->right){
        return stoi(root->data);
    }
    int ls = ninjaEncryption(root->left) ;
    int rs = ninjaEncryption(root->right) ;
    
    return calc(root->data[0] ,ls , rs);
}
```

71. [ninja and his girlfriend](https://www.codingninjas.com/codestudio/problems/ninja-and-his-girlfriend_1376433?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int mindiff , pre ;
void helper(TreeNode<int> *root){
    if(not root) return ;
    helper(root->left);
    if(pre != INT_MAX){
        mindiff = min(mindiff , root->data - pre);
    }
    pre = root->data ;
    helper(root->right);
}
int ninjaGf(TreeNode<int> *root)
{
    mindiff = 1e9+7 ;
    pre = INT_MAX ;
    helper(root);
    return mindiff ;
}
```

72. [split bst](https://www.codingninjas.com/codestudio/problems/split-bst_1376434?topList=top-trees-interview-questions)
```cpp
vector<TreeNode<int>* > splitBST (TreeNode<int>* root, int value)
{
    if(not root) return {NULL , NULL} ;
    if(root->val == value){
        TreeNode<int>* greater = root->right ;
        root->right = NULL ;
        return {root , greater};
    }
    else if(root->val  < value){
        vector<TreeNode<int>* > rs = splitBST(root->right , value);
        root->right = rs[0] ;
        return {root , rs[1]};
    }
    vector<TreeNode<int>* > rs = splitBST(root->left , value);
    root->left = rs[1] ;
    return {rs[0] , root} ;
}
```
73. [reorder edges](https://www.codingninjas.com/codestudio/problems/reorder-edges_1376443?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int reorderEdges(int n, vector<vector<int>> &edgeList) {
    int min_ops = 0 ;
    unordered_set<int> can_reach ;
    int reached = 1 ;
    
    for(vector<int> &edge : edgeList){
        if(edge[0] == 0){
            min_ops++ ;
            can_reach.insert(edge[1]);
            reached++ ;
            edge[0] = edge[1] ;
            edge[1] = 0 ;
        }    
        else if(edge[1] == 0){
            can_reach.insert(edge[0]);
            reached++ ;
        }
    }
    while(reached < n){
        for(vector<int> &edge : edgeList){
            if(can_reach.find(edge[1]) != can_reach.end()){
                reached++ ;
                can_reach.insert(edge[0]);
                edge[1] = 0 ;
            }
            else if(edge[1] != 0 and can_reach.find(edge[0]) !=can_reach.end()){
                min_ops++ ;
                can_reach.insert(edge[1]);
                reached++ ;
                edge[0] = edge[1] ;
                edge[1] = 0 ;
            }
        }
    }
    return min_ops ;
}
```
74. [find sum of left leaves](https://www.codingninjas.com/codestudio/problems/find-the-sum-of-the-left-leaves_1376446?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int totalsum ;
void helper(TreeNode<int> *root , bool isLeft){
    if(not root) return ;
    if(not root->left and not root->right){
        if(isLeft) totalsum += root->val ;
        return ;
    }
    helper(root->left , true);
    helper(root->right , false);
}
int sumOfLeftLeaves(TreeNode<int> *root)
{
    totalsum = 0 ;
    helper(root , false);
    return totalsum ;
}
```

75. [find special nodes](https://www.codingninjas.com/codestudio/problem-lists/top-trees-interview-questions?page=4)
```cpp
void helper(TreeNode<int> *root , bool isspecial , vector<int> &res){
    if(not root) return ;
    if(isspecial){
        res.push_back(root->val);    
    }
    if(not root->left){
        helper(root->right , true , res);
    }
    else if(not root->right){
        helper(root->left , true , res);
    }
    else{
        helper(root->left , false , res);
        helper(root->right ,false , res);
    }
}
vector<int> findSpecialNodes(TreeNode<int> *root) {
    vector<int> res ;
    
    helper(root , false , res);
    return res ;
}
```

76. [serialize and deserialize bst](https://www.codingninjas.com/codestudio/problems/serialize-and-deserialize-bst_1376612?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
void helper(TreeNode<int>* root , string &serialized){
    serialized.push_back(',');
    if(not root){
        serialized.push_back('#');
        return ;
    }
    serialized += to_string(root->data);
    helper(root->left , serialized);
    helper(root->right , serialized);
}
// Serialization
string serializeTree(TreeNode<int>* root)
{
    string serialized = "" ;
    helper(root , serialized);
    return serialized.substr(1);
}
TreeNode<int>* helperd(vector<string> &data , int &pos){
    
    if(pos == data.size()) return NULL ;
    if(data[pos] == "#"){
        pos++ ;
        return NULL ;
    }
    TreeNode<int> *root = new TreeNode<int>(stoi(data[pos]));
    pos++ ;
    root->left = helperd(data , pos);
    root->right = helperd(data , pos);
    return root ;
}
// Deserialization
TreeNode<int>* deserializeTree(string &data)
{
    vector<string> arr ;
    stringstream ss(data);
    string temp ;
    while(getline(ss , temp , ',')){
        arr.push_back(temp);
    }
    int pos = 0 ;
    return helperd(arr ,pos);
}
```
77. [second value in bt](https://www.codingninjas.com/codestudio/problems/second-minimum-node-in-a-binary-tree_1376617?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int mini ;
int ans ;
void helper(TreeNode<int> *root){
    if(not root) return ;
    if(root->data > mini and ans > root->data){
        ans = root->data ;
        return ;    
    }
    helper(root->left);
    helper(root->right);
}
int secondMinimumNode(TreeNode<int> *root)
{
    if(not root) return -1 ;
    mini = root->data ;
    ans = INT_MAX ;
    helper(root);
    return (ans == INT_MAX)?-1:ans ;
}
```
78. [bt max path sum](https://www.codingninjas.com/codestudio/problems/binary-tree-maximum-path-sum_1280142?topList=top-trees-interview-questions&leftPanelTab=0)
```cpp
int ans ;

int helper(TreeNode<int>* root){
 if(not root) return 0 ;
    int ls = helper(root->left);
    int rs = helper(root->right);
    int localmax = max(root->val , root->val+ls);
    localmax = max(localmax , root->val+rs);
    localmax = max(localmax , root->val+ls+rs);
    ans = max(ans , localmax);
    
    return max({root->val , root->val+ls , root->val+rs});
    
}
int maxPathSum(TreeNode<int>* root)
{
   if(not root) return -1 ;
   ans = root->val ;
   helper(root);
   return ans ;
}
```

79. [serialize and deserialize n array tree](https://www.codingninjas.com/codestudio/problems/serialize-and-deserialize-an-n-ary-tree_1376416?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>
void serialize(TreeNode<int> *root , string &res){
    res += "," + to_string(root->data) ;
    for(TreeNode<int> *ch : root->child){
        serialize(ch , res);
    }
    res+= ",#" ;
} 
TreeNode<int> *deserialize(int &pos , vector<string> &arr){
    if(arr[pos] == "#") return NULL ;
    TreeNode<int> *root = new TreeNode<int>(stoi(arr[pos++]));
    while(true){
        TreeNode<int> *child = deserialize(pos , arr);
        if(child == NULL) break ;
        root->child.push_back(child);
    }
    pos++ ;
    return root ;
}
TreeNode<int> *SerDeser(TreeNode<int> *root)
{
    string res = "" ;
    serialize(root , res);
    res = res.substr(1) ;
    vector<string> arr ;
    string tt ;
    stringstream ss(res);
    while(getline(ss , tt , ',')){
        arr.push_back(tt);
    }
    int pos = 0 ;
    return deserialize(pos , arr);
}
```