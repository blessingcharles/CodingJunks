/*
      A B C        A = 4 * 1
    4 1 2 3        B = 1 * 2
                   C = 2 * 3
                   
    A BC
*/
#include<bits/stdc++.h>
using namespace std ;

int dp[101][101] ;

int helper(int left , int right , vector<int> &arr){
    if(left == right) return 0 ;
    if(dp[left][right] != -1) return dp[left][right] ;
    
    int ans = 1e9 ;
    
    for(int k = left ; k < right ; k++){
        int merge = arr[left-1] * arr[k] * arr[right] ;
        merge = merge + helper(left , k,arr) + helper(k+1 , right,arr);
        ans = min(ans , merge);
    }
    return dp[left][right] = ans ;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    memset(dp , -1 , sizeof(dp));
    return helper(1 , N-1 , arr);
}