#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    int N ; 
    unordered_map<int , int> memo  ;


    bool isPalindrome(string &s , int start , int end){
        while(start < end){
            if(s[start] != s[end])
                return false ;
            start++ ; end-- ;
        }
        return true ;
    }
    
    int partition(string &s , int start , int end){
        // split from the end
        if(start >= N)
            return -1 ;
        if(memo.find(start) != memo.end())
            return memo[start] ;

        int minVal = INT_MAX ;
        
        for(int i = end ; i >= start ; i--){
            if(isPalindrome(s, start , i)){
                minVal = min( minVal , 1+partition(s , i+1 , s.size()-1) ) ;
            }
        }

        return memo[start] = minVal  ;
    }
public:
    int minCut(string &s) {
        N = s.size() ; 
        return partition(s , 0 , s.size()-1) ;
        
    }
};


int main()
{
    string A = "hello world" ;
    
    int N = A.size()-1 ;
    int slen = 0 ;
    
    while(N >= 0 and A[N] != ' '){
        N-- ; slen++ ;
    }

    cout << slen << endl ;

	return 0;
}
