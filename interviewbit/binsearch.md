## Practise

1. [sqrt]()
```cpp
int Solution::sqrt(int A) {
    long left =  0 , right = A ;
    long mid ;
    long long sq ;
    
    while(left < right){
        mid = left + (right-left+1)/2 ;
        sq = mid*mid ;
        
        if(sq == A){
            return mid ;
        }
        else if(sq < A){
            left = mid ;
        }
        else{
            right = mid-1 ;
        }
    }    
    return left ;
}
```

### Examples

1. [count-ele-occurence](https://www.interviewbit.com/problems/count-element-occurence/hints/)
```cpp
int Solution::findCount(const vector<int> &nums, int B) {
    // find the first ele smaller than B 
    int N = nums.size() ;
    if(N == 1){
        return nums[0] == B ;
    }
    int left = 0 , right = N-1 , mid ;
    
    while(left  < right){
        mid = left + (right-left+1)/2 ;
        if(nums[mid] < B){
            left = mid ;
        }
        else{
            right = mid-1 ;
        }
    }
    int left_ptr = right ;
    if(left_ptr == N-1 or nums[left_ptr+1] != B){
        return 0 ;
    }
    if(left_ptr == 0 and nums[left] == B){
        left_ptr = -1 ;
    }
    // find the first larger ele than B
    left = 0 ; right = N-1 ;
    
    while(left < right){
        mid  = left  + (right-left)/2 ;
        
        if(nums[mid] <= B){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    if(right == N-1 and nums[right] == B){
        right++ ;
    }
    return right-left_ptr-1 ;
    
}
```

2. [minimum in rotated array](https://www.interviewbit.com/problems/rotated-array/)
```cpp
int Solution::findMin(const vector<int> &nums) {
    int left = 0 , right = nums.size()-1 , mid ;
    int N = nums.size() ;
    if(nums[0] < nums[N-1]){
        return nums[0] ;
    }
    
    while(left < right){
        mid = left + (right - left)/2 ;
        
        if(nums[mid] > nums[right]){
            // then the mid is in the leftside greater part
            left = mid+1 ;
        }
        else if(nums[mid] < nums[right]){
            right = mid ;
        }
        else{
            // handling duplicates
            right = right-1 ;
        }
    }
    return nums[left] ;
}
```

### simple binary search

1.  [bitonic-search](https://www.interviewbit.com/problems/search-in-bitonic-array/)
```cpp

int Solution::solve(vector<int> &nums, int B) {
    int N = nums.size() ;
    int mid = 0 , left = 0 , right = N-1 ;
    int bitonic_point = -1 ;
    
    // find the bitonic point
    while(left <= right){
        mid = left + (right-left)/2 ;
        int left_ele = (mid > 0)?nums[mid-1]:INT_MIN ;
        int right_ele = (mid < N-1)?nums[mid+1]:INT_MIN ;
        if(nums[mid] > right_ele and nums[mid] > left_ele){
            bitonic_point = mid ;
            break ;        
        }
        else if(left_ele  < nums[mid]){
            left = mid+1 ;
        }
        else{
            right = mid-1 ;
        }
    }
    
    int idx = binary_search(nums  , B , 0 ,bitonic_point);
    if(idx == -1){
        idx = binary_search(nums , B , bitonic_point+1 , N-1 , -1);
    }
    return idx ;
}
```

2. [smaller-equal-elements](https://www.interviewbit.com/problems/smaller-or-equal-elements/)
```cpp
int Solution::solve(vector<int> &A, int B) {
    // find the first larger element
    if(B >= A[A.size()-1]){
        return A.size() ;
    }
    int left = 0 , right = A.size()-1 , mid ; 
    
    while(left < right){
        mid = left + (right-left)/2 ;
        
        if(A[mid] <= B){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    
    return left ;
}
```

3. [wood-cutting-made-easy](https://www.interviewbit.com/problems/woodcutting-made-easy/)
```cpp
bool isFeasible(vector<int> &trees , int cutting , long long target){
    long long collected = 0 ;
    for(int i = 0 ;i < trees.size() ; i++){
        if(trees[i]-cutting > 0){
            collected += trees[i]-cutting ;
        }
    }
    
    return collected >= target ;
}

int Solution::solve(vector<int> &A, int B) {
    int left = 0 , right = *max_element(A.begin() , A.end()) , mid ;
    
    while(left < right){
        mid = left + (right-left+1)/2 ;
        if(isFeasible(A , mid , B)){
            left = mid ;
        }
        else{
            right = mid-1 ;
        }
    }
    return right ;
}
```

4. [matrix-search](https://www.interviewbit.com/problems/matrix-search/)
```cpp
int Solution::searchMatrix(vector<vector<int> > &nums, int target) {
    // find the row B may present
    int M = nums.size() , N = nums[0].size() ;
    
    int left = 0 , right = M-1 , mid ;
    
    // find row which is just smaller than target 
    while(left < right){
        mid = left + (right - left + 1)/2 ;
        if(nums[mid][0] == target){
            return 1 ;
        }
        else if(nums[mid][0] > target){
            right = mid-1 ;
        }
        else{
            left = mid ;
        }
    }
    int row = right ;
    right = N-1 ; left = 0 ;
    
    // normal binary search
    while(left <= right){
        mid = left + (right-left)/2 ;
        if(nums[row][mid] == target){
            return 1 ;
        }
        else if(nums[row][mid] < target){
            left = mid+1 ;
        }
        else{
            right = mid-1 ;
        }
    }
    return 0 ;
}
```

5. [search-range](https://www.interviewbit.com/problems/search-for-a-range/)
```cpp
vector<int> Solution::searchRange(const vector<int> &nums, int B) {
    // find the first ele smaller than B 
    int N = nums.size() ;

    int left = 0 , right = N-1 , mid ;
    
    while(left  < right){
        mid = left + (right-left+1)/2 ;
        if(nums[mid] < B){
            left = mid ;
        }
        else{
            right = mid-1 ;
        }
    }
    int left_ptr = right ;
    
    if(left_ptr == 0){
        if(nums[left_ptr] > B){
            return {-1,-1};
        }
        else if(nums[left_ptr] == B){
            left_ptr = -1 ;
        }
    }
    
    
    // find the first larger ele than B
    left = 0 ; right = N-1 ;
    
    while(left < right){
        mid  = left  + (right-left)/2 ;
        
        if(nums[mid] <= B){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    if(right == N-1){
        if(nums[right] < B){
            return {-1,-1};
        }
        else if(nums[right] == B){
            right = N ;
        }
    }
    if(nums[left_ptr+1] != B){
        return {-1,-1};
    }
    
    return {left_ptr+1 , right-1} ;
}
```

6. [sorted-position](https://www.interviewbit.com/problems/sorted-insert-position/)
```cpp
int Solution::searchInsert(vector<int> &nums, int target) {
      int left = 0 , right = nums.size()-1 , mid ;
    
    if(nums[nums.size()-1] < target){
        return nums.size() ;
    }      
    
    while(left < right){
        mid = left + (right-left)/2 ;
        if(nums[mid] == target){
            return mid ;
        }
        else if(nums[mid] < target){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    
    return (right < 0)?0:right ;
}
```

### Search answer

1. [Matrix median](https://www.interviewbit.com/problems/matrix-median/)
```cpp
int M , N ;

int findLesserElements(vector<int> &arr , int target){
    if(arr[0] > target){
        return 0 ;
    }
    if(arr[N-1] <= target){
        return N ;
    }
    int left = 0 , right = N-1 , mid;
    
    while(left < right){
        mid = left + (right - left)/2 ;
        
        if(arr[mid] <= target){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    
    return right ;
}

int Solution::findMedian(vector<vector<int> > &A){
    M = A.size() ;
    N = A[0].size() ;
    
    int lesser = (M*N)/2 ;
    
    int left = 1 , right = A[0][N-1] ;
    
    for(int row = 1 ; row < M ; row++){
        right = max(right , A[row][N-1] ) ;
    }
    int mid ;
    
    while(left < right){
        mid = left + (right - left)/2 ;
        
        int cnt = 0 ;
        
        // find the lesser elements than mid
        for(int i = 0 ; i < M ; i++){
            cnt += findLesserElements(A[i] , mid);    
        }    
        if(cnt <= lesser){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    
    return right ;
}
```

2. [Allocate-books](https://www.interviewbit.com/problems/allocate-books/)
```cpp
#include<numeric>

bool CanIAllocate(vector<int> &arr , int students , int min_pages){
    int cur_sum = 0 , required_students = 1 ;
    
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] > min_pages){
            return false ;
        }
        if(arr[i] + cur_sum > min_pages){
            required_students++ ;
            if(required_students > students){
                return false ;
            }
            cur_sum = arr[i] ;
        }
        else{
            cur_sum += arr[i] ;
        }
    }
    
    return true ;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size() < B){
        return -1 ;
    }
    
    int left = *min_element(A.begin() , A.end()) ;
    int right = accumulate(A.begin() ,A.end() , 0);
    int mid ;
        
    while(left < right){
        mid = left + (right - left)/2 ;
        
        if(not CanIAllocate(A , B , mid)){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    
    return left ;
}
```

3. [painters-problem](https://www.interviewbit.com/problems/painters-partition-problem/)
```cpp
#include<bits/stdc++.h>

bool isPossible(vector<int> &heights , int painters ,long min_time){
    int required_painter = 1 ;
    long cur_sum = 0 ;
    
    for(int i = 0 ; i < heights.size() ; i++){
        if(heights[i] + cur_sum > min_time){
            required_painter++ ;
            if(required_painter > painters){
                return false ;
            }
            cur_sum = heights[i] ;
        }
        else{
            cur_sum += heights[i] ;
        }
    }
    
    return true ;
}
int Solution::paint(int A, int B, vector<int> &C) {
    
    long left = *max_element(C.begin() , C.end()) , right = accumulate(C.begin() , C.end() , 0) ;
    
    long mid ;
    
    while(left < right){
        mid = left + (right - left)/2 ;
        
        if(not isPossible(C , A , mid )){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    long long res = (right*B)%10000003 ;
    return res ; 
}
```

### Sort modification

2. [search in rotated array](https://www.interviewbit.com/problems/rotated-sorted-array-search/)
```cpp
int binSearch(const vector<int> &arr , int target , int left , int right){
    int mid ;
    while(left <= right){
        mid = left + (right-left)/2 ;
        if(arr[mid] == target){
            return mid ;
        }
        else if(arr[mid] > target){
            right = mid-1 ;
        }
        else{
            left = mid+1 ;
        }
    }
    return -1 ;
}
int Solution::search(const vector<int> &A, int B) {
    // find the minimum element 
    int N = A.size() ;
    int left = 0 , right = N-1 , mid ;
    
    while(left < right){
        mid = left + (right-left)/2 ;
        if(A[mid] > A[right]){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    } 
    int idx = binSearch(A , B , 0 ,right-1);
    
    if(idx == -1){
        idx = binSearch(A,B,right , N-1);
    }
    
    return idx ;
}
```

### Additional

1. [packages-ships](https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/)

```cpp
#include<bits/stdc++.h>
bool isPossible(vector<int>& packages,  int days , int weight){
    int required_days = 1 , cur_sum = 0 ;
    
    for(int i = 0 ; i < packages.size() ; i++){
        if(cur_sum + packages[i] > weight){
            required_days++ ;
            if(required_days > days){
                return false ;
            }
            cur_sum = packages[i] ;
        }
        else{
            cur_sum += packages[i] ;
        }
    }
    return true ;
}

int Solution::solve(vector<int> &A, int B) {
    int left = *max_element(A.begin() , A.end());
    int right = accumulate(A.begin() , A.end() , 0);
    int mid ;
    
    while(left < right){
        mid = left + (right - left)/2 ;
        if(not isPossible(A , B , mid)){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    return right ;
}
```