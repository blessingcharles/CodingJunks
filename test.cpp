#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin() , A.end());
    
    long mindiff = INT_MAX ;
    long maxdiff = INT_MIN ;
    
    int N = A.size()-1 ;
    long temp ;
    
    for(int i = 0 ; i < N-2 ; i++){
        int left = i+1 , right = N-1 ;
        
        while(left < right){
            temp = A[i] + A[left] + A[right] ;
                cout << B - temp << endl ;
            if(temp == B) return B ;
            if(temp < B){
                mindiff = min(mindiff , (long )B-temp);
                left++ ;
            }        
            else{
                maxdiff = max(maxdiff , (long )B-temp);
                right-- ;
            }
        }
    }
    
    if(maxdiff == INT_MIN){
        return B-mindiff ;
    }
    if(mindiff == INT_MAX){
        return B-maxdiff ;
     }
    return (abs(maxdiff) > mindiff)?B - mindiff:B-maxdiff ;
}



int main()
{
    vector<int> arr = {-10,-10,-10};

    cout << threeSumClosest(arr, -5) << endl ;
	return 0;
}