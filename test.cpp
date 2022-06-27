#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int helper(int left , int right , vector<int> &A , vector<int> &prefixsum){
    
    if(left == right){
        return 0 ;
    }
    if(left+1 == right){
        return A[left] + A[right] ;
    }
    
    int entire_merge =  (prefixsum[right+1] - prefixsum[left]) ;
    
    int curminsum = INT_MAX ;
    for(int i = left ; i < right ; i++){
        //merge at left 
        curminsum = min(curminsum , helper(left , i , A , prefixsum) + helper(i+1 , right , A , prefixsum));
    }
    return curminsum + entire_merge ;
}

int solve(vector<int> &A) {
    vector<int> prefixsum(A.size()+1,0);
    partial_sum(A.begin() , A.end() , prefixsum.begin()+1);
    
    return helper(0 , A.size()-1 , A , prefixsum);
}

int main()
{ // 0 1   2  3  4  5  6  7  8

    vector<int> arr = {1,2,3,4} ;
    cout << solve(arr);

    return 0;
}