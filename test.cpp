#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> solve(vector<int> &A) {
    vector<int> ans ;
    int carry = 0 , temp ;
    // remove all starting zeros
    int end = 0 ;
    
    for(int end = 0 ; end < A.size() ; end++){
        if(A[end] != 0) break ;
    }    
    cout << end << endl ;
    
    for(int i = A.size()-1 ; i >= end ; i--){
        if(i == A.size()-1){
            cout << "hii" << endl ;
            temp = A[i] + 1 ;
            carry = temp/10 ;
            ans.push_back(temp%10);
        }
        else{
            temp = A[i] + carry ;
            carry = temp/10 ;
            ans.push_back(temp%10);
        }
    }
    
    if(carry) ans.push_back(carry);
    
    reverse(ans.begin() , ans.end());
    return ans ;
}

int main(){
    vector<int> arr = {0, 3, 7, 6, 4, 0, 5, 5, 5};
    for(int ele : solve(arr)){
        cout << ele << " " ;
    } 
}