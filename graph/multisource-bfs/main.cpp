#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
/*

MULTI SOURCE BFS

Problem: shortest distance to reach 1 in the grid

Related Problems
1) Rotten Oranges        https://leetcode.com/problems/rotting-oranges/
2) Shortest bridge       https://leetcode.com/problems/shortest-bridge/
3) highest peak          https://leetcode.com/problems/map-of-highest-peak/
4) minimum height trees  https://leetcode.com/problems/minimum-height-trees/
*/

bool is_outlier(int row , int col , int M , int N){
    return (row < 0) or (row == M) or (col < 0) or (col == N) ;
}
int main(){
    freopen("inp.txt","r",stdin);
    int m , n ;
    cin >> m >> n ;

    int grid[m][n] , distance[m][n] ;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j] ;
        }
    }
    queue<pair<int,int>> q ;

    //find the starting sources to explores [multi source]
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            distance[i][j] = -1 ;
            if(grid[i][j] == 1){
                q.push({i,j});
                distance[i][j] = 0 ;
            }
        }
    }
    
    int dx[4] = {0,0,1,-1} ;
    int dy[4] = {1,-1,0,0} ;

    //explore from the multiple sources 
    while(!q.empty()){

        int row = q.front().first ;
        int col = q.front().second ;
        

        for(int i = 0 ; i < 4 ; i++){
            int neighbour_row = row + dx[i] ;
            int neighbour_col = col + dy[i] ;

            if(is_outlier(neighbour_row , neighbour_col , m , n)) continue ;

            if(distance[neighbour_row][neighbour_col] == -1){
                // its not yet explored
                distance[neighbour_row][neighbour_col] = distance[row][col] +1 ;
                q.push({neighbour_row , neighbour_col}) ;
            }

        }
        q.pop();
    }


    for(auto &row : distance){
        for(auto ele : row){
            cout << ele << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}