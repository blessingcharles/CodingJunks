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

### BFS

1. [Valid Path](https://www.interviewbit.com/problems/valid-path/)
```cpp
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int MAX_ROW , MAX_COL ;

bool isInvalid(int row , int col){
    return row < 0 or col < 0  or row >= MAX_ROW or col >= MAX_COL ;
}

bool dfs(int row , int col , vector<vector<int>> &board){
    if(board[row][col] == -1) return false ;
    if(row == MAX_ROW-1 and col == MAX_COL-1){
        return true ;
    }
    board[row][col] = 1 ;
    
    for(int i = 0 ; i < 8 ; i++){
        int neigh_x = row + dx[i] ;
        int neigh_y = col + dy[i] ;
        if(isInvalid(neigh_x , neigh_y) or board[neigh_x][neigh_y] != 0){
            continue ;        
        }
        if(dfs(neigh_x , neigh_y , board)) return true ;
    }
    return false ;
}

string Solution::solve(int ROW, int COL, int N, int R, vector<int> &X, vector<int> &Y) {
    queue<pair<int,int>> q;
    vector<vector<int>> board(ROW+1 , vector<int>(COL+1 , 0));

    MAX_ROW = ROW+1 ; MAX_COL = COL+1 ;
        
    // if (i , j) lies in the manhatten distance of any of the circle then mark it as -1
    
    for(int x = 0 ; x  < MAX_ROW ; x++){
        for(int y = 0 ; y < MAX_COL ; y++){
            for(int c = 0 ; c < N ; c++){
                if( (pow((X[c] - x) , 2) + pow((Y[c] - y) , 2)) <= R*R){
                    board[x][y] = -1 ;
                }
            }
        }
    }
    if(board[0][0] == -1) return "NO" ;
    return (dfs(0 , 0 , board))?"YES":"NO" ;
}
```

2. [snake and ladders](https://www.interviewbit.com/problems/snake-ladder-problem/)
```cpp
int Solution::snakeLadder(vector<vector<int> > &ladders, vector<vector<int> > &snakes){
    // building the board
    int SIZE = 100 ;
    vector<int> board(SIZE+1 , 0);
    
    for(int i = 1 ; i <= SIZE ; i++){
        board[i] = i ;
    }
    
    for(vector<int>& l : ladders){
        board[l[0]] = l[1] ;
    }
    for(vector<int>& s : snakes){
        board[s[0]] = s[1] ;
    }
    
    // build a graph of adjacency list representing the possible moves
    vector<vector<int>> graph(SIZE+1) ;
     
    for(size_t i = 1 ; i < SIZE ;i++){
        for(int dice = 1 ; dice <= 6 ; dice++){
            int pos_move = i+dice ;
            if(pos_move <= SIZE){
                graph[i].push_back(board[pos_move]);
            }
        }
    }    
    
    int dist = 0 ;
    queue<int> q ; q.push(1);
    vector<bool> visited(SIZE+1 , false);
    visited[1] = true ;
    
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            int curnode = q.front() ; q.pop() ;
            
            if(curnode == SIZE) return dist ;
            
            for(int neigh : graph[curnode]){
                if(not visited[neigh]){
                    visited[neigh] = true ;
                    q.push(neigh) ;
                }
            }
        }
        dist++ ;
    }
    
    return -1 ;
}
```

3. [Region in Binary Matrix](https://www.interviewbit.com/problems/region-in-binarymatrix/)
```cpp
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int ROW , COL ;

bool isInvalid(int row , int col){
    return row < 0 or col < 0  or row >= ROW or col >= COL ;
}

int dfs(int row , int col , vector<vector<int>> &graph){
    int length = 1 ;
    graph[row][col] = 0 ;
    
    for(int i = 0 ; i < 8 ; i++){
        int neigh_r = row + dx[i] ;
        int neigh_c = col + dy[i] ;
        if(isInvalid(neigh_r , neigh_c) or graph[neigh_r][neigh_c] != 1) continue ;
        
        length = length + dfs(neigh_r , neigh_c , graph);    
    }
    return length ;
}

int Solution::solve(vector<vector<int> > &A) {
    ROW = A.size() ; COL = A[0].size() ;
    int maxregion = 0 ;
    
    for(int i = 0 ; i < ROW ; i++){
        for(int j = 0; j < COL ; j++){
            if(A[i][j] == 1){
                maxregion = max(maxregion , dfs(i , j , A));
            }
        }
    }
    
    return maxregion ;
}
```

4. [level order traversal](https://www.interviewbit.com/problems/level-order/)
```cpp
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> res ;
    
    queue<TreeNode* > q ;
    q.push(A) ;
    
    while(not q.empty()){
        int sz = q.size() ;
        vector<int> level ;
        while(sz--){
            TreeNode* node = q.front() ; q.pop() ;
            level.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        res.push_back(level);
    }
    return res ;
}
```

5. [smallest multiple with 0 and 1](https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/)
```cpp
string Solution::multiple(int A) {
    if(A == 1) return "1" ;
    
    queue<pair<string , int>> q ;
    q.push({"1" , 1});
    
    unordered_set<int> memo ;
    memo.insert(1) ;
    
    pair<string , int> curnode ;
    
    while(not q.empty()){
        curnode = q.front() ; q.pop() ;
        
        // adding 0 to it 
        int rem1 = (10*curnode.second + 0)%A ;
        if(rem1 == 0){
            return curnode.first + "0" ;
        }
        
        if(memo.find(rem1) == memo.end()){
            memo.insert(rem1);
            q.push({curnode.first+"0" , rem1});    
        }
        
        int rem2 = (10*curnode.second + 1)%A ;
        if(rem2 == 0){
            return curnode.first + "1" ;
        }
        if(memo.find(rem2) == memo.end()){
            memo.insert(rem2);
            q.push({curnode.first+"1" , rem2});    
        }
    }
    return "1" ;
}
```

6.  [Min Cost Path](https://www.interviewbit.com/problems/min-cost-path/)
```cpp
class Point{
    public:
    int x;
    int y;
    int cost;
};
struct comp{
    bool operator()(Point const& p1, Point const& p2){
        return p1.cost>p2.cost;//mid priority_queue
    }
};
// R,D,L,U
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int Solution::solve(int r, int c, vector<string> &mat) {
    string s="RDLU"; // all for possible directions
    // to store distance
    vector<vector<int>>dist(r,vector<int>(c,INT_MAX-1));
    // to get min cost path
    priority_queue<Point,vector<Point>,comp>pq;
    // let's push initial co-ordinates
    pq.push({0,0,0});
    dist[0][0]=0;
    while(!pq.empty()){
        Point cp=pq.top();
        pq.pop();
        if(cp.x==r-1 and cp.y==c-1) return dist[cp.x][cp.y];
        for(int i=0;i<4;i++){
            int nx=cp.x+dx[i];
            int ny=cp.y+dy[i];
            int cost=dist[cp.x][cp.y];
            if(s[i]!=mat[cp.x][cp.y]) cost++;
            
            //check boundary condition and cost
            if(nx>=0 and ny>=0 and nx<r and ny<c and cost<dist[nx][ny]){
                pq.push({nx,ny,cost});
                dist[nx][ny]=cost;
            }
        }
    }
    return dist[r-1][c-1];
}
```

### Graph Connectivity

1. [Commutable Island](https://www.interviewbit.com/problems/commutable-islands/)
```cpp
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A+1 , false);
    vector<vector<pair<int , int>>> graph(A+1) ;
    
    for(vector<int> &edge : B){
        graph[edge[0]].push_back({edge[2] ,edge[1]});
        graph[edge[1]].push_back({ edge[2], edge[0]});
    }
    
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;

        pq.push({0,1});

        int mst_sum = 0;
        while (!pq.empty())
        {
            int weight = pq.top().first ;
            int node = pq.top().second ;
            pq.pop();

            if(visited[node]) continue ;
            
            visited[node] = true ;

            mst_sum += weight ;
            for(auto ele : graph[node]){
                if(!visited[ele.second]){
                    pq.push({ele.first,ele.second});
                }
            }
        }
        return mst_sum ;
}
```

2. [Possibility of finishing courses](https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/)
```cpp
bool isCyclic(int curnode , vector<bool> &visited  , vector<vector<int>> &graph , vector<bool> &mystack ){
    visited[curnode] = true ;
    mystack[curnode] = true ;
    
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            if(isCyclic(neigh , visited , graph , mystack)){
                return true ;
            }
        }
        else if(mystack[neigh] == true){
                return true ;
        }
    }   
    mystack[curnode] = false ;
    return false ; 
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    // finding cycles
    vector<vector<int>> graph(A+1);
    
    for(int i = 0 ; i < B.size() ; i++){
        graph[B[i]].push_back(C[i]);
    }
    vector<bool> visited(A+1 , false);
    vector<bool> mystack(A+1 , false);
    
    for(int i = 1 ; i <= A ; i++){
        if(not visited[i]){
            if(isCyclic(i , visited , graph , mystack)){
                return false ; // you can't do the courses
            }
        }
    }
    return true ;
}
```

3.  [cycle in undirected graph](https://www.interviewbit.com/problems/cycle-in-undirected-graph/)
```cpp
bool isCyclic(int curnode , vector<bool> &visited , vector<vector<int>> &graph , int parent){
    visited[curnode] = true ;
    
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            if(isCyclic(neigh , visited , graph , curnode)){
                return true ;
            }
        }
        else if(neigh != parent){
            return true ;
        }
    }
    return false ;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    vector<bool> visited(A+1 , false);
    
    for(vector<int> &edge : B){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    for(int i = 1 ; i <= A ;i++){
        if(not visited[i] and isCyclic(i , visited , graph , -1)){
            return true ;
        }
    }
    return false ;
}
```

4. [Black Shapes](https://www.interviewbit.com/problems/black-shapes/)
```cpp
int M , N ;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}

void helper(int row , int col , vector<string> &graph){
    graph[row][col] = 'O' ;
    
    for(int i = 0 ; i < 4 ; i++){
        int neigh_r = dx[i] + row ;
        int neigh_c = dy[i] + col ;
        
        if(isInvalid(neigh_r , neigh_c) or graph[neigh_r][neigh_c] == 'O') continue ;
        helper(neigh_r , neigh_c , graph) ;    
    }        
}

int Solution::black(vector<string> &A) {
    M = A.size() ; N = A[0].size() ;
    
    int count = 0 ;
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(A[i][j] == 'X'){
                count++ ; 
                helper(i , j , A);
            }
        }
    }
    return count ;    
}
```

 ## Graph Adhoc

 1. [list to bst](https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/)
 ```cpp
 TreeNode* buildTree(int left , int right , vector<int> &arr){
    if(left > right) return NULL ;
    if(left == right){
        return new TreeNode(arr[left]);
    }
    int mid = left + (right-left)/2 ;
    
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = buildTree(left , mid-1 , arr);
    root->right = buildTree(mid+1 , right ,arr);
    
    return root ;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> arr ;
    
    while(A){
        arr.push_back(A->val);
        A = A->next ;
    }
    
    return buildTree(0 , arr.size()-1 , arr);    
}
 ```

 ### Graph Hashing

1. [Clone Graph](https://www.interviewbit.com/problems/clone-graph/)
```cpp
unordered_map<int , UndirectedGraphNode* > memo ;

UndirectedGraphNode* helper(UndirectedGraphNode* root){
    UndirectedGraphNode *newroot = new UndirectedGraphNode(root->label);
    memo[newroot->label] = newroot ;
    
    for(UndirectedGraphNode* neigh : root->neighbors){
        if(memo.find(neigh->label) != memo.end()){
            newroot->neighbors.push_back(memo[neigh->label]);
        }
        else{
            newroot->neighbors.push_back( helper(neigh) );
        }
    }
    
    return newroot ;
    
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {

    memo.clear();    
    return helper(node);
}
```
