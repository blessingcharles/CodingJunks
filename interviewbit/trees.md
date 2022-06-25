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