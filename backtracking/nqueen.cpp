#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void logger(string s){
    cout << s << endl;
}
/*
ALGORITHM

func:
if(row == n)
    print_sol(board);
    return ;

for(int i = 0 ; i < n ; i++){
    if(can_i_place(row,i)){
        board[row][i] = 1 ;
        func(row+1);
        board[row][i] = 0 ;
    }
}

can_i_place:

//checking for same column
for(int i = 0 ; i < row ;i++){
    if(board[i][i])
        return false;
}

//checking for cross
k = 1
flag=1
while(flag){
    flag = 0
    if(row-k >= 0 && col-k >=0){
        flag = 1
        if(board[row-k][col-k]) return false;
    }
    if(row+k < board.size() ; col+k < board.size()){
        flag=1
        if(board[row+k][col+k]) return false;
    }
    if(row+k < board.size() ; col-k >= 0){
        flag=1
        if(board[row+k][col-k]) return false;
    }
    if(row-k >= 0 ; col+k < board.size()){
        flag=1
        if(board[row-k][col+k]) return false;
    }
    k++ 
}
return true


*/
bool can_i_place(int row , int col , vector<vector<int>> &board){
    //checking for same column
    for(int i = 0 ; i < row ;i++){
        if(board[i][col])
            return false;
    }

    //checking for cross
    int k = 1  ;
    int flag=1 ;

    while(flag){
        flag = 0 ;
        if(row-k >= 0 && col-k >=0){
            flag = 1 ;
            if(board[row-k][col-k]) return false;
        }
        if(row+k < board.size() && col+k < board.size()){
            flag=1 ;
            if(board[row+k][col+k]) return false;
        }
        if(row+k < board.size() && col-k >= 0){
            flag=1 ;
            if(board[row+k][col-k]) return false;
        }
        if(row-k >= 0 && col+k < board.size()){
            flag=1 ;
            if(board[row-k][col+k]) return false;
        }
        k++ ;
    }
    return true ;
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

void nqueen(int row , vector<vector<int>> &board){
    if(row == board.size()){
        print_sol(board);
        return  ;
    }
    for(int i = 0 ; i < board.size() ; i++){
        if(can_i_place(row,i,board)){
            board[row][i] = 1 ;
            nqueen(row+1,board);
            board[row][i] = 0 ;
        }
    }
}

int main(){
    vector<vector<int>> board = {   { 0, 0, 0, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 0, 0 } };

    nqueen(0,board);
    return 0;
}