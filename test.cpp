/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    string ring , key ; 
    int N ;
    
    int helper(int kpos , int rpos){
        if(kpos == key.size()) return 0 ;
        cout << kpos << endl ;
        
        if(ring[rpos] == key[kpos]){
            return 1+helper(kpos+1 , rpos);
        }
        int forward = (rpos+1)%N ;
        int backward = (rpos+N-1)%N ;
        
        int op1 = 1+helper(kpos , forward);
        int op2 = 1+helper(kpos , backward);
        cout << op1 << " " << endl ;
        return min(op1 , op2);
    }
    int findRotateSteps(string &ri, string &ke) {
        ring = ri ; key = ke ;
        N = ring.size() ;
        
        return helper(0,0);
    }
int main()
{
    string r = "godding", k = "godding" ;
    cout<< findRotateSteps(r , k);

    return 0;
}
