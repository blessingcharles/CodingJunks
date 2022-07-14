#include <iostream>

#include <bits/stdc++.h>
using namespace std ;

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
    cout << row << endl ;
    for(int i = 0 ; i < 4 ; i++){
        int neigh_r = row + dx[i] ;
        int neigh_c = col + dy[i] ;
        if(isInvalid(neigh_r , neigh_c) or arr[neigh_r][neigh_c] == 0){
            continue ;
        }
        cout << neigh_r << " " << neigh_c << endl ;
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
    M = ans.size() ; N = ans[0].size() ;
    cout << "hi" ;
    // if(arr[0][0] == 0 or arr[M-1][N-1] == 0) return ans ;
    // arr[0][0] = 0 ;
    // string path = "" ;
    // helper(0,0,arr , path , ans);
    return ans ;
}

int main()
{
    vector<vector<bool>>  arr = {{1,1},{1,1}} ;
    for(string ele : findAllPaths(arr)){
        cout << ele << " " ;
    }
}