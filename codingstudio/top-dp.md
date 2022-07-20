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

17. [distinct subsequences](https://leetcode.com/problems/distinct-subsequences-ii/submissions/)
```cpp
class Solution {
public:
int mod = 1e9+7 ;
int helper(int pos , string &str , vector<int> &memo){
    if(pos >= str.size()) return 1 ;
    if(memo[pos] != -1) return memo[pos] ;
    
    int ans = 1 ;
    unordered_set<char> charmap ;    
    for(int i = pos ; i < str.size() ; i++){
        if(charmap.find(str[i]) != charmap.end()) continue ;
        charmap.insert(str[i]);
        ans = (ans+helper(i+1 , str , memo))%mod;
    }
    return memo[pos] = ans%mod ;
}
    int distinctSubseqII(string s) {
        vector<int> memo(s.size() , -1);
        return helper(0 , s , memo)-1 ;
    }
};
#include<bits/stdc++.h>
int mod = 1e9+7 ;

int distinctSubsequences(string s) 
{
    unordered_map<char , long long> prev ;
    vector<long long> counts(s.size()+1 , 0);
    counts[0] = 1 ;
    for(int i = 1 ; i <= s.size() ; i++){
        counts[i] = (counts[i-1]*2)%mod ;
        if(prev.find(s[i-1]) != prev.end()){
            counts[i] -= counts[prev[s[i-1]]] ;
        }
        prev[s[i-1]] = i-1 ;
    }    
    
    int n = s.size() ;
    if(counts[n]%mod > 0) return counts[n]%mod ;
    return (counts[n]%mod+mod) ;
}
```

18. [rod cutting problem](https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int helper(int ele , int curlen , vector<int> &price , vector<vector<int>> &memo){
    if(ele == 0 or curlen == 0) return 0 ;
    if(memo[ele][curlen] != -1) return memo[ele][curlen];
    
    
    //can we cut the element from curlen
    int op1 = 0 ;
    if(curlen-ele >= 0){
        op1 = price[ele-1] + helper(ele , curlen-ele , price , memo);
    }
    return memo[ele][curlen] = max(op1 , helper(ele-1 , curlen , price , memo));
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> memo(n+1 , vector<int>(n+1 ,-1));
    return helper(n , n , price , memo);
}
```

19. [dice throws](https://www.codingninjas.com/codestudio/problems/dice-throws_799924?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int FACE ;
long mod = 1e9+7 ;

int helper(int dice , int target , vector<vector<int>> &memo){
    if(target == 0 and dice == 0) return 1 ;
    if(target <= 0 or dice <= 0) return 0 ;
    
    if(memo[dice][target] != -1) return memo[dice][target] ;
    
    
    long ans = 0 ;
    for(int i = 1 ; i <= FACE ; i++){
        ans = (ans + helper(dice-1 , target-i , memo))%mod ;
    }
    return memo[dice][target] = ans;
}
int diceThrows(int d, int f, int s) {
    FACE = f ;
    vector<vector<int>> memo(d+1 , vector<int>(s+1 , -1));
    return helper(d , s , memo);
}
```
20. [avoiding traps](https://www.codingninjas.com/codestudio/problems/avoiding-traps_839704?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int avoidTraps(vector<int>& obstacles, int n) 
{
    if(obstacles.size() == 0) return 1 ;
    
    int i = 2 ;
    while(true){
        bool flag = true ;
        for(int ob : obstacles){
            if(ob%i == 0){
                flag = false ;
                break ;
            }
        }
        if(flag) return i ;
        i++ ;
    }
    return -1 ;
}
```
21. [house robber 2](https://www.codingninjas.com/codestudio/problems/house-robber_839733?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

long long int helper(int start, int pos , vector<int>& house , bool isfirst , vector<vector<long long int>> &memo){
    if(pos == start) return house[start] ;
    if(pos < start) return 0 ;
    if(memo[pos][isfirst] != -1) return memo[pos][isfirst] ;
    
    return memo[pos][isfirst] = max(helper(start , pos-2 , house , isfirst , memo)+house[pos],helper(start , pos-1 , house , isfirst , memo));    
}
long long int houseRobber(vector<int>& house)
{
    
    int N = house.size() ;
    if(N == 1) return house[0] ;
    
    vector<vector<long long int>> memo(N , vector<long long int>(2, -1));    
    return max(helper(0 ,N-2 , house , true , memo) , helper(1 , N-1 , house , false , memo));
}
```
22. [kth ancestor in bt](https://www.codingninjas.com/codestudio/problems/kth-ancestor-of-a-node-in-binary-tree_842561?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int T ;
bool helper(BinaryTreeNode<int> *root , vector<int> &ancestors){
    if(not root) return false ;
    if(root->data == T) return true ;
    ancestors.push_back(root->data);

    if(helper(root->left , ancestors)) return true ;
    if(helper(root->right , ancestors)) return true ;
    ancestors.pop_back();
    return false ;
}
int findKthAncestor(BinaryTreeNode<int> *root, int target, int k) {
    vector<int> ancestors ;
    T = target ;
    helper(root , ancestors);
    if(ancestors.size() < k) return -1 ;
    return ancestors[ancestors.size()-k] ;    
}
```
23. [ways to arrange balls](https://www.codingninjas.com/codestudio/problems/ways-to-arrange-balls_845177?topList=top-dynamic-programming-questions)
```cpp
#include<bits/stdc++.h>
#define N 16
long long int memo[16][16][16][4] ;
long long int helper(int a , int b , int c , int prev_idx){
    if(a == 0 and b == 0 and c == 0) return 1 ;
    if(memo[a][b][c][prev_idx+1] != -1)
         return memo[a][b][c][prev_idx+1] ;
    
    long long int ans = 0 ;
    if(a > 0 and (prev_idx == -1 or prev_idx != 0) ){
        ans += helper(a-1 , b , c , 0);
    }
    if(b > 0  and (prev_idx == -1  or prev_idx != 1) ){
        ans += helper(a , b-1 , c , 1);
    }
    if(c > 0  and ( prev_idx == -1 or prev_idx != 2) ){
        ans += helper(a , b , c-1 , 2);
    }
    return memo[a][b][c][prev_idx+1] = ans ;
}
long long int totalWays(int a, int b, int c)
{
    memset(memo ,-1 ,sizeof(memo) );
    return helper(a,b,c,-1);
}
```

24. [longest pal subsequence](https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int dp[101][101] ;

int helper(int left , int right , string &s){
    if(left == right) return 1 ;
    if(left > right) return 0 ;
    if(dp[left][right] != -1) return dp[left][right] ;
    if(s[left] == s[right]) 
        return dp[left][right]=2+helper(left+1 , right-1 , s);
    
    return dp[left][right]=max(helper(left+1 , right , s ) , helper(left , right-1 , s));
}
int longestPalindromeSubsequence(string s){
    memset(dp , -1 , sizeof(dp));
    return helper(0 , s.size()-1 , s);    
}
```

25. [no of dearrangements](https://www.codingninjas.com/codestudio/problems/count-derangements_873861?topList=top-dynamic-programming-questions&leftPanelTab=1)
```cpp
#include<bits/stdc++.h>
unordered_map<int , long long int> memo ;
long long int mod = 1e9+7 ;

long long int helper(int n){
    if(n == 1) return 0 ;
    if(n == 2) return 1 ;
    if(memo.find(n) != memo.end()) return memo[n] ;
    
    return memo[n] = ((n-1)*(helper(n-1)%mod + helper(n-2)%mod)%mod)%mod ;
}
long long int countDerangements(int n) {
   return helper(n) ;
}
```

26. [minimum no of taps to water](https://www.codingninjas.com/codestudio/problems/minimum-number-of-taps-to-water-garden_873369?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int memo[10000+1] ;
int N ;

int helper(int pos , vector<pair<int,int>> &arr){
        if(pos >= N-1) return 0 ;
        if(memo[pos] != -1) return memo[pos] ;
        
        int ans = INT_MAX ;
        for(int i = pos ; i < N ; i++){
            if(arr[i].first > pos) break ;
            
            for(int nxt = i+1 ;nxt <= arr[i].second ; nxt++){
                
                if(nxt > N) break ;
                
                int res = helper(nxt , arr);
                if(res == INT_MAX) continue ;
                ans = min(ans , 1+res);
            }
        }
        return memo[pos] = ans ;
}
int minimumTapsToFillGarden(vector<int> &ranges, int n) {
        vector<pair<int,int>> arr(n+1) ;
        N = n+1 ;
        memset(memo , -1 , sizeof(memo));
    
        for(int i = 0 ; i <= n ; i++){
            arr[i] = {i-ranges[i] , i+ranges[i]} ;
        }
        sort(arr.begin() , arr.end());
        int ans = helper(0 , arr) ;
        return (ans == INT_MAX)?-1:ans ;
}

// OPTIMISATION
#include<bits/stdc++.h>
int minimumTapsToFillGarden(vector<int> &ranges, int n) {
        vector<pair<int,int>> arr(n+1) ;
        int N = n+1 ;
    
        for(int i = 0 ; i <= n ; i++){
            arr[i] = {i-ranges[i] , i+ranges[i]} ;
        }
        sort(arr.begin() , arr.end());
        int end = 0 , farCanReach = 0 ;
        int cnt = 0 ;
    
        for(int start = 0 ; end < n ; end = farCanReach){
            cnt++ ;
            while(start < N and arr[start].first <= end){
                farCanReach = max(farCanReach , arr[start++].second);
            }
            
            if(end == farCanReach) return -1 ;
        }
        return cnt ;
}
```

27. [partition equal subset sum](https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?topList=top-dynamic-programming-questions)
```cpp
#include<bits/stdc++.h>
bool memo[101][10005] ;
//TOP DOWN
bool helper(int pos , int target , vector<int> &arr){
    if(target == 0) return true ;
    if(target < 0 or pos >= arr.size()) return false ;
    if(memo[pos][target] != true) return false ;
    // take it
    if(helper(pos+1 , target-arr[pos] , arr)){
        return true ;
    }
    return memo[pos][target] = helper(pos+1 , target , arr);
}
//BOTTOM UP
bool canPartition(vector<int> &arr, int n)
{
    int totalsum = accumulate(arr.begin() , arr.end() , 0);
    if((totalsum&1) == 1) return false ;
    int target = totalsum/2 ;
    vector<vector<bool>> dp(n+1 , vector<bool>(target+1 ,false));
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = true ;
    }
    dp[0][0] = true ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= target ; j++){
            if(j-arr[i-1] >= 0){
                if(dp[i-1][j-arr[i-1]]) dp[i][j] = true ;
            }
            if(dp[i-1][j]) dp[i][j] = true ;
        }
    }
    return dp[n][target] ;
}

```

28. [pal substring](https://www.codingninjas.com/codestudio/problems/longest-palindromic-substring_892999?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int maxleft = 0 ;
int N ;
int maxlen1 = 0;

void expandWindow(int left , int right , string &str){
    while(left >= 0 and right < N and str[left] == str[right]){
        left-- ; right++ ;
    }
    int curlen = right-left-1 ;
    
    if(curlen > maxlen1){
        maxlen1 = curlen ;
        maxleft = left+1 ;
    }
}
string longestPalinSubstring(string &str)
{
    maxleft = 0 ; 
    maxlen1 = 1 ;
    N = str.size() ;    
    for(int i = 0 ; i < N ; i++){
        // even length
        expandWindow(i ,i+1 , str);
        expandWindow(i,i , str);
    }
    return str.substr(maxleft , maxlen1);
}
```
29. [min cost to buy n items](https://www.codingninjas.com/codestudio/problems/min-steps-to-reach-n_893288?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int T ;
int dp[10001] ;

int adding , doubling ;
int helper(int blades){
    if(blades == T) return 0 ;
    if(blades > T) return 1e9 ;
    if(dp[blades] != -1) return dp[blades] ;
    
    int minres = 1e9 ;
    //doubling
    if(blades != 0){
       minres = helper(2*blades) ;
       if(minres != 1e9) minres += doubling ;
    }
    
    return dp[blades] = min(minres , adding + helper(blades+1));
}
int minCostToBuyN(int n, int a, int b)
{
    T = n ;
    adding  = a ; doubling = b ;
    memset(dp , -1 ,sizeof(dp));
    return helper(0) ;
}
```

30. [candies](https://www.codingninjas.com/codestudio/problems/candies_893290?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int requiredCandies(vector < int > &students) {
    vector<int> candies(students.size() , 1);
    
    int N = students.size() ;
    for(int i = 1 ; i < N ; i++){
        if(students[i] > students[i-1]){
            candies[i] = candies[i-1]+1 ;
        }    
    }
    int total = candies[N-1] ;    
    for(int i = N-2 ; i >= 0 ; i--){
        if(students[i] > students[i+1] and 1+candies[i+1] > candies[i]){
            candies[i] = 1+candies[i+1];
        }
        total += candies[i] ;
    }
    return total ;
}
```

31. [minimum fountains](https://www.codingninjas.com/codestudio/problems/minimum-fountains_893176?topList=top-dynamic-programming-questions&leftPanelTab=3)
```cpp
#include<bits/stdc++.h>
int findMinFountains(vector<int> &arr, int n)
{
    int end = 0 ,fartherReach = 0 ;
    vector<pair<int,int>> fountains(n+1) ;
    for(int i = 0 ; i < arr.size() ; i++){
        fountains[i] = {i-arr[i] , i+arr[i]};
    }
    sort(fountains.begin() , fountains.end());
    int cnt = 0 ;
    
    for(int start = 0 ; end < n ; end = fartherReach){
        cnt++ ;
        while(start <= n and fountains[start].first <= end){
            fartherReach = max(fartherReach , fountains[start++].second);
        }
        if(end == fartherReach) return -1 ;
    }
    return cnt ;
}
```

32. [coin game](https://www.codingninjas.com/codestudio/problems/coin-game_920479?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int dp[1001][1001] ;

int helper(int left , int right , vector<int> &coins ){
    if(left > right) return 0 ;
    if(left == right) return coins[left] ;
    if(dp[left][right] != -1) return dp[left][right] ;
    
    int op1 =  helper(left+1 , right-1 , coins) ;
    int fromLeft =  coins[left] + min(helper(left+2 , right , coins) , op1);
    int fromRight = coins[right] + min(helper(left , right-2 , coins) ,op1);
    
    return dp[left][right] = max(fromLeft , fromRight) ;
}
int maxCoins(vector<int> coins, int n)
{
    memset(dp , -1 ,sizeof(dp));
    return helper(0 , n-1, coins );
}
```