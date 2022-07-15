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

22. [flip game 2](https://www.codingninjas.com/codestudio/problems/ninja-and-flip-game_1232645?leftPanelTab=0)
```cpp
bool canNinjaWin(string& str) {
    for(int i = 0 ; i < str.size()-1 ; i++){
        if(str[i] == '$' and str[i+1] == '$'){
            string tt = str.substr(0,i) + "**" + str.substr(i+2);
            if(not canNinjaWin(tt)){
                // if opponent can't win
                return true ;
            }            
        }
    }
    return false ;
}
```

23. [num with same consecutive diff](https://www.codingninjas.com/codestudio/problems/numbers-with-same-consecutive-differences_1235179?leftPanelTab=0)
```cpp
void helper(int num , int len , int diff , vector<int> &ans){
    if(len == 0){
        ans.push_back(num) ; 
        return  ;
    }
    int next_num1 =(num%10)-diff ;
    if(next_num1 >= 0){
        helper(num*10+next_num1 , len-1 , diff , ans);
    }
    int next_num2 = (num%10)+diff ;
    if(next_num2 == next_num1) return ;
    
    if(next_num2 <= 9){
        helper(num*10+next_num2 , len-1 , diff , ans);
    }
}

vector<int> numberWithSameConsecutiveDifference(int N, int K)
{
	vector<int> ans ;
    for(int i = 1 ; i <= 9 ; i++){
        helper(i ,N-1,K , ans);
    }
    return ans ;
}
```
24. [number of squareful array](https://www.codingninjas.com/codestudio/problems/number-of-squareful-arrays_1235194?leftPanelTab=0)
```cpp
bool isSquare(long num){
    long ss = sqrt(num) ;
    return (ss*ss) == num ;
}
int counter ;
void helper(int cc , vector<int> &arr , vector<bool> &used , int prev){
    if(cc == arr.size()){
        counter++ ; return ;        
    }
    for(int i = 0 ; i < arr.size() ; i++){
        if(used[i]) continue ;
        if(i > 0 and arr[i] == arr[i-1] and not used[i-1]) continue ;
        if(prev != -1 and not isSquare(prev+arr[i])) continue ;
        used[i] = true ;
        helper(cc+1 , arr, used , arr[i]);
        used[i] = false ;
    }
}
int numberOfSquarefulArrays(vector<int>& arr, int n){
    vector<bool> used(n , false);
    sort(arr.begin() , arr.end());
    counter = 0 ;
    
    helper(0 , arr , used , -1);    
    return counter ;
}
```
25. [flood fill](https://www.codingninjas.com/codestudio/problems/flood-fill_1082141?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int M , N ;
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    M = n ; N = m ;
    queue<pair<int,int>> q ;
    q.push({x,y});
    int target = image[x][y] ;
    image[x][y] = p ;
    
    while(not q.empty()){
        int row = q.front().first , col = q.front().second ;
        q.pop() ;
        for(int i = 0 ; i < 4 ; i++){
            int neigh_r = row + dx[i] ;
            int neigh_c = col + dy[i] ;
            if(isInvalid(neigh_r , neigh_c) or image[neigh_r][neigh_c] != target){
                continue ;
            }
            image[neigh_r][neigh_c] = p ;
            q.push({neigh_r , neigh_c});
        }
    }
    return image ;
}
```
26. [max depth of bt](https://www.codingninjas.com/codestudio/problems/maximum-depth-of-a-binary-tree_1090542?leftPanelTab=0)
```cpp
int findMaxDepth(TreeNode<int> *root) 
{
    if(not root) return 0 ;
    int ls = findMaxDepth(root->left);
    int rs = findMaxDepth(root->right);
    return 1+max(ls,rs);
}
```
27. [factor combination](https://www.codingninjas.com/codestudio/problems/factor-combinations_1232628?leftPanelTab=0)
```cpp
int maxf ;
void helper(int start ,int target, vector<int> &path , vector<vector<int>> &ans){
    if(target == 1){
        ans.push_back(path);
        return ;
    }
    if(start > target) return ;
    for(int i = start ; i < maxf ;i++){
        if(target%i == 0){
            path.push_back(i);
            helper(i , target/i , path , ans);
            path.pop_back();
            if(target/i == 1) break ;
        }    
    }
}
vector<vector<int>> factorCombinations(int n) 
{
	vector<vector<int>> ans ;
    vector<int> path ;
    maxf = n ;
    helper(2 , n , path , ans);
    return ans ;
}
```
28. [largest valid sequence](https://www.codingninjas.com/codestudio/problems/construct-the-lexicographically-largest-valid-sequence_1233105?leftPanelTab=0)
```cpp
#include <bits/stdc++.h>
using namespace std;
int N ;
bool helper(vector<int> &arr , int pos , vector<bool> &visited){
    if(pos == arr.size()){
        return true ;
    }
    if(arr[pos] != -1){
        return helper(arr , pos+1 , visited);
    }
    for(int i = N ; i >= 1 ; i--){
        if(visited[i]) continue ;
        visited[i] = true ;
        arr[pos] = i ;
        if(i == 1){
            if(helper(arr , pos+1 , visited)){
                return true ;
            }          
        }
        else if(pos+i < arr.size() and arr[pos+i] == -1){
            arr[pos+i] = i ;
            if(helper(arr , pos+1 , visited)){
                return true ;
            }
            arr[pos+i] = -1 ;
        }
        visited[i] = false ;
        arr[pos] = -1 ;
    }        
    return false ;    
}
vector<int> validSequence(int n)
{
    vector<int> arr(2 * n - 1, -1);
    vector<bool> visited(n+1 , false);
    N = n;
    helper(arr, 0, visited);
    return arr;
}
```
29. [word ladder 1](https://www.codingninjas.com/codestudio/problems/word-search_892986?leftPanelTab=0)
```cpp
int M , N ;
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool dfs(int row , int col , int pos , vector<vector<char>> &board , string &word){
    if(pos == word.size()) return true ;
    char curchar = board[row][col] ;
    board[row][col] = '.' ;
    
    for(int i = 0 ; i < 4 ; i++){
        int neigh_r = row + dx[i] , neigh_c = col + dy[i] ;
        if(isInvalid(neigh_r , neigh_c) or board[neigh_r][neigh_c] != word[pos]) continue ;
        if(dfs(neigh_r , neigh_c , pos+1 , board , word)) return true ;
    }
    board[row][col] = curchar ;
    return false ;
}
bool present(vector<vector<char>> &board, string word, int n, int m) 
{
    M = n ; N = m ;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == word[0] and dfs(i,j,1 , board , word)){
                return true ;
            }
        }
    }
    return false ;
}
```

30. [word boggle](https://www.codingninjas.com/codestudio/problems/word-boggle_1081474?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int M , N ;
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= M or col >= N ;
}
int dx[8] = {1,1,1,-1,-1,-1,0,0};
int dy[8] = {-1,0,1,-1,0,1,1,-1};

bool dfs(int row , int col , int pos , vector<vector<char>> &board , string &word){
    if(pos == word.size()) return true ;
    char curchar = board[row][col] ;
    board[row][col] = '.' ;
    
    for(int i = 0 ; i < 8 ; i++){
        int neigh_r = row + dx[i] , neigh_c = col + dy[i] ;
        if(isInvalid(neigh_r , neigh_c) or board[neigh_r][neigh_c] != word[pos]) continue ;
        if(dfs(neigh_r , neigh_c , pos+1 , board , word)){
             board[row][col] = curchar ;
            return true ;
        }
    }
    board[row][col] = curchar ;
    return false ;
}
vector<string> findPossibleWords(vector<string> arr, vector<vector<char>> mat){
	sort(arr.begin() , arr.end());
    vector<string> res ;
    M = mat.size() ; N = mat[0].size() ;
    for(string &word : arr){
        bool founded = false ;
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                   if(mat[i][j] == word[0] and dfs(i,j,1 , mat , word)){
                        res.push_back(word);
                        founded = true ;
                        break ;
                   }
            }
            if(founded) break ;
        }
    }
    return res ;
}
```

31. [settle debt]()
```cpp
#include<bits/stdc++.h>
bool isSameSign(int num1 , int num2){
    return (num1 < 0) ^ (num2 > 0);
}

int dfs(int start , vector<int> &transactions){
    while(start < transactions.size() and transactions[start] == 0){
        start++ ;
    }
    if(start == transactions.size()) return 0 ;
    
    int minval = INT_MAX ;
    for(int i = start+1 ; i < transactions.size() ; i++){
        if(isSameSign(transactions[start] , transactions[i])){
            continue ;            
        }    
        transactions[i] += transactions[start] ;
        minval = min(minval , 1+dfs(start+1 , transactions));
        transactions[i] -= transactions[start] ;
    }
    return minval ;
}
int settleDebt(vector<vector<int>> &arr){
    unordered_map<int , int> memo ;
    for(vector<int> &t : arr){
        memo[t[0]] -= t[2] ;
        memo[t[1]] += t[2] ;
    }
    vector<int> transactions ;
    for(auto it = memo.begin() ; it != memo.end() ; it++){
        if(it->second != 0){
            transactions.push_back(it->second);
        }
    }
    return dfs(0,transactions);
}
```

32. [Remove Invalid Parenthesis](https://www.codingninjas.com/codestudio/problems/remove-invalid-parentheses_1263697?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int MAXSIZE = 0 ;

void helper(int pos , int points , string &str , string &curpath, unordered_set<string> &res){
    if(pos == str.size()){
        if(points == 0 and curpath.size() >= MAXSIZE){
            if(curpath.size() > MAXSIZE){
                res.clear() ;
                MAXSIZE = curpath.size() ;
            }
            res.insert(curpath);
        }
        return ;
    }
    
    if(MAXSIZE > str.size()-pos+curpath.size()) return ;
    
    if(str[pos] == '('){
        helper(pos+1 , points , str , curpath , res);
        curpath.push_back('(');
        helper(pos+1 , points+1 , str , curpath , res);
        curpath.pop_back();
    }
    else if(str[pos] == ')'){
        if(points > 0){
            curpath.push_back(')');
            helper(pos+1 , points-1 , str , curpath , res);
            curpath.pop_back();
        }
        helper(pos+1 , points , str , curpath , res);
    }
    else{
        curpath.push_back(str[pos]);
        helper(pos+1 , points , str , curpath , res);
        curpath.pop_back();
    }
}
vector<string> removeInvalidParentheses(string &str)
{
    MAXSIZE = 0 ;
    string curpath ;
    unordered_set<string> res ;
    helper(0 ,0, str , curpath , res);
    return vector<string>(res.begin() , res.end()) ;
}
```

33. [all path in dag](https://www.codingninjas.com/codestudio/problems/minimum-number-of-vertices-to-reach-all-nodes_1380287?leftPanelTab=0)
```cpp
int target ;
#include<bits/stdc++.h>
void dfs(int node , vector<vector<int>> &graph , vector<int> &curpath , vector<vector<int>> &res){
    curpath.push_back(node);
    if(node == target){
        res.push_back(curpath);
        curpath.pop_back() ;
        return ;
    }
    for(int neigh : graph[node]){
        dfs(neigh , graph , curpath , res);
    }
    curpath.pop_back() ;
}
vector<vector<int>> allPathsFromSourceToTarget(int n, vector<vector<int>>& edges)
{
	vector<vector<int>> graph(n);
    for(int i = 0 ; i < edges.size() ; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    target = n-1 ;
    vector<int> curpath ;
    vector<vector<int>> res ;
    dfs(0 , graph , curpath , res);
    sort(res.begin() , res.end());
    return res ;
}
```

34. [maximum length of chain](https://www.codingninjas.com/codestudio/problems/maximum-length-of-chain_1063253?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int getLongestChainLength(vector<vector<int>> &pp)
{
   	sort(pp.begin() , pp.end() , [](const vector<int> &a , const vector<int> &b){
           return a[1] < b[1] ; 
    });
    int maxlen = 1 ;
    int prev = pp[0][1] ;
    int idx = 1 ;
    while(idx < pp.size()){
        if(pp[idx][0] > prev){
            maxlen++ ;
            prev = pp[idx][1] ;
        }
        idx++ ;
    }
    return maxlen ;
}
```

35. [path more than dist k](https://www.codingninjas.com/codestudio/problems/find-if-there-is-a-path-of-more-than-k-length-from-a-source_1229512?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int reqsum ;

bool helper(int node , int cursum , vector<bool> &visited , vector<vector<pair<int,int>>> &graph){
    if(cursum >= reqsum) return true ;
    
    visited[node] = true ;
    for(auto &neigh : graph[node]){
        if(visited[neigh.first]) continue ;
        if(helper(neigh.first , cursum + neigh.second , visited , graph)){
            return true ;
        }
    }
    visited[node] = false ;
    return false ;
}
string pathMoreThanK(int n, int m, int k, vector<vector<int>>& edges)
{
    vector<bool> visited(n , false);
    vector<vector<pair<int,int>>> graph(n);
    reqsum = k ;
    for(vector<int> &e : edges){
        graph[e[0]].push_back({e[1] , e[2]});
        graph[e[1]].push_back({e[0] , e[2]});
    }
    return (helper(0 , 0 , visited , graph))?"YES":"NO" ;
}
```

36. [path sum2](https://www.codingninjas.com/codestudio/problems/finding-paths_1281314?leftPanelTab=0)
```cpp
int target ;
void helper(TreeNode<int> *root , int cursum ,vector<int> &curpath ,vector<vector<int>> &res){
    if(not root) return ;
    curpath.push_back(root->data);
    if(not root->left and not root->right){
        if(cursum + root->data == target){
            res.push_back(curpath);
        }
        curpath.pop_back();
        return ;
    }
    helper(root->left , cursum+root->data , curpath , res);
    helper(root->right , cursum+root->data , curpath , res);
    
    curpath.pop_back();
}
vector<vector<int>> KSumPaths(TreeNode<int> *root, int k)
{
	vector<vector<int>> res ;
    vector<int> curpath ;
    target = k ;
    helper(root , 0 , curpath , res);
    return res ;
}
```
37. [find permutation](https://www.codingninjas.com/codestudio/problems/find-permutations_1171049?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int nums ;
bool can_i_place(int pos , int ele , vector<int> &arr){
    int nxt_idx = pos + ele + 1 ;
    if(nxt_idx >= arr.size()) return false ;
    if(arr[nxt_idx] != 0) return false ;
    return true ;
}

bool helper(int pos ,vector<int> &arr , unordered_set<int> &used){
    if(used.size() == nums) return true ;
    if(pos > arr.size()) return false ;
    
    if(arr[pos] != 0) return helper(pos+1 , arr , used); 
    
    for(int i = nums ; i >= 1 ; i--){
        if(used.find(i) != used.end()) continue ;
        if(can_i_place(pos , i , arr)){
            used.insert(i) ;
            
            arr[pos] = i ;
            arr[pos+i+1] = i ;
            if(helper(pos+1 , arr , used)) return true ;
            arr[pos] = 0 ;
            arr[pos+i+1] = 0 ;
            
            used.erase(i) ;
        }
    }
    return false ;
}
vector<int> findPermutation(int N)
{
	unordered_set<int> used ;
    vector<int> arr(2*N , 0) ;
    nums = N ;
    if(not helper(0 , arr , used)) return vector<int>() ;
    return arr ;
}
```
38. [path with max gold](https://www.codingninjas.com/codestudio/problems/path-with-maximum-gold_1214654?leftPanelTab=0)
```cpp
int M , N ;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInvalid(int row ,int col){
    return row < 0 or col <0 or row >= M or col >= N ;
}
int helper(int row , int col , vector<vector<int>> &grid){
    int curgold = grid[row][col] ;
    grid[row][col] = 0 ;
    int maxg = 0 ;
    
    for(int i = 0 ; i < 4 ; i++){
        int neigh_r = row + dx[i] ;
        int neigh_c = col + dy[i] ;
        if(isInvalid(neigh_r , neigh_c) or grid[neigh_r][neigh_c] == 0){
            continue ;
        }
        maxg = max(maxg , helper(neigh_r , neigh_c , grid)) ;        
    }
    grid[row][col] = curgold ;
    
    return maxg+curgold ;
}
int maxGold(vector<vector<int>> &grid, int n, int m)
{
	int maxg = 0 ;
    M = n ; N = m ;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(grid[i][j] != 0){
                maxg = max(maxg , helper(i , j , grid));
            }
        }
    }
    return maxg ;
}
```

39. [number with same consecutive diff](https://www.codingninjas.com/codestudio/problems/digits-with-the-same-consecutive-difference_1232624?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int diff , len ;
void helper(int curr , unordered_set<int> &res , string &path){
    if(path.size() == len){
        res.insert(stoi(path));
        return ;
    }
    if(curr >= 10 or curr < 0) return ;
    path.push_back(curr+'0');
    helper(curr+diff , res , path);
    helper(curr-diff , res , path);
    path.pop_back();
}

vector<int> digitsSameConsecDiff(int n, int k) {
    unordered_set<int> res ;
    string path = "" ;
    diff = k ;
    len = n ;
    for(int i = 1 ; i < 10 ;i++){
        helper(i , res , path);
    }
    return vector<int>(res.begin() , res.end()) ;
}
```