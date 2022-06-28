#include <iostream>
#include <bits/stdc++.h>

using namespace std;


vector<vector<int> > avgset(vector<int> &A) {
    int totalsum = accumulate(A.begin() , A.end() , 0);
    int N = A.size() ;
    vector<int> list1 , list2 ;
    uint64_t seq = 0 ;
    sort(A.begin() , A.end());
    
    uint64_t M = pow(2 , N);
    for(uint64_t i = 1 ; i < M ; i++){
        vector<int> temp1 ;
        int cursum = 0 ;
        
        for(int j = 0 ; j < N ; j++){
            if(i & (1 << j)){
                temp1.push_back(A[j]);
                cursum += A[j] ;        
            }
        }
        
        if(cursum/temp1.size() == (totalsum-cursum)/(N-temp1.size())){
            // got it 
            seq = i ;
            list1 = temp1  ;
            break ;       
        }
    }
    
    if(seq == 0) return vector<vector<int>>() ;
    
    for(int j = 0 ; j < N ; j++){
        if((seq& (1 << j)) == 0){
            list2.push_back(A[j]) ;
        }
    }
    if(list1.size() < list2.size()) return {list1 , list2};
    if(list2.size() < list1.size()) return {list2 , list1} ;
    
    // checl for lexi order
    for(int i = 0 ; i < list1.size() ; i++){
        if(list1[i] < list2[i]) return {list1 , list2};
        if(list2[i] < list1[i]) return {list2 , list1} ;
    }
    return {list1 , list2} ;
}


int main()
{ 
    vector<int> arr = { 22, 12, 32, 19};

    // cout << solve(arr , b ,c);

    for(auto vec : avgset(arr)){
        for(int ele : vec){
            cout << ele << " " ;
        }
        cout << endl ;
    }
    
    return 0;
}