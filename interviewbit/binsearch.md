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