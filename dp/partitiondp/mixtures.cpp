#include<bits/stdc++.h>
using namespace std ;

#include<bits/stdc++.h>
int dp[101][101] ;

int mod = 100 ;
int calc(int i , int j , vector<int> &color){
    int sum = 0 ;
    for(int k = i ; k <= j ; k++) sum += color[k] ;
    return sum%mod ;
}

int helper(int left , int right , vector<int> &prefixsum){
    if(left >= right) return 0 ;
    if(dp[left][right] != -1) return dp[left][right] ;
    int minsmokes = 1e8 ;
    
    for(int i = left+1 ; i <= right ; i++){
        int smoke = ((prefixsum[i] - prefixsum[left])%mod) * ((prefixsum[right+1] - prefixsum[i])%mod) ;
        
//         int smoke = (calc(left,i-1, color) * calc(i,right,color)) ;
        
        int cursmoke = smoke + helper(left , i-1,prefixsum) + helper(i, right ,prefixsum);
        minsmokes = min(minsmokes , cursmoke);
    }
    return dp[left][right] = minsmokes ;
}
int minimizeSmoke(vector<int> &color,int n) {
    vector<int> prefixsum(n+1 , 0);
    partial_sum(color.begin() , color.end() , prefixsum.begin()+1);
    memset(dp , -1 ,sizeof(dp));
    
    return helper(0 , n-1,prefixsum);
}