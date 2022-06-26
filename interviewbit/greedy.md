### GREEDY

## Easy Greedy

1. [highest-product](https://www.interviewbit.com/problems/highest-product/)
```cpp
int Solution::maxp3(vector<int> &A) {
    int N = A.size() ;
    if(N == 1){
        return A[0] ;
    }
    if(N == 2){
        return A[0]*A[1] ;
    }
    
    sort(A.begin() , A.end());
    
    int maxval = max(A[0]*A[1]*A[N-1] , A[N-1]*A[N-2]*A[N-3]);
    
    return maxval ;
}
```

2. [bulbs](https://www.interviewbit.com/problems/interview-questions/)
```cpp
int Solution::bulbs(vector<int> &A) {
    int N = A.size() , count = 0 ;
    
    
    for(int i = 0 ; i < N ; i++){
        if( (count&1) == 0){
            // initial state
            if(A[i] == 0){
                count++ ;
            }
        }
        else{
            // switched state
            if(A[i] == 1){
                count++ ;
            }
        }
    }
    
    return count ;
}
```

3. [disjoint-intervals](https://www.interviewbit.com/problems/disjoint-intervals/)
```cpp
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin() , A.end() , [](const vector<int>& a , const vector<int> &b){
       if(a[1] == b[1]){
           return a[0] > b[0] ;
       } 
       return a[1] < b[1] ;
    });
    
    int count = 1 ;
    int rightmost = A[0][1] ;
    
    for(int i = 1 ; i < A.size() ; i++){
        if(rightmost < A[i][0]){
            rightmost = A[i][1] ;
            count++ ;
        }
    }
    
    return count ;
}
```

4. [largest permutation](https://www.interviewbit.com/problems/largest-permutation/)
```cpp
vector<int> Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < A.size() ; i++){
        memo[A[i]] = i ;
    }
    int N = A.size() ;
    for(int i = 0 ; i < A.size() and B > 0; i++ , N--){
        if(N != A[i]){
            B-- ;
            int idx = memo[N] ;
            swap(A[i] , A[idx] );
            swap(memo[A[i]] , memo[A[idx]]);
        }
    }
    return A ;
}
```