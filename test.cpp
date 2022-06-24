#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isLexSmaller(int e1 , int e2 , int e3 , int e4 , int x1 , int x2 , int x3 , int x4){
    if(x1 != e1){
        return x1 < e1 ;
    }

    if(x2 != e2){
        return x2 < e2 ;
    }


    if(x3 != e3){
        return x3 < e3 ;
    }

    if(x4 != e4){
        return x4 < e4 ;
    }

    return false ;
}
vector<int> equal(vector<int> &A) {
    unordered_map<int , pair<int,int>> memo ;
    int first = INT_MAX , second = INT_MAX, third = INT_MAX, fourth = INT_MAX;
    pair<int,int> temp ;
    
    for(int i = 0 ; i < A.size()-1 ; i++){
        for(int j = i+1 ; j < A.size() ; j++){
            int cursum = A[i] + A[j] ;
                    
            if(memo.find(cursum) != memo.end()){
                    temp = memo[cursum] ;
                    if(temp.first == i or temp.first == j or temp.second == i  or temp.second == j){
                        continue ;
                    }

                    cout << temp.first << " " << temp.second << " " << i << " " << j << endl ;
                    if(isLexSmaller(first , second , third , fourth , temp.first , temp.second , i , j)){
                        first = temp.first ;
                        second = temp.second ;
                        third = i ;
                        fourth = j ;
                    }
            }
            else{
                memo[cursum] = {i,j};
            }
        }
    }
    if(first == INT_MAX) return  {} ;
    
    return {first, second,third,fourth} ;
}


int main()
{
    vector<int> arr = {3, 4, 7, 1, 2, 9, 8};
    for(int ele :equal(arr)){
    cout << "----------" ;
        cout << ele << " " ;
    }

    return 0;
}