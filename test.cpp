#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printvec(vector<int> &arr){
    for(auto ele : arr){
        cout << ele << " " ;
    }
    cout << endl ;
}

int solve(vector<int> &A) {
    set<int> arr(A.begin() , A.end());
    int idx = 0 ;
    int N = arr.size() ;
    for(auto ele : arr){
        cout << ele << endl ;
    }
    for(auto it = arr.begin() ; it != arr.end() ; it++ , idx++ ){
        if(*it == (N-idx-1)){
            return 1 ;
        }
    }
    return -1 ;
}


int main()
{
    vector<int> arr = {1, 2, 7, 0, 9, 3, 6, 0, 6 };
    cout << solve(arr) ;
}