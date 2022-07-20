#include<bits/stdc++.h>

using namespace std;

template<typename T>
void print_1d(vector<T> &container){
    for(auto ele : container) cout << ele << " " ;
    cout << "--" << endl ;
}
vector<long long> dp(1001 , -1);
long long mod = 1e9+7 ;
long long factorial(int n){
    if(n <= 0) return 1 ;
    if(dp[n] != -1) return dp[n] ;
    
    return dp[n] = (n*factorial(n-1))%mod;
}
int calculateBinomialCoefficient(int n, int r) {
    if(n < r) return 0 ;
    if(n-r == 1) return 1 ;
    long long factn = factorial(n);
    long long denominator = (factorial(r)*factorial(n-r))%mod;

    return factn/denominator ; 
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout << calculateBinomialCoefficient(44 , 41) ;
}
