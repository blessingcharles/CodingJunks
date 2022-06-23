# QUEUE

1. [first-non-repeating-char](https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/)
```cpp
string Solution::solve(string A) {
    vector<int> memo(26,0) ;
    
    unordered_set<char> repeated ;
    queue<char> q ;
    
    string res = "" ;
    
    for(char ch : A){
        q.push(ch);
        
        if(memo[ch-'a'] == 1){
            // already occured 
            repeated.insert(ch); 
        }
        else{
            memo[ch-'a'] = 1 ;
        }
        
        while(not q.empty() and repeated.find(q.front()) != repeated.end()){
            q.pop();
        }          
        if(q.empty()){
            res.push_back('#');
        }
        else{
            res.push_back(q.front());
        }
    }
    
    return res ;
}
```

2. [max-window](https://www.interviewbit.com/problems/sliding-window-maximum/)
```cpp
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<pair<int,int>> q ;
    
    for(int i = 0 ; i < B ; i++){
        while(not q.empty() and q.back().second <= A[i]){
            q.pop_back();
        }
        q.push_back({i , A[i]});
    }
    
    vector<int> ans ;
    ans.push_back(q.front().second);
    
    for(int i = B ; i < A.size() ; i++){
        //moving the window
        while(not q.empty() and q.front().first <= i-B){
            q.pop_front();
        }
        
        while(not q.empty() and q.back().second <= A[i]){
            q.pop_back();
        }
        
        q.push_back({i , A[i]});
        ans.push_back(q.front().second);
    
    }
    return ans ;
}
```
