#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

/*
    Intuition : How many elements should occur before me so i can find my idx
    Algo :
        1. create buckets and store the occurences count
        2. do prefix sum to get how many elements before me
        3. loop through the arr : place the ele based on the mapping in output arr
*/
vector<int> countSort(vector<int> &arr){
    int max_ele = *max_element(arr.begin() , arr.end());
    vector<int> mapping(max_ele+1 , 0);

    for(int ele : arr){
        mapping[ele]++ ;
    }
    for(int i = 1 ; i <= max_ele ; i++){
        mapping[i] += mapping[i-1] ;
    }
    vector<int> output(arr.size() , 0);
    for(int i = arr.size()-1 ; i >= 0 ; i--){
        int ele = arr[i] ;
        output[mapping[ele]-1] = ele ;
        mapping[ele]-- ;
    }
    return output ;
}
int main(){
    vector<int> arr = {5,3,2,9,5,4,3,2,0} ;
    for(int ele : countSort(arr)){
        cout << ele << " " ;
    }
    cout << endl ;
    sort(arr.begin() , arr.end());
    for(int ele : arr) cout << ele << " " ;
}