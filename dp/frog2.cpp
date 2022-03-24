#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
/*
MEMOISATION ALGO
if pos == 0
    return 0

if(pos in memo)
    return memo[pos]

min_val = INT_MAX

for(i = pos-1 ; (i > -1 && i >= pos-steps) ; i--){
    min_val = min(min_val , func(i) + abs(h[i] - h[pos]))
}

return memo[pos] = min_val

*/

int memoisation(int steps ,int pos , vector<int> &stone_heights , unordered_map<int,int> &memo){
    if(pos == 0)
        return 0;
    if(memo.find(pos) != memo.end())
        return memo[pos];

    int min_value = INT_MAX  ;

    for(int i = pos-1 ; (i > -1 && i >= pos-steps) ; i--){
        min_value = min(min_value , memoisation(steps , i , stone_heights , memo) + abs(stone_heights[i] - stone_heights[pos])) ;

    }
    return memo[pos] = min_value ;

}

int tabulation(int steps , vector<int> &stone_heights){
    vector<int> dp(stone_heights.size() , 0);
    //initialising

    dp[0] = 0 ;
    dp[1] = abs(stone_heights[0] - stone_heights[1]);

    for(int i = 2 ; i < stone_heights.size() ; i++){
        int min_value = INT_MAX ;
        for(int j = i-1 ;(j > -1 && j >= i-steps) ; j--){
            min_value = min(min_value , dp[j]+abs(stone_heights[i]-stone_heights[j]));
        }
        dp[i] = min_value ;
    }

    return dp[stone_heights.size()-1] ;

}

int main(){

    vector<int> stone_heights = {40, 10, 20, 70, 80, 10 ,20, 70 ,80 , 60};
    int steps = 4 ;
    unordered_map<int,int> memo;
    cout << memoisation(steps ,stone_heights.size()-1 ,stone_heights , memo) << endl ;
    // cout << tabulation(steps ,stone_heights) << endl ;


    return 0;
}