1. [magic index](https://www.codingninjas.com/codestudio/problems/magic-index_1199229?topList=cracking-the-coding-interview-questions&leftPanelTab=0)
```cpp
int magicIndex(vector<int> a, int n) {
    for(int i = 0 ; i < n ; i++){
        if(i == a[i]) return i ;
    }
    return -1 ;
}
```
2. [search in rotated sorted array](https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_630450?topList=cracking-the-coding-interview-questions&leftPanelTab=0)
```cpp
int findRotatedIdx(int *arr , int n){
    int left = 0 , right = n-1 , mid ;
    while(left < right){
        mid = left + (right - left)/2 ;
        if(arr[mid] <= arr[right]){
            right = mid ;
        }
        else{
            left = mid+1 ;
        }
    }
    return left ;
}
int binsearch(int target , int left , int right , int *arr){
    int mid ;
    while(left <= right){
        mid = left + (right-left)/2 ;
        if(arr[mid] == target) return mid ;
        else if(arr[mid] < target) left = mid+1 ;
        else right = mid-1 ;
    }
    return -1 ;
}
int search(int* arr, int n, int key) {
    /*
        4 5 1 2 3 
    */
    int rotated_idx = findRotatedIdx(arr , n);
    int res = binsearch(key , 0 , rotated_idx-1 , arr) ;
    if(res == -1){
        return binsearch(key, rotated_idx , n-1 , arr);
    }
    return res ;
}
```

3. [intersection of linked list](https://www.codingninjas.com/codestudio/problems/intersection-of-linked-list_630457?topList=cracking-the-coding-interview-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int findIntersection(Node *h1, Node *h2)
{
    unordered_set<Node* > memo ;
    while(h1 or h2){
        if(h1){
            if(memo.find(h1) != memo.end()) return h1->data ;
            memo.insert(h1);
            h1 = h1->next ;
        }
        if(h2){
            if(memo.find(h2) != memo.end()) return h2->data ;
            memo.insert(h2);
            h2 = h2->next ;
        }
    }
    return -1 ;
}  
// O(1)
#include<bits/stdc++.h>
int findIntersection(Node *h1, Node *h2)
{    Node* root1 = h1 , *root2 = h2 ;
 
    while(h1 != h2){
        if(h1 == NULL){
            h1 = root2 ;
        }
        else{
            h1 = h1->next ;
        }  
        if(h2 == NULL){
            h2 = root1 ;
        }
        else{
            h2 = h2->next ;
        }
        
    }
    return (h1 == NULL)?-1:h1->data ;
}      
```

4. [ways to make coin change]()
```cpp

// Memoization
#include<bits/stdc++.h>
int N ;

long helper(int pos , int *coins , int value , vector<vector<long>> &memo){
    if(value == 0) return 1 ;
    if(value < 0 or pos == N) return 0 ;
    if(memo[pos][value] != -1) return memo[pos][value] ;
    
    return memo[pos][value] = helper(pos ,coins, value-coins[pos] , memo) + helper(pos+1, coins , value , memo);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    N = n ;
    vector<vector<long>> memo(n , vector<long>(value+1 , -1));
    return helper(0 , denominations , value , memo);
}
```