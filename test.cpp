#include <iostream>

#include <bits/stdc++.h>
using namespace std ;

#include<bits/stdc++.h>
string remover(string board){
    if(board.size() < 3) return board ;  
    string res = "" ;
    int N = board.size() ;
    
    for(int i = 0 ; i < board.size() ;i++){
        if(i < N-2 and board[i] == board[i+1] and board[i] == board[i+2]){
            i += 2 ;
        }    
        else{
            res.push_back(board[i]);
        }
    }
    cout << board << " " << res << endl ;
    return res ;
}
int helper(string board , string &hand , unordered_set<int> used){
    board = remover(board);
    if(board.size() == 0) return 0 ;
    if(used.size() == hand.size()){
        return INT_MAX ;
    }
    int minlen = INT_MAX ;
    
    for(int i = 0 ; i < hand.size() ; i++){
        if(used.find(i) != used.end()) continue ;
        used.insert(i);
        for(int j = 1 ; j < board.size() ; j++){
            string new_board = remover(board.substr(0,j) + hand[i] + board.substr(j)) ;       
            minlen = min(minlen , helper(new_board , hand , used));
        }
        used.erase(i);
    }
    return (minlen == INT_MAX)?minlen:1+minlen ;
}

int minInsertions(string &board, string &hand) 
{
    unordered_set<int> used ;    
	int ans = helper(board , hand ,used);
    return (ans == INT_MAX)?-1:ans ;
}
int main()
{
    vector<string> arr = {"of" , "on" , "pon"};
    vector<vector<char>> bb = {{'g' , 'n'} , {'o' , 'p'}};
    string b = "GYGG" ;
    string h = "YY";
    cout << minInsertions(b,h);

}