#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int seats(string A) {
    // find the largest group 
    int N = A.size();
    vector<int> groups(N , 0);
    int group_idx = -1 , maxlen = 0 ;
    
    for(int i = 0 ; i < N ; i++){
    
        int starting_point = i ;    
        while(i < N and A[i] == 'x'){
            i++ ;
        }
        
        if(maxlen < i-starting_point){
            maxlen = i-starting_point ;
            group_idx = starting_point ;    
        }
        
        if(i-starting_point > 0) i-- ;
    }
    cout << group_idx << " " << maxlen << endl ;
    int left_ptr = group_idx-1 , right_ptr = group_idx+maxlen ;
    int end_group = group_idx+maxlen-1 ;
    
    long swaps_count = 0 ;
    long mod = 10000003 ;
    
    while(left_ptr >= 0){
        if(A[left_ptr] == 'x'){
            swaps_count = (swaps_count + (group_idx-left_ptr-1))%mod ;
            group_idx-- ;
        }
        left_ptr-- ;
    }
    cout << "right pre " << end_group << endl ;
    while(right_ptr < N){
        if(A[right_ptr] == 'x'){
            swaps_count = (swaps_count + (right_ptr - end_group))%mod ;
            end_group++ ;
        }    
        right_ptr++ ;
    }

    return swaps_count ;
}



int main()
{                    // 0 1   2  3  4  5  6  7  8
    vector<int> arr = { 10, 9, 8, 7, 6, 4, 5, 2, 1, 3 };

    string a = ".x.x.x..x" ;
    cout << seats(a) ;

    return 0;
}