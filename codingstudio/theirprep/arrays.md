### Arrays

1. [pair sum](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280152?leftPanelTab=0)
```cpp

// Approach 1
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
     unordered_map<int , int> memo ;
     vector<vector<int>> ans ;
    
     for(int ele : arr){
         int req = s - ele ;
         if(memo.find(req) != memo.end()){
             if(req > ele){
                 for(int i = 0 ; i < memo[req] ; i++)
                     ans.push_back({ele , req});
             }
             else{
                 for(int i = 0 ; i < memo[req] ; i++)
                     ans.push_back({req , ele});
             }
         }
         memo[ele]++;
     }
     sort(ans.begin() , ans.end());
     return ans ;
}

// Approach 2
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin() , arr.end());
    vector<vector<int>> ans ;
    int left = 0 ,right = arr.size()-1 ;
    while(left < right){
        int tt = arr[left] + arr[right] ;
        if(tt == s){
            if(arr[left] == arr[right]){
                // same elements
                // count the elements c*(c-1)
                int count = 1 ; left++ ;
                while(arr[left] == arr[left-1]){
                    count++ ; left++ ;
                }
                count = ((count-1)*count)/2 ;
                for(int i = 0 ; i < count ; i++){
                    ans.push_back({arr[right], arr[right]});
                }
            }
            else{
                // diff elements c*c
                int left_count = 1 ; left++ ;
                int right_count = 1 ; right-- ;
                while(arr[left] == arr[left-1]){
                    left++ ; left_count++ ;
                }
                while(arr[right] == arr[right+1]){
                    right-- ; right_count++ ;
                }
                int count = left_count*right_count ;
                for(int i = 0; i < count ; i++){
                    ans.push_back({ arr[left-1] , arr[right+1]}  );
                }
            }
        }
        else if(tt > s){
            right-- ;
        }
        else{
            left++ ;
        }
    }
     
     return ans ;
}
```

2. [check overlapping intervals](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280151?leftPanelTab=1)
```cpp
#include<bits/stdc++.h>

bool checkOverlappingIntervals(long* start, long* end, int n)
{
    if(n <= 1) return false ;
    
    vector<pair<long,long>> arr ;
    for(int i = 0 ; i < n ; i++){
        arr.push_back({start[i] , end[i]});
    }
    sort(arr.begin() , arr.end());
    
    long prev_end = arr[0].second ;
    for(int i = 1 ; i < n ; i++){
        if(prev_end > arr[i].first){
            return true ;
        }
        prev_end = arr[i].second ;
    }
    return false ;
}
```

3. [flip bits](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280149?leftPanelTab=1)
```cpp
int flipBits(int* arr, int n) 
{
        // 1 1 0 0 1 1 0 
        //find the subset where zero's are maximised
    
    int ptr = 0 ;
    int zeros_count = 0 ;
    int max_zeros_count = 0 ; 
    int ones_count = 0 ;
    
    for(int i = 0 ; i < n ; i++){
        if(zeros_count == 0 and arr[i] == 1){
             ones_count++ ;   
        }
        else if(arr[i] == 1){
            ones_count++ ;
            zeros_count-- ;
        }
        else{
            zeros_count++ ;
            max_zeros_count = max(max_zeros_count , zeros_count);
        }
    }
    return ones_count + max_zeros_count ;
}
```

4. [majority element](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280156?leftPanelTab=3)
```cpp
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// moore's voting algorithm
    int ele = arr[0] , current_votes = 1 ;
    
    for(int i = 1 ; i < n ; i++){
        if(ele == arr[i]){
            current_votes++ ;
        }
        else{
            current_votes-- ;
            if(current_votes < 0){
                // you are eliminated by boy
                ele = arr[i] ;
                current_votes = 1 ;
            }
        }
    }
    // check if the ele occurs more than N/2 ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(ele == arr[i]) count++ ;
    }
    if(count > n/2) return ele ;
    return -1 ;
}
```

5. [smallest subarray with k distinct](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1266129?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    int l_idx , r_idx , minlen = INT_MAX;
    unordered_map<int,int> memo ;
    int right = 0 , left = 0 ;
    int N = arr.size() ;
    while(right < N){
        memo[arr[right]]++ ;
        while(memo.size() > k){
            memo[arr[left]]-- ;
            if(memo[arr[left]] == 0) memo.erase(arr[left]);
            left++ ;
        }
        while(memo.size() == k){
            int curlen = right-left+1 ;
            if(curlen < minlen){
                minlen = curlen ;
                l_idx = left  ;
                r_idx = right ;
            }
            // can we still decrease the window
            memo[arr[left]]-- ;
            if(memo[arr[left]] == 0) memo.erase(arr[left]);
            left++ ;
        }
        right++ ;
    }
    if(minlen == INT_MAX) return {-1} ;
    return {l_idx , r_idx};
}
```

6. [container with most water](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280150?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int maxArea(vector<int>& height) {
   if(height.size() <= 1) return 0 ;
    
   int left_ptr = 0 , right_ptr = height.size()-1 ;
   int maxarea = 0 ;
   while(left_ptr < right_ptr){
       int min_h = min(height[left_ptr] , height[right_ptr]);
       maxarea = max(maxarea , min_h*(right_ptr - left_ptr));
       // decide which side to move
       if(height[left_ptr] < height[right_ptr]){
           left_ptr++ ;
       }
       else{
           right_ptr-- ;
       }
   }
    return maxarea ;
}
```
7. [sort012](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280153?leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int zero_ptr = 0 , one_ptr = 0 , two_ptr = n-1 ;
   while(one_ptr <= two_ptr ){
       if(arr[one_ptr] == 0){
           swap(arr[one_ptr] , arr[zero_ptr]);
           one_ptr++ ;
           zero_ptr++ ;
       }
       else if(arr[one_ptr] == 1){
           one_ptr++ ;
       }
       else{
           swap(arr[one_ptr] , arr[two_ptr]);
           two_ptr-- ;
       }
   }
}
```
8. [search in rotated sorted array](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280154?leftPanelTab=0)
```cpp
int binsearch(int *arr , int left , int right , int t){
    int mid ;
    while(left <= right){
        mid = left + (right - left)/2 ;
        if(arr[mid] == t) return mid ;
        else if(arr[mid] > t) right = mid-1 ;
        else left = mid+1 ;
    }
    return -1 ;
}

int search(int* arr, int n, int key) {
    // find the pivot element first smallest
    int left = 0 ,  right = n-1 ;
    int mid ;
    while(left < right){
        if(arr[left] <= arr[right]){
            break ;
        }
        mid = left + (right - left)/2 ;
        if(arr[mid] >= arr[left]){
            left = mid+1 ;
        }
        else{
            right = mid ; 
        }
    }
    int r1 = binsearch(arr, left , n-1 , key);
    int l1 = binsearch(arr ,0,left-1 , key);
    if(r1 != -1) return r1 ;
    if(l1 != -1) return l1 ;
    return -1 ;
}
```

9. [zero triplets](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280155?leftPanelTab=3)
```cpp
#include<bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int>arr, int n) {
	vector<vector<int>> res ;
    sort(arr.begin() , arr.end());
    
    for(int i = 0 ; i < n ; i++){
        if(i != 0 and arr[i] == arr[i-1]) continue ;
        if(arr[i] > 0) break ;
        int left = i+1 , right = n-1 ;
        while(left < right){
            int cursum = arr[left] + arr[right] + arr[i] ;
            if(cursum > 0){
                right-- ;
            }
            else if(cursum < 0){
                left++ ;
            }
            else{
                // 0 occured
                res.push_back({arr[i] , arr[left] , arr[right] });
                // remove the duplicates
                do{
                   left++ ;
                }while(left < right and arr[left-1] == arr[left]);
                do{
                    right-- ;
                }while(left < right and arr[right] == arr[right+1]);
            }
        }
    }
    return res ;
}
```