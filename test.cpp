#include <iostream>
#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> memo ;


int helper(string &str , vector<vector<vector<int>>> memo , int left , int right , int choice){
    if(left >= right){
        cout << " hi " ;
        return 1 ;
    }
    
    if(memo[left][right][choice] != -1){
        return memo[left][right][choice] ;
    }
    if(str[left] != str[right]){
        if(choice == 0)
            return 0 ;
        else{
            cout << left << " " << right << " " << choice << endl ;
            return memo[left][right][choice] = (helper(str , memo , left+1 , right , 0) || helper(str , memo , left, right-1 , 0) ) ;
        }
    }
    return memo[left][right][choice] = helper(str , memo , left+1 , right-1 , choice) ;
}

int solve(string A) {
    vector<vector<vector<int>>> memo ;
    memo.resize(A.size() , vector<vector<int>>(A.size() , vector<int>(2,-1)));
    
    return helper(A , memo , 0 , A.size()-1 , 1);
}




int main()
{
    string A = "jubgxwdiiidwxgbbj" ;
    
    cout << solve(A);
	return 0;
}