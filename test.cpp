#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int helper(int pos ,bool canbuy, const vector<int> &arr , vector<vector<int>> &memo ){
    if(pos < 0){
        return 0 ;
    }
    // if(memo[pos][canbuy] != -1){
    //     return memo[pos][canbuy] ;
    // }
    
    if(canbuy){
        // buy now
        int option1 = helper(pos-1 , false , arr , memo) - arr[pos] ;
        // skip it    
        int option2 = helper(pos-1 , true , arr , memo) ; 
        return memo[pos][canbuy] = max(option1 , option2) ;
    }
        
    // sell now 
    int option1 = arr[pos] + helper(pos-1 , true , arr , memo) ;
    int option2 = helper(pos-1 , false , arr , memo);
    
    return memo[pos][canbuy] = max(option1 , option2) ;
}

int maxProfit(const vector<int> &A) {
    int N = A.size() ;
    vector<vector<int>> memo(N , vector<int>(2 , -1));
    
    return helper(N-1 , true , A , memo );
}

int main()
{ 
    vector<int> arr = { 2 , 1};

    cout << maxProfit(arr);


    return 0;
}