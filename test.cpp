#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printvec(vector<int> &arr){
    for(auto ele : arr){
        cout << ele << " " ;
    }
    cout << endl ;
}
bool isFeasible(vector<int> &trees , int cutting , int target){
    int collected = 0 ;
    for(int i = 0 ;i < trees.size() ; i++){
        if(trees[i]-cutting > 0){
            collected += trees[i]-cutting ;
        }
    }
    cout << cutting << " collected : " << collected << endl ;
    return collected >= target ;
}

int solve(vector<int> &A, int B) {
    int left = 0 , right = *max_element(A.begin() , A.end()) , mid ;
    
    while(left < right){
        mid = left + (right-left+1)/2 ;
        if(isFeasible(A , mid , B)){
            left = mid ;
        }
        else{
            right = mid-1 ;
        }
        cout << left << " " << right << endl ;

    }
    
    return right ;
}




int main()
{
    vector<int> arr = {20, 15, 10, 17};
    cout << solve(arr, 7) ;
}