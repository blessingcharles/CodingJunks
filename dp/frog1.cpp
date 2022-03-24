#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
// https://atcoder.jp/contests/dp/tasks/dp_a

/*
MEMOISATION ALGO

if(pos in memo)
    return memo[pos]

if(pos+2 < n)
    jump1 = abs(h[pos+1] - h[pos]) + func(pos+1)
    jump2 = abs(h[pos+2] - h[pos]) + func(pos+2)
    memo[pos] = min(jump1 , jump2)
    return memo[pos]

else if(pos+1 < n)
    jump1 = abs(h[pos+1] - h[pos]) + func(pos+1)
    memo[pos] = jump1
    return memo[pos]
    
else 
    return 0

*/

int solve(int pos ,vector<int> &stone_heights , unordered_map<int,int> &memo){
    if(memo.find(pos) != memo.end())
        return memo[pos] ;

    if(pos+2 < stone_heights.size()){
        int jump1 = abs(stone_heights[pos] - stone_heights[pos+1]) + solve(pos+1 , stone_heights , memo);
        int jump2 = abs(stone_heights[pos] - stone_heights[pos+2]) + solve(pos+2 , stone_heights , memo);
        memo[pos] = min(jump1 , jump2);
        return memo[pos] ;

    }
    else if(pos+1 < stone_heights.size()){
        int jump1 = abs(stone_heights[pos] - stone_heights[pos+1]) + solve(pos+1 , stone_heights , memo);
        return memo[pos] = jump1 ;
    }

    return 0 ;
}

int dp_solve(vector<int> &stone_heights){
    if(stone_heights.size() < 2){
        return 0 ;
    }
    vector<int> dp(stone_heights.size() , 0) ;
    dp[0] = 0 ;
    dp[1] = abs(stone_heights[0] - stone_heights[1]) ;

    for(uint32_t i = 2 ; i < stone_heights.size() ; i++){
        uint32_t jump1 = dp[i-1] + abs(stone_heights[i] - stone_heights[i-1]);
        uint32_t jump2 = dp[i-2] + abs(stone_heights[i] - stone_heights[i-2]);
        dp[i] = min(jump1 , jump2);
    }
    return dp[stone_heights.size()-1] ;

}

int main(){
    vector<int> stone_heights = {30 , 10 , 60 , 10 , 60 , 50};
    unordered_map<int,int> memo;

    // cout << solve(0,stone_heights,memo) << endl ;

    cout << dp_solve(stone_heights) << endl ;

    return 0;
}