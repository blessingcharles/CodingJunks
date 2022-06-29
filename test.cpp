#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int mod=1e9+7;
pair<long long,long long> helper(string &s,int i,int j,vector<vector<pair<long long,long long>>> &dp){
    if(i==j){
        if(s[i]=='T'){
            return {1,0};
        }
        else{
            return {0,1};
        }
    }
    if(dp[i][j]!=make_pair((long long)-1,(long long)-1)){
        return dp[i][j];
    }
    
    long long ans1=0,ans2=0;
    for(int k=i+1;k<j;k+=2){
        auto l=helper(s,i,k-1,dp);
        auto r=helper(s,k+1,j,dp);
        if(s[k]=='|'){
            int tans1 = ((l.first*r.first)%mod + (l.first*r.second)%mod + (l.second*r.first)%mod)%mod;
            int tans2=(l.second*r.second)%mod;
            ans1=(ans1+tans1)%mod;
            ans2=(ans2+tans2)%mod;
        }
        else if(s[k]=='&'){
            int tans1 = (l.first*r.first)%mod;
            int tans2=((l.first*r.second)%mod + (l.second*r.first)%mod + (l.second*r.second)%mod)%mod;
            ans1=(ans1+tans1)%mod;
            ans2=(ans2+tans2)%mod;
        }
        else{
            int tans1 = ((l.first*r.second)%mod + (l.second*r.first)%mod)%mod;
            int tans2= ((l.first*r.first)%mod + (l.second*r.second)%mod)%mod;
            ans1=(ans1+tans1)%mod;
            ans2=(ans2+tans2)%mod;
        }
    }
    return dp[i][j] = {ans1,ans2};
}

int evaluateExp(string & s) {
    int n=s.size();
    vector<vector<pair<long long,long long>>> dp(n,vector<pair<long long,long long>>(n,{-1,-1}));
    return helper(s,0,n-1,dp).first;
}


int main()
{
    string A = "T^T^T^F|F&F^F|T^F^T";
    vector<string> arr = {"cat", "cats", "and", "sand", "dog"};

    cout << evaluateExp(A) << endl ;
    
    // for(auto str : wordBreak(A, arr)){
    //     cout << str << endl ;
    // }
    
    return 0;
}