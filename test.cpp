#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int mod = 100 ;
int ROWS , COLS ;

bool isValid(int row , int col){
    return row >= 0 and col >= 0 and row < ROWS and col < COLS ;
}

void solve(vector<vector<char> > &A) {
    ROWS = A.size() ; COLS = A[0].size() ;
    vector<vector<int>> board(ROWS , vector<int>(COLS , 0));
    queue<pair<int,int>> q ;
    
    for(int i = 0 ; i < ROWS ; i++){
        for(int j =0 ; j < COLS ; j++){
            if(A[i][j] == 'X'){
                board[i][j] = -1 ;
                q.push({i,j});
            }
        }
    }
    pair<int,int> curnode ;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    
    while(not q.empty()){
        curnode = q.front() ; q.pop() ;
        
        for(int i = 0 ; i < 4 ; i++){
            int n_row = curnode.first + dx[i] ;
            int n_col = curnode.second + dy[i] ;
            if(isValid(n_row , n_col) and board[n_row][n_col] != -1 and n_row != 0 and n_col != 0 and n_row != ROWS-1 and n_col != COLS-1){
                cout << n_row << " " << n_col << endl ;
                board[n_row][n_col]++ ;
                q.push({n_row ,n_col}) ;
            }
        }
    }
    
    for(int i = 1 ; i < ROWS-1 ; i++){
        for(int j = 1 ; j < COLS-1 ; j++){
            if(board[i][j] >= 4 ){
                A[i][j] = 'X' ;
            }
        }
    }

}
int main()
{
   
    vector<vector<char>> bb = {{'X' , '0' , 'X'} 
                              ,{'X' , '0' , 'X'} ,
                               {'X' , '0' , 'X'} };

    solve(bb);

    for(auto ff : bb){
        for(char ch : ff){
            cout << ch << " " ;
        }
        cout << endl ;
    }
    return 0;
}