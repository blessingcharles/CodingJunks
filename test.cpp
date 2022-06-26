#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A, int B) {
    map<int,int ,greater<int>> memo ;
    
    for(int i = 0 ; i < A.size() ; i++){
        memo[A[i]] = i ;
    }
    
    auto it = memo.begin() ;
    int idx = 0 ;
    while(B-- and idx < A.size()){
        if(it->first != A[idx]){
            // memo[A[idx]] = it->second ;
            // memo[A[it->second]] = idx ;
            
            swap(A[idx] , A[it->second]);
        }
        it++ ; idx++ ;
    }
    return A ;
}



int main()
{                    // 0 1   2  3  4  5  6  7  8
    vector<int> arr = { 10, 9, 8, 7, 6, 4, 5, 2, 1, 3 };

    for(int ele : solve(arr , 6)){
        cout << ele << " " ;
    }

    return 0;
}