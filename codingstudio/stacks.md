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

13. 