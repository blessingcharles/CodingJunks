1. [wildcard matching](https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int N1 , N2 ;
/*
    @pos1: pattern idx
    @pos2: string idx 
*/
bool helper(int pos1 , int pos2 , string &pattern , string &text , vector<vector<bool>> &memo){
    if(pos1 == N1 and pos2 == N2) return true ;
    if(pos1 == N1) return false ;
    if(pos2 == N2){
        if(pattern[pos1] != '*') return false ;
        return helper(pos1+1 , pos2 , pattern , text, memo) ;
    }
    if(memo[pos1][pos2] != true) return false ;
    
    if(pattern[pos1] == '?'){
        return memo[pos1][pos2] = helper(pos1+1 , pos2+1 , pattern , text, memo);
    }
    else if(pattern[pos1] == '*'){
        return memo[pos1][pos2] = helper(pos1 , pos2+1 , pattern , text, memo) or helper(pos1+1 , pos2 , pattern ,text , memo);
    }
    else if(pattern[pos1] == text[pos2]){
        return memo[pos1][pos2] = helper(pos1+1 , pos2+1 , pattern , text , memo);
    }
    return memo[pos1][pos2] = false ;
}
bool wildcardMatching(string pattern, string text)
{
    N1 = pattern.size() ; N2 = text.size() ;
    vector<vector<bool>> memo(N1 , vector<bool>(N2 , true));

    return helper(0 , 0 ,pattern , text , memo);
}

```

2. [LCS](https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
/*
    @pos1: string s idx
    @pos2: string t idx
*/
int helper(int pos1 , int pos2 , string &s , string &t,vector<vector<int>> &memo){
    
    if(pos1 < 0 or pos2 < 0) return 0 ;
    if(memo[pos1][pos2] != -1) return memo[pos1][pos2];
    
    if(s[pos1] == t[pos2]){
        return memo[pos1][pos2] = 1 + helper(pos1-1 , pos2-1 , s ,t , memo);
    }
    return memo[pos1][pos2] = max(helper(pos1-1 , pos2 , s, t , memo) , helper(pos1 , pos2-1 , s ,t , memo));
}
int lcs(string s, string t)
{
    vector<vector<int>> memo(s.size() , vector<int>(t.size() , -1));
    
    return helper(s.size()-1 , t.size()-1 , s , t , memo);
}

// BOTTOM UP
int lcs(string s, string t)
{
    vector<vector<int>> dp(s.size()+1 , vector<int>(t.size()+1 , 0));
    for(int i = 1 ; i <= s.size() ; i++){
        for(int j = 1 ; j <= t.size() ; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
            }
        }
    }
    return dp[s.size()][t.size()];
}
```

3. [colorful knapsack](https://www.codingninjas.com/codestudio/problems/colorful-knapsack_630415?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int helper(int pos , int weight , vector<vector<int>> &stones , vector<vector<int>> &memo){
    
    if(pos < 0) return 0 ;
    if(memo[pos][weight] != -2) return memo[pos][weight];
    
    int ans = -1 ;
    for(int w : stones[pos]){
        if(weight-w >= 0){
            int t =  helper(pos-1 , weight-w ,stones , memo);
            if(t != -1){
                ans = max(ans , w + t) ;
            }
        }
    }
    return memo[pos][weight] = ans ;
}
int colorfulKnapsack(int w[], int c[], int n, int m, int x)
{
     vector<vector<int>> stones(m);
     vector<vector<int>> memo(m , vector<int>(x+1 ,-2));
    
     for(int i = 0 ; i < n ; i++){
         stones[c[i]-1].push_back(w[i]);
     }
     int ans = helper(m-1 , x , stones , memo) ;
     return (ans == -1)?-1:x-ans;
}
```

4. [edit distance](https://www.codingninjas.com/codestudio/problems/edit-distance_630420?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int helper(int pos1 , int pos2 , string &str1 , string &str2 , vector<vector<int>> &memo){
    
    if(pos1 < 0 and pos2 < 0) return 0 ;
    if(pos1 < 0) return pos2+1 ;
    if(pos2 < 0) return pos1+1 ;
    if(memo[pos1][pos2] != -1){
        return memo[pos1][pos2] ;
    }
    
    if(str1[pos1] == str2[pos2]){
        return memo[pos1][pos2] = helper(pos1-1 , pos2-1 , str1 , str2 , memo);
    }
    //insert
    int op1 = 1+helper(pos1-1 , pos2 , str1 , str2 , memo);
    //delete
    int op2 = 1+helper(pos1 , pos2-1 , str1 , str2 , memo);
    //replace
    int op3 = 1+helper(pos1-1 , pos2-1 , str1 , str2 , memo);
    return memo[pos1][pos2] = min(op1 , min( op2 , op3));
}

int editDistance(string str1, string str2)
{
    vector<vector<int>> memo(str1.size() , vector<int>(str2.size() , -1)) ;
    
    return helper(str1.size()-1 , str2.size()-1 , str1 , str2 , memo) ;
}
```

5. [maximum sum subarray](https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_628288?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {

    int N = 0 ;
    cin >> N ;
    vector<int> arr(N) ;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i] ;        
    }
    int maxsum = arr[0] , cursum = arr[0] ;
    for(int i = 1 ; i < N ; i++){
        cursum = max(cursum+arr[i] , arr[i]);
        maxsum = max(maxsum , cursum);
    }
    cout << maxsum << endl ;
    return 0 ;
}
```
6. [min cost to buy oranges](https://www.codingninjas.com/codestudio/problems/minimum-cost-to-buy-oranges_630455?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int helper(int cost[] , int pos , int w , vector<vector<int>> &memo){
    if(pos < 0 and w == 0) return 0 ;
    if(pos < 0 or w < 0) return -1 ;
    if(memo[pos][w] != -2) return memo[pos][w] ;
    // skip it
    int op1 = helper(cost , pos-1 , w , memo) ;
    // take it
    if(cost[pos] == -1) return memo[pos][w] = op1 ;
    
    int op2 =  helper(cost , pos , w-(pos+1) , memo) ;
    if(op2 != -1){
        op2 += cost[pos] ;
    }
    if(op1 != -1 and op2 != -1) return memo[pos][w] = min(op1 , op2) ;
    if(op1 != -1) return memo[pos][w] =op1 ;
    if(op2 != -1) return memo[pos][w] =op2 ;
    return memo[pos][w] =-1 ;
}
int minCostToBuyOranges(int cost[], int n, int w)
{
    vector<vector<int>> memo(n , vector<int>(w+1 , -2));
    return helper(cost , n-1 , w , memo);
}
```

7. [house robber](https://www.codingninjas.com/codestudio/problems/loot-houses_630510?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int helper(int pos , vector<int> &houses , vector<int> &memo){
    if(pos == 0) return houses[0] ;
    if(pos < 0) return 0 ;
    if(memo[pos] != -1) return memo[pos] ;
    
    int op1 = houses[pos] + helper(pos-2 , houses , memo) ;
    int op2 = helper(pos-1 , houses , memo);
    return memo[pos] = max(op1 , op2);
}
int maxMoneyLooted(vector<int> &houses, int n)
{
    int curr , prev1 = houses[0] , prev2 ;
    for(int i = 1 ; i < n ; i++){
        int op1 = houses[i] ;
        if(i-2 >=0) op1 += prev2 ;
        int op2 = prev1 ;
        curr = max(op1 , op2);
        prev2 = prev1 ;
        prev1 = curr ;
    }
    return prev1 ;
}
```
8. [tiling problem](https://www.codingninjas.com/codestudio/problems/tiling-problem_630464?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int numberOfWaysToTile(long long n)
{ 
    int prev0 = 0  , prev3 = 1 ;
    int cur0 , cur3 ;
    
    int mod = 1e9+7 ;
    while(n--){
        cur0 = prev3;
        cur3 = (prev3 + prev0)%mod ;
        prev0 = cur0 ;
        prev3 = cur3 ;
    }

    return prev3%mod ;
}
```
9. [minimum cost path](https://www.codingninjas.com/codestudio/problems/minimum-cost-path_630515?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int M , N ;
int X , Y ;
bool isInvalid(int row , int col){
    return row >= M or col >= N ;
}
int helper(int row , int col , int **cost ,vector<vector<int>> &memo){
    if(isInvalid(row , col)) return INT_MAX ;
    if(row == X and col == Y) return cost[row][col] ;
    if(memo[row][col] != -1) return memo[row][col] ;
    
    int op1 = helper(row+1 , col , cost , memo);
    int op2 = helper(row , col+1 , cost , memo);
    int op3 = helper(row+1 , col+1,cost , memo);
    
    if(op1==INT_MAX and op2 == INT_MAX and op3 == INT_MAX)
        return memo[row][col] = op1 ;
    
    return memo[row][col] = cost[row][col] + min({op1 , op2 , op3});
    
}
int minCostPath(int** cost, int n, int m, int x, int y)
{
    X = x-1 ; Y = y-1 ; M = n ; N = m ;
    vector<vector<int>> memo(M , vector<int>(N,-1));
    return helper(0,0,cost , memo);
}
```
10. [simplify dir](https://www.codingninjas.com/codestudio/problems/simplify-the-directory_668400?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp

#include<bits/stdc++.h>
string simplifyDirectory(string str) {
    if(str.size() <= 1) return str ;
    stringstream ss(str);
    deque<string> st ;
    string word ;
    while(getline(ss ,word , '/' )){
        if(word.size() == 0) continue;
        if(word == ".."){
            if(not st.empty()) st.pop_back() ;            
        }
        else if(word != "."){
            st.push_back(word);
        }
    }
    string res = "" ;
    while(not st.empty()){
        res += "/" + st.front() ;
        st.pop_front() ;
    }    
    return (res.size() == 0)?"/":res ;
}
```
11. [common digit sequence](https://www.codingninjas.com/codestudio/problems/common-digit-longest-subsequence_630566?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
unordered_map<int , unordered_set<int>> memory ;
bool isCommon(int num1 , int num2){    
    int t1 = num1 ;
    
    if(memory.find(num1) == memory.end()){
        while(t1){
            memory[num1].insert(t1%10);
            t1 = t1/10 ;
        }
    }    
    while(num2){
        if(memory[num1].find(num2%10) != memory[num1].end()) return true ;        num2 = num2/10 ;
    }
    return false ;
}
int helper(int pos ,int prev_idx , int *arr){
    if(pos < 0) return 0 ;
    int op1 = 0 ;
    if(prev_idx == -1 or isCommon(arr[pos] , arr[prev_idx])){
        op1 = 1+helper(pos-1 , pos , arr);
    }
    return max(op1 , helper(pos-1 , prev_idx , arr));
}
int commonDigitLongestSubsequence(int *arr, int n)
{
    return helper(n-1 , -1 , arr);
}
// OPTIMISED
#include<bits/stdc++.h>

int commonDigitLongestSubsequence(int *arr, int n)
{
    vector<int> dp(n , 1);
    int maxlen = 1 ;
    for(int i = 1 ; i < n ; i++){
        int t1 = arr[i] ;
        vector<bool> num1(10 , false);
        while(t1){
            num1[t1%10] = true ;
            t1 = t1/10 ;
        }
        
        for(int j = 0 ; j < i ; j++){
            int t2 = arr[j] ;
            while(t2){
                if(num1[t2%10] == true){
                    dp[i] = max(dp[i] , 1+dp[j]);
                    maxlen = max(maxlen , dp[i]);
                    break ;
                }
                t2 = t2/10 ;
            }
        }
    }
    return maxlen ;
}
```

12. [best time to buy and sell](https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell_696432?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp

#include<bits/stdc++.h>
int N ;
int helper(int pos ,int *prices ,bool canbuy , vector<vector<int>> &memo){
    if(pos == N) return 0 ;
    if(memo[pos][canbuy] != -1) return memo[pos][canbuy] ;
    
    if(canbuy){
        // buy now
        int op1 = helper(pos+1 , prices , false , memo) - prices[pos] ;
        //postpone
        int op2 = helper(pos+1 , prices , true , memo)  ;
        return memo[pos][canbuy] = max(op1 , op2);
    }
    // sell now
    int op1 = helper(pos+1 , prices , true , memo) + prices[pos] ;
    int op2 = helper(pos+1 , prices , false , memo)  ;
    
    return memo[pos][canbuy] = max(op1 , op2);
}
int maxProfit(int prices[], int n)
{
    N = n ;
    vector<vector<int>> memo(n , vector<int>(2 , -1));
    return helper(0 , prices , true , memo);
}
```

13. [break number](https://www.codingninjas.com/codestudio/problems/break-number_759411?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int N ;

void helper(int num , int ele , vector<int> &path , vector<vector<int>> &res){
    if(num == 0){
        res.push_back(path) ; return ;
    }
    if(num < 0 or ele > N){
        return ;
    }
    // include this number 
    path.push_back(ele);
    helper(num-ele , ele , path , res);
    path.pop_back() ;

    // skip this number
    helper(num , ele+1,path , res);
}
vector<vector<int>> breakNumber (int n) {
    vector<vector<int>> res ;
    vector<int> path ;
    N = n ;    
    helper(n , 1 , path , res);
    return res ;
    
}
```
14. [maximum coins](https://www.codingninjas.com/codestudio/problems/maximum-coins_758902?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int M , N ;
int dy1[9] = {1 , 1 , 1 ,-1 , -1 ,-1 ,0,0,0};
int dy2[9] = {1, -1,  0 , 1 , -1  ,0 ,1,-1,0} ;

bool isInvalid(int col){
    return col < 0 or col >= N ;
}
int helper(int row , int col1 , int col2 , int **mat ,  vector<vector<vector<int>>> &memo){
   if(row == M-1 and col1 == 0 and col2 == N-1){
       return (col1 != col2)?mat[row][col1] + mat[row][col2]:mat[row][col1] ;
   }
   if(row == M-1) return -1e8 ;
   if(memo[row][col1][col2] != -1) return memo[row][col1][col2] ;
    
   int ans = -1e8 ;
   int pickups = mat[row][col1] ;
   if(col1 != col2){
       pickups += mat[row][col2] ;
   }
   for(int i = 0 ; i < 9 ; i++){
       int c1 = col1 + dy1[i] ;
       int c2 = col2 + dy2[i] ;
       
       if(isInvalid(c1) or isInvalid(c2)) continue ;
       ans = max(ans , helper(row+1 , c1 , c2 ,mat , memo));
   } 
   if(ans == -1e8) return memo[row][col1][col2] = ans ;
    return memo[row][col1][col2] = ans + pickups ;
}
int maximumCoin(int** mat, int n, int m)
{
    M = n ; N = m ;
    vector<vector<vector<int>>> memo(M ,vector<vector<int>>(N , vector<int>(N , -1)) ) ;
    
    return helper(0,0,N-1 , mat , memo);
}
```

15. [valid string](https://www.codingninjas.com/codestudio/problems/valid-string_762939?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int N ;
bool helper(int open_paren , int pos , string &s , vector<vector<bool>> &memo){
    if(pos == N){
        return open_paren == 0 ;
    }
    if(memo[pos][open_paren] != true) return false ;
    
    if(s[pos] == '('){
        return memo[pos][open_paren]=helper(open_paren+1 , pos+1 , s , memo);
    }
    else if(s[pos] == ')'){
        if(open_paren == 0) return false ;
        return memo[pos][open_paren]=helper(open_paren-1 , pos+1 , s , memo);
    }
    // star case
    // skip it
    if(helper(open_paren , pos+1 , s , memo))
        return true ;
    // use it as closed paren if only if open_paren > 1
    if(open_paren > 0){
        if(helper(open_paren-1 , pos+1 , s , memo)) return true ;
    }
    // use it as open paren
    return memo[pos][open_paren]=helper(open_paren+1 , pos+1 , s , memo)  ;
    
}
bool checkValidString(string &s){
     N = s.size() ;
     vector<vector<bool>> memo(N , vector<bool>(N , true));
     return helper(0 , 0 , s , memo);
}

// Adhoc
bool checkValidString(string &s){
    int leftMax = 0 , leftMin = 0 ;
    for(char ch :s){
        if(ch == '('){
            leftMax++ ; leftMin++ ;
        }
        else if(ch == ')'){
            leftMax-- ; leftMin-- ;
        }
        else{
            leftMax++ ;
            leftMin-- ;
        }
        if(leftMax < 0) return false ;
        if(leftMin < 0) leftMin = 0 ;
    }
    return leftMin == 0 ;
}
```

16. [shortest common supersequence](https://leetcode.com/problems/shortest-common-supersequence/)
```cpp
// MEMOIZATION
class Solution {
    int N1 , N2 ;
    vector<vector<string>> memo ;
    
    string helper(int pos1 , int pos2 , string &s1 , string &s2){
        if(pos1 == N1 and pos2 == N2) return "" ;
        if(pos1 == N1) return s2.substr(pos2) ;
        if(pos2 == N2) return s1.substr(pos1) ;
        if(memo[pos1][pos2].size() != 0) return memo[pos1][pos2] ;
        
        if(s1[pos1] == s2[pos2]){
            return memo[pos1][pos2] = string(1 , s1[pos1]) + helper(pos1+1 , pos2+1 , s1 , s2) ;
        }
        // doesn't match
        string res1 = helper(pos1+1 , pos2 , s1 , s2) ;
        string res2 = helper(pos1 , pos2+1 , s1 ,s2) ;
        
        if(res1.size() < res2.size()){
            return memo[pos1][pos2] = string(1 , s1[pos1]) + res1 ;
        }
        return memo[pos1][pos2] = string(1 , s2[pos2]) + res2 ;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        N1 = str1.size() ; N2 = str2.size() ;
        memo.resize(N1 , vector<string>(N2 , ""));
        
        return helper(0,0,str1,str2) ;
    }
};
// BOTTOM UP
class Solution {
    int N1 , N2 ;
public:
    string shortestCommonSupersequence(string str1, string str2) {
        N1 = str1.size() ; N2 = str2.size() ;
        vector<vector<int>> dp(N1+1 , vector<int>(N2+1 , 0));
        for(int i = 1 ; i <= N1 ; i++){
            dp[i][0] = i ;
        }
        for(int j = 1 ; j <= N2 ; j++){
            dp[0][j] = j ;
        }
        
        for(int i = 1 ; i <= N1 ; i++){
            for(int j = 1 ; j <= N2 ; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
        string res = "" ;
        int row = N1 , col = N2 ;
        while(row != 0 and col != 0){
           if(str1[row-1] == str2[col-1]){
               
               res = str1[row-1] + res ;
               row-- ; col-- ;
           }
           else{
               if(dp[row][col-1] < dp[row-1][col]){
                    res = str2[col-1] + res ;
                    col-- ;
               }
               else{
                   res = str1[row-1] + res ;
                   row-- ;
               }
           } 
        }
        while(row != 0){
            res = str1[row-1] + res ; row-- ;
        }
        
        while(col != 0){
            res = str2[col-1] + res ; col-- ;
        }
        return res ;
    }
};
```