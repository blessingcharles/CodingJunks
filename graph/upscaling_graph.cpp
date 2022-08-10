#include<bits/stdc++.h>

using namespace std ;

// 1. check if there is valid path 
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
class Solution {
public:
    int M , N ;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1} ;
    
    bool isInvalid(int row, int col){
        return row < 0 or col < 0 or row >= M or col >= N ;
    }
    
    bool dfs(int row , int col , vector<vector<bool>> &grid){
        if(row == M-2 and col == N-2)
            return true ;
        grid[row][col] = false ;
        
        for(int i = 0 ; i < 4 ; i++){
            int neigh_r = row + dx[i] ;
            int neigh_c = col + dy[i] ;
            
            if(isInvalid(neigh_r , neigh_c) or not grid[neigh_r][neigh_c])
                continue ;
        
            if(dfs(neigh_r , neigh_c , grid))
                return true ;
        }
        return false ;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        // graph upscaling
        M = grid.size() ; N = grid[0].size() ;
        vector<vector<bool>> paths(M*3 , vector<bool>(N*3 , false));
        
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                int val = grid[i][j] ;
                
                paths[i*3+1][j*3+1] = true ;
                
                paths[i*3+0][j*3+1] = (val == 2) or (val == 5) or (val == 6) ;
                paths[i*3+1][j*3+0] = (val == 1) or (val == 3) or (val == 5) ;
                paths[i*3+1][j*3+2] = (val == 1) or (val == 4) or (val == 6) ;
                paths[i*3+2][j*3+1] = (val == 2) or (val == 3) or (val == 4) ;
                
            }
        }
        M = M*3 ;
        N = N*3 ;
        
        return dfs(1 , 1 , paths);
    }
};

// 2. region cut by slashes
// https://leetcode.com/problems/regions-cut-by-slashes/ 

class Solution {
public:
    int M , N ;
    int dx[4] = {1,-1,0,0} ;
    int dy[4] = {0,0,1,-1} ;
    
    bool isInvalid(int row , int col){
        return row < 0 or col < 0 or row >= M or col >= N ;
    }
    void dfs(int row , int col , vector<vector<bool>> &grid){
        grid[row][col] = false ;
        
        for(int i = 0 ; i < 4 ; i++){
            int neigh_r = row + dx[i] ;
            int neigh_c = col + dy[i] ;
            
            if(isInvalid(neigh_r , neigh_c) or
                not grid[neigh_r][neigh_c])
                continue ;
            
            dfs(neigh_r , neigh_c, grid) ;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        M = grid.size() ; N = grid[0].size() ;
        
        vector<vector<bool>> paths(M*3 , vector<bool>(N*3 , true));
        
        for(int i = 0; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                char ch = grid[i][j] ;
                if(ch == '/'){
                    paths[i*3+0][j*3+2] = false ;
                    paths[i*3+1][j*3+1] = false ;
                    paths[i*3+2][j*3+0] = false ;
                }
                else if(ch == '\\'){
                    paths[i*3+0][j*3+0] = false ;
                    paths[i*3+1][j*3+1] = false ;
                    paths[i*3+2][j*3+2] = false ;
                }
            }
        }
        M = M*3 ; N = N*3 ;
        int count = 0 ;
        
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(paths[i][j]){
                    count++ ;
                    dfs(i , j , paths);
                }
            }
        }
        return count ;
    }
};
