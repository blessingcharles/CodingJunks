### Array math

1. [pick from both sides](https://www.interviewbit.com/problems/pick-from-both-sides/)
```cpp
  int maxsum = 0 ;
    int left ;
    for(left = 0 ; left < B ; left++){
        maxsum += A[left] ;
    }
    left-- ;
    int right = A.size()-1 , cursum = maxsum ;
    
    while(left >= 0){
        cursum -= A[left] ;
        cursum += A[right] ;
        left-- ;   right-- ;
        maxsum = max(maxsum , cursum);
    }
    
    return maxsum ;
```

2. [max-min](https://www.interviewbit.com/problems/min-steps-in-infinite-grid/)
```cpp
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int N = A.size() ;
    int minsteps = 0 ;
    
    for(int i = 1 ; i < N ; i++){
        minsteps += max(abs(A[i]-A[i-1]) , abs(B[i] - B[i-1]));
    }
    return minsteps ;
}

```

3. [minimum-light-to-activate](https://www.interviewbit.com/problems/minimum-lights-to-activate/)
```cpp
int rightmostcover(vector<int> &A , int start , int end){
    if(start < 0)
        return -1 ;
        
    while(end >= start){
        if(A[end] == 1){
            return end ;
        }
        end-- ;
    }
    return -1 ;
}
int solve(vector<int> &A, int B) {
    int ptr = 0 ;
    int turnedon = 0 ;
    
    int cover ;
    
    while(ptr < A.size()){
        cover = rightmostcover(A , ptr , ptr+B-1);
        if(cover == -1){
            // check the left part
            cover = rightmostcover(A , ptr-B+1 , ptr-1);
            if(cover == -1){
                return cover ;
            }
            ptr++ ;
        }            
        ptr = cover + B ;
        turnedon++ ;
    }
    
    return turnedon ;
}
```

4. [max-sum-triplet](https://www.interviewbit.com/problems/maximum-sum-triplet/)
```cpp
int Solution::solve(vector<int> &A) {
    int N = A.size(); 
    vector<int> maxFromRight(N);
    set<int> maxFromLeft;
    
    maxFromRight[N-1] = A[N-1];
    
    for(int i = N-2 ; i >= 0 ; i--){
        maxFromRight[i] = max(maxFromRight[i+1] , A[i]);
    }    
    int maxsum = 0 ;
    maxFromLeft.insert(A[0]);
    
    for(int i = 1 ; i < A.size()-1 ; i++){
        // consider ith as the middle element ;
        
        maxFromLeft.insert(A[i]);
            
        int right_ele = maxFromRight[i+1];
        auto cur_it =  maxFromLeft.find(A[i]) ;        
        
        if(cur_it == maxFromLeft.begin()) continue ;
        cur_it-- ;
        
        int left_ele = *cur_it ;
        
        if(A[i] > left_ele and right_ele > A[i]){
            maxsum = max(maxsum , left_ele + A[i] + right_ele);
        }
        
    }
    return maxsum ;
}
``` 

5. [max-subarrray-sum](https://www.interviewbit.com/problems/max-sum-contiguous-subarray/)
```cpp
int Solution::maxSubArray(const vector<int> &A) {
    // kadane's algorithm
    int maxsum = A[0] ;
    int cursum = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] + cursum < A[i]){
            cursum = A[i] ;
        }
        else{
            cursum += A[i] ;
        }
        maxsum = max(cursum , maxsum);
    }
    
    return maxsum ;
}
```

6. [add-one-to-number](https://www.interviewbit.com/problems/add-one-to-number/)
```cpp
vector<int> Solution::plusOne(vector<int> &A) {
        
    vector<int> ans ;
    int carry = 0 , temp ;
    // remove all starting zeros
    int end = 0 ;
    
    if(A.size() != 1){
        for(end = 0 ; end < A.size() ; end++){
            if(A[end] != 0) break ;
        }    
    }
    
    for(int i = A.size()-1 ; i >= end ; i--){
        if(i == A.size()-1){
            temp = A[i] + 1 ;
            carry = temp/10 ;
            ans.push_back(temp%10);
        }
        else{
            temp = A[i] + carry ;
            carry = temp/10 ;
            ans.push_back(temp%10);
        }
    }
    
    if(carry) ans.push_back(carry);
    
    reverse(ans.begin() , ans.end());
    return ans ;
}
```

7. [max-abs-diff](https://www.interviewbit.com/problems/maximum-absolute-difference/)
```cpp
int Solution::maxArr(vector<int> &A) {
    int N = A.size() ;
    int max1 = INT_MIN , max2 = INT_MIN ;
    int min1 = INT_MAX , min2 = INT_MAX ;
         
    for(int i = 0 ; i < N ; i++){
        
        max1 = max(max1 , A[i]+i);
        max2 = max(max2 , i-A[i]);
        
        min1 = min(min1 , A[i]+i );
        min2 = min(min2 , i - A[i] );  
    
    } 
    
    return max(max1-min1 , max2-min2);
}
```

8. 