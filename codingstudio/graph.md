### GRAPH

1. [Alien-dictionary](https://www.codingninjas.com/codestudio/problems/alien-dictionary_630423?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int ctoi(char ch){
    return ch - 'a' ;
}
char itoc(int ele){
    return 'a' + ele ;
}

void buildC(unordered_set<int> &charmaps , string* dictionary , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < dictionary[i].size() ; j++){
            charmaps.insert(ctoi(dictionary[i][j])) ;
        }
    }
}

vector<char> getAlienLanguage(string* dictionary, int n)
{
    vector<vector<int>> graph(26) ;
    vector<char> res ;
    unordered_set<int> charmaps ;
    buildC(charmaps , dictionary , n);
    
    for(int i = 0 ; i < n-1 ; i++){
        if(dictionary[i].size() > dictionary[i+1].size()){
            return res ;
        }
        for(int j = 0 ; j < dictionary[i].size() ; j++){
            if(dictionary[i][j] != dictionary[i+1][j]){
                graph[ctoi(dictionary[i][j])].push_back(ctoi(dictionary[i+1][j]));
                break ;
            }
        }
    }
        vector<int> indegree(26 , 0);
        
        for(int i = 0 ; i < 26 ; i++){
            for(int ele : graph[i]){
                indegree[ele]++ ;
            }
        }
        queue<int> q ;
        
        for(int i = 0 ; i < 26 ; i++){
            if(indegree[i] == 0 and charmaps.find(i) != charmaps.end()){
                q.push(i) ;        
            }
        }
        if(q.empty()) return res ;       
        
        while(not q.empty()){
            int ele = q.front() ; q.pop() ;
            charmaps.erase(ele);
            
            res.push_back(itoc(ele));
            for(int neigh : graph[ele]){
                if(charmaps.find(neigh) != charmaps.end()){
                    indegree[neigh]-- ;
                    if(indegree[neigh] == 0){
                        q.push(neigh);
                    }
                }
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            if(indegree[i] != 0){
                return vector<char>() ;
            }
        }
        for(auto it = charmaps.begin() ; it != charmaps.end() ; it++){
            res.push_back(itoc(*it));
        }
        
        return res ;
     
}
```

2. [detect cycle in undirected graph](https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-undirected-graph_626071?leftPanelTab=0)
```cpp

#include<bits/stdc++.h>

bool helper(int curnode , list<int>* adj , vector<bool> &visited , int parent){
    visited[curnode] = true ;
    
    for(int neigh : adj[curnode]){
        if(not visited[neigh]){
            if(helper(neigh , adj , visited , curnode)){
                return true ;
            }
        }
        else if(neigh != parent){
            return true ;
        }
    }
    return false ;
}

bool isCyclic(Graph g)
{
	vector<bool> visited(g.V , false);
    
    for(int i = 0 ; i < g.V ; i++){
        if(not visited[i]){
            if(helper(i , g.adj , visited , -1)){
                return true ;
            }
        }
    }
    return false ;
}
```

3. [dfs traversal](https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1)
```cpp
#include<bits/stdc++.h> 

void dfs(int curnode , vector<vector<int>> &graph , vector<bool> &visited ,vector<int> &storage){
    visited[curnode] = true ;
    storage.push_back(curnode);
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            dfs(neigh , graph , visited , storage);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V) ;
    
    for(int i = 0 ; i < E ; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(V+1 , false);
    vector<vector<int>> ans ;
    for(int i = 0 ; i < V ;i++){
        if(not visited[i]){
            vector<int> temp ;
            dfs(i , graph , visited , temp);
            ans.push_back(temp);
        }
    }
    return ans ;
}
```

4. [count ways](https://www.codingninjas.com/codestudio/problems/count-ways_758964?leftPanelTab=0)
```cpp
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
long mod = 1e9+7 ;

int helper(int srcnode ,vector<vector<int>> &graph , vector<int> &memo){
    if(memo[srcnode] != -1) return memo[srcnode] ;
    
    long ways = 1 ;
    for(int neigh : graph[srcnode]){
        ways = (ways + helper(neigh , graph , memo))%mod;
    }    
    return memo[srcnode] = ways%mod ;
}

int main()
{
    int V = 0 , E = 0 , S = 0;
    
    cin >> V >> E >> S ;
    if(E == 0 or V == 1){
         cout << 1 << endl ;
        return 0 ;
    }
    vector<int> memo(V+1 , -1);
    
    vector<vector<int>> graph(V+1);
    int e1 , e2 ;
    
    for(int i = 0 ; i < E ; i++){
        cin >> e1 >> e2 ;
        graph[e1].push_back(e2);
    }
    cout << helper(S , graph , memo) << endl ;
    return 0 ;
}
```

5. [Jumping numbers]()
```cpp
#include<bits/stdc++.h>

vector<int> jumpingNumbers(int n)
{
    vector<int> ans ;
    ans.push_back(0);
    queue<int> q ;
    for(int i = 1 ; i < 10 ; i++){
        q.push(i);
    }
    
    while(not q.empty()){
        int curr = q.front() ; q.pop() ;
        if(curr > n) continue ;
        ans.push_back(curr);
        
        int last_digit = curr%10 ;
        if(last_digit != 0){
            q.push(curr*10 + (last_digit-1));        
        }
        if(last_digit != 9){
            q.push(curr*10 + (last_digit+1));
        }
    }
    return ans ;
}
``` 

6. [shortest path in unweighted graph](https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<vector<int>> graph(n+1);
    for(int i = 0 ; i < m ; i++){
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    
    queue<pair<int , vector<int>> > q ;
    q.push({s , {s}});
    pair<int , vector<int>> curnode ;
    vector<bool> visited(n+1 , false);
    visited[s] = true ;
    
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            curnode = q.front() ; q.pop() ;
            if(curnode.first == t){
                return curnode.second ;
            }
            for(int neigh : graph[curnode.first]){
                if(not visited[neigh]){
                    visited[neigh] = true ;
                    curnode.second.push_back(neigh);
                    q.push({neigh , {curnode.second}});
                    curnode.second.pop_back() ;
                }
            }
        }
        
    }
    return {} ;
}
```

7. [check bipartite](https://www.codingninjas.com/codestudio/problems/check-graph-is-bipartite-or-not_920551?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

bool isBip(int curnode , vector<vector<int>> &graph , int color , vector<int> &visited){
    visited[curnode] = color ;
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            if(not isBip(neigh , graph , 3-color , visited)){
                return false ;
            }
        }
        else if(visited[neigh] == color){
            return false ;
        }
    }
    return true ;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int V = edges.size() ;
    vector<vector<int>> graph(V);
    vector<int> visited(V , 0);
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            if(edges[i][j] == 1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    for(int i = 0 ; i < V ; i++){
        if(not visited[i] and not isBip(i , graph ,1, visited )){
            return false ;
        }
    }
    return true ;
}
```
8. [topological sort](https://www.codingninjas.com/codestudio/problems/topological-sort_982938?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> graph(v);
    vector<int> indegree(v , 0);
    
    for(int i = 0 ; i < e ; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++ ;
    }
    queue<int> q ;
    vector<bool> visited(v , false);
    for(int i = 0 ; i < v ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans ;    
    while(not q.empty()){
        int curnode = q.front() ; q.pop() ;
        ans.push_back(curnode);
        for(int neigh : graph[curnode]){
            indegree[neigh]-- ;
            if(indegree[neigh] == 0){
                q.push(neigh);
            }
        }
    }
    return ans ;
}
```

9. [celebrity problem](https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?leftPanelTab=0)
```cpp

#include<bits/stdc++.h>

int findCelebrity(int n) {
 	stack<int> st ;
    
    for(int i = 0 ; i < n ;i++){
        st.push(i);
    }
    
    while(st.size() > 1){       
        int p1 = st.top() ; st.pop() ;
        int p2 = st.top() ; st.pop() ;
        if(knows(p1 , p2) == true){
            st.push(p2);
        }
        else{
           st.push(p1);
        }
    }
//     if(st.empty()) return -1 ;
    int celeb = st.top() ;
    // now check is celeb is the actual person
    for(int i = 0 ; i < n ; i++){
        if(celeb != i) {
            if(knows(celeb , i)){
                return -1 ;
            }
            if(not knows(i , celeb)){
                return -1; 
            }
        }
    }
    return celeb ;
}
```

10. [cycle undirected graph](https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

bool isCyclic(int curnode , vector<vector<int>> &graph , vector<bool> visited , int parent){
    visited[curnode] = true ;
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            if(isCyclic(neigh , graph ,visited , curnode)){
                return true ;
            }
        }
        else if(neigh != parent){
                return true ;
        }
    }
    return false ;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<bool> visited(n+1 , false);
    vector<vector<int>> graph(n+1) ;
    for(int i = 0 ; i < m ; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i = 1 ; i <= n ;i++){
        if(not visited[i]){
            if(isCyclic(i , graph , visited , -1)){
                return "Yes";
            }
        }
    }
    return "No" ;
}
```

11. [clone graph](https://www.codingninjas.com/codestudio/problems/clone-graph_1103394?leftPanelTab=1)
```cpp

graphNode* clone(graphNode *node , unordered_map<graphNode* , graphNode* > &memo){
    graphNode* newnode = new graphNode(node->data);
    memo[node] = newnode ;
    for(graphNode* neigh : node->neighbours){
        if(memo.find(neigh) != memo.end()){
            newnode->neighbours.push_back(memo[neigh]);
        }    
        else{
            newnode->neighbours.push_back(clone(neigh , memo));
        }
    }
    return newnode ;
}
graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode* , graphNode* > memo ;
      
    return clone(node , memo) ;
}
```

12. [course schedule](https://www.codingninjas.com/codestudio/problems/course-schedule_985288?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

bool isCyclic(int curnode , vector<vector<int>> &graph , vector<bool> &visited , vector<bool> &mystack){
    visited[curnode] = true ;
    mystack[curnode] = true ;
    
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            if(isCyclic(neigh , graph , visited,mystack)){
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
string canFinish(vector<vector<int>>& pre, int n, int m)
{
    vector<vector<int>> graph(n+1);
    
    for(int i = 0 ; i < m ; i++){
        graph[pre[i][0]].push_back(pre[i][1]);
    }
    vector<bool> visited(n+1 , false);
    vector<bool> mystack(n+1 , false);
    
    for(int i = 1 ; i <= n ; i++){
        if(not visited[i]){
            if(isCyclic(i , graph , visited , mystack)){
                return "No" ;
            }
        }    
    }
    return "Yes" ;
}
```
13. [roots of tree having min height]()
```cpp
#include<bits/stdc++.h>

vector<int> minHeightRoots(vector<vector<int>> &edges)
{
    if(edges.size() == 0) return {1} ;
    
    unordered_map<int , vector<int>> graph ;
    unordered_map<int , int> indegree ;
    
    int V = edges[0][0] ;
    
    for(int i = 0 ; i < edges.size() ; i++){
        V = max({V , edges[i][0] , edges[i][1]});
        indegree[edges[i][0]]++ ;
        indegree[edges[i][1]]++ ;
        
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> q ;
    
    // find the leaf nodes
    for(int i = 1 ; i <= V ; i++){
        if(indegree[i] == 1){
            q.push(i);
        }
    }
    
    vector<int> ans ;
    while(V > 2){
        int sz = q.size() ;
        V = V-sz ;
        
        while(sz--){
            int curnode = q.front() ; q.pop() ;
            for(int neigh : graph[curnode]){
               indegree[neigh]-- ;
               if(indegree[neigh] == 1){
                   q.push(neigh);
               }
            }
        }
    }
    
    while(not q.empty()){
        ans.push_back(q.front()); q.pop() ;
    }
    sort(ans.begin() , ans.end());
    return ans ;
}
```

14. [djisktra](https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int e, int source) {
    vector<vector<pair<int,int>>> graph(vertices);
    for(int i = 0 ; i < e ; i++){
        graph[edges[i][0]].push_back({edges[i][2] ,edges[i][1]}) ;
        graph[edges[i][1]].push_back({edges[i][2] ,edges[i][0]}) ;
    }
    set<pair<int,int>> myset ;
    myset.insert({0,0});
    vector<int> dist(vertices , INT_MAX) ;;
    dist[0]  = 0 ;
    
    while(not myset.empty()){
        auto curnode = *myset.begin() ; myset.erase(curnode) ;
        
        for(pair<int,int> neigh : graph[curnode.second]){
            if(dist[neigh.second] > dist[curnode.second] + neigh.first){
                
                auto it = myset.find({dist[neigh.second] , neigh.second});
                
                if(it != myset.end()){
                    myset.erase(it);
                }
                dist[neigh.second] = neigh.first + curnode.first ;
                myset.insert({dist[neigh.second] , neigh.second});
            }
        }
    }
    
    return dist ;
}
```

15. [min swaps to sort arr](https://www.codingninjas.com/codestudio/problems/minimum-swaps-to-sort-array_1806885?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>

int minSwaps(vector<int> &arr)
{
	vector<pair<int,int>> graph ;
    for(int i = 0 ; i < arr.size() ; i++){
        graph.push_back({arr[i] , i});
    }
    sort(graph.begin() , graph.end());
    int swaps = 0 ;
    //find the cycles 
    vector<bool> visited(arr.size() , false);
    for(int i = 0 ; i < arr.size() ; i++){
        if(visited[i] or arr[i] == graph[i].first) continue ;
        int nodes_in_cycle = 0 ;
        
        while(not visited[i]){
            visited[i] = true ;
            i = graph[i].second ;
            nodes_in_cycle++ ;
        }
        if(nodes_in_cycle > 0){
            swaps = swaps + (nodes_in_cycle-1);
        }
    }
    return swaps ;
}
```

16. [M coloring problem](https://www.codingninjas.com/codestudio/problems/m-coloring-problem_981273?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

bool isBip(int curnode , vector<vector<int>> &graph , int color , vector<int> &visited){
    visited[curnode] = color ;
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            if(not isBip(neigh , graph , 3-color , visited)){
                return false ;
            }
        }
        else if(visited[neigh] == color){
            return false ;
        }
    }
    return true ;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    if(m >= 3) return "YES" ;
    bool flag = false ;
    vector<int> visited(mat.size() , 0);

    vector<vector<int>> graph(mat.size()) ;
    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ; j < mat[0].size() ; j++){
            if(mat[i][j] == 1){
                flag = true ;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    if(m == 1){
        return (flag)?"NO":"YES" ;
    }
    for(int i = 0 ; i < mat.size() ; i++){
        if(not visited[i] and not isBip(i , graph ,1, visited )){
            return "NO" ;
        }
    }
    return "YES" ;
}
```

17. [flood fill](https://www.codingninjas.com/codestudio/problems/flood-fill-algorithm_1089687?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>

vector<vector<int>> floodFill(vector<vector<int>> &images, int x, int y, int newColor)
{
    int ROW = images.size() , COL = images[0].size() ;
    
    queue<pair<int,int>> q;
    q.push({x , y});
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int cc = images[x][y] ;
    if(cc == newColor) return images ;
    int neigh_r , neigh_c ;
    
    images[x][y] = newColor ;
    while(not q.empty()){
        int row = q.front().first , col = q.front().second ;
        q.pop() ;
        for(int i = 0 ; i < 4 ; i++){
            neigh_r = row + dx[i] ;
            neigh_c = col + dy[i] ;
            if(neigh_r < 0  or neigh_c < 0 or neigh_r >= ROW or neigh_c >= COL or images[neigh_r][neigh_c] != cc){
                continue ;
            }
            images[neigh_r][neigh_c] = newColor ;
            q.push({neigh_r , neigh_c});
        }
    }
    return images ;
}
```

18. [minimize cash flow](https://www.codingninjas.com/codestudio/problems/minimize-cash-flow-among-a-given-set-of-friends-who-have-borrowed-money-from-each-other_1170048?leftPanelTab=3)
```cpp
#include<bits/stdc++.h>
int N ;
int getMin(vector<int> &arr)
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
int getMax(vector<int> &arr)
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
int minOf2(int x, int y)
{
    return (x<y)? x: y;
}
void findMinCashFlow(vector<int> &amount , vector<vector<int>> &transactions){
    int mxCredit = getMax(amount), mxDebit = getMin(amount);
 
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;
 
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
     
    transactions[mxDebit][mxCredit] = min ;
 
    findMinCashFlow(amount , transactions);
}
vector<vector<int>> minCashFlow(vector<vector<int>>& transactions , int n){
    N = n ;    
    vector<int> amount(N , 0);
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++){
            amount[i] = amount[i] + transactions[j][i] - transactions[i][j] ;
        }
    }
    vector<vector<int>> res(N , vector<int>(N,0));
    
    findMinCashFlow(amount , res);
    return res ;
}
```

19. [water supply in village](https://www.codingninjas.com/codestudio/problems/water-supply-in-a-village_1380956?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>

class DSU{
    // union by rank (optimise set union function)
    // path compression optimisation (optimise set finding function)

private:
    int V;
    vector<int> parents ;
    vector<int> rank ;
    
public:
    DSU(int V){
        this->V = V;
        parents.resize(V , -1);
        rank.resize(V,1);
    }
    int find_set(int node){
        if(this->parents[node] == -1){
            return node ;
        }
        //path compression
        this->parents[node] = this->find_set(this->parents[node]);
        return this->parents[node];
    }

    bool union_set(int node1 , int node2){
        int s1 = find_set(node1);
        int s2 = find_set(node2);
        if(s1 != s2){
            // union by rank
            if(this->rank[s1] > this->rank[s2]){
                this->parents[s2] = s1;
                this->rank[s1] += this->rank[s2] ;
            }
            else{
                this->parents[s1] = s2;
                this->rank[s2] += this->rank[s1] ;
            }
            return true ;
        }
        //failed to join because cycle present
        return false ;
    }
};

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	// create a dummy point represents the well for each house with cost of well as the edge
    vector<vector<int>> edges ;
    
    for(int i = 0 ; i < pipes.size() ; i++){
        edges.push_back({pipes[i][2] , pipes[i][0]-1 , pipes[i][1]-1});
    }
    
    for(int i = 0 ; i < wells.size() ; i++){
        edges.push_back({wells[i],i,n}); // ith house to well of cost well[i]
    }
    sort(edges.begin() , edges.end());
    
    DSU *d = new DSU(n+1);
    int mstsum = 0 ;
    
    for(int i = 0 ; i < edges.size() ; i++){
        if(d->union_set(edges[i][1] , edges[i][2])){
            mstsum += edges[i][0] ;
        }    
    }
    return mstsum ;
}
```

20. [min steps to reach target](https://www.codingninjas.com/codestudio/problems/minimum-steps-to-reach-target-by-a-knight_893050?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int N ;

bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row > N or col > N ;
}
int dx[8] = {-2 , -1 ,-2 , -1 ,1 ,2 , 2 , 1};
int dy[8] = {-1 , -2 , 1 , 2 ,-2 ,-1 ,1 , 2};

int minSteps(pair<int, int> kp, pair<int, int> T, int size) {
    // Write your code here.
    N = size ;    
    queue<pair<int,int>> q ; // O(n)
    q.push(kp);
    vector<vector<bool>> visited(size+1 , vector<bool>(size+1 , false));
    
    visited[kp.first][kp.second] = true ;
    
    int moves = 0 ;
    
    while(not q.empty()){
        int sz = q.size();    
        while(sz--){
            kp = q.front() ; q.pop() ;
            if(kp.first == T.first and kp.second == T.second){
                return moves ;
            }
            for(int i = 0 ; i < 8 ; i++){
                int neigh_r = kp.first + dx[i] ;
                int neigh_c = kp.second + dy[i] ;
                
                if(isInvalid(neigh_r , neigh_c) or visited[neigh_r][neigh_c] == true){
                    continue ;
                }
                visited[neigh_r][neigh_c] = true ;
                q.push({neigh_r , neigh_c});
            }
        }
        moves++ ;
    }
    return moves ;
}
```

21. [strongly connected components](https://www.codingninjas.com/codestudio/problems/strongly-connected-components-tarjan-s-algorithm_985311?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

void dfs(int curnode , vector<vector<int>> &graph , vector<bool> &visited , stack<int> &mystack){
    
    visited[curnode] = true ;
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            dfs(neigh , graph , visited , mystack);
        }    
    }
    mystack.push(curnode);
}
void helper(int curnode , vector<vector<int>> &graph , vector<bool> &visited , vector<int> &mystack){
    visited[curnode] = true ;
    mystack.push_back(curnode);
    for(int neigh : graph[curnode]){
        if(not visited[neigh]){
            helper(neigh , graph , visited , mystack);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n);
    vector<vector<int>> reversed_graph(n);
    
    for(int i = 0 ; i < edges.size() ; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        reversed_graph[edges[i][1]].push_back(edges[i][0]);
    }
    // topological sort ;
    vector<bool> visited(n , false);
    stack<int> mystack ;
    for(int i = 0 ; i < n ; i++){
        if(not visited[i]){
            dfs(i , graph , visited , mystack);
        }
    }
    vector<bool> visited1(n , false) ;
    vector<vector<int>> ans ;
    
    while(not mystack.empty()){
        int curnode = mystack.top() ; mystack.pop() ;
        if(not visited1[curnode]){
            vector<int> temp ;
            helper(curnode , reversed_graph , visited1 , temp);
            ans.push_back(temp);
        }
    }
    return ans ;
}
```