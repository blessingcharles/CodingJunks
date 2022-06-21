#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int romanToInt(string A) {
    vector<int> nums = {1000 , 900 , 500 , 400 , 100 , 90,50 , 40 , 10 ,9 , 5 , 4 , 1};
    vector<string> nums_map = {
        "M" ,
        "CM" ,
        "D" ,
        "CD" ,
        "C" ,
        "XC" ,
        "L" ,
        "XL" ,
        "X" ,
        "IX" ,
        "V" ,
        "IV" ,
        "I"
    };
    
    int ptr = 0 ;
    int N = A.size() ;
    int idx = 0 ;
    
    int res = 0 ;
    
    while(idx < N){
        int sz = nums_map[ptr].size() ;
        int count = 0 ;
        
        if(sz == 1){
            char ch = nums_map[ptr][0] ;
            
            while(idx < N and ch == A[idx]){
                count++ ;
                idx++   ;      
            }
        }
        else{
            if(idx < N-1 and nums_map[ptr] == A.substr(idx , 2)){
                count++ ;
                idx += 2 ;
            }
        }

        cout << nums[ptr] << " " << count << endl ; 
        res = res + nums[ptr]*count ;
        ptr++ ;
        
    }
    
    return res ;
}


int main()
{
    string A = "MDCCCIV" ;
    cout << romanToInt(A) << endl ;
	return 0;
}