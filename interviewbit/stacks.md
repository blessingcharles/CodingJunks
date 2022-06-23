# STACKS

### practise

1. [valid-paren](https://www.interviewbit.com/problems/generate-all-parentheses/)
```cpp
int Solution::isValid(string A) {
    stack<char> st ;
    
    for(char ch : A){
        if(ch == '[' or ch == '{' or ch == '('){
            st.push(ch);
        }
        else if(st.empty()){
           return 0 ;
        }
        else if(ch == ']'){
            if(st.top() != '['){
                return 0 ;
            }
            st.pop();
        }    
        else if(ch == '}'){
            if(st.top() != '{'){
                return 0 ;
            }
            st.pop();
        }
        else{
            if(st.top() != '('){
                return 0 ;
            }
            st.pop();
        }
    }
    return (st.empty())?1:0 ;
}
```

### Stack simple

1. [simple-paren](https://www.interviewbit.com/problems/balanced-parantheses/)
```
int Solution::solve(string A) {
    int open_paren = 0 ;
    for(char ch : A){
        if(ch == '('){
            open_paren++ ;
        }
        else if(open_paren == 0){
            return 0 ;
        }
        else{
            open_paren-- ;
        }
    }
    return (open_paren == 0)?1:0 ;
}
```

2. [unix-dir](https://www.interviewbit.com/problems/simplify-directory-path/)
```cpp
string Solution::simplifyPath(string A) {
    int N = A.size() ;
    int idx = 0 ;
    deque<string> st ;
    
    
    while(idx < N){
        if(A[idx] == '/'){
            idx++ ;
        }
        else if(A[idx] == '.'){
            // check if its a double dot
            if(idx+1 < N and A[idx+1] == '.'){
                if(not st.empty())
                    st.pop_back();
                idx += 2 ;
            }
            else{
                idx++ ;
            }
        }
        else{
            // character token so parse until / or EOF reached
            string temp = "" ;
            while(idx < N and A[idx] != '/'){
                temp.push_back(A[idx++]);
            }
            st.push_back(temp);
        }
    }
    string res = "";
    
    while(not st.empty()){
        res.push_back('/');
        res += st.front() ; st.pop_front() ;
    }
    
    return (res.size() == 0)?"/":res ;
}
```

3. [redundant-brace](https://www.interviewbit.com/problems/redundant-braces/)
```cpp
bool isExpression(char ch){
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' ;
}

int Solution::braces(string A) {
    stack<char> st ;
    
    for(char ch : A){
        if(ch == '('){
            st.push('(');
        }
        else if(ch == ')'){
            if(st.empty()){
                return 1 ;
            }
            bool is_exp = false ;
            
            while(st.top() != '('){
                if(st.empty()){
                    return 1 ;
                }
                if(isExpression(st.top())){
                    is_exp = true ;
                }
                st.pop();
            }
            if(not is_exp){
                return 1 ;
            }
            
            st.pop() ;
        }
        else{
            st.push(ch);
        }
    }
    
    return 0 ;
}
```
4. [mistack](https://www.interviewbit.com/problems/min-stack/)
```cpp
template<typename T> class Node{
public:
    T val ;
    Node* nxt ;
    Node(){
        this->nxt = NULL ;
    };
    Node(T value){
        this->val = value ;
        this->nxt = NULL ;
    }
};
template<typename T> class MyStack{
public:
    Node<T> *head ;
    MyStack(){
        head = NULL ;
    }    
    void push(T val){
        if(not head){
            head = new Node<T>(val);
        }else{
            Node<T>* temp = new Node<T>(val);
            temp->nxt = head ;
            head = temp ;
        }
    }    
    void pop(){
        if(not head){
            return ;
        }
        Node<T> *temp = head ; 
        head = head->nxt ;
        delete temp ; 
    }
    int top(){
        if(not head){
            return -1 ;
        }
        return head->val ;
    }
    bool isEmpty(){
        return head == NULL ;
    }
};

MyStack<int> *st ;
MyStack<int> *minst ;

MinStack::MinStack() {
    st = new MyStack<int>() ;
    minst = new MyStack<int>() ;    
}

void MinStack::push(int x) {
    st->push(x);
    if(minst->isEmpty() or minst->top() >= x){
        minst->push(x);
    }
}

void MinStack::pop() {
    if(st->isEmpty()){
        return ;
    }
    if(st->top() == minst->top()){
        minst->pop();
    }
    st->pop();
}

int MinStack::top() {
    if(st->isEmpty()){
        return -1 ;
    }
    return st->top() ;
}

int MinStack::getMin() {
    if(minst->isEmpty()){
        return -1 ;
    }
    return minst->top();
}
```

### Clever Stack

1. [nearest-smaller-ele](https://www.interviewbit.com/problems/nearest-smaller-element/)
```cpp
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st ; // monotonic increasing stactk 
    vector<int> ans(A.size()) ;
    
    for(int i = 0 ; i < A.size() ; i++){
        while(not st.empty() and st.top() >= A[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1 ;
        }
        else{
            ans[i] = st.top() ;
        }
        st.push(A[i]);
    }

    return ans ;
}
```

2. [largest-rectangle-histogram](https://www.interviewbit.com/problems/largest-rectangle-in-histogram/)
```cpp
int Solution::largestRectangleArea(vector<int> &A) {
    stack<pair<int,int>> st ;
    A.push_back(0);
    st.push({0,A[0]});
    int maxarea = A[0] ;
    
    for(int i = 0 ; i < A.size() ; i++){
        int left_expandable = i ;
        
        while(not st.empty() and st.top().second >= A[i]){
            left_expandable = st.top().first ;
            maxarea = max(maxarea , st.top().second * (i-left_expandable));
            st.pop();
        }
        st.push({left_expandable , A[i]});
    }
    return maxarea ;
}
```

### Stack Math

1. [Evaluate exp](https://www.interviewbit.com/problems/evaluate-expression/)
```cpp
int calc(int op1 , int op2 , string &op){

    if(op == "+")
        return op1+op2 ;
    if(op == "-")
        return op1-op2 ;
    if(op == "*" or op == "" or op == " ")
        return op1*op2 ;
    if(op == "/")
        return op1/op2 ;

    return 0 ;
}

bool isSymbol(string &s){
    return s == "+" or s == "-" or s == "*" or s == "" or s == " " or s == "/" ;
}

int Solution::evalRPN(vector<string> &A) {
    stack<string> st ;
    
    for(string &symbol : A){
        if(isSymbol(symbol)){
            int op2 = stoi(st.top()) ; st.pop();
            int op1 = stoi(st.top()) ; st.pop() ;
            
            int res = calc(op1 , op2 , symbol);
            st.push(to_string(res));   
        }
        else{
            st.push(symbol);
        }
    }
    if(st.empty()){
        return 0 ;
    }
    
    return stoi(st.top()) ;
}
```

2. [trap-rain-water](https://www.interviewbit.com/problems/rain-water-trapped/)
```cpp
int Solution::trap(const vector<int> &A) {
    int N = A.size() ;
    
    vector<int> fromleft(N);
    vector<int> fromright(N);
    fromleft[0] = 0 ;
    fromright[N-1] = 0 ;
    
    for(int i = 1, j = N-2 ; i < N ; i++ , j--){
        fromleft[i] = max(fromleft[i-1] , A[i-1]);
        fromright[j] = max(fromright[j+1] , A[j+1]);
    }
    
    int water = 0 ;
    
    for(int i = 1 ; i < N-1 ; i++){
        int height = min(fromleft[i] , fromright[i]) - A[i] ;
        if(height > 0){
            water += height ;
        }
    }
    
    return water ;
}
```