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