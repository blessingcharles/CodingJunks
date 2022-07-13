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

5. 