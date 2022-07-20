#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int dp[301][301] ;
    
    int helper(int left , int right , vector<int> &nums){
        if(left > right) return 0 ;
        if(dp[left][right] != -1) return dp[left][right] ;
        
        int maxans = 0 ;
        
        for(int i = left ; i <= right ; i++){
            // burst him
            int profit = nums[left-1]*nums[i]*nums[right+1] ;
            
            profit = profit+helper(left,i-1 , nums) + helper(i+1,right,nums);
            maxans = max(maxans , profit);
        }
        return dp[left][right]= maxans ;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        memset(dp , -1 , sizeof(dp));
        
        nums.push_back(1);
        return helper(1,nums.size()-2,nums) ;
        
    }
};