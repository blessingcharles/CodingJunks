#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int mod = 1e9 + 7;
int helper(int left , int right , int k , string &A ,vector<vector<vector<int>>> &memo){
    // if(memo[left][right][k] != -1){
    //     return memo[left][right][k] ;
    // }
    
    if(k == 1){
        //calculate and return ;
        int white_h = 0 , black_h = 0 ;
        
        for(int i = left ; i <= right ; i++){
            if(A[i] == 'W') white_h++ ;
            else black_h++ ;
        }
        cout << left << " | " << right << endl ;
        return memo[left][right][1] = white_h*black_h ;
    }
    if(left == right){
        if(k == 1) return 0 ;
        return INT_MAX ;
    }
    
    long min_val = INT_MAX ;
    
    for(int i = left ; i < right ; i++){
        if(k%2 == 1){
            // odd number
            long pos1 = helper(left , i , (k/2)+1 , A , memo) + helper(i+1 , right , k/2 , A , memo);
            long pos2 = helper(left , i , (k/2) , A , memo) + helper(i+1 , right , (k/2)+1 , A ,memo);
            
            min_val = min(min_val , min(pos1 , pos2));
        }
        else{
            long pos1 = helper(left , i , (k/2) , A , memo) + helper(i+1 , right , k/2 , A,memo );
            min_val = min(min_val , pos1);
        }
    }
    cout << left << " ^ " << right << endl ;
    return memo[left][right][k] = min_val ;
}

int arrange(string A, int B) {
    // WBWB 
    vector<vector<vector<int>>> memo(A.size() , vector<vector<int>>(A.size() , vector<int>(B+1 , -1)));
    
    int ans = helper(0 , A.size()-1 , B , A , memo);
    return (ans == INT_MAX)?-1:ans ;
}

int main()
{
    string str = "WBWB" ;

    vector<vector<int>> arr = {{0, 0}};
    cout << arrange(str , 2) << endl;
  

    return 0;
}