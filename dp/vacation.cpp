#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

// https://atcoder.jp/contests/dp/tasks/dp_c

int dp(vector<vector<int>> &happiness){
    
    vector<vector<int>> dp(happiness.size() , vector<int>(3,0));
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];

    for(int i = 1 ;i < happiness.size() ;i++ ){
        for(int j = 0 ; j < 3 ; j++){

            int prev1 = (j+1)%3 ;
            int prev2 = (j+2)%3 ;

            int way1 = happiness[i][j] + dp[i-1][prev1];
            int way2 = happiness[i][j] + dp[i-1][prev2];
            dp[i][j] = max(way1,way2) ;
        }
    }

    int n = happiness.size()-1 ;

    // int max_val = ;

    return max(dp[n][0] ,max(dp[n][1] , dp[n][2]));
}

int memoisation(vector<vector<int>> &happiness ,vector<vector<int>> &memo , int day , int parent){
    // some problems with memoisation
    
    if(day < 0)
        return 0 ;
    int max_val = INT_MIN ;
    

    for(int i = 0 ; i < 3 ; i++){
        if(i == parent) continue ;

        cout << "DAY "<< day << "| ACTIVITY " << i << endl;
        int val = happiness[day][i] + memoisation(happiness ,memo , day-1 , i);
        max_val = max(max_val ,val ) ;
        
    }
    cout << "DAY "<< day << "| MAX VAL " << max_val << endl;

    return max_val ;
}

int main(){

    vector<vector<int>> happiness = {
{6, 7, 8},
{8, 8, 3},
{2, 5, 2},
{7, 8, 6},
{4, 6, 8},
{2, 3, 4},
{7, 5, 1}
        };

    vector<vector<int>> memo(happiness.size(),vector<int>(3,-1));
    // cout << dp(happiness) << endl ;
    cout << memoisation(happiness , memo , happiness.size()-1 , -1) << endl;

    return 0;
}