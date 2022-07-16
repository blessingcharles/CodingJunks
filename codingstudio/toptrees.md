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