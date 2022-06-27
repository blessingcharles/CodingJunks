#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N , M ;

bool helper(const string &str , const string &pattern , int ptr1 , int ptr2 ,  vector<vector<int8_t>> &memo){
    if(ptr1 >= M and ptr2 >= N) return true ;
    if(ptr2 >= N) return false ;
    if(memo[ptr1][ptr2] != -1){
        return memo[ptr1][ptr2] ;
    }
    
    if(ptr1 >= M){
        // string finished can we finish this pattern somewhat ?
        if(ptr2+1 >= N or pattern[ptr2+1] != '*') return memo[ptr1][ptr2] = false ;
        return memo[ptr1][ptr2] = helper(str , pattern , ptr1 , ptr2+2, memo) ;
    }
    // check if star presents
    bool isstar = false ;
    
    if(ptr2+1 < N and pattern[ptr2+1] == '*') isstar = true ;
    
    if(isstar){
        //skip the []* completely in the pattern
        if(helper(str , pattern , ptr1 , ptr2+2 , memo)){
            return memo[ptr1][ptr2] = true ;
        }
        // use the []*
        if(pattern[ptr1] != '.' and str[ptr1] != pattern[ptr2]){
            return memo[ptr1][ptr2] = false ;
        }
        else{
            return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2, memo);
        }
    }
    if(pattern[ptr2] == '.'){
        return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2+1, memo);
    }
    //normal characters match
    if(str[ptr1] != pattern[ptr2]) return memo[ptr1][ptr2] = false ;    
    return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2+1 , memo);
}

int isMatch(const string str, const string pattern) {
    M = str.size() ;
    N = pattern.size() ;
    vector<vector<int8_t>> memo(M+1 , vector<int8_t>(N+1 , -1));
    
    return helper(str , pattern , 0 , 0 , memo);
}




int main()
{                    // 0 1   2  3  4  5  6  7  8

    string str = "acbcd" , pattern = "a.*b.*d" ;

    cout << isMatch(str , pattern) ;

    return 0;
}