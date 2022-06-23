# HASHING

## Hash search

1. [colorful-number](https://www.interviewbit.com/problems/colorful-number/)
```cpp
int Solution::colorful(int A) {
    unordered_set<long long> memo ;
    vector<int> arr ;
    
    while(A){
        arr.push_back(A%10);
        A = A/10 ;
    }
    
    for(int i = 0 ;i<arr.size() ; i++){
        long long mult = 1 ;
        for(int j = i ; j < arr.size() ; j++){
            mult = mult*arr[j] ;
            if(memo.find(mult) != memo.end()){
                return 0 ;
            }
            memo.insert(mult);
        }
    }
    return 1 ;
}
```

2. [largest-contiguos-zero-seq](https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/)
```cpp
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int> memo ;
    memo[0] = -1 ;
    int maxlen = 0 ;
    
    if(A[0] != 0){
        memo[A[0]] = 0 ;
    }
    else{
        maxlen = 1 ;    
    }
    int left = 0 ;
    vector<int> arr = A ;
    
    
    for(int i = 1 ;i < A.size() ; i++){
        A[i] += A[i-1] ;
        if(memo.find(A[i]) == memo.end()){
            memo[A[i]] = i ;
        }
        else{
           int len = i - memo[A[i]] ;
           if(maxlen < len){
                left = memo[A[i]]+1 ;           
                maxlen = len ;
           } 
        }
    }
    
    if(maxlen == 0){
        return {} ;
    }
    return vector<int>(arr.begin()+left , arr.begin()+left+maxlen);
}
```

3. [longest-subarray-length](https://www.interviewbit.com/problems/longest-subarray-length/)
```cpp
int Solution::solve(vector<int> &arr) {
    unordered_map<int , int> memo ;

    // A : [ 0, 1, 1, 0, 0, 1 ]
    int maxlen = 0 , maxsum = 0 ;
    
   
    for(int i = 0 ; i < arr.size() ; i++){
        
        maxsum = (arr[i] == 0)?maxsum-1:maxsum+1 ;
                
        if(maxsum == 1){
            maxlen = i+1 ;
        }
        
        else if(memo.find(maxsum) == memo.end()){
            memo[maxsum] = i ;            
        }
        
        if(memo.find(maxsum-1) != memo.end()){
            maxlen = max(maxlen , i - memo[maxsum-1]);
        }            
    }
    return maxlen ;
}
```

4. [first-repeating](https://www.interviewbit.com/problems/first-repeating-element/)
```cpp
int Solution::solve(vector<int> &A) {
    int minidx = INT_MAX ;
    unordered_map<int,int> memo ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(memo.find(A[i]) != memo.end()){
            minidx = min(minidx , memo[A[i]]);
        }    
        else{
            memo[A[i]] = i ;
        }
    }
    return (minidx == INT_MAX)?-1:A[minidx] ;   
}
```

5. [2sum](https://www.interviewbit.com/problems/2-sum/)
```cpp
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> memo ;
    int minidx1 = INT_MAX , minidx2 = INT_MAX ;
    
    for(int i = 0 ; i < A.size() ; i++){
        int req = B - A[i] ;
        if(memo.find(req) != memo.end()){
            return {memo[req]+1 , i+1};
        }
        if(memo.find(A[i]) == memo.end())
            memo[A[i]] = i ;
    }
    return {} ;
}
```

6. [4sum](https://www.interviewbit.com/problems/4-sum/)
```cpp
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> res ;
    sort(A.begin() , A.end());
    
    for(int i = 0 ; i < A.size()-3 ; i++){
        // if same elements repeated 
        if(i != 0 and A[i] == A[i-1]) continue ;
        for(int j = i+1 ; j < A.size()-2 ; j++){
            if(j != i+1 and A[j] == A[j-1] ) continue ;
            int left = j+1 , right = A.size()-1; 
            
            while(left < right){
                int cursum = A[i] + A[j] + A[left] + A[right] ;
                
                if(cursum > B){
                    right-- ;
                }
                else if(cursum < B){
                    left++ ;
                }
                else{
                    //cursum is equal 
                    res.push_back({A[i],A[j],A[left],A[right]});
                    
                    //remove the duplicated on left and right
                    do{
                        left++ ;
                    }while(left < right and A[left] == A[left-1]);
                    do{
                        right-- ;
                    }while(left < right and A[right] == A[right+1]);
                }
            }
        }
        
    }
    return res ;
}
```

7. [valid-sudoku](https://www.interviewbit.com/problems/valid-sudoku/)
```cpp
int Solution::isValidSudoku(const vector<string> &A) {
    for(int row = 0 ; row < 9 ; row++){
        unordered_set<char> memo1 ;
        unordered_set<char> memo2 ;
        
        for(int col = 0 ; col < 9 ; col++){
            
            if(memo1.find(A[row][col]) != memo1.end()){
                return 0 ;
            }
            if(A[row][col] != '.')
                memo1.insert(A[row][col]);
            
            if(memo2.find(A[col][row]) != memo2.end()){
                return 0 ;
            }
            if(A[col][row] != '.')
                memo2.insert(A[col][row]);
        }
    }
    
    for(int i = 0 ; i < 9 ; i = i+3){
        for(int j = 0 ; j < 9 ; j = j+3){
            unordered_set<char> memo ;
            
            for(int row = 0 ; row < 3 ; row++){
                for(int col = 0 ; col < 3 ; col++){
                    if(memo.find(A[i+row][j+col]) != memo.end()){
                        return 0 ;
                    }
                    if(A[row+i][col+j] != '.')
                        memo.insert(A[i+row][j+col]);
                }
            }
        }
    }
    return 1 ;
}
```

8. [diffk-2](https://www.interviewbit.com/problems/diffk-ii/)
```cpp
int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> memo ;
    
    for(int i = 0 ; i < A.size() ; i++){
        int req = A[i] - B ;
        int req1 = B + A[i] ;
        
        if(memo.find(req) != memo.end()){
            return 1 ;
        }
        if(memo.find(req1) != memo.end()){
            return 1 ;
        }
        memo.insert(A[i]);
    }
    return 0 ;
}
```