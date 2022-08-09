#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


int main(){

    vector<vector<int>> arr = {{1,2} , {1,5} , {3,5} , {5,9} ,{5,3} , {8,9}} ;

    auto it = *lower_bound(arr.begin() , arr.end() , 4 , [](const vector<int> &b , int val){
        return b[0] >= val ;
    }) ;

    // for(int ele : it) cout << ele << " " ;

    // cout << d->name << endl ;
}