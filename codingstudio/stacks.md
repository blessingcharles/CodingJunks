1. [reverse ll](https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897?leftPanelTab=1)
```cpp
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   LinkedListNode<int>* prev = NULL , *curr = head , *nxt = NULL ;
   while(curr){
       LinkedListNode<int>* temp = curr->next ;
       curr->next = prev ;
       prev = curr ;
       curr = temp ;
   }
   return prev ;
}
```

2. [reverse stack recursion](https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0)
```cpp
void insert(stack<int> &st , int curr){
    if(st.size() == 0){
        st.push(curr);
        return ;
    }
    int val = st.top() ; st.pop() ;
    insert(st , curr);
    st.push(val);
}
void reverseStack(stack<int> &st) {
    if(st.empty()) return ;
    int curr = st.top() ; st.pop() ;
    reverseStack(st) ;
    insert(st , curr);
}
```

3. [rearrange string](https://www.codingninjas.com/codestudio/problems/rearrange-string_985247?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

string rearrangeString(string &str) {
    priority_queue<pair<int,int>> pq ;
    unordered_map<char , int> memo ;
    
    for(int i = 0; i < str.size() ; i++){
        memo[str[i]]++ ;        
    }
    for(auto it = memo.begin() ; it != memo.end() ; it++){
        pq.push({it->second , it->first});
    }
    string res = "" ;
    
    while(not pq.empty()){
        pair<int,int> tt = pq.top() ; pq.pop() ;
        if(res.size() != 0 and tt.second == res.back()){
            //find current top ele 
            if(pq.empty()) return "NO SOLUTION" ;
            pair<int,int> second_one = pq.top() ; pq.pop() ;
            res.push_back(second_one.second);
            if(second_one.first-1 > 0){
                pq.push({second_one.first-1 ,second_one.second});
            }
        }
        res.push_back(tt.second);

        if(tt.first-1 > 0){
            pq.push({tt.first-1 , tt.second});
        }
    }
    return res ;
}
```

4. [implement a queue](https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0)
```cpp
class Node{
public:
     int data ;
    Node* next ;
    Node(int data){
        this->data = data ;
        this->next = NULL ; 
    }
};

class Queue {
public:
    Node* head , *tail ;
    Queue() {
        head = NULL ;
        tail = NULL ;
    }
    
    bool isEmpty() {
        return (head == NULL) ;
    }

    void enqueue(int data) {
        Node* newnode = new Node(data);
        if(not head){
            head = newnode ;
            tail = newnode ;
        }   
        else{
            tail->next = newnode ;
            tail = newnode ;
        }
    }

    int dequeue() {
        if(isEmpty()) return -1 ;
        Node* ff = head ; 
        head = head->next ;
        int data = ff->data ; delete ff ;
        return data ;
    }
    int front() {
         if(isEmpty()) return -1 ;
         return head->data ;
    }
};
```

5. [sort a stack](https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0)
```cpp
void insert(stack<int> &st , int curr){
    if(st.empty()){
        st.push(curr);
        return ;
    }
    if(st.top() > curr){
        int ele = st.top() ; st.pop() ;
        insert(st , curr);
        st.push(ele);
        return ;
    }
    st.push(curr);
    return ;
}

void sortStack(stack<int> &st)
{
    if(st.empty()) return ;
    
	int curele = st.top() ; st.pop() ;
    sortStack(st);
    insert(st , curele);
}
```

6. [next greater element](https://www.codingninjas.com/codestudio/problems/next-greater-element_799354?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st ;
    vector<int> res(n , -1) ;
    
    for(int i = n-1 ; i >= 0 ; i--){
        while(not st.empty() and st.top() <= arr[i]){
            st.pop() ;
        }
        if(not st.empty()){
            res[i] = st.top() ;
        }
        st.push(arr[i]);
    }
    return res ;
}
```

7. [ll palindrome](https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352?leftPanelTab=0)
```cpp

LinkedListNode<int>* getMid(LinkedListNode<int> *head){
    LinkedListNode<int>* fast = head->next ;
    while(fast and fast->next){
        fast = fast->next->next ;
        head = head->next ;
    }
    return head->next ;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(not head or not head->next) return true ;
    // Write your code here.
    LinkedListNode<int>* mid = getMid(head);
    stack<int> st ;
    while(mid){
        st.push(mid->data);
        mid = mid->next ;
    }
    while(not st.empty()){
        if(st.top() != head->data) return false ;
        st.pop() ;
        head = head->next ;
    }
    return true ;
}
```

8. [valid parenthesis](https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=1)
```cpp
bool isValidParenthesis(string expression)
{
    stack<char> st ;
    
    for(char ch : expression){
        if(ch == '[' or ch == '{' or ch == '('){
            st.push(ch) ;
        }
        else{
            if(st.empty()) return false ;
            if(ch == ']'){
                if(st.top() != '[') return false ;
                st.pop() ;
            }
            else if(ch == '}'){
                if(st.top() != '{') return false ;
                st.pop() ;
            }
            else{
                if(st.top() != '(') return false ;
                st.pop() ;
            }
        }
    }
    
    return (st.empty())?true:false ;
}
```
9. [delete middle ele from stack](https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0)
```cpp
void helper(stack<int> &st , int N , int mid){
    if(st.empty()){
        return ;
    }
    int ele = st.top() ; st.pop() ;
    helper(st , N+1 , mid);
    if(N != mid){
        st.push(ele);
    }
}

void deleteMiddle(stack<int>& st, int N){
	
   // Write your code here
    int mid = N/2 ;
    helper(st , 0 , mid);
}   
```

10. [two stacks in an array](https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class TwoStack {
public:
    vector<int> st ;
    int top1 , top2 ;
    
    TwoStack(int s) {
        top1 = -1 ;
        top2 = s ;
        st.resize(s);       
    }
    bool isEmpty(int st_no){
        if(st_no == 1) return (top1 == -1) ;
        return (top2 == st.size()) ;
    }
    bool isFull(){
        return (top2-top1 == 1) ;            
    }
    // Push in stack 1.
    void push1(int num) {
        if(isFull()) return ;
        top1++ ;
        st[top1] = num ;
    }
    // Push in stack 2.
    void push2(int num) {
        if(isFull()) return ;
        top2-- ;
        st[top2] = num ;
    }
    // Pop from stack 1 and return popped element.
    int pop1() {
        if(isEmpty(1)) return -1 ;
        int ele = st[top1] ;
        top1-- ;
        return ele ;
    }
    // Pop from stack 2 and return popped element.
    int pop2() {
        if(isEmpty(2)) return -1 ;
        int ele = st[top2] ;
        top2++ ;
        return ele ;
    }
};
```
11. [n stacks in an array](https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0)
```cpp
class NStack
{
   int *arr;
    int *top;
    int *next;
    
    int n, s;
     
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
        
    }

    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        
        //find index
        int index = freespot;
        
        //insert element into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};
```
12. [redundant brackets]()
```cpp
#include<bits/stdc++.h>

bool isOperators(char ch){
    return (ch == '+') or (ch == '-') or (ch == '*') or (ch == '/') ;
}

bool findRedundantBrackets(string &s)
{
    stack<char> st ;
    for(char ch : s){
        if(ch != ')'){
            st.push(ch);
        }
        else{
            bool f_operators = false ;
            while(not st.empty()){
                char tt = st.top() ; st.pop() ;
                if(tt == '(') break ;
                if(isOperators(tt)){
                    f_operators = true ;
                }
            }
            if(not f_operators) return true ;
        }
    }
    return false ;
}
```

13. [lru cache](https://www.codingninjas.com/codestudio/problems/lru-cache-implementation_670276?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class LRUCache
{
public:
unordered_map<int , list<pair<int,int>>::iterator > memo ;
    list<pair<int,int>> dl ;
    int capacity ;
    
    LRUCache(int capacity)
    {
        this->capacity = capacity ;
    }
    int get(int key){
         unordered_map<int , list<pair<int,int>>::iterator>::iterator it = memo.find(key) ;
        
        if(it == memo.end())
            return -1 ;
        
        dl.splice(dl.begin() ,dl,it->second);
        return it->second->second ;
        
    }
    void put(int key, int value){
          unordered_map<int , list<pair<int,int>>::iterator>::iterator it = memo.find(key);
        if(it != memo.end()){
            it->second->second = value ;
            dl.splice(dl.begin() , dl , it->second);
            return ;
        }
        if(memo.size() == capacity){
            memo.erase(dl.back().first) ;
            dl.pop_back() ;
        }
        dl.push_front({key,value});
        memo[key] = dl.begin();
        
    }
};
```

14. [largest rectangle in histogram](https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int largestRectangle(vector<int> & heights) {
    stack<pair<int,int>> st ; // value , pos
    st.push({0 , -1});
    int N = heights.size() ;
    pair<int,int> curr ;
    int max_area = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        int max_left = i ;
        
        while(not st.empty() and heights[i] <= st.top().first){
            curr = st.top() ; st.pop() ;
            max_area = max(max_area , curr.first*(i-curr.second));
            max_left = curr.second ;    
        }
        st.push({heights[i] , max_left});
    }
    
    while(not st.empty()){
        curr = st.top() ; st.pop() ;
        max_area = max(max_area , curr.first*(N-curr.second));
    }
    return max_area ;
}
```

15. [min cost to make str valid](https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int findMinimumCost(string str) {
  // Write your code here
    if((str.size()&1) == 1) return -1 ;
    stack<char> st ;
    // }}{{
    int ops = 0 ;
    
    for(char ch : str){
        if(ch == '{') st.push('{');
        else{
            if(not st.empty()) st.pop() ;
            else{
                ops++ ;
                st.push('{');
            }
        }
    }
    while(not st.empty()){
        ops++ ;
        st.pop() ; st.pop() ;
    }
    return ops ;
}
```

16. [minStack](https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class SpecialStack {
    public:
    stack<int> minStack ;
    stack<int> st ;
    
    void push(int data) {
        st.push(data);
        if(minStack.empty() or minStack.top() >= data){
            minStack.push(data);
        }
    }
    int pop() {
        if(isEmpty()) return -1 ;
        if(minStack.top() == st.top()){
            minStack.pop() ;
        }
        int ele = st.top() ; st.pop() ;
        return ele ;
    }

    int top() {
        return st.top() ;
    }
    bool isEmpty() {
        return st.empty() ;
    }
    int getMin() {
        if(isEmpty()) return -1 ;
        
        return minStack.top() ;
    }  
};
```

17. [diagonal sum](https://www.codingninjas.com/codestudio/problems/diagonal-sum_790722?leftPanelTab=0)
```cpp
#include <bits/stdc++.h>

void helper(BinaryTreeNode<int>* root,unordered_map<int,long long> &memo , int &maxlevel ,int marker){
    if(root == NULL) return ;
    maxlevel = max(maxlevel , marker);
    memo[marker] += root->data ;
    
    helper(root->left , memo , maxlevel , marker+1);
    helper(root->right , memo , maxlevel , marker);
    
}

vector < long long > diagonalSum(BinaryTreeNode < int >* root) {
    if(not root) return {} ;
    
    unordered_map<int , long long> memo ;
    int maxlevel = 0 ;
    helper(root , memo , maxlevel , 0);
    vector<long long> ans(maxlevel+1);
    for(int i = 0 ; i <= maxlevel ; i++){
        ans[i] = memo[i];
    }
    return ans ;
}
```

18. [insert at bottom](https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0)
```cpp
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int> myst ;
    while(not myStack.empty()){
        myst.push(myStack.top()) ; myStack.pop() ;
    }
    myStack.push(x);
    while(not myst.empty()){
        myStack.push(myst.top()) ; myst.pop() ;
    }
    return myStack ;
}
```

19. [max of all subarray k](https://www.codingninjas.com/codestudio/problems/maximum-of-all-subarrays-of-size-k_1071161?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> maximumInAllSubarraysOfSizeK(vector<int> arr, int n, int k)
{
    deque<int> st ;
    
    for(int i = 0 ; i < k ; i++){
        while(not st.empty() and arr[st.back()] <= arr[i]){
            st.pop_back();
        }
        st.push_back(i);
    }
    int right = k ;
    vector<int> ans ;
    ans.push_back(arr[st.front()]);
    int left = 0 ;
    
    while(right < n){
        //remove the left side
        if(not st.empty() and st.front() == left){
            st.pop_front() ;
        }
        
        while(not st.empty() and arr[st.back()] <= arr[right]){
            st.pop_back();
        }
        st.push_back(right);  
        ans.push_back(arr[st.front()]);
        right++ ; left++ ;
    }
    return ans ;
}   
```

20. [remove consecutive duplicates](https://www.codingninjas.com/codestudio/problems/remove-consecutive-duplicates-from-string_630473?leftPanelTab=0)
```cpp
string removeConsecutiveDuplicates(string str) 
{
    string res = "" ;
    res.push_back(str[0]);
    int N = str.size() ;
    
    for(int i = 1 ; i < N ; i++){
        while(i < N and str[i] == str[i-1]) i++ ;
        if(i < N){
            res.push_back(str[i]);
        }
    }
    return res ;
}
```

21. [bst iterator](https://www.codingninjas.com/codestudio/problems/bst-iterator_1112601?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class BSTiterator
{
public:
    vector<int> arr ;
    int ptr = 0 ;
    void helper(TreeNode<int> *root){
        if(not root) return ;
        helper(root->left);
        arr.push_back(root->data);
        helper(root->right);
    }
    
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        helper(root); ptr = 0 ;
    }

    int next()
    {
        return arr[ptr++] ;
    }

    bool hasNext()
    {
        return (ptr < arr.size());
    }
};
```

22. [mirror tree](https://www.codingninjas.com/codestudio/problems/convert-binary-tree-to-mirror-tree_873140?leftPanelTab=0)
```cpp
BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root){
    if(not root) return NULL ;
    BinaryTreeNode<int>* temp = root->left ;
    root->left = helper(root->right);
    root->right = helper(temp);
    return root ;
}
void mirrorTree(BinaryTreeNode<int> *root) {
    root = helper(root);
}
```
23. [odd even diff](https://www.codingninjas.com/codestudio/problems/odd-even-level_794960?leftPanelTab=0)
```cpp
void evenOddLevelDifference(BinaryTreeNode<int>* root){
    if(not root){
        cout << 0 << endl ;
        return ;
    }
    int level = 0 ; 
	queue<BinaryTreeNode<int>* > q ;
    q.push(root);
    long long oddsum = 0 , evensum = 0 ;
    BinaryTreeNode<int>* curr ;
    
    while(not q.empty()){
        int sz = q.size() ;
        long long cursum = 0 ;
        while(sz--){
            curr = q.front() ; q.pop() ;
            cursum += curr->data ;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        if((level&1) == 1) oddsum += cursum ;
        else evensum += cursum ;
        level++ ;
    }
    cout << abs(oddsum-evensum) << endl ;
}
```
24. [sort stack](https://www.codingninjas.com/codestudio/problems/abc_1229513?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

void insert(stack<int> &st , int curr){
    if(st.empty() or st.top() <= curr){
        st.push(curr);
        return ;
    }
    int tt = st.top() ; st.pop() ;
    insert(st , curr);
    st.push(tt);
}
void helper(stack<int> &st){
    if(st.empty()) return ;
    int curr_ele = st.top() ; st.pop() ;
    helper(st);
    insert(st , curr_ele);
}
stack<int> sortStack(stack<int> &s)
{
   	helper(s);
    return s ;
}
```

25. [max equal stack sum](https://www.codingninjas.com/codestudio/problems/maximum-equal-stack-sum_1062571?leftPanelTab=0)
```cpp
int getSum(stack<int> st){
    int cursum = 0 ;
    while(not st.empty()){
        cursum += st.top() ; st.pop() ;
    }
    return cursum ;
}

int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3) {
    int sum1 = getSum(stk1);
    int sum2 = getSum(stk2) ;
    int sum3 = getSum(stk3) ;
    
    int minsum = min({sum1 , sum2 , sum3});
    while(true){
        if(sum1 > minsum){
            sum1 -= stk1.top() ; stk1.pop() ;
        }
        if(sum2 > minsum){
            sum2 -= stk2.top() ; stk2.pop() ;
        }
        if(sum3 > minsum){
            sum3 -= stk3.top() ; stk3.pop() ;
        }
        if(sum1 == sum2 and sum2 == sum3) break ;
        minsum = min({sum1 , sum2 , sum3});
    }
    return sum1 ;
}
```

26. [interleave queue](https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0)
```cpp
void interLeaveQueue(queue < int > & q) {
    vector<int> arr ;
    while(not q.empty()){
        arr.push_back(q.front()) ; q.pop() ;
     }
    int N = arr.size() ;
    int mid = N/2 ;
    int right = mid , left = 0;
    while(right < N){
       q.push(arr[left++]);
        q.push(arr[right++]);
    }
}
```
27. [stack permutation](https://www.codingninjas.com/codestudio/problems/valid-stack-permutation_1170061?leftPanelTab=0)
```cpp
bool validStackPermutation(vector<int> &first, vector<int> &other){
	stack<int> st ;
    int ptr1 = 0 , N = other.size();
    
    for(int ele : first){
        st.push(ele);
        while(not st.empty() and other[ptr1] == st.top()){
            st.pop() ; ptr1++ ;
        }
    }
    return ptr1 == N ;
}
```

28. [connect n ropes](https://www.codingninjas.com/codestudio/problems/connect-n-ropes-with-minimum-cost_630476?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

long long connectRopes(int* arr, int n)
{
    priority_queue<long long , vector<long long> , greater<long long>> pq ;
    for(int i = 0 ; i < n ; i++){
        pq.push(arr[i]);
    }
    
    long long cursum = 0 ;
    while(pq.size() > 1){
        long long r1 = pq.top() ; pq.pop() ;
        long long r2 = pq.top() ; pq.pop() ;
        cursum = cursum + r1+r2 ;
        pq.push(r1+r2);
    }
    return cursum ;
}
```

29. [max stack](https://www.codingninjas.com/codestudio/problems/max-stack_985280?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class MaxStack {
public:    	
	stack<int> st ;
    stack<int> m_st ;
    
	MaxStack() {
		// Write your code here.
	}
	
	void specialPush(int value) {
        st.push(value);
        if(m_st.empty() or value >= m_st.top()){
            m_st.push(value);
        }
    }
    bool isEmpty(){
        return st.empty() ;
    }
    
	// Return the popped value.
	int specialPop() {
        if(isEmpty()){
            return -1 ;
        }
        int ele = st.top() ; st.pop();
        if(m_st.top() == ele) m_st.pop();
        return ele ;
    }

	// Return value at the top of stack.
	int specialTop() {
        if(isEmpty()) return -1 ;
        return st.top() ;
    }

	// Return maximum value in stack.
	int specialMax() {
        if(isEmpty()) return -1 ;
        return m_st.top() ;        
	}
};
```

30. [Evaluate Postfix]()
```cpp
bool isOperator(char ch){
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' ;
}
int mod = 1e9+7 ;

int calc(long num1 , long num2 , char op){
    if(op == '+'){
        return (num1+num2)%mod ;
    }   
    else if(op == '-'){
        return (num1-num2) ;
    }
    else if(op == '*'){
        return (num1*num2)%mod ;
    }
    else{
        return (num1/num2) ;
    }
    return 0 ;
}

int evaluatePostfix(string &exp) {
    stack<string> st ;
    int N = exp.size() ;
    if(N == 0) return 0 ;
    
    for(int i = 0 ; i < N ; i++){
        if(isOperator(exp[i])){
            long num2 = stol(st.top()) ; st.pop() ;
            long num1 = stol(st.top()) ; st.pop() ;
            
            int res = calc(num1 , num2 , exp[i]);
            st.push(to_string(res));
            i++ ;
        }
        else{
            //build the digits untill space character occurs
            string num = "" ;
            while(i < N and exp[i] != ' '){
                num.push_back(exp[i++]);
            }
            st.push(num);
        }
    }
    return stoi(st.top());
}
```

31. [online stock span](https://www.codingninjas.com/codestudio/problems/span-of-ninja-coin_1475049?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
    stack<int> st ;
    int N = price.size() ;
    vector<int> res(N);
    
    for(int i = 0 ; i < N ; i++){
         while(not st.empty() and price[st.top()] <= price[i]) st.pop() ;
         if(st.empty()){
             // I took control of all
             res[i] = i+1 ;
         }
        else{
            res[i] = i-st.top() ;
        }
        st.push(i);
    }
    return res ;
}
```

32. [ninja circular array](https://www.codingninjas.com/codestudio/problems/ninja-s-circular-array_2221409?leftPanelTab=0)
```cpp
vector<int> ninjaCircularArray(int n, vector<int> &nums) {
   stack<int> st ;
   vector<int> res(n,-1);
   
   for(int i = 2*n-1 ; i >= 0 ; i--){
       int idx = i%n ;
       while(not st.empty() and st.top() <= nums[idx]){
           st.pop() ;
       }
       if(not st.empty()){
           res[idx] = st.top() ;
       }
       st.push(nums[idx]);
   }
    
   return res ;
}
```

33. [decode string](https://www.codingninjas.com/codestudio/problems/decode-string_696319?leftPanelTab=0)
```cpp

bool isNum(char ch){
    return ch >= '0' and ch <= '9' ;
}
int N ;


string helper(string &s , int &pos){
    string word = "" ;
    int num = 0 ;
    
    while(pos < N){
        if(s[pos] == '['){
            pos++ ;
            string n_word = helper(s , pos);
            while(num > 0){
                word += n_word ; 
                num-- ;
            }
        }
        else if(s[pos] == ']'){
            pos++ ;
            return word ;
        }
        else if(isNum(s[pos])){
            num = num*10 + (s[pos++] - '0') ;
        }
        else{
            word.push_back(s[pos++]);
        }
    }
    return word ;
}
string decodeString(string s){
    N = s.size() ;
    int pos = 0 ;
    return helper(s , pos);
}
```

34. [stack using queue](https://www.codingninjas.com/codestudio/problems/stack-using-queue_795152?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class Stack {
	// Define the data members.
    queue<int> q ;
   public:
    Stack() {
        // Implement the Constructor.
    }

    int getSize() {
        return q.size() ;
    }

    bool isEmpty() {
        return q.empty() ;
    }

    void push(int element) {
        int sz = q.size();
        q.push(element);
        while(sz--){
            q.push(q.front()) ; q.pop() ;
        }
    }
    int pop() {
        if(q.empty()) return -1 ;
        int ele = q.front() ; q.pop() ;
        return ele ;
    }

    int top() {
        if(q.empty()) return -1;
        return q.front() ;
    }
};
```

35. [deepest leaves sum](https://www.codingninjas.com/codestudio/problems/deepest-leaves-sum_797824?leftPanelTab=0)
```cpp
int maxDepth(TreeNode<int>* root){
    if(not root) return 0 ;
    return 1+max(maxDepth(root->left) , maxDepth(root->right));
}
int maxlevel ;
int sumDeepest(TreeNode<int>* root , int level){
    if(not root) return 0 ;
    if(level == maxlevel) return root->data ;
    
    return sumDeepest(root->left , level+1) + sumDeepest(root->right , level+1);
}
int deepestLeavesSum(TreeNode<int>* root)
{
    maxlevel = maxDepth(root);
    return sumDeepest(root , 1);
}
```

36. [is subsequence](https://www.codingninjas.com/codestudio/problems/is-subsequence_892991?leftPanelTab=0)
```cpp
bool isSubSequence(string &str1, string &str2) {
    int M = str1.size() , N = str2.size() ;
    int ptr1 = 0 ,ptr2 = 0 ;
    while(ptr1 < M and ptr2 < N){
        if(str1[ptr1] == str2[ptr2]) ptr1++ ;
        ptr2++ ;
    }
    return ptr1 == M ;
}
```

37. [order of pets](https://www.codingninjas.com/codestudio/problems/find-the-order-in-which-pets-are-bought-from-the-pet-shop_1199010?leftPanelTab=0)
```cpp
vector < int > findOrder(vector < vector < int > > arr, int n) 
{
    queue<pair<int,int>> dogs , cats ;
    vector<int> res ;
    int time = 0 ;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i][0] == 1){
            // they are giving pets
            if(arr[i][2] == 0){
                //dog 
                dogs.push({arr[i][1],time++});
            }        
            else{
                cats.push({arr[i][1],time++});
            }
        }
        else{
            // adopting pets
            if(arr[i][1] == 0){
                // dogs
                int uid = dogs.front().first ; dogs.pop() ;
                res.push_back(uid) ;
            }
            else if(arr[i][1] == 1){
                int uid = cats.front().first ; cats.pop() ;
                res.push_back(uid);
            }
            else{
                if(dogs.size() == 0){
                    res.push_back(cats.front().first) ; cats.pop() ;
                }
                else if(cats.size() == 0){
                    res.push_back(dogs.front().first) ; dogs.pop() ;
                }
                else if(cats.front().second < dogs.front().second){
                    res.push_back(cats.front().first) ; cats.pop() ;
                }
                else{
                    res.push_back(dogs.front().first) ; dogs.pop() ;
                }
            }
        }
    }
```

38. 