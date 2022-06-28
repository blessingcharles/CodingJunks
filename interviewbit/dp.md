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

3. [0/1 knapsack]()
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