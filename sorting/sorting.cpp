#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


void merge(vector<int> &arr , int start , int mid , int end){
    vector<int> left(mid-start+1);
    vector<int> right(end-mid);

    for(int i = start ; i <= mid ; i++){
        left[i-start] = arr[i] ;
    }
    for(int i = mid+1 ; i <= end ; i++){
        right[i-mid-1] = arr[i] ;
    }

    // merge both sorted arrays
    int ptr1 = 0 , ptr2 = 0 , idx = start ;

    while(ptr1 < left.size() and ptr2 < right.size()){
        if(left[ptr1] <= right[ptr2]){
            arr[idx] = left[ptr1] ;
            ptr1++ ;
        }
        else{
            arr[idx] = right[ptr2] ;
            ptr2++ ;
        }
        idx++ ;
    }
    while(ptr1 < left.size()){
        arr[idx] = left[ptr1];
        ptr1++ ; idx++ ;
    }

    while(ptr2 < right.size()){
        arr[idx] = right[ptr2] ;
        ptr2++ ; idx++ ;
    }
}

void mergesort(vector<int> &arr  , int start , int end){
    if(start >= end)
        return ;

    int mid = start + (end-start)/2 ;
    mergesort(arr , start , mid);
    mergesort(arr , mid+1 , end);
    merge(arr , start , mid , end);    
}


void insertionsort(vector<int> &arr){
    /*
        choose the current element find backwards where it can be inserted
    */
   for(int i = 1 ; i < arr.size() ; i++){
       int prev_idx = i-1 ;
       int cur_ele = arr[i] ;

       while(prev_idx >= 0 and arr[prev_idx] > cur_ele){
           arr[prev_idx+1] = arr[prev_idx] ;  // moving the prev element forward
           prev_idx-- ;
       }
        arr[prev_idx+1] = cur_ele ;
   }

}
void printarr(vector<int> &arr){
    for(int ele : arr){
        cout << ele << " " ;
    }
    cout << endl ;
}

int main(){
    vector<int> arr = {6,8,2,3,0,10,14,17,12,2,8,9};
    insertionsort(arr);
    printarr(arr);
}