#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int mod = 100 ;

pair<int,int> helper(int left , int right , vector<int> &arr){
    if(left == right){
        return {1 , arr[left]%mod};    // smoke , addition
    }
    if(left+1 == right){
        return {arr[left]*arr[right] , (arr[left]+arr[right])%mod } ;
    }
    
    int minsmoke = INT_MAX , addition_val = 0 ;
    pair<int,int> leftside , rightside ;
    
    for(int i = left ; i < right ; i++){
        leftside = helper(left , i , arr);
        rightside = helper(i+1 , right , arr);
        int smoke_generated = leftside.first*rightside.first ;
        
        if(smoke_generated < minsmoke){
            minsmoke = smoke_generated ;
            addition_val = (leftside.second + rightside.second)%mod ;
        }
    }
    
    return {minsmoke , addition_val};
}

int minSmoke(vector<int> &A) {
    return helper(0 , A.size()-1 , A).first ;    
}

int main()
{
   
   vector<int> arr = {2,3,4,5};
   cout << minSmoke(arr) ;
  
    return 0;
}