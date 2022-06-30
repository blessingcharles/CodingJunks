### GRAPH

1. [Path in directed graph](https://www.interviewbit.com/problems/path-in-directed-graph/)
```cpp

bool dfs(int curnode , int target , vector<vector<int>> &adj_l , vector<bool> &visited){
    if(curnode == target){
        return true ;
    }
    visited[curnode] = true ;
    for(int neigh : adj_l[curnode]){
        if(not visited[neigh]){
            if(dfs(neigh , target , adj_l , visited)){
                return true ;
            }
        }
    }
    return false ;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj_l(A+1);
    
    for(int i = 0 ; i < B.size() ; i++){
        adj_l[B[i][0]].push_back(B[i][1]);
    }
    
    vector<bool> visited(A+1 , false);
    return dfs(1 , A , adj_l , visited);    
}
```

2. [water flow](https://www.interviewbit.com/problems/water-flow/)
```cpp
int ROWS , COLS ;
int dx[4] = {1 , -1 , 0 , 0} ;
int dy[4] = {0 , 0 , 1 , -1} ;
set<pair<int,int>> reachables ;

bool isInvalid(int row , int col){
    return row <0 or col < 0 or row >= ROWS or col >= COLS ;
}

void dfs(int row , int col , vector<vector<int>> &A , vector<vector<bool>> &visited , int parent){
    
    // marker from pacific ocean                 
    if(isInvalid(row , col) or visited[row][col] == true or A[row][col] < parent ){
        return ;
    }
    
    visited[row][col] = true ;
    reachables.insert({row , col});
    for(int i = 0 ; i < 4 ; i++){
        dfs(row+dx[i] , col + dy[i] , A , visited , A[row][col]);
    }
}

void find_common(int row , int col ,int &common ,vector<vector<int>> &A , vector<vector<bool>> &visited , int parent){
    if(isInvalid(row , col) or visited[row][col] == true or A[row][col] < parent ){
        return ;
    }
    visited[row][col] = true ;
    if(reachables.find({row , col}) != reachables.end()){
        // common one 
        common++ ;
    }    
    
    for(int i = 0 ; i < 4 ; i++){
        find_common(row+dx[i] , col + dy[i] , common , A , visited , A[row][col]);
    }
}

int Solution::solve(vector<vector<int> > &A) {
    ROWS = A.size() ; COLS = A[0].size() ;
    reachables.clear() ;
    
    vector<vector<bool>> visited(ROWS , vector<bool>(COLS , false));
    // get all the nodes which are reached by left and top side lake
    for(int col = 0 ; col < COLS ; col++){
        dfs(0 , col ,  A , visited , -1);
    }
    
    for(int row = 0 ; row < ROWS ; row++){
        dfs(row , 0 , A , visited , -1);
    }
    
    int common = 0 ;
    vector<vector<bool>> visited1(ROWS , vector<bool>(COLS , false));
    for(int col = 0 ; col < COLS ; col++){
        find_common(ROWS-1 , col , common , A , visited1 , -1);
    }
    
    for(int row = 0 ; row < ROWS ; row++){
        find_common(row , COLS-1 , common , A , visited1 , -1);
    }
    return common ;
}
```

3. [stepping numbers](https://www.interviewbit.com/problems/stepping-numbers/hints/)
```cpp
bool isStepping(int num){
    int prev = num%10 ;
    num = num/10 ;
    int curr ;
    
    while(num){
        curr = num%10 ;
        if(abs(curr - prev) != 1) return false ;
        prev = curr ;
        num = num/10 ;    
    }
    return true ;
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans ;
    
    for(int i = A ; i <= B ;i++){
        if(isStepping(i)){
            ans.push_back(i) ;
        }    
    }
    return ans ;
}
```

4. [capture regions on board](https://www.interviewbit.com/problems/capture-regions-on-board/)
```cpp
int ROWS , COLS ;

bool isValid(int row , int col){
    return row >= 0 and col >= 0 and row < ROWS and col < COLS ;
}
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int row , int col , vector<vector<char>> &grid){
    if(not isValid(row , col) or grid[row][col] == 'X' or grid[row][col] == 'Z'){
        return  ;
    }
    grid[row][col] = 'Z' ;
    
    for(int i = 0; i < 4 ; i++){
        dfs(row+dx[i] , col+dy[i] , grid);
    }
}

void Solution::solve(vector<vector<char> > &A) {
    ROWS = A.size() ; COLS = A[0].size() ;
    for(int row = 0 ; row < ROWS ; row++){
        dfs(row , 0 , A);
        dfs(row , COLS-1 , A);
    }
    
    for(int col = 0 ; col < COLS ; col++){
        dfs(0 , col , A);
        dfs(ROWS-1 , col , A);
    }
    for(int i = 0 ; i < ROWS ; i++){
        for(int j = 0 ; j < COLS ; j++){
            if(A[i][j] == 'Z'){
                A[i][j] = 'O' ;
            }
            else{
                A[i][j] = 'X' ;
            }
        }
    }
}
```
5. [word search](https://leetcode.com/problems/word-search/submissions/)
```cpp
class Solution {
    int N , M ;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool within_board(int row , int col){
        return (row >= 0 and row < this->M and col >= 0 and col < this->N ) ;
    }
    bool helper(vector<vector<char>>& board , string &word ,int row , int col, int cur_idx){
        if(cur_idx == word.size())
             return true ;
        
        int neigh_row , neigh_col ;
        // explore the neighbours
        for(int i = 0 ; i < 4 ; i++){
            neigh_row = row + dx[i] ;
            neigh_col = col + dy[i] ;
            
            if(within_board(neigh_row , neigh_col) and board[neigh_row][neigh_col] == word[cur_idx]){
                //make it visited and can it solve recursively ?
                board[neigh_row][neigh_col] = '.' ;
                if(helper(board , word , neigh_row , neigh_col , cur_idx+1)){
                    return true ;
                }
                //make it not visited
                board[neigh_row][neigh_col] = word[cur_idx];
            }
        }
        
        return false ;
    }
public:
    bool exist(vector<vector<char>>& board, string &word) {
        this->M = board.size() ;
        this->N = board[0].size() ;
        
        for(int i = 0 ; i < this->M ; i++){
            for(int j = 0 ; j < this->N ; j++){
                if(board[i][j] == word[0]){
                    
                    board[i][j] = '.' ;
                    if(helper(board , word , i , j , 1))
                        return true ;
                    board[i][j] = word[0];
                    
                }
            }
        }
        
        return false ;
    }
};
```

### DFS

1. [path with good nodes](https://www.interviewbit.com/problems/path-with-good-nodes/)
```cpp
int helper(int curnode , int good_nodes , vector<int> &isGood , vector<vector<int>> &graph , int parent){
    if(good_nodes < 0){
        return 0 ;
    }
    if(graph[curnode].size() == 1){
        // leaf node 
        if(good_nodes-isGood[curnode-1] >= 0) return 1 ;
        return 0 ;
    }
    int ways = 0 ;
    for(int neigh_node : graph[curnode]){
        if(neigh_node == parent) continue ;
        ways = ways + helper(neigh_node , good_nodes - isGood[curnode-1] , isGood , graph , curnode);
    }
    
    return ways ;
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int V = A.size() ;
    vector<vector<int>> graph(V+1);
    
    for(int i = 0 ; i < B.size() ; i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    return helper(1 , C , A , graph , -1) ;
}
```

2. [largest distance between nodes of a tree](https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/)
```cpp
int maxdist ;

int dfs(int curnode , vector<vector<int>> &graph , int parent){
    if(graph[curnode].size() == 0 or (graph[curnode].size() == 1 and graph[curnode][0] == parent)) return 1 ;
    
    int prev_max_height = 0 ;
    int maxheight = 0 ;
    int maxheight1 = 0 ;
    
    for(int neigh : graph[curnode]){
        if(neigh == parent) continue ;
        
        int res = dfs(neigh , graph , curnode) ;
        if(res > maxheight){
            prev_max_height = maxheight ;
            maxheight = res ;
            if(prev_max_height > maxheight1){
                maxheight1 = prev_max_height ;
            }
        }
        else if(res > maxheight1){
            maxheight1 = res ;
        }
        
    }
    
    maxdist = max(maxdist , maxheight1+maxheight);
        
    return 1+max(maxheight1 , maxheight)  ;
    
}
int Solution::solve(vector<int> &A) {
    int N = A.size() ;
    vector<vector<int>> graph(N);
    if(N == 1) return 0 ;
    
    maxdist = 0 ;
    
    int root_node = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == -1){
            root_node = i ;        
        }
        else{
            graph[A[i]].push_back(i);
            graph[i].push_back(A[i]);
            
        }
    }
    
    dfs(root_node , graph , -1) ;
    return maxdist ;
}
```

3. [cycle directed graph](https://www.interviewbit.com/problems/cycle-in-directed-graph/)
```cpp

bool isCyclic(int curnode , vector<vector<int>> &graph , vector<bool> &visited , vector<bool> &mystack){
    mystack[curnode] = true ;
    visited[curnode] = true ;
    
    for(int neigh : graph[curnode]){
        if(mystack[neigh]) return true ;
        
        if(visited[neigh]) continue ;
        
        if(isCyclic(neigh , graph, visited , mystack)){
            return true ;
        }
    }
    mystack[curnode] = false ;
    return false ;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1) ;
    
    for(int i = 0 ; i < B.size() ; i++){
        if(B[i][0] == B[i][1]) continue;
        graph[B[i][0]].push_back(B[i][1]);
    }
    vector<bool> mystack(A+1 , false);
    vector<bool> visited(A+1 , false) ;
    
    for(int i = 1 ; i <= A ; i++){
        if(not visited[i]){      
            if(isCyclic( i , graph , visited , mystack)){
                return true ;
            }
        }
    }
    return false ;
}
```

4. [two teams ?](https://www.interviewbit.com/problems/two-teams/)
```cpp
bool helper(int node ,vector<vector<int>> &l , vector<int > &visited , int color){


    visited[node] = color ;

    for(auto neighbour : l[node]){
        if(!visited[neighbour]){
            if(!helper(neighbour ,l, visited , 3-color)){
                return false ;
            }
        }
        else if(visited[neighbour] == color){
            return false ;
        }
    }
    return true ;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1) ;
    
    for(int i = 0 ; i < B.size() ; i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    
    vector<int> visited(A+1 , 0) ;
    
    for(int i = 1 ; i <= A ; i++){
        if(visited[i] == 0){      
            if(not helper( i , graph , visited , 1)){
                return false ;
            }
        }
    }
    return true ;
    
}
```