## BFS

1. [Create Binary Tree from descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/)
```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode* > memo ;
        unordered_set<int> indegree ;
        
        for(vector<int> &d : descriptions){
            int parent = d[0] , child = d[1] ;
            bool isleft = d[2] ;
            TreeNode* pn , *cn;
            indegree.insert(child) ;
            
            if(memo.find(parent) != memo.end()){
                pn = memo[parent] ;    
            }
            else{
                pn = new TreeNode(parent);
                memo[parent] = pn ;
            }
            
            if(memo.find(child) != memo.end()){
                cn = memo[child] ;
            }
            else{
                cn = new TreeNode(child) ;
                memo[child] = cn ;
            }
            
            if(isleft){
                pn->left = cn ;
            }
            else{
                pn->right = cn ;
            }
        }
        
        for(auto it = memo.begin() ; it != memo.end() ; it++){
            if(indegree.find(it->first) == indegree.end()){
                return memo[it->first] ;
            }
        }
        
        return NULL ;
    }
};
```

2. [K highest ranked item](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/)
```cpp
class Solution {
int M , N ;
    
public:
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= M or col >= N ;
    }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        M = grid.size() ; N = grid[0].size() ;
        
        queue<pair<int,int>> q ;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq ;
        
        q.push({start[0] , start[1]} ) ;
        int minp = pricing[0] , maxp = pricing[1] ;
        
        if(minp <= grid[start[0]][start[1]] and maxp >= grid[start[0]][start[1]]){
            pq.push({0 , grid[start[0]][start[1]] , start[0] , start[1] } );
        }
        
        grid[start[0]][start[1]] = 0 ;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1} ;
        int dist = 1 ;
        
        while(not q.empty()){
            int sz = q.size() ;
            
            while(sz--){
                int row = q.front().first , col = q.front().second ;
                q.pop() ;

                for(int i = 0 ; i < 4 ; i++){
                    int neigh_r = row + dx[i] ;
                    int neigh_c = col + dy[i] ;
                    if(isInvalid(neigh_r , neigh_c) or grid[neigh_r][neigh_c] == 0)
                        continue ;

                    q.push({neigh_r , neigh_c}) ;

                    int curp = grid[neigh_r][neigh_c] ;
                    if(minp <= curp and maxp >= curp){
                        pq.push({dist , curp , neigh_r , neigh_c}) ;
                    }

                    grid[neigh_r][neigh_c] = 0 ;

                }    
            }
            dist++ ;
        }
        
        vector<vector<int>> res ;
        while(k--  and not pq.empty()){
            res.push_back({pq.top()[2]  , pq.top()[3]}) ;
            pq.pop() ;
        }
        
        return res ;
        
    }
};
```

3. [min operation to convert number](https://leetcode.com/problems/minimum-operations-to-convert-number)
```cpp
class Solution {
public:
   
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visited(1001 , false);
        queue<int> q ;
        q.push(start) ;
        int levels = 0 ;
        
        while(not q.empty()){
            int sz = q.size() ;
            
            while(sz--){
                int curr = q.front() ; q.pop() ;
                if(curr == goal)
                    return levels ;
                
                if(curr < 0 or curr > 1000 or visited[curr])
                    continue ;
                
                visited[curr] = true ;
                for(int ele : nums){
                    int a = curr + ele ;
                    int b = curr - ele ;
                    int c = curr ^ ele ;
                    q.push(a) ; q.push(b) ; q.push(c) ;
                }
            }
            levels++ ;
        }
        return -1 ;
    }
};
```

4. [operations on tree](https://leetcode.com/problems/operations-on-tree/)
```cpp
class LockingTree {
public:
    vector<int> ancestors ;
    unordered_map<int , vector<int>> graph ;
    vector<int> locked ;
    int N ;
    
    LockingTree(vector<int>& parent) {
        N = parent.size() ;
        ancestors = parent ;
        
        locked.resize(N , 0);
        for(int i = 1 ; i < N ; i++){
            graph[parent[i]].push_back(i) ;
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num] != 0) return false ;
        locked[num] = user ;
        return true ;
    }
    
    bool unlock(int num, int user) {
        if(locked[num] != user) return false ;
        locked[num] = 0 ;
        return true ;
    }
    
    bool upgrade(int num, int user) {
        if(locked[num] != 0)
            return false ;
        
        // check for locked ancestors
        int curr = ancestors[num] ;
        while(curr != -1 and locked[curr] == 0){
            curr = ancestors[curr] ;
        }
        if(curr != -1) return false ;
        
        // check for the descendents
        queue<int> q ;
        q.push(num) ;
        int count = 0 ;
        
        while(not q.empty()){
            curr = q.front() ; q.pop() ;
            
            for(int neigh : graph[curr]){
                if(locked[neigh] != 0){
                    count++ ;
                    locked[neigh] = 0 ;
                }
                q.push(neigh) ;
            }
        }
        
        if(count == 0)
            return false ;
        
        locked[num] = user ;
        return true ;
    }
};
```

5. [find all group of farmlands](https://leetcode.com/problems/find-all-groups-of-farmland/)
```cpp
class Solution {
public:
    int M , N ;
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res ;
        M = land.size() ; N = land[0].size() ;
        
        for(int i = 0 ;i < M ;i++){
            for(int j = 0 ; j < N ; j++){
                if(land[i][j] != 0){
                    int x = i , y = j ;
                    
                    for( ; x < M and land[x][j]; x++){
                        for(y = j; y < N and land[x][y] ; y++){
                            land[x][y] = 0 ;
                        }
                    }
                    res.push_back({i , j , x-1 , y-1}) ;
                }
            }
        }
        return res ;
    }
};
```


6. [nearest exit from entraance in maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/)
```cpp
class Solution {
public:
    int M , N ;
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= M or col >=N ;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q ;
        int dx[4] = {1,-1,0,0} ;
        int dy[4] = {0,0,1,-1} ;
        M = maze.size() ;
        N = maze[0].size() ;
        if(maze[entrance[0]][entrance[1]] != '.')
            return -1 ;
        
        q.push({entrance[0] , entrance[1]}) ;
        maze[entrance[0]][entrance[1]] = '+' ;
        
        int level = 0 ;
        
        while(not q.empty()){
            int sz = q.size() ;
            
            while(sz--){
                int row = q.front().first ;
                int col = q.front().second ; q.pop() ;
                // cout << row << " " << col << endl ;
                for(int i = 0 ; i < 4 ; i++){
                    int neigh_r = row + dx[i] ;
                    int neigh_c = col + dy[i] ;
                    
                    if(isInvalid(neigh_r , neigh_c)){
                        if(level != 0)
                            return level ;
                        continue ;
                    }
                    if(maze[neigh_r][neigh_c] == '+') continue ;
                    maze[neigh_r][neigh_c] = '+' ;
                    
                    q.push({neigh_r , neigh_c} ) ;
                }
            }
            level++ ;
        }
        
        return -1 ;
    }
};
```

7. [count sub islands](https://leetcode.com/problems/count-sub-islands/)
```cpp
class Solution {
public:
    int dx[4] = {1,-1,0,0} ;
    int dy[4] = {0,0,1,-1} ;
    int M , N ;
    
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= M or col >= N ;
    }
    
    bool bfs(int row , int col , vector<vector<int>> &grid1 , vector<vector<int>> &grid2){
        queue<pair<int,int>> q ;
        q.push({row , col}) ;
        
        grid1[row][col] = 0 ;
        grid2[row][col] = 0 ;
        
        bool isValid = true ;
        while(not q.empty()){
            row = q.front().first ; col = q.front().second ;
            q.pop() ;
            
            for(int i = 0 ; i < 4 ; i++){
                int neigh_r = row + dx[i] ;
                int neigh_c = col + dy[i] ;
                
                if(isInvalid(neigh_r , neigh_c) or grid2[neigh_r][neigh_c] == 0)
                    continue ;
                
                if(grid1[neigh_r][neigh_c] == 0){
                    isValid=false ;
                }
                
                grid1[neigh_r][neigh_c] = 0 ;
                grid2[neigh_r][neigh_c] = 0 ;
                
                q.push({neigh_r , neigh_c}) ;
            }
        }
        
        return isValid ;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        M = grid1.size() ; N = grid1[0].size() ;
        
        int count = 0 ;
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(grid1[i][j] == 1 and grid2[i][j] == 1){
                    if(bfs(i , j , grid1 , grid2 )){
                        count++ ;
                    }
                }
            }
        }
        
        return count ;
    }
};
```

8. [path with min effort](https://leetcode.com/problems/path-with-minimum-effort/)
```cpp
class Solution {
public:
    int M , N ;
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= M or col >= N ;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dx[4] = {1,-1,0,0} ;
        int dy[4] = {0,0,1,-1} ;
        M = heights.size() ; N = heights[0].size() ;
        
        priority_queue<vector<int> , vector<vector<int>> ,
                        greater<vector<int>> > pq ;
        
        pq.push({0 , 0 , 0});
        vector<vector<bool>> visited(M , vector<bool>(N ,  false)) ;
        
        while(not pq.empty()){
            int effort = pq.top()[0] ;
            int row = pq.top()[1] ;
            int col = pq.top()[2] ; pq.pop() ;
            if(visited[row][col]) continue ;
            
            visited[row][col] = true ;
            
            if(row == M-1 and col == N-1)
                return effort ;
            
            for(int i = 0 ; i < 4 ; i++){
                int neigh_r = row + dx[i] ;
                int neigh_c = col + dy[i] ;
                if(isInvalid(neigh_r , neigh_c) 
                    or visited[neigh_r][neigh_c])
                    continue ;
                
                int e = abs(heights[row][col] - heights[neigh_r][neigh_c]);
                
                pq.push({max(effort,e) , neigh_r , neigh_c});
            }
        }
        
        return -1 ;
    }
};
```

9. [lex smallest string after applying operation](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/)
```cpp
class Solution {
public:
    unordered_set<string> seen ;
    string minval ;
    void adder(string &s , int a){
        for(int i = 1 ; i < s.size() ; i += 2){
            int n = s[i] - '0' ;
            s[i] = (n+a)%10 + '0' ;
        }
    }
    
    void rotater(string &s , int b){
        reverse(s.begin() , s.end()) ;
        reverse(s.begin() , s.begin()+b) ;
        reverse(s.begin()+b , s.end()) ;
    }
    void dfs(string s, int a , int b){
        if(seen.find(s) != seen.end()) return ;
        seen.insert(s) ;
        minval = min(minval , s);
        
        string temp = s ;
        
        adder(s , a);
        dfs(s , a , b);
        
        rotater(temp , b);
        dfs(temp , a , b);
        
    }
    string findLexSmallestString(string s, int a, int b) {
        minval = s ;
        dfs(s , a , b);
        return minval ;
    }
};
```

10. []()
```cpp

```