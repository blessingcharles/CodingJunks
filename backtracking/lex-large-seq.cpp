#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

int N ;
bool helper(vector<int> &arr , int pos , vector<bool> &visited){
    if(pos == arr.size()){
        return true ;
    }
    if(arr[pos] != -1){
        return helper(arr , pos+1 , visited);
    }
    for(int i = N ; i >= 1 ; i--){
        if(visited[i]) continue ;
        visited[i] = true ;
        arr[pos] = i ;
        if(i == 1){
            if(helper(arr , pos+1 , visited)){
                return true ;
            }          
        }
        else if(pos+i < arr.size() and arr[pos+i] == -1){
            arr[pos+i] = i ;
            if(helper(arr , pos+1 , visited)){
                return true ;
            }
            arr[pos+i] = -1 ;
        }
        visited[i] = false ;
        arr[pos] = -1 ;
    }        
    return false ;    
}

vector<int> validSequence(int n)
{
    vector<int> arr(2 * n - 1, -1);
    vector<bool> visited(n+1 , false);
    N = n;
    helper(arr, 0, visited);
    return arr;
}