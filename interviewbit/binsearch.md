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

