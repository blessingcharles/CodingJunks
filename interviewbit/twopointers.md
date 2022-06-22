## TWO POINTERS

### Sorting

1. [Pair with given diff](https://www.interviewbit.com/problems/pair-with-given-difference/)

```cpp
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> memo ;
    
    for(int ele : A){
        memo[ele]++ ;
    }
    int need = 0 ;
    for(int ele : A){
        need = ele - B ;
        if(need == ele and memo[ele] > 1){
                return 1 ;
        }
        if(need != ele and memo.find(need) != memo.end()){
            return 1 ;
        }
    }
    
    return 0 ;
}
```

2. [pair-with-given-diff](https://www.interviewbit.com/problems/3-sum/)
```cpp
int Solution::threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin() , A.end());
    
    long mindiff = INT_MAX ;
    long maxdiff = INT_MIN ;
    
    int N = A.size() ;
    long temp ;
    
    for(int i = 0 ; i < N-2 ; i++){
        int left = i+1 , right = N-1 ;
        
        while(left < right){
            temp = A[i] + A[left] + A[right] ;
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
```

3. [three-sum](https://www.interviewbit.com/problems/3-sum-zero/)
```cpp
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> res ;
    int N = A.size() ;
    sort(A.begin() , A.end());
    long temp ;
    
    for(int i = 0 ; i  < N ; i++){
        int left = i+1 , right = N-1 ;
        if(i != 0 and A[i] == A[i-1]){
            continue ;
        }
        
        while(left < right){
            temp = (long )A[left] + A[right] + A[i] ;
            if(temp < 0){
                left++ ;
            }           
            else if(temp > 0){
                right-- ;
            }         
            else{
                // they are zero ;
                res.push_back({A[i] , A[left] , A[right]});
                // remove the duplicates
                right-- ;
                left++ ;
                while(left < right and A[left] == A[left-1]){
                    left++ ;
                }
                while(left < right and A[right] == A[right+1]){
                    right-- ;
                }
            }
        }
    }
    return res ;
}
```

4. [counting-triangles](https://www.interviewbit.com/problems/counting-triangles/)
```cpp
int Solution::nTriang(vector<int> &nums) {
    long long ans = 0 ;
    long temp ;
    int N = nums.size() ;
    sort(nums.begin() , nums.end() , greater<int>());
    long mod = 1e9+7 ;
    
    // triangle inquality theorem sum of two sides must be greater than third sides
    int mid ;
    
    for(int i = 0 ; i < N-2 ; i++){
        int left = i+1 , right = N-1 ;
        
        while(left < right){
            if(nums[i] < nums[left] + nums[right]){
                // possible candidate from left to right 
                ans = (ans + (right-left))%mod ;
                left++ ;
            }
            else{
                right-- ;
            }
        }
    }
    return ans ;
}
```

5. [difk](https://www.interviewbit.com/problems/diffk/)
```cpp
int Solution::diffPossible(vector<int> &nums, int B) {
    long temp ;
    
    for(int i = 0 ; i < nums.size()-1 ; i++){
        int req = B + nums[i] ;
        int left = i+1 , right = nums.size()-1 , mid ;
        while(left <= right){
            mid = left + (right-left)/2 ;
            if(nums[mid] == req){
                return 1 ;
            }
            else if(nums[mid] < req){
                left = mid+1 ;
            }
            else{
                right = mid-1 ;
            }
        }
    }
    return 0 ;
}
```

### Tricks

1. [max-ones](https://www.interviewbit.com/problems/maximum-ones-after-modification/)
```cpp
int Solution::solve(vector<int> &nums, int B) {
    // sliding window 
    int cur_shift = 0 ;
    int maxwindow = 0 , left = 0 , right = 0 ;
    int N = nums.size() ;
    
    while(right < N){
        if(nums[right] == 0){
            cur_shift++ ;
        }
        while(cur_shift > B){
            if(nums[left] == 0){
                cur_shift-- ;
            }
            left++ ;
        }
        maxwindow = max(maxwindow , right-left+1);
        right++ ;
    }    
    return maxwindow ;
}
```

2. [counting-subarrays](https://www.interviewbit.com/problems/counting-subarrays/)
```cpp
#include<bits/stdc++.h>

int Solution::solve(vector<int> &nums, int B) {
    long ans = 0 ;
    int N = nums.size() ;
    vector<int> prefixsum(N+1 , 0);
    partial_sum(nums.begin() , nums.end() , prefixsum.begin()+1);
    int left = 0 , right = 1 ;    
    
    while(right <= N){
        while(right <= N and prefixsum[right] - prefixsum[left] < B){
            ans += (right-left);
            right++ ;
        }
        left++ ;
    }   
    return ans ;
}
```

3. [subarrays-with-distinct](https://www.interviewbit.com/problems/subarrays-with-distinct-integers/)
```cpp

int helper(vector<int> &nums , int B){
    // atmost b distincts 
    
    int left = 0 , right = 0 ;
    int N = nums.size() ;
    unordered_map<int,int> memo ;
    
    int current_distincts = 0 ;
    int ans = 0 ;
    
    while(right < N){
        if(memo.find(nums[right]) == memo.end()){
            current_distincts++ ;
        }    
        memo[nums[right]]++ ;
        
        while(current_distincts > B){
            if(memo[nums[left]] == 1){
                memo.erase(nums[left]);
                current_distincts-- ;
            }
            else{
                memo[nums[left]]-- ;
            }
            left++ ;
        }
        
        ans += (right - left+1);
        right++ ;
    }
    
    return ans ;
}
int Solution::solve(vector<int> &nums, int B) {
    // exactly(B) = atmost(B) - atmost(B-1)
    if(B == 1){
        return helper(nums,1);
    }
    
    return helper(nums,B)-helper(nums,B-1) ;
}
```

4. [max-continuos-1s](https://www.interviewbit.com/problems/max-continuous-series-of-1s/)
```cpp
vector<int> Solution::maxone(vector<int> &nums, int maxflips) {
    int maxlen = 0 , maxleft = 0;
    int cur_flips = 0 , left = 0 , right = 0 ;
    int N = nums.size() ;
    
    while(right < N){
        if(nums[right] == 0){
            cur_flips++ ;
        }   
        while(cur_flips > maxflips){
            if(nums[left] == 0){
                cur_flips-- ;
            }
            left++ ;
        }
        if(maxlen < (right-left+1)){
            maxlen = right-left+1 ;
            maxleft = left ;
        }
        right++ ;
    }
    vector<int> res ;
    
    if(maxlen == 0){
        return res ;    
    }
    right = maxleft+maxlen ;
    
    while(maxleft < right){
        res.push_back(maxleft); maxleft++ ;
    }
    return res ;
}
```

5. [array-3-pointers](https://www.interviewbit.com/problems/array-3-pointers/)
```cpp
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans = INT_MAX ;
    int ptr1 = 0 , ptr2 = 0 , ptr3 = 0;
    
    while(ptr1 < A.size() and ptr2 < B.size() and ptr3 < C.size()){    
        ans = min(ans , max(abs(A[ptr1] - B[ptr2]) , max(abs(A[ptr1] - C[ptr3]) , abs(B[ptr2] - C[ptr3])))) ;
        if(A[ptr1] <= B[ptr2] and A[ptr1] <= C[ptr3]){
            ptr1++ ;
        }
        else if(B[ptr2] <= A[ptr1] and B[ptr2] <= C[ptr3]){
            ptr2++ ;
        }
        else{
            ptr3++ ;
        }
    }
    return ans ;
}
```

6. [container-with-most-water](https://www.interviewbit.com/problems/container-with-most-water/)
```cpp
int Solution::maxArea(vector<int> &A) {
    int left = 0 , right = A.size()-1 ;
    int maxarea = 0 ;
    int curarea ;
    
    while(left < right){
        curarea = (right-left)*min(A[left] , A[right]);
        
        maxarea = max(maxarea , curarea) ;
        
        if(A[left] < A[right]){
            left++ ;
        }    
        else{
            right-- ;
        }
    }
    
    return maxarea ;
}
```