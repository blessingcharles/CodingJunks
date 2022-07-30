#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void countingSort(vector<int> &arr , int place){
    vector<int> mapping(10 , 0);

    for(int ele : arr){
        int loc = (ele/place)%10 ;
        mapping[loc]++ ;
    }
    for(int i = 1 ; i < 10 ; i++) mapping[i] += mapping[i-1] ;

    vector<int> output(arr.size()) ;

    for(int i = arr.size()-1 ; i >= 0 ; i--){
        int loc = (arr[i]/place)%10 ;
        output[mapping[loc]-1] = arr[i] ;
        mapping[loc]-- ;
    }
    // cout << "Place : " << place << endl ;
    // for(int ele : output) cout << ele << " " ;
    cout << endl ;
    arr = output ;
}
void radixSort(vector<int> &arr){

    int max_ele = *max_element(arr.begin() , arr.end());
    for(int place = 1 ; (max_ele/place) > 0 ; place = place*10){
        countingSort(arr  , place);
    }
}
int main(){
    vector<int> arr = {5,77,32,1,67,55,44,33,32,14};
    radixSort(arr);
    for(int ele : arr){
        cout << ele << " " ;
    }
    cout << endl ;
}