#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int dp[102][102] ;
    
    int helper(int left , int right , vector<int>& cuts){
        if(left+1 == right)
            return 0 ;
        if(dp[left][right] != -1)
            return dp[left][right] ;
        
        int mincost = INT_MAX ;
        
        int curcost = cuts[right]-cuts[left] ;
        
        for(int i = left+1 ; i < right ; i++){
            
            int temp = helper(left , i , cuts) +
                        helper(i , right , cuts) ;
            mincost = min(mincost , temp);
        }
        return dp[left][right]=curcost + mincost ;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin() , cuts.end());
        memset(dp , -1 ,sizeof(dp));
        
        return helper(0,cuts.size()-1,cuts);
    }
};