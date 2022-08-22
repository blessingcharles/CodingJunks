#include<bits/stdc++.h>
#include<iostream>


using namespace std ;


void quickSort(vector<int> &arr , int start , int end){
    if(start >= end){
        return ;
    }
    int ele = arr[end] ;
    int ptr1 = start , idx = start ;

    while(idx < end){
        if(arr[idx] <= arr[end]){
            swap(arr[idx] , arr[ptr1]) ;
            ptr1++ ;
        }
        idx++ ;
    }
    swap(arr[ptr1] , arr[end]) ;

    quickSort(arr , start , ptr1-1) ;
    quickSort(arr , ptr1+1 , end) ;
}

int main(){
    vector<int> arr = {4,3,5,1,2} ;

    quickSort(arr , 0 , arr.size()-1);

    for(int ele : arr) cout << ele << " " ;
    return 0 ;
}