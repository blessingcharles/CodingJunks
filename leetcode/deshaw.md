1. [Relative sort Array](https://leetcode.com/problems/relative-sort-array/)
```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> memo ;
        for(int ele : arr1) memo[ele]++ ;
        int ptr = 0 ;
        for(int ele : arr2){
            while(memo[ele]--){
                arr1[ptr] = ele ;
                ptr++ ;
            }
            memo.erase(ele);
        }
        
        for(auto it = memo.begin() ; it != memo.end() ; it++){
            while(it->second--){
                arr1[ptr] = it->first ;
                ptr++ ;
            }
        }
        return arr1 ;
    }
};
```

2. [freedom tail](https://leetcode.com/problems/freedom-trail/)
```cpp
class Solution {
public:
    string key ; 
    int N ;
    int dp[101][101] ;
    
    int helper(int kpos , int rpos , vector<vector<int>> &graph){
        if(kpos == key.size()) return 0 ;
        if(dp[kpos][rpos] != -1) return dp[kpos][rpos] ;
        
        int mini = 1e9 ;
        for(int nxt : graph[key[kpos] - 'a']){
            int f_dist = abs(rpos - nxt) ;
            int r_dist = N-f_dist ;
            
            mini = min(mini , min(f_dist , r_dist) + helper(kpos+1 , nxt , graph));
        }
        return dp[kpos][rpos]=1+mini ;
    }
    int findRotateSteps(string &ri, string &ke) {
        key = ke ;
        N = ri.size() ;
        vector<vector<int>> graph(26) ;
        
        for(int i = 0 ; i < ri.size() ; i++){
            graph[ri[i]-'a'].push_back(i);
        }
        memset(dp , -1 ,sizeof(dp));
        return helper(0,0 , graph);
    }
};
```

3. [critical connection in network](https://leetcode.com/problems/critical-connections-in-a-network/)
```cpp
class Solution {
    vector<vector<int>> graph ;
    
    vector<int> disc , low ;
    vector<bool> visited ;
    int time = 0 ;
public:
    vector<vector<int>> bridges ;
    
    void dfs(int curnode , int parent){
        visited[curnode] = true ;
        disc[curnode] = time++ ;
        low[curnode] = disc[curnode] ;
        
        for(int neigh : graph[curnode]){
            if(not visited[neigh]){
                dfs(neigh , curnode);   
                low[curnode] = min(low[curnode] , low[neigh]);
                
                if(low[neigh] > disc[curnode]){
                    bridges.push_back({curnode , neigh});
                }
            }
            else if(parent != neigh){
                low[curnode] = min(low[curnode] , disc[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n) ;
        disc.resize(n) ;
        low.resize(n) ;
        
        visited.resize(n , false);
        for(vector<int>& edge : connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1);
        return bridges ;
     }
};
```

4. [paint house 3](https://leetcode.com/problems/paint-house-iii/)
```cpp
class Solution {
public:
    int N , M;
    int dp[101][21][101] ;
    
    /*
        m houses  ,  n colors , target -- neighbourhood
    */
    int helper(int pos , int prevcolor , int rem , vector<int>& houses , vector<vector<int>> &cost){
        if(pos < 0 and rem == 0) return 0 ;
        if(pos < 0 or rem < 0) return 1e8 ;
        if(dp[pos][prevcolor][rem] != -1)
            return dp[pos][prevcolor][rem] ;
        
        // Is current house is painted
        if(houses[pos] != 0){
            if(prevcolor == houses[pos]){
                // same neighbourhood
                return dp[pos][prevcolor][rem]=helper(pos-1 ,prevcolor , rem  , houses , cost);
            }
            else{
                return dp[pos][prevcolor][rem]=helper(pos-1 , houses[pos] , rem-1 , houses , cost);
            }
            
        }
        int mincost = 1e8 ;
        for(int color = 1 ; color <= N ; color++){
            // if prevcolor == color : same neighbourhood
            if(prevcolor == color){
                int curcost = cost[pos][color-1] + helper(pos-1 , color , rem , houses , cost);
                mincost = min(mincost , curcost);
            }
            else{
                int curcost = cost[pos][color-1] + helper(pos-1 , color , rem-1 , houses , cost);
                mincost = min(mincost , curcost);
            }
        }
        return dp[pos][prevcolor][rem]=mincost ;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        N = n ;
        memset(dp, -1 , sizeof(dp));
        int ans = helper(m-1 , 0 , target , houses , cost);
        
        return (ans >= 1e8)?-1:ans ;
    }
};
```

5. [first missing positive](https://leetcode.com/problems/first-missing-positive/)
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> memo(nums.begin() , nums.end());
        
        for(int i = 1 ; i <= nums.size() ; i++){
            if(memo.find(i) == memo.end()) return i ;
        }
        return nums.size()+1 ;
    }
};
class Solution {
public:
    int N ;

bool isInvalid(int idx){
    return idx >= N or idx < 0 ;
}
    int firstMissingPositive(vector<int>& A) {
    N = A.size() ;
    /*
        The answer must be in the rangle og 1..N+1
        
        1. Make all negatives 0
        2. take abs(A[i]) and then map it to A[A[i]-1] , mark that place negative
    */
    
    // make all negatives zero
    for(int i = 0 ; i < N ; i++){
        if(A[i] < 0){
            A[i] = 0 ;
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        int cur_idx = abs(A[i])-1 ;
        if(isInvalid(cur_idx)){
            continue ;
        }
        if(A[cur_idx] == 0){
            A[cur_idx] = -1*(N+1) ;
        }        
        else if(A[cur_idx] > 0){
            A[cur_idx] = A[cur_idx]*-1 ;
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        if(A[i-1] >= 0){
            return i ;
        }
    }
    
    return N+1 ;
    }
};
``` 

6. [verifying an alien dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)
```cpp
class Solution {
public:
    unordered_map<char,int> memo ;
    
    bool islesser(string &str1 , string &str2){
        int n = min(str1.size() , str2.size()) ;
        
        for(int i = 0 ; i < n ; i++){
            if(memo[str1[i]] < memo[str2[i]]) return true ;
            else if(memo[str1[i]] > memo[str2[i]]) return false ;
        }
        
        return str1.size() <= str2.size() ;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0 ; i < order.size() ; i++){
            memo[order[i]] = i ;
        }
        
        for(int i = 1 ; i < words.size() ; i++){
            if(not islesser(words[i-1] , words[i])){
                // cout << i << endl ;
                return false ;
            }                 
        }
        return true ;
    }
};
```