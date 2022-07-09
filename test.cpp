#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

#include<bits/stdc++.h>

string shortestSubstring(string s)
{
    unordered_set<char> myset(s.begin() , s.end());
    int n = myset.size() ;
    int left = 0 , right = 0 ;
    unordered_map<char , int> memo ; 
    int left_idx = 0 ,right_idx , maxlen = s.size() ;
    
    while(right < n){
        memo[s[right]]++ ;
        while(memo.size() == n){
            int curlen  = right-left+1 ;
            if(curlen < maxlen){
                left_idx = left ;
                maxlen = curlen ;
            }
            memo[s[left]]-- ;
            if(memo[s[left]] == 0) memo.erase(memo[s[left]]);
            left++ ;
        }
        right++ ;
    }
    return s.substr(left_idx ,maxlen);
}

int main()
{
    cout << shortestSubstring("abbbcbbbbabbc");
}