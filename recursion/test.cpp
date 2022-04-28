#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
class Solution {
public:
    int N ;
    
    bool isInvalid(int row , int col){
        return (row < 0) or (col < 0) or (row >= N) or (col >= 0);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int>(n,0)) ;
        N = n ;
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        int row = 0 , col = 0 , n_row = 0 , n_col = 0 ;
        int direction = 0 ;
        
        for(int i = 1 ;i <= n*n ;i++){
            ans[row][col] = i ;
            cout << i << endl ;
            n_row = dx[direction] + row  ;
            n_col = dy[direction] + col  ;
            
            if(isInvalid(n_row , n_col) or ans[n_row][n_col] != 0){
                direction = (direction+1)%4;
                row = row + dx[direction] ;
                col = col + dy[direction] ;
            }
            else{
                row = n_row ;
                col = n_col ;
            }
        }
        return ans ;
    }
};
int main(){

    Solution s ;
    s.generateMatrix(3);

    return 0 ;
}
/*

1-(k++ + --k)

k = 7
1 - (6 + 6 )
*/