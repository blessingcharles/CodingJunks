#include<bits/stdc++.h>
#include<iostream>

using namespace std ;
// quick Select for finding kth largest or smallest 
int quickSelect(vector<int>& arr ,int left , int right ,int k){
    int ele = arr[right] ;
    int ptr = left ; 
    int idx = left ;
    while(idx < right){
        if(arr[idx] < ele){
            swap(arr[idx] , arr[ptr]) ;
            ptr++ ;
        }
        idx++ ;
    }
    swap(arr[ptr] , arr[right]) ;
    if(arr.size()-k == ptr){
        return ele ;
    }
    if(arr.size()-k > ptr){
        return quickSelect(arr , ptr+1 , right , k);
    }
    return quickSelect(arr , left , ptr-1 , k);
}
int kthLargest(vector<int>& arr, int size, int K)
{
    return quickSelect(arr , 0 , size-1 , K);
}
int main(){

}