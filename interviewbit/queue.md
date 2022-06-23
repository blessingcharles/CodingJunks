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

### Multisource bfs

1. [hotel-service](https://www.interviewbit.com/problems/hotel-service/)
```cpp
bool isInValid(int row , int col, int M , int N){
    return row < 0 or col < 0 or row >= M or col >= N ;
}

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int dx[4] = {1 , -1 , 0 , 0} ;
    int dy[4] = {0 , 0 , 1 , -1} ;
    queue<vector<int>> q ;
    int M = A.size() , N = A[0].size() ;
    
    // Multisource bfs
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(A[i][j] == 1){
                q.push({0,i,j});
                A[i][j] = 0 ;
            }
            else{
                A[i][j] = -1 ;
            }
        }
    }
    vector<int> cur_node ;
    
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            cur_node = q.front() ;
            for(int i = 0 ; i < 4 ; i++){
                int neigh_row = dx[i] + cur_node[1] , neigh_col = dy[i] + cur_node[2] ;
                if(not isInValid(neigh_row , neigh_col , M , N) and A[neigh_row][neigh_col] == -1){
                    A[neigh_row][neigh_col] = 1+cur_node[0] ;
                    q.push({A[neigh_row][neigh_col] , neigh_row , neigh_col });
                }
            }        
            q.pop();
        }
    }
    vector<int> res(B.size());
    for(int i = 0 ; i < B.size() ; i++){
        res[i] = A[B[i][0]-1][B[i][1]-1] ;    
    }
    
    return res ;
}
```