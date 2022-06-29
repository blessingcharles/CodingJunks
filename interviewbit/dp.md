# DYNAMIC PROGRAMMING

### 2d string dp

1. [LCS](https://www.interviewbit.com/problems/longest-common-subsequence/)

```cpp

// TOP DOWN

int helper(string &str1 , string &str2 , int pos1 ,int pos2 ,vector<vector<int>> &dp){
    if(pos1 < 0 or pos2 < 0){
        return 0 ;
    }
    if(dp[pos1][pos2] != -1){
        return dp[pos1][pos2] ;
    }

    if(str1[pos1] == str2[pos2]){
        return dp[pos1][pos2] = 1 + helper(str1 , str2 , pos1-1 , pos2-1 , dp);
    }

    // doesn't match
    return dp[pos1][pos2] = max(helper(str1 , str2 , pos1-1 , pos2 , dp) , helper(str1 , str2 , pos1 , pos2-1 , dp));

}

int Solution::solve(string A, string B) {
    vector<vector<int>> dp(A.size() , vector<int>(B.size() , -1));

    return helper(A , B , A.size()-1 , B.size()-1 , dp);
}

// BOTTOM UP

int Solution::solve(string A, string B) {
    vector<vector<int>> dp(A.size() , vector<int>(B.size() , 0));
    int M = A.size() , N = B.size() ;

    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(A[i] == B[j]){
                int from_prev = 0 ;
                if(i > 0 and j > 0) from_prev = dp[i-1][j-1];
                dp[i][j] = 1 + from_prev ;
            }
            else{
                if(i == 0 and j == 0) dp[i][j] = 0 ;
                else if(i == 0) dp[i][j] = dp[i][j-1] ;
                else if(j == 0) dp[i][j] = dp[i-1][j] ;
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
    }
    return dp[M-1][N-1] ;
}
```

2. [Longest Palindromic Subsequence](https://www.interviewbit.com/problems/longest-palindromic-subsequence/)

```cpp

// Top Down

int helper(string &str1 , string &str2 , int pos1 ,int pos2 ,vector<vector<int>> &dp){
    if(pos1 < 0 or pos2 < 0){
        return 0 ;
    }
    if(dp[pos1][pos2] != -1){
        return dp[pos1][pos2] ;
    }

    if(str1[pos1] == str2[pos2]){
        return dp[pos1][pos2] = 1 + helper(str1 , str2 , pos1-1 , pos2-1 , dp);
    }

    // doesn't match
    return dp[pos1][pos2] = max(helper(str1 , str2 , pos1-1 , pos2 , dp) , helper(str1 , str2 , pos1 , pos2-1 , dp));

}
int Solution::solve(string A) {
    string B = A ;
    int left_ptr = 0 , right_ptr = A.size()-1;
    while(left_ptr < right_ptr){
        swap(B[left_ptr++] , B[right_ptr--]);
    }

    vector<vector<int>> dp(A.size() , vector<int>(B.size() , -1));

    return helper(A , B , A.size()-1 , B.size()-1 , dp);
}
// Bottom Up

    vector<vector<int>> dp(A.size()+1 , vector<int>(B.size()+1 , 0));

    for(int i = 0 ; i <= M ; i++){
        for(int j = 0 ; j <= N ; j++){
            if(i == 0 or j == 0) continue ;
            if(A[i-1] == B[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[M][N] ;
```

3. [Edit distance](https://www.interviewbit.com/problems/edit-distance/)
```cpp

// TOP DOWN

int helper(string &str1 , string &str2 , int ptr1 , int ptr2 , vector<vector<int>> &memo){
    if(ptr1 < 0 and ptr2 < 0){
        return 0 ;
    }    
    if(ptr1 < 0){
        return ptr2+1 ;
    }
    if(ptr2 < 0){
        return ptr1+1 ;
    }
    if(memo[ptr1][ptr2] != -1){
        return memo[ptr1][ptr2] ;
    }
    
    if(str1[ptr1] == str2[ptr2]){
        return memo[ptr1][ptr2] = helper(str1 , str2 , ptr1-1 , ptr2-1 , memo);
    }
    // we can insert delete and update
    
    // insert move ptr2 
    int inserting = helper(str1 , str2 , ptr1 , ptr2-1 , memo);
    int deleting = helper(str1 , str2 , ptr1-1 , ptr2 , memo);
    int replacing = helper(str1 , str2 , ptr1-1 , ptr2-1 , memo);
    
    return memo[ptr1][ptr2] = 1+min(inserting , min(deleting , replacing));
}

int Solution::minDistance(string A, string B) {
    int M = A.size() ;
    int N = B.size() ;
    vector<vector<int>> memo(M , vector<int>(N , -1));
    
    return helper(A , B , M-1 , N-1 , memo);
}

// BOTTOM UP
int Solution::minDistance(string A, string B) {
    int M = A.size() ;
    int N = B.size() ;
    vector<vector<int>> dp(M+1 , vector<int>(N+1 , 0));
    
    
    for(int i = 0 ;i <= M ; i++){
        for(int j = 0 ; j <= N ; j++){
            if(i == 0 or j == 0) dp[i][j] = max(i,j) ;
            
            else if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = 1+min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j] )) ;
            }
        }
    }
    return dp[M][N] ;   
}
```

4. [Repeating Subsequence](https://www.interviewbit.com/problems/repeating-subsequence/)

```cpp
// TOP DOWN
int helper(string &A , int ptr1 , int ptr2 , vector<vector<int>> &memo){
    if(ptr1 < 0 or ptr2 < 0){
        return 0 ;
    }
    if(memo[ptr1][ptr2] != -1){
        return memo[ptr1][ptr2] ;
    }
    
    if(ptr1 == ptr2){
        // both can't be same index 
        return memo[ptr1][ptr2] = helper(A , ptr1 , ptr2-1 , memo) ;
    }
    if(A[ptr1] == A[ptr2]){
        // matched
        return memo[ptr1][ptr2] = 1 + helper(A , ptr1-1 , ptr2-1 , memo) ;
    }
    // no match also both ptr at different index
    
    // option1 move ptr1
    int option1 = helper(A , ptr1-1 , ptr2 , memo);
    int option2 = helper(A , ptr1 , ptr2-1 , memo);
    return memo[ptr1][ptr2] = max(option1 , option2);
}

int Solution::anytwo(string A) {
    int N = A.size() ;
    
    vector<vector<int>> memo(N , vector<int>(N , -1));
    int ans = helper(A , N-1 , N-1 , memo);
    
    return (ans > 1)?1:0 ;       
}

// BOTTOM UP
int Solution::anytwo(string A) {
    int N = A.size() ;
    
    vector<vector<int>> dp(N+1 , vector<int>(N+1 , 0));
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(i == j) dp[i][j] = dp[i][j-1]  ;
            else if(A[i-1] == A[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    for(int ele : dp[N]){
        if(ele > 1) return 1 ;
    }
    return 0 ;
}
```

5. [distinct subsequences](https://www.interviewbit.com/problems/distinct-subsequences/)
```cpp

// TOP DOWN

int helper(string &str1, string &str2, int ptr1 , int ptr2 , vector<vector<int>> &memo){
    if(ptr2 < 0){
        return 1 ;
    }
    if(ptr1 < 0) return 0 ;
    if(memo[ptr1][ptr2] != -1){
        return memo[ptr1][ptr2] ;
    }
    
    if(str1[ptr1] == str2[ptr2]){
        
        return memo[ptr1][ptr2] = helper(str1, str2 , ptr1-1 , ptr2-1 , memo) + helper(str1 , str2 , ptr1-1 , ptr2 , memo) ;
    }
    
    return memo[ptr1][ptr2] = helper(str1 , str2 , ptr1-1 , ptr2 , memo);
}
int Solution::numDistinct(string A, string B) {
    int M = A.size() , N = B.size() ;
    vector<vector<int>> memo(M , vector<int>(N , -1));
    
    return helper(A , B , M-1 , N-1 , memo);
}

//BOTTOM UP
int Solution::numDistinct(string A, string B) {
    int M = A.size() , N = B.size() ;
    vector<vector<int>> dp(M+1 , vector<int>(N+1 , 0));
    // for empty string of B match all length of
    // so initialize the cols or 1st row to be 1
    for(int rows = 0 ; rows <= M ; rows++){
        dp[rows][0] = 1 ; 
    }
    
    for(int i = 1 ; i <= M ;i++){
        for(int j = 1 ; j <= N ; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ;
            }   
            else{
                dp[i][j] = dp[i-1][j] ;
            }     
        }
    }   
    return dp[M][N] ;
}
```

6. [Scramble String](https://www.interviewbit.com/problems/scramble-string/)
```cpp
bool helper(const string str1 , const string str2 , unordered_map<string , bool> &memo){
    if(str1.size() == 1){
        return str1 == str2 ;
    }

    if(str1 == str2) return true ;
    int N = str1.size() ;
    
    string key = str1+str2 ;
    if(memo.find(key) != memo.end()) return memo[key] ;
    
    for(int i = 1 ; i < N ; i++){
        if(helper(str1.substr(0,i) , str2.substr(0,i) , memo) and helper(str1.substr(i) , str2.substr(i), memo)){
            return memo[key] = true ;
        }
        if(helper(str1.substr(0,i) , str2.substr(N-i), memo) and helper(str1.substr(i) , str2.substr(0,N-i), memo)){
            return memo[key] = true ;
        }
    }
    
    return memo[key] = false ;
}
int Solution::isScramble(const string A, const string B) {
    if(A.size() != B.size()) return 0 ;
    unordered_map<string , bool> memo ;
    
    return helper(A , B , memo) ;
}
```

7. [Regular Expression Match](https://www.interviewbit.com/problems/regular-expression-match/)
```cpp
bool helper(const string &str , const string &pattern , int ptr1 , int ptr2 , vector<vector<int8_t>> &memo){
    if(ptr1 >= str.size() and ptr2 >= pattern.size()) return true ;
    if(ptr2 >= pattern.size()) return false ;
    
    if(memo[ptr1][ptr2] != -1) return memo[ptr1][ptr2] ;
    
    if(ptr1 >= str.size()){
       if(pattern[ptr2] != '*') return false ;
       return memo[ptr1][ptr2] = helper(str , pattern , ptr1 , ptr2+1 , memo); 
    }
    
    if(pattern[ptr2] == '?'){
        return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2+1 , memo);
    }
    if(pattern[ptr2] == '*'){
        if(helper(str , pattern , ptr1+1 , ptr2 , memo)){
            return memo[ptr1][ptr2] = true ;
        }
        return memo[ptr1][ptr2] = helper(str , pattern , ptr1 , ptr2+1 , memo);
    }
    if(str[ptr1] != pattern[ptr2]) return false ;
    
    return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2+1 , memo);
}

int Solution::isMatch(const string str, const string pattern) {
    vector<vector<int8_t>> memo(str.size()+1 , vector<int8_t>(pattern.size()+1 , -1));
    
    return helper(str , pattern , 0 , 0 , memo );
}
```

8. [regex-2](https://www.interviewbit.com/problems/regular-expression-ii/)
```cpp
int N , M ;

bool helper(const string &str , const string &pattern , int ptr1 , int ptr2 ,  vector<vector<int8_t>> &memo){
    if(ptr1 >= M and ptr2 >= N) return true ;
    if(ptr2 >= N) return false ;
    if(memo[ptr1][ptr2] != -1){
        return memo[ptr1][ptr2] ;
    }
    
    if(ptr1 >= M){
        // string finished can we finish this pattern somewhat ?
        if(ptr2+1 >= N or pattern[ptr2+1] != '*') return memo[ptr1][ptr2] = false ;
        return memo[ptr1][ptr2] = helper(str , pattern , ptr1 , ptr2+2, memo) ;
    }
    // check if star presents
    bool isstar = false ;
    
    if(ptr2+1 < N and pattern[ptr2+1] == '*') isstar = true ;
    
    if(isstar){
        //skip the []* completely in the pattern
        if(helper(str , pattern , ptr1 , ptr2+2 , memo)){
            return memo[ptr1][ptr2] = true ;
        }
        // use the []*
        if(pattern[ptr2] != '.' and str[ptr1] != pattern[ptr2]){
            return memo[ptr1][ptr2] = false ;
        }
        else{
            return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2, memo);
        }
    }
    if(pattern[ptr2] == '.'){
        return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2+1, memo);
    }
    //normal characters match
    if(str[ptr1] != pattern[ptr2]) return memo[ptr1][ptr2] = false ;    
    return memo[ptr1][ptr2] = helper(str , pattern , ptr1+1 , ptr2+1 , memo);
}

int Solution::isMatch(const string str, const string pattern) {
    M = str.size() ;
    N = pattern.size() ;
    vector<vector<int8_t>> memo(M+1 , vector<int8_t>(N+1 , -1));
    
    return helper(str , pattern , 0 , 0 , memo);
}
```

9. [interleaving-strings](https://www.interviewbit.com/problems/interleaving-strings/)
```cpp
int M , N , O ;

bool helper(string &str1 , string &str2 , string &req , int ptr1 , int ptr2 , int ptr3 , vector<vector<vector<bool>>> &memo){
    if(ptr3 >= O) return true ;
    if(memo[ptr1][ptr2][ptr3] != true) return false ;
    
    if(ptr1 < M and str1[ptr1] == req[ptr3]){
        if(helper(str1 , str2 , req , ptr1+1 , ptr2 , ptr3+1 , memo)){
            return true ;
        }
    }
    if(ptr2 < N and str2[ptr2] == req[ptr3]){
        if(helper(str1 , str2 , req , ptr1 , ptr2+1 , ptr3+1 , memo)){
            return true ;
        }
    }
    
    return memo[ptr1][ptr2][ptr3] = false ;
}
int Solution::isInterleave(string A, string B, string C) {
    M = A.size() ; N = B.size() ; O = C.size() ;
    if(M+N != O) return false ;
    vector<vector<vector<bool>>> memo(M+1 , vector<vector<bool>>(N+1 , vector<bool>(O+1 , true)));
    
    return helper(A , B , C , 0 , 0 , 0 , memo);
}
```

### DERIVED DP

1. [chain-of-pairs](https://www.interviewbit.com/problems/chain-of-pairs/)
```cpp
// greedy solution
int Solution::solve(vector<vector<int> > &A) {
 	sort(A.begin(), A.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });
    int maxlen = 1;
    int curend = A[0][1];

    for (int i = 1; i < A.size(); i++)
    {
        if (curend < A[i][0])
        {
            maxlen++;
            curend = A[i][1];
        }
    }

    return maxlen;
}
```

2. [maxsum without adjacent](https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/)
```cpp
// TOP DOWN
int helper(int col , vector<vector<int>> &A , vector<int> &memo){
    if(col == 0) return max(A[0][0] , A[1][0]) ;
    if(col < 0) return 0 ;
    if(memo[col] != -1) return memo[col] ;
    
    int option1 = max(A[0][col] , A[1][col]) + helper(col-2 , A , memo);
    int option2 = helper(col-1 , A , memo );
    
    return memo[col] = max(option1 , option2);
}

int Solution::adjacent(vector<vector<int> > &A) {
    vector<int> memo(A[0].size() , -1);
    
    return helper(A[0].size()-1 , A , memo);
}

// BOTTOM UP

int Solution::adjacent(vector<vector<int> > &A) {
    vector<int> dp(A[0].size()+1 , 0);
    dp[1] = max(A[0][0] , A[1][0]) ;
    
    for(int col = 2 ; col <= A[0].size() ; col++){
        int option1 = max(A[0][col-1] , A[1][col-1]) + dp[col-2] ;
        int option2 = dp[col-1] ;
        
        dp[col] = max(option1 , option2) ; 
    }
    
    return dp.back() ;
}
```

3. [merge-elements](https://www.interviewbit.com/problems/merge-elements/)
```cpp
// TOP DOWN

int helper(int left , int right , vector<int> &A , vector<int> &prefixsum , vector<vector<int>> &memo){
    if(left == right){
        return 0 ;
    }
    if(left+1 == right){
        return A[left] + A[right] ;
    }
    if(memo[left][right] != -1){
        return memo[left][right] ;
    }
    
    int entire_merge =  (prefixsum[right+1] - prefixsum[left]) ;
    
    int curminsum = INT_MAX ;
    for(int i = left ; i < right ; i++){
        //merge at left 
        curminsum = min(curminsum , helper(left , i , A , prefixsum , memo) + helper(i+1 , right , A , prefixsum , memo));
    }
    return memo[left][right] = curminsum + entire_merge ;
}

int Solution::solve(vector<int> &A) {
    vector<int> prefixsum(A.size()+1,0);
    vector<vector<int>> memo(A.size() , vector<int>(A.size() , -1));
    
    partial_sum(A.begin() , A.end() , prefixsum.begin()+1);
    
    return helper(0 , A.size()-1 , A , prefixsum , memo);
}
```

### KNAPSACK DP

1. [flip-arrays](https://www.interviewbit.com/problems/flip-array/)
```cpp
#include<bits/stdc++.h>

pair<int,int> helper(int pos , const vector<int> &arr , int cursum ,vector<vector<pair<int,int>>> &memo){
    if(pos < 0){
        return {cursum , 0} ;  
    }
    if(memo[pos][cursum].first != -1){
        return memo[pos][cursum] ;
    }
    
    // can we make this negative
    int decreaser = 2*arr[pos] ;
    
    if(cursum - decreaser >= 0){
        pair<int,int> res1 = helper(pos-1 , arr , cursum-decreaser , memo ) ;
        pair<int,int> res2 = helper(pos-1 , arr , cursum ,memo ) ;
        
        res1.second += 1 ;
        if(res1.first < res2.first){
            return memo[pos][cursum] = res1 ;
        }
        if(res1.first == res2.first and res1.second < res2.second){
            return memo[pos][cursum] =  res1 ;
        }
        return memo[pos][cursum] =  res2 ;
    }
    
    return memo[pos][cursum] =  helper(pos-1 , arr,cursum  , memo);
}

int Solution::solve(const vector<int> &A) {
    
    int total_sum = accumulate(A.begin() , A.end() , 0);
    vector<vector<pair<int,int>>> memo(A.size() , vector<pair<int,int>>(total_sum+1 , {-1 , -1}));
    
    return helper(A.size()-1 , A , total_sum , memo).second ;
}
```

2. [Tushar's-birthday-party](https://www.interviewbit.com/problems/tushars-birthday-party/)
```cpp
int helper(int pos ,int remaining,const vector<int> &capacity ,const vector<int>& cost , vector<vector<int>> &memo){
    if(remaining == 0){
        return 0 ;
    }
    if(remaining < 0 or pos < 0){
        return 1e9 ;
    }
    if(memo[pos][remaining] != -1) return memo[pos][remaining] ;
    
    // he can eat this dish and again eat this dish or skip this dish 
    int option1 = cost[pos] + helper(pos , remaining-capacity[pos] , capacity , cost , memo);
    int option2 = helper(pos-1 , remaining , capacity , cost , memo);
    
    return memo[pos][remaining] = min(option1 , option2);
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int total_cost = 0 ;
    int N = B.size() ;
    int maxele = *max_element(A.begin() , A.end());
    
    vector<vector<int>> memo(N , vector<int>(maxele+1 , -1));
    
    for(int i = 0 ; i < A.size() ; i++){
        total_cost += helper(N-1 , A[i] , B , C , memo );
    }
    return total_cost ;
}
```

3. [0/1 knapsack](https://www.interviewbit.com/problems/0-1-knapsack/)
```cpp
// TOP DOWN
int helper(int pos , int capacity , vector<int> &weight , vector<int> &profit , vector<vector<int>> &memo){
    if(pos < 0) return 0 ;
    if(capacity == 0) return 0 ;
    if(memo[pos][capacity] != -1) return memo[pos][capacity] ;
    
    // add this item or skip item
    int option1 = INT_MIN ;
    
    if(capacity - weight[pos] >= 0 ){
        option1 = profit[pos] + helper(pos-1 , capacity - weight[pos] , weight , profit , memo);
    }
    
    int option2 = helper(pos-1 , capacity , weight , profit, memo);
    
    return memo[pos][capacity] = max(option1 , option2);
}
// BOTTOM UP
int Solution::solve(vector<int> &profit, vector<int> &weight, int C) {
    int N = profit.size() ;
    vector<vector<int>> dp(N+1 , vector<int>(C+1 , 0));
    
    for(int pos = 1 ; pos <= N ; pos++){
        for(int capacity = 1 ; capacity <= C ; capacity++){
            if(capacity - weight[pos-1] >= 0){
                 dp[pos][capacity] = max(profit[pos-1] + dp[pos-1][capacity-weight[pos-1]] , dp[pos-1][capacity]);
            }
            else{
                dp[pos][capacity] = dp[pos-1][capacity];
            }
        }
    }
    return dp[N][C] ;
}


```

### Simple Array dp

1. [Longest Increasing subsequence Bitonic](https://www.interviewbit.com/problems/length-of-longest-subsequence/)
```cpp
int Solution::longestSubsequenceLength(const vector<int> &arr) {
    int N = arr.size() ;
    
    vector<int> dp1(N , 1);
    vector<int> dp2(N , 1);
    
    // lis
    
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i] and dp1[i] < dp1[j]+1){
                dp1[i] = 1+dp1[j] ;
            }
        }
    }
    
    // decreasing lis 
    for(int i = N-2 ; i >= 0 ; i--){
        for(int j = N-1 ; j > i ; j--){
            if(arr[j] < arr[i] and dp2[i] < dp2[j]+1){
                dp2[i] = dp2[j]+1 ;
            }
        }
    }
    
    int max_bitonic = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        max_bitonic = max(max_bitonic ,dp1[i]+dp2[i]-1) ;
    }
    
    return max_bitonic ;
}
```

2. [smallest sequence with given primes](https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/)
```cpp
vector<int> Solution::solve(int A, int B, int C, int count) {
    vector<int> arr(1,1);
    int idx1 = 0 , idx2 = 0 , idx3 = 0 ;
    
    while(count--){
        int ele1 = arr[idx1]*A ;
        int ele2 = arr[idx2]*B ;
        int ele3 = arr[idx3]*C ;
        
        if(ele1 < ele2 and ele1 < ele3){
            // ele1 is the smallest
            arr.push_back(ele1);
            idx1++ ; 
        }    
        else if(ele2 < ele3 and ele2 < ele1){
            // ele2 is the smallest 
            arr.push_back(ele2);
            idx2++ ;
        }
        else if(ele3 < ele1  and ele3 < ele2){
            //ele3 is the smallest
            arr.push_back(ele3); idx3++ ;
        }
        else if(ele1 == ele2 and ele2 == ele3){
            // all are same 
            idx1++ ; idx2++ ; idx3++ ;
            arr.push_back(ele1);
        }
        else if(ele1 == ele2){
            arr.push_back(ele1);
            idx1++ ; idx2++ ;
        }
        else if(ele2 == ele3){
            arr.push_back(ele2);
            idx2++ ; idx3++ ;
        }
        else{
            // ele3 == ele1 
            arr.push_back(ele1);
            idx1++ ; idx3++ ;
        }
    }
    
    return vector<int>(arr.begin()+1 , arr.end()) ;
}

```

3. [largest area of rectangle with permutation](https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/)
```cpp
int Solution::solve(vector<vector<int> > &A) {
    int M = A.size() ;int  N = A[0].size() ;
    if(M == 0 and N == 0) return 0 ;
    
    for(int i = 1 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(A[i][j] != 0)
                A[i][j] = A[i][j] + A[i-1][j] ;
        }
    }
    
    for(vector<int> &x : A){
        sort(x.begin() , x.end());
    }
    int maxarea = 0 ;
    for(int i = 0 ; i < M ; i++){
        int width = 1 , curarea = 0  ;
        for(int j = N-1 ; j >= 0 ;j--){
            curarea = width*A[i][j] ;
            maxarea = max(maxarea , curarea);
            width++ ;
        }
    }
    return maxarea ;
}

```

4. [Tiling with dominos](https://www.interviewbit.com/problems/tiling-with-dominoes/)
```cpp
int Solution::solve(int N) {
    // For 3 X N board , for each col there are 8 states are possible 
    long mod = 1e9+7 ;
    
    vector<vector<long>> dp(N+1 , vector<long>(8 , 0));
    dp[0][7] = 1 ;
    for(int i = 1 ; i <= N ; i++){
        dp[i][0] = dp[i-1][7]%mod ;
        
        dp[i][1] = dp[i-1][6]%mod ;
        dp[i][2] = dp[i-1][5]%mod ;
        
        dp[i][3] += dp[i-1][7]%mod ;
        dp[i][3] += dp[i-1][4]%mod ;
        
        dp[i][4] = dp[i-1][3]%mod ;
        dp[i][5] = dp[i-1][2]%mod ;
        
        dp[i][6] = dp[i-1][7]%mod ;
        dp[i][6] += dp[i-1][1]%mod ;
        
        dp[i][7] = dp[i-1][3]%mod ;
        dp[i][7] += dp[i-1][6]%mod ;
        dp[i][7] += dp[i-1][0]%mod ;
    }
    return dp[N][7]%mod ;
}
```

4. a) [Domino tromino tiling](https://leetcode.com/problems/domino-and-tromino-tiling/) 
```cpp
class Solution {
public:
    int numTilings(int n) {
        long mod = 1e9+7 ;
        
        vector<vector<long>> dp(n+1 , vector<long>(4 , 0));
        dp[0][3] = 1 ;
        for(int i = 1 ; i <= n ; i++){
            dp[i][0] = dp[i-1][3]%mod ;
            
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod ;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1])%mod ;
            
            dp[i][3] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][1] + dp[i-1][3])%mod;
        }
        
        return dp[n][3]%mod ;
    }
};
```

5. [Paint house](https://www.interviewbit.com/problems/paint-house/)
```cpp
int helper(int pos , int prev_color , vector<vector<int>> &A , vector<vector<int>> &memo){
    if(pos < 0){
        return 0 ;
    }
    if(memo[pos][prev_color] != -1) return memo[pos][prev_color] ;
    
    int mincost = INT_MAX ;
    
    for(int i = 0 ; i < 3 ; i++){
        if(i != prev_color){
            mincost = min(mincost ,A[pos][i] + helper(pos-1 , i , A , memo));
        }
    }
    
    return memo[pos][prev_color] = mincost ;
}

int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> memo(A.size() , vector<int>(4 , -1));
    
    return helper(A.size()-1 , 3 , A , memo) ;    
}

// BOTTOM UP

int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size()+1 , vector<int>(4 , INT_MAX));
    dp[0][0] = 0 ; dp[0][1] = 0 ; dp[0][2] = 0 ;
    
    for(int i = 1 ; i <= A.size() ; i++){
        for(int prev_color = 0 ; prev_color < 3 ; prev_color++){
            for(int color = 0 ; color < 3 ; color++){
                if(color != prev_color){
                    dp[i][prev_color] = min(dp[i][prev_color] , dp[i-1][color] + A[i-1][color]) ;                            
                }
            }
        }
    }
    int N = dp.size() ;
    
    return *min_element(dp[N-1].begin() , dp[N-1].end());
}
```

6. [ways to decode](https://www.interviewbit.com/problems/ways-to-decode/)
```cpp

int N ;
int mod = 1e9+7 ;

int helper(string &encoded , int pos , vector<int> &memo){
    if(pos == N) return 1 ;
    
    if(memo[pos] != -1) return memo[pos] ;
    
    if(encoded[pos] == '0'){
        return 0 ;
    }
    if(pos+1 < N and encoded[pos] == '1'){
        return memo[pos] = (helper(encoded , pos+1 , memo) + helper(encoded , pos+2 , memo))%mod;
    }
    if(pos+1 < N and encoded[pos] == '2' and encoded[pos+1] < '7'){
        return  memo[pos] = (helper(encoded , pos+1 , memo) + helper(encoded , pos+2 , memo))%mod;
    }
    
    return memo[pos] = helper(encoded , pos+1 , memo)%mod ;
    
}
int Solution::numDecodings(string A) {
    N =A.size() ;
    vector<int> memo(A.size() , -1);
    return helper(A , 0, memo) ; 
}
```

7. [stairs](https://www.interviewbit.com/problems/stairs/)
```cpp

// TOP DOWN

int helper(int A , vector<int> &memo){
     if(A == 0){
        return 1 ;
    }
    if(A < 0) return 0 ;
    if(memo[A] != -1) return memo[A] ;
    
    return memo[A] = helper(A-1 , memo) + helper(A-2 , memo) ;
}

int Solution::climbStairs(int A) {
    vector<int> memo(A+1 , -1);
    return helper(A , memo) ;
}

// BOTTOM UP

int Solution::climbStairs(int A) {
    vector<int> dp(A+1 , 1);
    dp[1] = 1 ;

    for(int i = 2 ; i <= A ; i++){
        dp[i] = dp[i-1] + dp[i-2] ;
    }    
    return dp[A] ;
}

```

8. [Longest Increasing subsequence](https://www.interviewbit.com/problems/longest-increasing-subsequence/)
```cpp
int Solution::lis(const vector<int> &A) {
    int N = A.size() ;
    vector<int> dp(N , 1);
    int maxlen = 1 ;
    
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(A[i] > A[j] and dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1 ;   
            }
        }
        maxlen = max(maxlen , dp[i]);
    }
    return maxlen ;
}
```

9. [Intersecting chords](https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/)
```cpp
int mod = 1e9+7 ;

long helper(int n , vector<int> &memo){
    
    if(n <= 1) return 1 ;
    long res = 0 ;
    if(memo[n] != -1) return memo[n] ;
    
    for(int i = 0 ; i < n ; i++){
        res = (res + (helper(i ,memo)%mod*helper(n-i-1 , memo )%mod)%mod)%mod ;
    }
    
    return memo[n] = res%mod ;
}

int Solution::chordCnt(int A) {
    // finding the catalan number 1 1 2 5 14
    vector<int> memo(A+1 , -1);
    return helper(A , memo)%mod ;    
}
```

### ADHOC

1. [buy-sell stock2](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/)
```cpp
int helper(int pos ,bool canbuy, const vector<int> &arr , vector<vector<int>> &memo ){
    if(pos == arr.size()){
        return 0 ;
    }
    if(memo[pos][canbuy] != -1){
        return memo[pos][canbuy] ;
    }
    
    if(canbuy){
        // buy now
        int option1 = helper(pos+1 , false , arr , memo) - arr[pos] ;
        // skip it    
        int option2 = helper(pos+1 , true , arr , memo) ; 
        return memo[pos][canbuy] = max(option1 , option2) ;
    }
        
    // sell now 
    int option1 = arr[pos] + helper(pos+1 , true , arr , memo) ;
    int option2 = helper(pos+1 , false , arr , memo);
    
    return memo[pos][canbuy] = max(option1 , option2) ;
}

int Solution::maxProfit(const vector<int> &A) {
    int N = A.size() ;
    vector<vector<int>> memo(N , vector<int>(2 , -1));
    
    return helper(0 , true , A , memo );
}
```

### DP OPTIMIZED BACKTRACK

1. [word break 2](https://www.interviewbit.com/problems/word-break-ii/)
```cpp

int N ;

vector<string> combine(string &temp , vector<string> arr){
    
    for(int i = 0 ; i < arr.size() ; i++){
        arr[i] = arr[i] + " " + temp ;
    }
    
    return arr ;
}

vector<string> helper(string s , unordered_set<string> &dict ,unordered_map<string , vector<string>> &memo ){
    vector<string> results ;
    if(memo.find(s) != memo.end())
        return memo[s] ;
    
    if(dict.find(s) != dict.end()){
        results.push_back(s);
    }
    
    for(int i = 1 ; i < s.size() ; i++){
        string temp = s.substr(i);
        if(dict.find(temp) != dict.end()){
            vector<string> local = combine(temp , helper(s.substr(0,i),dict , memo));
            
            for(string &st : local){
                results.push_back(st);
            }
            
        }
    }
    return memo[s] = results ;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    N = A.size() ;    
    unordered_set<string> dictionary(B.begin() , B.end());
    unordered_map<string , vector<string>> memo ;
    
    vector<string> res = helper(A , dictionary , memo) ;
    sort(res.begin() , res.end());
    return res ;    
}
```

### Multiply dp

1. [unique BST](https://www.interviewbit.com/problems/unique-binary-search-trees-ii/)
```cpp
int helper(int N , vector<int> &memo){
    if(N <= 1){
        return 1 ;
    }
    if(memo[N] != -1) return memo[N] ;
    
    int res = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        res = (res+ helper(i , memo)*helper(N-i-1 , memo)) ;    
    }
    
    return memo[N] = res ;
}
int Solution::numTrees(int A) {
    // catalan's number
    vector<int> memo(A+1 , -1);
    return helper(A , memo);
}
```

### Breaking Words
1. [Palindrome Partioning 2](https://www.interviewbit.com/problems/palindrome-partitioning-ii/)
```cpp
int N ;

bool isPalindrome(string &str , int start , int end){
    while(start < end){
        if(str[start++] != str[end--]) return false ;
    }
    return true ;
}
int helper(int start , int end , string &str ,  vector<vector<int>> &memo){
    if(start == end) return 0 ;
    if(start > end){
        return N ;
    }
    if(memo[start][end] != -1) return memo[start][end] ;
    
    if(isPalindrome(str , start , end)){
        return 0 ;
    }

    int minlen = N ;
    for(int i = start ; i < end ; i++){
        //put a cut in i 
        minlen = min(minlen , 1 + helper(start , i , str,memo) + helper(i+1 , end , str , memo)) ;
    }
    return memo[start][end] = minlen ;
}

int Solution::minCut(string A) {
    N = A.size() ;
    vector<vector<int>> memo(N , vector<int>(N , -1));
    
    return helper(0 , N-1 , A , memo);
}
```
2. [word break](https://www.interviewbit.com/problems/word-break/)
```cpp
int N ;

bool helper(int pos , string &str , unordered_set<string> &dictionary , vector<int> &memo){
    if(pos >= N){
        return true ;
    }    
    if(memo[pos] != -1){
        return memo[pos] ;
    }
    
    string temp = "" ;
    for(int i = pos ; i < N ; i++){
        temp.push_back(str[i]);
        if(dictionary.find(temp) != dictionary.end()){
            if(helper(i+1 , str, dictionary , memo)){
                return memo[pos] = true ;
            }
        }
    }
    return memo[pos] = false ;
}

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dictionary(B.begin() , B.end());
    N = A.size() ;
    vector<int> memo(A.size() , -1);
    return helper(0 , A , dictionary , memo);
}
```

### GREEDY OR DP

1. [Tushar's Birthday Bomb](https://www.interviewbit.com/problems/tushars-birthday-bombs/)
```cpp
vector<int> Solution::solve(int A, vector<int> &B) {
    vector<pair<int,int>> maxB ;
    int small_power = INT_MAX ;
    
    for(int i = 0 ; i < B.size() ; i++){
        if(small_power > B[i]){
            small_power = B[i] ;
            maxB.push_back({i , B[i]});
        }
    }
    int N = maxB.size() ;
    vector<int> ans ;
    int idx = 0 ;
    while(idx < N){
        //for lexicographical order this strongest person can kick without altering the maxkicks
        pair<int,int> person = maxB[idx] ;
        
        while(A-person.second >= 0 and (1 + (A-person.second)/small_power) == A/small_power){
            A = A-person.second ;
            ans.push_back(person.first);
        }
        idx++ ;
    }
    return ans ;
}
```

2. [jump game array](https://www.interviewbit.com/problems/jump-game-array/)
```cpp
int N ;

bool helper(int pos , vector<int> &arr , vector<bool> &memo){
    if(pos >= N) return true ;
    if(memo[pos] == false) return false ;
    
    for(int i = 1 ; i <= arr[pos] ; i++){
        if(helper(pos+i , arr , memo)){
            return true ;
        }
    }
    return memo[pos] = false ;
}

int Solution::canJump(vector<int> &A) {
    vector<bool> memo(A.size() , true);
    N = A.size() ;
    if(N == 1) return true ;
    
    return helper(0 , A , memo);    
}
```

3. [min jumps array](https://www.interviewbit.com/problems/min-jumps-array/)
```cpp
int N ;
// TOP DOWN
int helper(int pos , vector<int> &A , vector<int> &memo){
    if(pos >= N-1) return 0 ;
    if(memo[pos] != -1) return memo[pos] ;
    
    int minjumps = N+1 ;
    
    for(int i = 1 ; i <= A[pos] ; i++){
        minjumps = min(minjumps ,helper(pos+i , A , memo));
    }
    return memo[pos] = 1 + minjumps ;
}
// BOTTOM UP
int Solution::jump(vector<int> &A) {
    N = A.size() ;
    vector<int> dp(N , INT_MAX);
    dp[0] = 0 ;
    
    for(int i = 0 ; i < N-1 ; i++){
        // if we can reach here first
        if(dp[i] != INT_MAX){
            for(int pos = 1 ; pos <= A[i] ; pos++){
                int maxreachable = min(N-1 ,pos+i);
                if(dp[maxreachable] > 1+dp[i]){
                    dp[maxreachable] = 1+dp[i] ;
                }
            }
        }
    }
    
    if(dp[N-1] == INT_MAX) return -1 ;
    return dp[N-1] ;
}

// GREEDY
int Solution::jump(vector<int> &A) {
    int N = A.size() ;
    if(N <= 1) return 0 ;
    
    int maxReachable = A[0] ;
    int curMaxReachable = A[0] ;
    int cursteps = 1 ;
    
    for(int i = 1 ; i <= maxReachable ; i++){
        if(i == N-1){
            return cursteps ;
        }
        curMaxReachable = max(curMaxReachable , i+A[i]);
        if(i == maxReachable){
            if(curMaxReachable == maxReachable) return -1 ;
            maxReachable = curMaxReachable ;
            cursteps++ ;
        }
    }
    
    return -1 ;
}
```

### DP TRICKY

1. [Longest Arithmetic sequence]()
```cpp
// BRUTE FORCE
int N ;

int helper(int prev_idx , int pos , int diff , const vector<int> &arr){
    if(pos >= N) return 0 ;
    
    int curdiff = abs(arr[prev_idx] - arr[pos]) ;
    if(curdiff == diff){
        // we can incluede it 
        return 1 + helper(pos , pos+1 , diff , arr);
    }
    
    return helper(prev_idx , pos+1 , diff , arr);
}

int Solution::solve(const vector<int> &A) {
    N = A.size() ;
    if(N == 0) return 0 ;
    if(N == 1) return 1 ;
    
    int maxlen = 2 ;
    for(int i = 0 ; i < N-1 ; i++){
        for(int j = i+1 ; j < N ; j++){
            int curdiff = abs(A[i]-A[j]);
            maxlen = max(maxlen , 2+helper(j , j+1 , curdiff , A));        
        }
    }
    
    return maxlen ;
}


int Solution::solve(const vector<int> &A) {
    int N = A.size() ;
    if(N == 0) return 0 ;
    if(N == 1) return 1 ;    
    int maxlen = 1 ;
    vector<unordered_map<long,int>> dictionary(N);
    
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            int curdiff = A[i] - A[j] ;
            // if the same curdiff occured in j's map then 1 + prev_occ
            if(dictionary[j].find(curdiff) != dictionary[j].end()){
                dictionary[i][curdiff] = 1 + dictionary[j][curdiff] ;
                maxlen = max(maxlen , dictionary[i][curdiff] ) ;
            }
            else{
                dictionary[i][curdiff] = 1 ;
            }
        }
    }
    
    return 1+maxlen ;
}

```

2. [N digit number with sum s](https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/)
```cpp
string producer = "0123456789" ;
long mod = 1000000007 ;

long helper(int req_sum , int reqlen , vector<vector<int>> &memo){
    if(req_sum == 0 and reqlen == 0) return 1 ;
    if(req_sum < 0 or reqlen <= 0) return 0 ;
    if(memo[req_sum][reqlen] != -1) return memo[req_sum][reqlen] ;
    
    long ways = 0 ;
    for(char ele : producer){
        ways = (ways + helper(req_sum-(ele-'0') , reqlen-1 , memo))%mod;
    }
    return memo[req_sum][reqlen] = ways%mod ;
}

int Solution::solve(int A, int B) {
    long ways = 0 ;
    vector<vector<int>> memo(B+1 , vector<int>(A+1 , -1));
    
    for(int i = 1 ; i < 10 ; i++){
        ways = (ways + helper(B-(producer[i]-'0') , A-1 , memo))%mod ;    
    }
    
    return ways ;
}

```

3. [ways to color 3*N](https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/)
```cpp
int dp[5][5][5][100005] = {-1} ; 
int mod = 1e9+7 ;

int helper(int col , int x , int y , int z){
    if(col == 0) return 1 ; 
    if(dp[x][y][z][col] != -1) return dp[x][y][z][col] ;
         
    long ways = 0 ;
    
    for(int i = 0 ; i < 4 ; i++){
        if(i == x) continue ;
        
        for(int j = 0 ; j < 4 ; j++){
        
            if(i == j or j == y) continue ;
            for(int k = 0 ; k < 4 ; k++){
                
                if(j == k  or k == z) continue ;
                ways = (ways + helper(col-1 ,i , j , k))%mod; 
            }
        }
    }
    
    return dp[x][y][z][col] = ways%mod ;
}
int Solution::solve(int A) {
    memset(dp , -1 , sizeof(dp));
    return helper(A , 4 ,4,4);
}
```

4. [kth manhatten neighbourhood](https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/)
```cpp
int M , N ;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,1,-1,-1,0,1} ;


bool isInvalid(int row , int col){
    return row < 0 or col < 0  or row >= M or col >= N ;
}

int findManhettan(int row , int col , int dist , vector<vector<int>> &matrix ,  vector<vector<vector<int>>> &memo){
    if(dist < 0) return INT_MIN ;
    if(dist == 0) return matrix[row][col] ;
    if(memo[row][col][dist] != -1) return memo[row][col][dist] ;
    
    // 8 possible neighbours
    int max_ele = matrix[row][col] ;
    
    for(int i = 0 ; i < 8 ; i++){
        if(isInvalid(row+dx[i] , col+dy[i])) continue ;
        
        int moving_dist = abs(dx[i]) + abs(dy[i]);
        
        max_ele = max(max_ele , findManhettan(row+dx[i] , col + dy[i] , dist-moving_dist , matrix , memo));
    }    
    return memo[row][col][dist] = max_ele ;
}

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    M = B.size() ; N = B[0].size() ;
    
    vector<vector<int>> res = B ;
    vector<vector<vector<int>>> memo(M , vector<vector<int>>(N , vector<int>(A+1 , -1)));
        
    for(int row = 0 ; row < M ; row++){
        for(int col = 0 ; col < N ; col++){
            res[row][col] = max(res[row][col] , findManhettan(row , col , A , B , memo));
        }
    }
    return res ;
}
```

5. [best time to buy and sell](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/)
```cpp

// TOP DOWN 

int N ;

int helper(int day , bool canbuy , int t_count , vector<int> &stocks ,  vector<vector<vector<int>>> &memo){
    if(day == N) return 0 ;
    if(t_count == 0) return 0 ;
    if(memo[day][canbuy][t_count] != -1) return memo[day][canbuy][t_count] ;
    
    if(canbuy){
        //buy now
        int option1 = helper(day+1 , false , t_count , stocks , memo) - stocks[day] ;
        // skip 
        int option2 = helper(day+1 , true , t_count , stocks , memo) ;
        return memo[day][canbuy][t_count] = max(option1 , option2) ;
    }
    // sell now and reduce t_count
    int option1 = helper(day+1 , true , t_count-1 , stocks , memo) + stocks[day] ;
    
    // skip
    int option2 = helper(day+1 , false , t_count , stocks , memo);
    
    return memo[day][canbuy][t_count] = max(option1 , option2);
}

int Solution::solve(vector<int> &A, int B) {
    N = A.size() ;
    vector<vector<vector<int>>> memo(N , vector<vector<int>>(2 , vector<int>(B+1 , -1)));
    
    return helper(0 , true , B , A, memo);
        
}

// BOTTOM UP
int Solution::solve(vector<int> &A, int B) {
    int N = A.size() ;
    
    vector<vector<int>> after(2 , vector<int>(B+1 , 0));
    vector<vector<int>> curr(2 , vector<int>(B+1 , 0));
    
    for(int day = N-1 ; day >= 0 ; day--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 1 ; cap <= B ; cap++){
                if(buy){
                    curr[buy][cap] = max(after[0][cap]-A[day] , after[1][cap]);
                }
                else{
                    curr[buy][cap] = max(after[1][cap-1] + A[day], after[0][cap]);
                }
            }
        }
        after = curr ;
    }
    
    return after[1][B] ;
}
```

6. [coins in a line](https://www.interviewbit.com/problems/coins-in-a-line/)
```cpp
int helper(int left , int right , bool isMyChance , vector<int> &arr , vector<vector<vector<int>>> &memo){
    if(left == right){
        if(isMyChance) return arr[left] ;
        return 0 ;
    }
    if(memo[left][right][isMyChance] != -1) return memo[left][right][isMyChance] ;
    
    if(isMyChance){
        return memo[left][right][isMyChance] = max(arr[left] + helper(left+1 , right, false , arr , memo) ,arr[right]+helper(left , right-1 , false , arr, memo));
    }
    return memo[left][right][isMyChance] = min(helper(left+1 , right , true , arr, memo) , helper(left , right-1 , true , arr, memo));
}

int Solution::maxcoin(vector<int> &A) {
    vector<vector<vector<int>>> memo(A.size() , vector<vector<int>>(A.size() , vector<int>(2 , -1)));
    
    return helper(0 , A.size()-1 , true , A , memo);    
}
```

7. [Evaluate Expression](https://www.interviewbit.com/problems/evaluate-expression-to-true/discussion/p/expected-output-for-t-t-t-f-f-f-f-t-f-t-should-be-2539-and-should-not-be-533/17400/921)
```cpp
#define T first    // true 
#define F second   // false

int mod = 1003 ;

void combine(char op , pair<int,int> &current , pair<int,int> leftside , pair<int,int> rightside){
    if(op == '|'){
        current.T = (current.T%mod + (leftside.T%mod * rightside.T%mod)%mod + (leftside.F%mod * rightside.T%mod)%mod + (leftside.T%mod * rightside.F%mod)%mod)%mod  ;
        
        current.F = (current.F%mod + (leftside.F%mod * rightside.F%mod)%mod)%mod ;
    }
    else if(op == '&'){
        current.F = (current.F%mod + (leftside.F%mod * rightside.F%mod)%mod  + (leftside.F%mod * rightside.T%mod)%mod + (leftside.T%mod * rightside.F%mod)%mod)%mod ;
        
        current.T = (current.T%mod + (leftside.T * rightside.T)%mod)%mod ;
    }
    else{
        current.T = (current.T%mod + (leftside.F%mod * rightside.T%mod)%mod + (leftside.T%mod * rightside.F%mod)%mod)%mod ; 

        current.F = (current.F%mod + (leftside.T%mod * rightside.T%mod)%mod + (leftside.F%mod * rightside.F%mod)%mod)%mod ;    
    }
}

pair<int,int> helper(int left , int right ,string &expr ,vector<vector<pair<int,int>>> &memo){
    if(left == right){
        return (expr[left] == 'T')?make_pair(1,0):make_pair(0,1) ;
    }
    if(memo[left][right].T != -1){
        return memo[left][right] ;
    }
    
    // "T|F&F^F" 
    pair<int,int> current = {0 , 0};
    
    for(int i = left+1 ; i < right ; i = i+2 ){
        combine(expr[i] ,current,helper(left , i-1 , expr , memo ) , helper(i+1, right , expr , memo) ) ;
    }
    
    return memo[left][right] = current ;
}

int Solution::cnttrue(string A) {
    
    vector<vector<pair<int,int>>> memo(A.size() , vector<pair<int,int>>(A.size() , make_pair(-1,-1)));
    
    return helper(0 , A.size()-1 , A , memo ).T%mod ;
    
}
```

9. [best time to buy and sell](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/)
```cpp
int Solution::maxProfit(const vector<int> &A) {
    int N = A.size() ;
    
    vector<vector<int>> after(2 , vector<int>(3 , 0));
    vector<vector<int>> curr(2 , vector<int>(3 , 0));
    
    for(int day = N-1 ; day >= 0 ; day--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 1 ; cap <= 2 ; cap++){
                if(buy){
                    curr[buy][cap] = max(after[0][cap]-A[day] , after[1][cap]);
                }
                else{
                    curr[buy][cap] = max(after[1][cap-1] + A[day], after[0][cap]);
                }
            }
        }
        after = curr ;
    }
    
    return after[1][2] ;
}
```

10. [Longest Valid Parenthesis](https://www.interviewbit.com/problems/longest-valid-parentheses/)
```cpp
int Solution::longestValidParentheses(string A) {
    stack<int> st ;
    st.push(-1);
    int maxlen = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == '(') st.push(i);
        else{
            if(not st.empty()) st.pop() ;
            if(not st.empty()){
                maxlen = max(maxlen , i - st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    
    return maxlen ;
}
```

11. 