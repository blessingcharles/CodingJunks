#include <iostream>
#include <bits/stdc++.h>

using namespace std;


#include<bits/stdc++.h>

long mod = 1e9+7;

int cntBits(vector<int> &A) {
    long sum = 0 ;
    
        
    for(int i = 0 ; i < 4 ; i++){
        long ones_count = 0 , zeros_count = 0 ;
        int mask = (1 << i) ;
        
        for(int j = 0 ; j < A.size() ; j++){
             
            cout << A[j] << " " << (A[j] & mask) << endl ;

            if((A[j] >> i)&1 != 0){
                 ones_count++ ;
            }
            else{
                 zeros_count++ ;
            }
        }
        cout << i << " " << ones_count << " " << zeros_count << endl ;
        sum = (sum + (ones_count*zeros_count)%mod)%mod ;
    }
    
    return 2*sum  ;
}


int main()
{
    vector<int> arr = {1,3,5};

    cout << cntBits(arr) ;

    return 0;
}