#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

/*
ALGORITHM 

can_i_place:

//check in row and column
for(int i = 0 ; i < 9 ; i++){
    if(board[i][col] == val) return false ;
    if(board[row][i] == val) return false ;
}
row_start = floor(row/3)*3;
col_start = floor(col/3)*3;

for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3 ; j++){
        if(row_start+i == row && col_start+j == col) continue ;

        if(board[row_start+i][col_start+j] == val)
            return false ;
    }
}   
return true


func:
    if(row == m && col == 0)
        print_sol(board)
        return
    if(board[row][col] != 0){
        col = col+1;
        if(col == 9){
            row = row+1;
            col = 0;
        }
        func(row,col);
    }

    for(int i = 0 ; i < 9 ;i++){
        if(can_i_place(row,col,i)){
            board[row][col] = i;
            
            col = col+1;
            if(col == 9){
                row = row+1;
                col = 0;
            }
            func(row,col);
        
        }
        board[row][col] = 0 ;
    }

*/
void logger(string s){
    cout << s << endl;
}
void print_sol(vector<vector<int>> &board){
    for(auto row : board){
        for(auto ele : row){
            cout << ele << " " ;
        }
        cout << endl ;
    }
    cout << endl ;
}
bool can_i_place(int row , int col , int val , vector<vector<int>> &board){
    for(int i = 0 ; i < 9 ; i++){
        if(board[i][col] == val) return false ;
        if(board[row][i] == val) return false ;
    }
    int row_start = floor(row/3)*3;
    int col_start = floor(col/3)*3;

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(row_start+i == row && col_start+j == col) continue ;

            if(board[row_start+i][col_start+j] == val)
                return false ;
        }
    }   
    return true ;

}

bool solve(int row , int col , vector<vector<int>> &board){
    if(row == 9 && col == 0){
        print_sol(board) ;
        return true;
    }
    if(board[row][col] != 0){
        col = col+1;
        if(col == 9){
            row = row+1;
            col = 0;
        }
        if(solve(row,col,board)){
            return true ;
        }

    }
    else{
        for(int i = 1 ; i <= 9 ;i++){
            if(can_i_place(row,col,i,board)){
                
                board[row][col] = i;
                
                int temp_col = col+1;
                int temp_row = row ;

                if(temp_col == 9){
                    temp_row = row+1;
                    temp_col = 0;
                }
                if(solve(temp_row,temp_col,board)){
                    return true ;
                }
            
                board[row][col] = 0 ;
            }
        }
    }

    return false ;
}
int main(){

    vector<vector<int>> board = {
                        {5,3,0,0,7,0,0,0,0}
                        ,{6,0,0,1,9,5,0,0,0}
                        ,{0,9,8,0,0,0,0,6,0}
                        ,{8,0,0,0,6,0,0,0,3}
                        ,{4,0,0,8,0,3,0,0,1}
                        ,{7,0,0,0,2,0,0,0,6}
                        ,{0,6,0,0,0,0,2,8,0}
                        ,{0,0,0,4,1,9,0,0,5}
                        ,{0,0,0,0,8,0,0,7,9}
                        } ;

    solve(0,0,board);
    return 0;
}