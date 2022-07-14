# Backtracking 

1. [longest unique value paths](https://www.codingninjas.com/codestudio/problems/longest-univalue-path_985291?leftPanelTab=0)
```cpp
int helper(BinaryTreeNode<int> *root , int &maxval , int prev_val){
    if(not root) return 0 ;
    
    int ls = helper(root->left , maxval , root->data);
    int rs = helper(root->right , maxval , root->data);
    
    maxval = max(maxval , ls+rs);
    
    return (root->data == prev_val)?1+max(ls,rs):0 ;
}
int longestUnivaluePath(BinaryTreeNode<int> *root) {
    int maxval = 0 ;
    helper(root , maxval , INT_MIN);
    return maxval ;
}
```

2. [rat in a maze](https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_758966?leftPanelTab=0)
```cpp
int N ;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= N or col >= N ;
}
void helper(vector<vector<int>> &maze , int row , int col , vector<int> &path ,vector<vector<int>> &ans){
    if(maze[row][col] == 0) return ;
    if(row == N-1 and col == N-1){
        ans.push_back(path);
        return ;
    }    
    for(int i = 0 ; i < 4 ; i++){
        int neigh_r = row + dx[i] ;
        int neigh_c = col + dy[i] ;
        int idx = neigh_r*N+neigh_c ;

        if(isInvalid(neigh_r , neigh_c) or path[idx] == 1){
            continue ;
        }
        path[idx] = 1 ;
        helper(maze , neigh_r , neigh_c , path , ans);
        path[idx] = 0 ;
    }
}
vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
   if(n == 0) return vector<vector<int>>() ;
    
   N = n ;
   vector<int> path(n*n , 0);
   vector<vector<int>> ans ;
   if(maze[n-1][n-1] == 0) return ans ;
   path[0] = 1 ;
   helper(maze , 0 , 0 , path , ans);    
   return ans ;
}
```

3. [permutation](https://www.codingninjas.com/codestudio/problems/print-permutations-string_758958?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>
int N ;
void permute(string &str , int curstart , vector<string> &res){
    if(curstart == N){
        res.push_back(str);
        return ;
    }
    for(int i = curstart ; i < N ; i++){
        swap(str[i] , str[curstart]);
        permute(str , curstart+1 , res);        
        swap(str[i] , str[curstart]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> res ;
     N = s.size();
    permute(s , 0 , res);
    return res ;
}
```

4. [word break-1](https://www.codingninjas.com/codestudio/problems/word-break-1_758963?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int N ;

vector<string> helper(string str , unordered_set<string> &dict){
    vector<string> res ;
    
    if(dict.find(str) != dict.end()){
        res.push_back(str);    
    }
    string curstr ;     

    for(int i = 0 ; i < str.size()-1 ; i++){
        curstr = str.substr(0,i+1);
        if(dict.find(curstr) != dict.end()){
            for(string prev : helper(str.substr(i+1) , dict)){
                res.push_back(curstr + " " + prev);
            }
        }
    }
    
    return res ;
}
vector<string> getAllValidSentences(string &sentence, vector<string> &dictionary){
    unordered_set<string> dict(dictionary.begin() , dictionary.end());
    return helper(sentence ,dict);
}
```

5. [islands count](https://www.codingninjas.com/codestudio/problems/find-number-of-islands_630512?leftPanelTab=3)
```cpp
int M , N ;
int dx[8] = {1,1,1,-1,-1,-1,0,0} ;
int dy[8] = {1,0,-1,1,0,-1,1,-1} ;

bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}
void dfs(int row , int col , int **arr){
    arr[row][col] = 0 ;
    
    for(int i = 0 ; i < 8 ; i++){
        int neigh_r = row + dx[i] ;
        int neigh_c = col + dy[i] ;
        
        if(isInvalid(neigh_r , neigh_c) or arr[neigh_r][neigh_c] == 0){
            continue ;
        }
        dfs(neigh_r , neigh_c , arr);
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    M = n ; N = m ; 
    int islands = 0 ;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(arr[i][j] == 1){
                islands++ ;
                dfs(i,j,arr);
            }
        }
    }
    return islands ;
}
```

6. [partial bst](https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0)
```cpp
bool helper(BinaryTreeNode<int> *root , int minval, int maxval){
    if(not root) return true ;
    if(root->data > maxval or root->data < minval) return false ;
    
    return helper(root->left ,minval , root->data) and helper(root->right , root->data , maxval);
}
bool validateBST(BinaryTreeNode<int> *root) {
    return helper(root , INT_MIN , INT_MAX);
 }
```

7. [palindrome partioning](https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_799931?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
bool isPalindrome(string &str){
    int left = 0 , right = str.size()-1 ;
    while(left < right){
        if(str[left] != str[right]) return false ;
        left++ ; right-- ;
    }
    return true ;
}

int N ;
void helper(int pos , string &s , vector<string> &curr , vector<vector<string>> &res){
    if(pos == N){
        res.push_back(curr);
        return ;
    }
    string tt = "" ;
    for(int i = pos ; i < N ; i++){
        tt.push_back(s[i]);
        if(isPalindrome(tt)){
            curr.push_back(tt);
            helper(i+1 , s , curr , res);
            curr.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res ;
    vector<string> curr ;
    N = s.size() ;
    helper(0 , s , curr , res);
    return res ;
}
```

8. [tug of war](https://www.codingninjas.com/codestudio/problems/tug-of-war_985253?leftPanelTab=0)
```cpp
int totalsum ;

void helper(int pos , int counts , int &minsum ,int cursum,vector<int> &arr){
    if(counts == 0){
        minsum = min(minsum ,abs(totalsum-2*cursum));
        return ;
    }  
    if(pos == arr.size()) return ;
    
    helper(pos+1 , counts-1 , minsum , cursum+arr[pos] , arr);
    helper(pos+1 , counts , minsum , cursum , arr); 
}
int tugOfWar(vector<int> &arr, int n)
{
    totalsum = accumulate(arr.begin() , arr.end() , 0) ;
    int minsum = INT_MAX ; 
    helper(0 ,n/2,minsum,0 , arr);
    return minsum ;
}
```

9. [restore ip addresses](https://www.codingninjas.com/codestudio/problems/ip-address_992846?leftPanelTab=0)
```cpp
int N ;

void helper(string &str , int pos , string curip , int points ,     vector<string> &res){
    
    if(pos >= N) return ;
    if(points == 1 and pos >= N-3){
        if(pos != N-1 and str[pos] == '0') return ;
        string num = str.substr(pos);
        if(stoi(num) > 255) return ;
        curip = curip + "." + num ;
        res.push_back(curip); return ;
    }
    if(points == 1) return ;
    if(str[pos] == '0'){
        if(points == 4){
            helper(str , pos+1 , "0" ,points-1 , res);         
        }
        else{
            helper(str,pos+1 , curip+".0" , points-1,res);
        }
        return ;
    }
    string tt ;    
    for(int i = 0 ; i < 3 and pos+i < N-1; i++){
        tt.push_back(str[pos+i]);
        if(stoi(tt) <= 255){
            if(points == 4){
                helper(str , pos+i+1 ,tt ,points-1,res);
            }
            else{
                helper(str , pos+i+1 , curip+"."+tt , points-1,res);
            }
        }
    }
}
vector<string> generateIPAddress(string s)
{
    N = s.size() ;
    vector<string> res ;
    helper(s , 0 , "" , 4 , res);
    return res ;
}
```

10. [shortest path in bt](https://www.codingninjas.com/codestudio/problems/shortest-path-in-a-binary-matrix_699835?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int X , Y ;
int M , N ;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}

int findShortestPath(vector<vector<bool>>& mat, 
                        int sourceX, int sourceY,  
                        int destX, int destY,  
                        int n, int m){
    if(mat[destX][destY] == 0) return -1 ;
    M = n ; N = m ;
    queue<pair<int,int>> q ;
    q.push({sourceX , sourceY});
    int level = 1 ;
    while(not q.empty()){
        int sz = q.size(); 
        while(sz--){
            int row = q.front().first , col = q.front().second ;
            q.pop() ;
            if(row == destX and col == destY) return level ;
            
            for(int i = 0 ; i < 4 ; i++){
                int neigh_r = row + dx[i] ; 
                int neigh_c = col + dy[i] ;
                if(isInvalid(neigh_r , neigh_c) or mat[neigh_r][neigh_c] == 0){
                    continue ;
                }
                mat[neigh_r][neigh_c] = 0 ;
                q.push({neigh_r , neigh_c});    
            }
        }
        level++ ;
    }
    return -1 ;
}
```

11. [partition to k equal subset](https://www.codingninjas.com/codestudio/problems/partition-to-k-equal-sum-subsets_843262?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int target ;
int N ;

bool helper(vector<int> &nums , int pos , int k , int cursum , vector<bool> &visited){
    
    if(k == 0) return true ;
    if(cursum == target){
            return helper(nums , 0 , k-1 , 0 , visited) ;
    }
    if(pos == N) return false ;
    
    if(not visited[pos] and cursum + nums[pos] <= target){
         // we can add it
        visited[pos] = true ;
        if(helper(nums ,pos+1 , k , cursum+nums[pos] , visited)){
            return true ;
         }
         visited[pos] = false ;
    }
    return helper(nums , pos+1 , k , cursum , visited);    
}
bool canPartitionKSubsets(vector<int>& nums, int n, int k)
{
    int totalsum = accumulate(nums.begin() , nums.end() , 0);
    if(totalsum%k != 0) return false ;
    target = totalsum/k ;
    vector<bool> visited(n , false);
    N = n ;    
    return helper(nums , 0 , k , 0 , visited);
}
```

12. [additive number](https://www.codingninjas.com/codestudio/problems/ninja-s-string_1279685?leftPanelTab=0)
```cpp
int N  ;
bool helper(string &str , int pos , int prev1 , int prev2 ,bool atleast){
    if(pos == N and atleast and prev1 != -1 and prev2 != -1) return true ;
    if(pos == N or str[pos] == '0') return false ;
    
    if(prev1 == -1){
        // first num 
        int num1 = 0 ;
        for(int i = 0 ; i < N-2 ; i++){
            num1 = num1*10 + (str[i] - '0');
            if(helper(str , i+1 , num1 , prev2 , false)){
                return true ;
            }
        }
        return false ;
    }
    else if(prev2 == -1){
        // second num
        int num2 = 0 ;
        for(int i = pos ; i < N-1 ; i++){
            num2 = num2*10 + (str[i] - '0');
            if(helper(str , i+1 , prev1 , num2 , false)){
                return true ;
            }
        }
        return false ;
    }   
    int num3 = 0 ;
    for(int i = pos ; i < N ; i++){
        num3 = num3*10 + (str[i] - '0');
        if(prev1 + prev2 == num3){
            if(helper(str , i+1 , prev2 , num3 , true)){
                return true ;
            }
        }
    }
    return false ;
}
bool ninjaString(string &str)
{
	if(str.size() < 3) return false ;
    N = str.size();
    return helper(str , 0 , -1 , -1 , false);
}
```

13. [word ladder](https://www.codingninjas.com/codestudio/problems/word-ladder_1102319?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int wordLadder(string begin, string end, vector<string> &d) 
{
	unordered_set<string> dict(d.begin() , d.end());
    queue<string> q ;
    unordered_set<string> visited ;
    visited.insert(begin);
    q.push(begin);
    string alphabets = "abcdefghijklmnopqrstuvwxyz" ;
    
    int levels = 1;
    string curr ;
    
    while(not q.empty()){
        int sz = q.size();
        while(sz--){
            curr = q.front() ; q.pop() ;
            if(curr == end) return levels ;
            for(int i = 0 ; i < curr.size() ; i++){
                char prev = curr[i] ;
                for(char ch : alphabets){
                    curr[i] = ch ;
                    if(visited.find(curr) == visited.end() and dict.find(curr) != dict.end()){
                        visited.insert(curr);
                        q.push(curr);
                    }
                }
                curr[i] = prev ;
            }
        }
        levels++ ;
    }
    return -1 ;
}
```
14. [combination sum2](https://www.codingninjas.com/codestudio/problems/combination-sum-ii_1112622?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

void helper(int pos , int cursum ,int target , vector<int> &arr , vector<int> &path , vector<vector<int>> &ans ){
    if(cursum == target){
        ans.push_back(path);
        return ;
    }
    if(pos == arr.size()) return ;
    for(int i = pos ; i < arr.size() ; i++){
        if(i > pos and arr[i-1] == arr[i]) continue ;    
        if(cursum + arr[i] <= target){
            path.push_back(arr[i]);
            helper(i+1 , cursum+arr[i],target , arr , path , ans);
            path.pop_back() ;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin() , arr.end());
    vector<vector<int>> ans ;
    vector<int> path ;
    helper(0 , 0 , target , arr ,path ,ans);
    return ans ;
}
```

15. [shortest safe route](https://www.codingninjas.com/codestudio/problems/shortest-safe-route-in-a-field-with-landmines_1164264?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int M , N ;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}

int shortestPath(vector<vector<int>> &field)
{
    M = field.size() ; N = field[0].size() ;
    for(int row = 0 ; row < M ; row++){
        for(int col = 0 ; col < N ; col++){
            if(field[row][col] == 0){
                for(int i = 0 ; i < 4 ; i++){
                    int neigh_r = row + dx[i] ;
                    int neigh_c = col + dy[i] ;
                    if(isInvalid(neigh_r , neigh_c) or field[neigh_r][neigh_c] == 0){
                        continue ;
                    }
                    field[neigh_r][neigh_c] = -1 ;   
                }
            }
        }
    }   
    int level = 0;
    queue<pair<int,int>> q ;
    for(int row = 0 ; row < M ; row++){
        if(field[row][0] == 1){
            field[row][0] = -1 ;
            q.push({row , 0});
        }
    }
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            int row = q.front().first , col = q.front().second ;
            q.pop() ;
            if(col == N-1){
                return level ;
            }
             for(int i = 0 ; i < 4 ; i++){
                    int neigh_r = row + dx[i] ;
                    int neigh_c = col + dy[i] ;
                    if(isInvalid(neigh_r , neigh_c) or field[neigh_r][neigh_c] != 1){
                        continue ;
                    }
                    field[neigh_r][neigh_c] = -1 ;   
                    q.push({neigh_r , neigh_c});
             }
        }
        level++;
    }
    return -1 ;
}
```

16. [generate parenthesis](https://www.codingninjas.com/codestudio/problems/print-parentheses_982760?leftPanelTab=0)
```cpp
void helper(int open_paren , int closed_paren , int n ,string &curr){
    if(n == 0){
        cout<< curr << endl ;
        return ;
    }
    if(open_paren < closed_paren){
        curr.push_back('}');
        helper(open_paren , closed_paren-1 , n-1 , curr);
        curr.pop_back() ;
    }
    if(open_paren > 0){
        curr.push_back('{');
        helper(open_paren-1 , closed_paren , n-1 , curr);
        curr.pop_back() ;
    }
}
void printParantheses(int n) {
    string curr = "" ;
    helper(n , n , 2*n ,curr);
}
```

17. [k path sum in bt](https://www.codingninjas.com/codestudio/problems/k-sum-path-in-a-binary-tree_893543?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

void helper(BinaryTreeNode<int> *root , int target , vector<int> &container , vector<vector<int>> &ans){
    if(not root) return ;
    container.push_back(root->data);
    helper(root->left , target , container , ans);
    helper(root->right , target , container , ans);
    
    int sum = 0 ;
    vector<int> temp ;
    
    for(int i = container.size()-1 ; i >= 0 ; i--){
        sum += container[i];
        temp.push_back(container[i]);
        if(sum == target){
            ans.push_back(temp);
        }
    }
    
    container.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<vector<int>> ans ;
    vector<int> container ;
    helper(root , k , container , ans);
    for(vector<int> &t : ans) reverse(t.begin() , t.end());
    return ans ;
}
```

18. [path in maze](https://www.codingninjas.com/codestudio/problems/paths-in-a-maze_981287?leftPanelTab=0)
```cpp
int M , N ;
int dx[4] =   {1,-1,0,0};
int dy[4] =   {0,0,1,-1};
char dir[4] = {'D' ,'U' , 'R' , 'L'};

bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}

void helper(int row , int col ,vector<vector<bool>> &arr,string &path , vector<string> &res){
    if(row == M-1 and col == N-1){
        res.push_back(path); return ;
    }
    for(int i = 0 ; i < 4 ; i++){
        int neigh_r = row + dx[i] ;
        int neigh_c = col + dy[i] ;
        if(isInvalid(neigh_r , neigh_c) or arr[neigh_r][neigh_c] == 0){
            continue ;
        }
        arr[neigh_r][neigh_c] = 0 ;
        path.push_back(dir[i]);
        helper(neigh_r , neigh_c , arr, path , res);
        path.pop_back();
        arr[neigh_r][neigh_c] = 1 ;
        
    }
}
vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    vector<string> ans ;
    M = arr.size() ; N = arr[0].size() ;
    if(arr[0][0] == 0 or arr[M-1][N-1] == 0) return ans ;
    arr[0][0] = 0 ;
    string path = "" ;
    helper(0,0,arr , path , ans);
    return ans ;
}
```

19. [letter combination](https://www.codingninjas.com/codestudio/problems/letter-combinations-of-a-phone-number_983623?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

unordered_map<char , string> memo = {
    {'2', "abc"} ,
    {'3' , "def"} ,
    {'4' , "ghi"} ,
    {'5' , "jkl"} ,
    {'6' , "mno"} ,
    {'7' , "pqrs"} ,
    {'8' , "tuv"} ,
    {'9' , "wxyz"} 
};
void helper(string &str , int pos , string &curpath , vector<string> &res){
    if(pos == str.size()){
        res.push_back(curpath) ;
        return ;
    }
    for(char ch : memo[str[pos]]){
        curpath.push_back(ch);
        helper(str , pos+1 , curpath , res);
        curpath.pop_back();
    }
}
vector<string> combinations(string s){
	string curpath = "" ;
    vector<string> res ;
    helper(s , 0 , curpath , res);
    return res ;
}
```

20. [bst to greater sum tree](https://www.codingninjas.com/codestudio/problems/convert-bst-to-the-greater-sum-tree_800290?leftPanelTab=0)
```cpp
int helper(TreeNode<int> *root , int topsum){
    if(not root){
        return 0 ;
    }
    int rs = helper(root->right , topsum);
    int ls = helper(root->left , topsum+root->val+rs);
    int temp = root->val ;
    root->val = rs + topsum ;
    return temp+ls+rs ;
}
TreeNode<int> *convertBstToGreaterSum(TreeNode<int> *root)
{
    helper(root , 0);
    return root ;
}
```

21. [maze with N doors and key](https://www.codingninjas.com/codestudio/problems/maze-with-n-doors-and-1-key_839809?leftPanelTab=0)
```cpp
int N ;
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= N or col >= N ;
}

bool helper(int row , int col , vector<vector<int>> &maze , bool keyused , vector<vector<vector<bool>>> &memo){
    if(row == N-1 and col == N-1) return true ;
    if(memo[row][col][keyused] == false) return false ;
    
    if(not isInvalid(row+1 , col)){
        if(maze[row+1][col] == 0){
            // no key req 
            if(helper(row+1 , col , maze , keyused , memo)){
                return true ;
            }
        }
        else if(not keyused){
            if(helper(row+1 , col , maze , true , memo)){
                return true ;
            }
        }
    }    
    //rightward
    if(not isInvalid(row , col+1)){
        if(maze[row][col+1] == 0){
            // no key req 
            if(helper(row , col+1 , maze , keyused , memo)){
                return true ;
            }
        }
        else if(not keyused){
            if(helper(row , col+1 , maze , true , memo)){
                return true ;
            }
        }
    }    
    return memo[row][col][keyused]=false ;
}

bool mazeWithNDoorsAnd1Key(vector<vector<int>> &maze, int n)
{
    N = n ;
    vector<vector<vector<bool>>> memo(n , vector<vector<bool>>(n,vector<bool>(2,true)));
    return (maze[0][0] == 1)?helper(0,0,maze,true , memo):helper(0,0,maze,false , memo);
}
```

22. 