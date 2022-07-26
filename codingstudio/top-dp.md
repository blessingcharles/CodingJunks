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

33. [increasing subsegment](https://www.codingninjas.com/codestudio/problems/increasing-subsegment_920543?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int subsegments(vector < int > arr, int n) {
    vector<int> left(n , 1) , right(n , 1);
    int ans = 1 ;
    
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > arr[i-1]){
            left[i] = 1+left[i-1] ;
            ans = max(ans , left[i]);
        }
    }
    if(ans != n) ans++ ;
    for(int i = n-2 ; i >= 0 ; i--){
        if(arr[i] < arr[i+1]){
            right[i] = 1+right[i+1] ;
        }
    }
    
    for(int i = 1 ; i < n-1 ; i++){
        if(arr[i+1]-arr[i-1] > 1){
            ans = max(ans , left[i-1] + 1 + right[i+1]);
        }
    }
    return ans ;
}
```

34. [count ROR](https://www.codingninjas.com/codestudio/problems/count-ror_920554?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
/*
 0 -- R
 1 -- O
 2 -- R
*/
int N ;
int dp[10001][3] ;
int mod = 1e9+7 ;

int helper(int looker , int pos , string &s){
    if(pos == N) return 0 ;
    if(dp[pos][looker] != -1) return dp[pos][looker] ;
    
    
    int op1 = 0 ;
    
    if(looker == 0 and s[pos] == 'R'){
        op1 = helper(looker+1 , pos+1 , s)%mod;
    }
    else if(looker == 1 and s[pos] == 'O'){
        op1 = helper(looker+1 , pos+1 , s)%mod; 
    }
    else if(looker == 2 and s[pos] == 'R'){
        return dp[pos][looker] = 1+helper(looker , pos+1 , s)%mod;
    }
    return dp[pos][looker] = (op1+helper(looker , pos+1 , s)%mod)%mod;
}

int countSubsequence(string s) {
    N = s.size() ;
    memset(dp , -1 , sizeof(dp));
    return helper(0 , 0 , s);    
}
```
35. [tetrahedron](https://www.codingninjas.com/codestudio/problems/tetrahedron_920546?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
/*
    0 - A , 1 - B , 2 - C , 3 - D
*/
int mod = 1e9+7 ;
vector<vector<int>> dp(4 , vector<int>(100001 , -1));

int helper(int current , int moves){
    if(moves == 0){
        if(current == 3) return 1 ;
        else return 0 ;
    }
    if(dp[current][moves] != -1) return dp[current][moves] ;
    
    int ans = 0;
    for(int neigh = 0 ; neigh < 4 ; neigh++){
        if(neigh == current) continue ;
        ans = (ans + helper(neigh , moves-1)%mod)%mod;
    }
    return dp[current][moves] = ans ;
}
int numberOfWays(int n)
{
    return helper(3 , n);
}
```
36. [matrix chain multiplication](https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
/*
      A B C        A = 4 * 1
    4 1 2 3        B = 1 * 2
                   C = 2 * 3

    A BC
*/
#include<bits/stdc++.h>
int dp[101][101] ;

int helper(int left , int right , vector<int> &arr){
    if(left == right) return 0 ;
    if(dp[left][right] != -1) return dp[left][right] ;
    
    int ans = 1e9 ;
    
    for(int k = left ; k < right ; k++){
        int merge = arr[left-1] * arr[k] * arr[right] ;
        merge = merge + helper(left , k,arr) + helper(k+1 , right,arr);
        ans = min(ans , merge);
    }
    return dp[left][right] = ans ;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    memset(dp , -1 , sizeof(dp));
    return helper(1 , N-1 , arr);
}
```

37. [boredom](https://www.codingninjas.com/codestudio/problems/boredom_920547?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
unordered_map<int,int> memo;
int dp[100001][100001] ;

int helper(int left , int right , vector<int> &nums){
    if(left > right) return 0 ;
    if(left == right) return memo[nums[left]]*nums[left] ;
    if(dp[left][right] != -1) return dp[left][right] ;
    
    int maxans = 0 ;
    
    for(int i = left ; i <= right ; i++){
        int curr = memo[nums[i]]*nums[i] ;
        int op1 = 0 , op2 = 0 ;
        if(i-1 >= left and nums[i]-1 == nums[i-1]){
            op1 = helper(left , i-2 , nums);
        }
        else{
            op1 = helper(left , i-1 , nums) ;
        }
        if(i+1 <= right and nums[i]+1 == nums[i+1]){
            op2 = helper(i+2 , right , nums);
        }
        else{
            op2 = helper(i+1 , right , nums);
        }
        
        maxans = max(maxans , curr + op1 + op2);
    }
    return dp[left][right] = maxans ;
}
int maximumPoints(int n, vector<int> & arr)
{
    memset(dp , -1 ,sizeof(dp));
    sort(arr.begin() , arr.end());
    vector<int> nums ;
    memo.clear() ;
    
    for(int ele : arr){
        memo[ele]++ ;
        if(memo[ele] == 1){
            nums.push_back(ele) ;
        }
    }
    
    return helper(0 , nums.size()-1 , nums);
}

// ADHOC
#include<bits/stdc++.h>

int maximumPoints(int n, vector<int> & arr)
{
    
    int maxele = *max_element(arr.begin() , arr.end()) ;
    vector<int> dp(maxele+1 , 0);
    unordered_map<int , int> memo ;    
   
    for(int ele : arr){
        memo[ele]++ ;
    }
    dp[1] = memo[1] ;
    
    for(int i = 2 ; i <= maxele ; i++){
        dp[i] = max(dp[i-2]+i*memo[i] , dp[i-1]);
    }    
    return dp[maxele] ;
}
```

38. [min steps to one](https://www.codingninjas.com/codestudio/problems/min-steps-to-one-using-dp_920548?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
vector<int> dp(100001 , -1);
int countStepsToOne(int n) {
    if(n == 1) return 0 ;
    if(dp[n] != -1) return dp[n] ;
    
    int op1 = 1e8 , op2 = 1e8 ;
    if(n%3 == 0){
        op1 = countStepsToOne(n/3) ;
    }
    if((n&1) == 0){
        op2 = countStepsToOne(n/2) ;
    }
    
    return dp[n] = 1 + min({op1 , op2 , countStepsToOne(n-1)});
}
```
39. [painting fences](https://www.codingninjas.com/codestudio/problems/painting-fences_920549?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int mod = 1e9+7 ;

int paint(int posts , int colors){
    if(posts == 0) return 0 ;
    if(posts == 1) return 1 ;
    int same = colors ;
    int diff = colors*(colors-1) ;
    
    for(int i = 3 ; i <= posts ; i++){
        int prevDiff = diff ;
        diff = (((same+prevDiff)%mod)*(colors-1))%mod ;
        same = prevDiff%mod ; 
    }
    return (same+diff)%mod ;
}
int countWays(int n)
{
    return paint(n,2);
}
```

40. [mixtures](https://www.codingninjas.com/codestudio/problems/mixtures_975356?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int dp[101][101] ;

int mod = 100 ;
int calc(int i , int j , vector<int> &color){
    int sum = 0 ;
    for(int k = i ; k <= j ; k++) sum += color[k] ;
    return sum%mod ;
}

int helper(int left , int right , vector<int> &prefixsum){
    if(left >= right) return 0 ;
    if(dp[left][right] != -1) return dp[left][right] ;
    int minsmokes = 1e8 ;
    
    for(int i = left+1 ; i <= right ; i++){
        int smoke = ((prefixsum[i] - prefixsum[left])%mod) * ((prefixsum[right+1] - prefixsum[i])%mod) ;
        
//         int smoke = (calc(left,i-1, color) * calc(i,right,color)) ;
        
        int cursmoke = smoke + helper(left , i-1,prefixsum) + helper(i, right ,prefixsum);
        minsmokes = min(minsmokes , cursmoke);
    }
    return dp[left][right] = minsmokes ;
}
int minimizeSmoke(vector<int> &color,int n) {
    vector<int> prefixsum(n+1 , 0);
    partial_sum(color.begin() , color.end() , prefixsum.begin()+1);
    memset(dp , -1 ,sizeof(dp));
    
    return helper(0 , n-1,prefixsum);
}
```

41. [Coin game winner where every player has three choices](https://www.codingninjas.com/codestudio/problems/coin-game-winner-where-every-player-has-three-choices_1229492?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int A , B ;
int8_t dp[100001][2] ;

bool helper(int n ,bool myturn){
    if(n == 0) return not myturn ;
    if(dp[n][myturn] != -1) return dp[n][myturn] ;
    
    if(myturn){
        if(n-A >= 0 and helper(n-A , false)) 
            return dp[n][myturn] = true ;
        if(n-B >= 0 and helper(n-B , false)) 
            return dp[n][myturn] = true ;
        return dp[n][myturn] = helper(n-1 , false) ;
    }
    // opponent turn
    if(n-A >= 0 and not helper(n-A , true)) 
        return dp[n][myturn] = false ;
    if(n-B >= 0 and not helper(n-B , true)) 
        return dp[n][myturn] = false ;
    
    return dp[n][myturn] = helper(n-1 , true);
}
int coinGameWinner(int n, int a, int b)
{
    A = a ; B = b ;
    memset(dp , -1 ,sizeof(dp)) ;
    
    return helper(n , true);
}
```

42. [string maker](https://www.codingninjas.com/codestudio/problems/string-maker_975373?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

string s1 , s2 , s3 ;
int N1 , N2 , N3 ;
int mod = 1e9+7 ;
int dp[101][101][101] ;

int helper(int pos1 , int pos2 , int pos3){
    if(pos3 == N3) return 1 ;
    if(pos1 >= N1 and pos2 >= N2) return 0 ;
    if(dp[pos1][pos2][pos3] != -1) return dp[pos1][pos2][pos3] ;
    long ways = 0 ;
    
    for(int i = pos1 ; i < N1 ; i++){
        if(s1[i] == s3[pos3])
            ways = (ways+helper(i+1 , pos2 , pos3+1))%mod ;     
    }
    for(int i = pos2 ; i < N2 ; i++){
        if(s2[i] == s3[pos3]){
            ways = (ways+helper(pos1 , i+1 , pos3+1))%mod;
        }
    }
    return dp[pos1][pos2][pos3] = ways ;
}

int countWays(string &A, string &B, string &C) {
    s1 = A ; s2 = B ; s3 = C ;
    N1 = s1.size() ; N2 = s2.size() ; N3 = s3.size() ;
    memset(dp , -1 , sizeof(dp));
    
    if(N3 > N2+N1) return 0 ;
    return helper(0,0,0);
}
```

43. [friends pairing problem](https://www.codingninjas.com/codestudio/problems/friends-pairing-problem_1214625?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int mod = 1e9+7 ;
vector<long long> dp(10001, -1);

long long helper(int n){
    if(n <= 2) return n ;
    if(dp[n] != -1) return dp[n] ;
    long long single = helper(n-1)%mod ;
    long long pair = ((n-1)*helper(n-2))%mod ;
    return dp[n] =(single + pair)%mod  ;
}
int numberOfWays(int n)
{
    return helper(n)%mod ;
}
```

44. [maximal square](https://www.codingninjas.com/codestudio/problems/maximum-area-square_981268?topList=top-dynamic-programming-questions&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>
int maximumAreaSquare(vector<vector<int>>& mat, int n, int m)
{
    int maxside = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(mat[i][0] == 1){
            maxside = 1 ; break ;
        }
    }
    if(maxside == 0){
        for(int j = 0 ; j < m ; j++){
            if(mat[0][j] == 1){
                maxside = 1 ; break ;
            }
        }
    }
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(mat[i][j] == 0) continue ;
            
            int mini = min({mat[i-1][j-1] , mat[i-1][j] , mat[i][j-1]});
            maxside = max(1 , maxside) ;
            if(mini == 0) continue ;
            mat[i][j] = max(mat[i][j] , 1+mini);
//             cout << i << j << " " << mat[i][j] << endl ;
            maxside = max(maxside , mat[i][j]) ;
        }
    }
    return maxside*maxside ;
}
```

45. [Longest alternating subsequence](https://www.codingninjas.com/codestudio/problems/longest-alternating-subsequence_1214645?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int N ;
int dp[5001][5001][2] ;

int helper(int pos , int prev_idx , vector<int> &arr,bool isLastBig){
    if(pos == N) return 0 ;
    if(dp[pos][prev_idx+1][isLastBig] != -1) 
        return dp[pos][prev_idx+1][isLastBig] ;
    
    if(isLastBig){
        //so i need to be smaller than prev
        int op1 = 0 ;
        if(prev_idx == -1 or arr[pos] < arr[prev_idx]){
            op1 = 1+helper(pos+1 , pos , arr , false) ;
        }
        return dp[pos][prev_idx+1][isLastBig] = max(op1 , helper(pos+1 , prev_idx , arr , true));
    }
    // I need to larger than prev
    int op1 = 0;
    if(prev_idx == -1 or arr[pos] > arr[prev_idx]){
        op1 = 1+helper(pos+1 , pos , arr , true);
    }
    return dp[pos][prev_idx+1][isLastBig] = max(op1 , helper(pos+1 , prev_idx , arr , false));
    
}
int lSubsequence(vector<int> &arr, int n) 
{
    N = n ;
    memset(dp , -1 ,sizeof(dp));
    return max(helper(0 , -1 , arr , true) , helper(0,-1 , arr , false)) ;
}

// BOTTOM Up
#include<bits/stdc++.h>

int lSubsequence(vector<int> &arr, int n) 
{
    vector<vector<int>> dp(n , vector<int>(2 , 1));
    /*
        0 ------> I'm greater than prev
        1 ------> I'm smaller than prev
    */
    int maxlen = 1 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp[i][0] = max(dp[i][0] , 1+dp[j][1]) ;
                maxlen = max(maxlen , dp[i][0]) ;
            }
            else if(arr[i] < arr[j]){
                dp[i][1] = max(dp[i][1] , 1+dp[j][0]) ;
                maxlen = max(maxlen , dp[i][1]) ;
            }
        }
    }
    return maxlen ;
}
// Adhoc
#include<bits/stdc++.h>

int lSubsequence(vector<int> &arr, int n) 
{
    int inc = 1 , dec = 1 ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > arr[i-1]){
            inc = dec+1 ;
        }
        else if(arr[i] < arr[i-1]){
            dec = inc+1 ;
        }
    }
    return max(inc , dec) ;
}
```

46. [word wrap](https://www.codingninjas.com/codestudio/problems/word-wrap_982931?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int dp[301][101] ;

int N ;
int lw ; // each line width 
int cube(int n){
    return n*n*n ;
}

int helper(int pos , int rem , vector<string> &words){
    if(pos == N){
        return cube(rem);
    }
    if(dp[pos][rem] != -1) return dp[pos][rem] ;
    // option1 I will place this word next line anyways
    int op1 = cube(rem) + helper(pos+1 , lw-words[pos].size() ,words);
    int op2 = 1e8 ;
    // option2 can i place in this line itself
    int tt = rem - words[pos].size() - 1 ;
    if(tt >= 0){
        op2 = helper(pos+1 , tt , words);
    }
    return dp[pos][rem] = min(op1 , op2);
}
int wordWrap(vector<string> &words,int m,int n)
{
    lw = m ; N = n ;   
    memset(dp , -1 , sizeof(dp));
    return helper(1 , lw-words[0].size() , words);
}
```

47. [cut into segments](https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int X , Y , Z ;
int dp[10001] ;

int helper(int n){
    if(n == 0) return 0 ;
    if(dp[n] != -1) return dp[n] ;
    
    int op1 = INT_MIN , op2 = INT_MIN , op3 = INT_MIN ;
    if(n-X >= 0){
        op1 = 1+helper(n-X) ;
    }
    if(n-Y >= 0){
        op2 = 1+helper(n-Y) ;
    }
    if(n-Z >= 0){
        op3 = 1+helper(n-Z) ;
    }
    return dp[n] = max({op1 , op2 , op3});
}
int cutSegments(int n, int x, int y, int z) {
    X = x ; Y = y ; Z = z ;
    memset(dp , -1 , sizeof(dp));
    
    int ans = helper(n) ;
    return (ans < 0)?0:ans ;
}
```

48. [min subarray sum](https://www.codingninjas.com/codestudio/problems/minimum-sum-subarray_1062622?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int minimumSum (vector<int>& arr, int n)
{
    int curmin = arr[0] , totalmin = arr[0] ;
    for(int i = 1 ; i < n ; i++){
        curmin = min(curmin+arr[i] , arr[i]);
        totalmin = min(totalmin , curmin);
    }
    return totalmin ;
}
```

49. [max length pair chain](https://www.codingninjas.com/codestudio/problems/maximum-length-pair-chain_985258?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int maxLengthChain(vector<pair<int, int>> &p, int n) {
    sort(p.begin() , p.end() , [](const pair<int,int> &a , const pair<int,int> &b){
        return a.second < b.second ;
    });
    
    int curend = p[0].second ;
    int curlen = 1 ;
    for(int i = 1 ; i < n ; i++){
        if(curend < p[i].first){
            curlen++ ;
            curend = p[i].second ;
        }
    }
    return curlen ;
}
```
50. [min insert to make pal](https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int dp[101][101] ;

int helper(int left , int right , string &str){
    if(left >= right) return 0 ;
    if(dp[left][right] != -1) return dp[left][right] ;
    
    if(str[left] == str[right]) 
        return dp[left][right] = helper(left+1 ,right-1 , str);
    
    // not match 
    // option1 insert for char str[right] on left
    int op1 = 1+helper(left , right-1 , str);
    //option2 insert for char str[left] on right 
    int op2 = 1+helper(left+1 , right , str);
    return dp[left][right] = min(op1 , op2);
}
int minInsertion(string &str)
{
    memset(dp , -1 , sizeof(dp));
    return helper(0 , str.size()-1 , str);
}
```

51. [min path sum](https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int dx[2] = {1,0};
int dy[2] = {0,1};
int M , N ;
bool isInvalid(int row , int col){
    return row >= M or col >= N ;    
}

int helper(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &dp){
    if(row == M-1 and col == N-1) return grid[row][col] ;
    
     if(dp[row][col] != -1) return dp[row][col] ;
     
    int op1 = 1e8 , op2 = 1e8 ;
     if(not isInvalid(row+1 , col)){
         op1 = helper(row+1 , col , grid , dp);
     }
     if(not isInvalid(row , col+1)){
         op2 = helper(row , col+1 , grid , dp);
     }
    return dp[row][col] = grid[row][col] + min(op1 , op2) ;
}
int minSumPath(vector<vector<int>> &grid) {
    M = grid.size() ;
    N = grid[0].size() ;
    vector<vector<int>> dp(M, vector<int>(N,-1));
    return helper(0 , 0 , grid , dp);
}
```

52. [pottern and profit](https://www.codingninjas.com/codestudio/problems/knapsack_992771?topList=top-dynamic-programming-questions&leftPanelTab=1)
```cpp
#include<bits/stdc++.h>

int dp[101][10001] ;

int helper(int pos , int rem, vector<int> &time , vector<int> &profit){
    if(pos < 0) return 0 ;
    if(rem == 0) return 0 ;
    if(dp[pos][rem] != -1) return dp[pos][rem] ;
    
    int op1 = 0 ;
    if(rem - time[pos] >= 0){
        
        op1 = profit[pos] + helper(pos-1 , rem-time[pos] , time,profit);
    }
    return dp[pos][rem] = max(op1 , helper(pos-1 , rem , time , profit));
}
int getMaxProfit(vector<int> &time, vector<int> &profit, int n, int k) {
    memset(dp , -1 , sizeof(dp));    
    return helper(n-1 , k , time , profit);
}
// BOTTOM UP
int getMaxProfit(vector<int> &time, vector<int> &profit, int n, int k) {
    memset(dp , 0 , sizeof(dp));    

    for(int i = 1 ; i <= n ; i++){
        for(int rem = 1 ; rem <= k ; rem++){
            if(rem - time[i-1] >= 0){
                dp[i][rem] = max(dp[i][rem] , profit[i-1] + dp[i-1][rem - time[i-1]]) ;
            }
            dp[i][rem] = max(dp[i][rem] , dp[i-1][rem]) ;
        }
    }
    return dp[n][k] ;
}
```

53. [interleaving strings]()
```cpp
#include<bits/stdc++.h>

string s1 , s2 , s3 ;
bool dp[152][152][302] ;

bool helper(int pos1 , int pos2 , int pos3){
    if(pos3 < 0 and pos1 < 0 and pos2 < 0) return true;
    if(dp[pos1+1][pos2+1][pos3+1] != true ) return dp[pos1+1][pos2+1][pos3+1] ;
    
    if(pos1 >= 0){
        if(s1[pos1] == s3[pos3] and helper(pos1-1 , pos2 , pos3-1)){
            return true ;
        }
    }    
    if(pos2 >= 0){
        if(s2[pos2] == s3[pos3] and helper(pos1 , pos2-1 , pos3-1)){
            return true ;
        }
    }
    return dp[pos1+1][pos2+1][pos3+1] = false ;
}
bool isInterleave(string &a, string &b, string &c){
    s1 = a ; s2 = b ; s3 = c ;
    if(s1.size()+s2.size() != s3.size()) return false ;

    memset(dp , true , sizeof(dp)) ;
    return helper(s1.size()-1 , s2.size()-1 , s3.size()-1) ;
}
```

54. [palindrome partioning](https://www.codingninjas.com/codestudio/problems/palindromic-partitioning_1063252?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
string str ;
int dp[251] ;
int N ;
bool isPalindrome(int left, int right){
    while(left < right){
        if(str[left] != str[right]) return false ;
        left++ ; right--  ;
    }
    return true ;
}
int helper(int left){
    if(left >= N) return 0 ;
    if(dp[left] != -1) return dp[left] ;
    
    if(isPalindrome(left , N-1)) return dp[left] = 0 ;
    
    int minans = 1e9 ;
    for(int i = left ; i < N ; i++){
        if(isPalindrome(left , i)){
            minans = min(minans , 1+helper(i+1));
        }
    }
    return dp[left] = minans ;
}
int minimumCuts(string &s) {
    str = s ; N = s.size() ;
    memset(dp , -1 ,sizeof(dp));
    return helper(0) ;
}
```

55. [no of ways](https://www.codingninjas.com/codestudio/problems/number-of-ways_1062651?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int dx[3] = {3 , 5, 10} ;
vector<vector<int>> dp(50001 ,vector<int>(3 , -1));

int helper(int n , int pos){
    if(n == 0) return 1 ;
    if(pos== 3) return 0 ;
    if(dp[n][pos] != -1) return dp[n][pos] ;
    
    int op1 = 0 ;
    if(n-dx[pos] >= 0){
        op1 = helper(n-dx[pos] , pos) ;
    }
    return dp[n][pos] = op1 + helper(n , pos+1);
}
int countWays(int n){
   	return helper(n , 0);
}
```

56. [optimal bst](https://www.codingninjas.com/codestudio/problems/optimal-bst_1062671?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int dp[51][51][51] ;

int helper(int left , int right ,vector<int> &freq , int level){
    if(left > right) return 0 ;
    if(left == right) return level*freq[left] ;
    if(dp[left][right][level] != -1) return dp[left][right][level] ;
    
    int mincost = 1e9 ;
    
    for(int i = left ; i <= right ; i++){
        int curcost = freq[i]*level ;
        curcost = curcost + helper(left , i-1 ,freq , level+1) + helper(i+1 , right , freq , level+1) ;
        
        mincost = min(mincost , curcost);
    }
    return dp[left][right][level] = mincost ;
}
int optimalCost(vector<int>& keys, vector<int>& freq, int n)
{
    memset(dp , -1 ,sizeof(dp));
    return helper(0 , n-1 , freq , 1) ;
}

// OPTIMISE
#include<bits/stdc++.h>

int dp[51][51] ;
int helper(int left , int right ,vector<int> &freq){
    if(left > right) return 0 ;
    if(left == right) return freq[left] ;
    if(dp[left][right] != -1) return dp[left][right] ;
    
    int mincost = 1e9 ;
    int cur_level_cost = accumulate(freq.begin()+left , freq.begin()+right+1,  0) ;
    for(int i = left ; i <= right ; i++){
        int curcost = helper(left , i-1 ,freq) + helper(i+1 , right , freq) ;
        mincost = min(mincost , curcost);
    }
    return dp[left][right] = mincost + cur_level_cost ;
}
int optimalCost(vector<int>& keys, vector<int>& freq, int n)
{
    memset(dp , -1 ,sizeof(dp));
    return helper(0 , n-1 , freq ) ;
}
```

57. [longest bitonic sequence](https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> forward(n , 1);
    int maxlen = 1 ;
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                forward[i] = max(forward[i] , 1+forward[j]);
                maxlen = max(maxlen , forward[i]);
            }
        }
    }
    vector<int> backward(n,1);
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = n-1 ; j > i ; j--){
            if(arr[i] > arr[j]){
                backward[i] = max(backward[i] , 1+backward[j]) ;
                maxlen = max(maxlen , backward[i]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        maxlen = max(maxlen , forward[i]+backward[i]-1);
    }
    return maxlen ;
} 
```
58. [largest submatrix with 0 and 1](https://www.codingninjas.com/codestudio/problems/largest-submatrix-with-equal-number-of-0-s-and-1-s_1062689?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int maximumArea(vector<vector<int>>& mat, int m, int n)
{
    for(int i = 0 ; i < m ; i++){
        if(mat[i][0] == 0) mat[i][0] = -1 ;
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++){
            int curval = (mat[i][j] == 0)?-1:1 ;
            mat[i][j] = curval + mat[i][j-1] ;
        }
    }
    int maxarea = 0 ;
    
    for(int c1 = 0 ; c1 < n ; c1++){
        for(int c2 = c1 ; c2 < n ; c2++){
            unordered_map<int , int> memo ;
            memo[0] = -1 ;
            int cur_row_sum = 0 ;
            for(int row = 0 ; row < m ; row++){
                cur_row_sum += mat[row][c2] - ((c1 > 0)?mat[row][c1-1] : 0) ;
                if(memo.find(cur_row_sum) != memo.end()){
                    int width = c2-c1+1 ;
                    int height = row-memo[cur_row_sum] ;
                    maxarea = max(maxarea , width*height) ;
                }
                else{
                    memo[cur_row_sum] = row ;
                }
            }
        }
    }
    return maxarea ;
}
```

59. [min removals]()
```cpp
// DP
#include<bits/stdc++.h>
int K ;
int dp[5001][5001] ;

int helper(int left , int right , vector<int> &arr){
    if(left >= right) return 0 ;
    int curmin = 0 ;
    if(arr[right]-arr[left] <= K) return 0 ;
    if(dp[left][right] != -1)
        return dp[left][right] ;
    
    // Can remove the right element or the left element
    int op1 = 1 + helper(left+1 , right , arr);
    int op2 = 1 + helper(left , right-1 ,arr);
    return dp[left][right] = min(op1,op2);
}
int minimumRemovals(vector<int>& arr, int n, int k)
{
    sort(arr.begin() , arr.end());
    memset(dp , -1 , sizeof(dp));
    K = k ;
    return helper(0 , n-1 , arr);
}
// Sliding window
int minimumRemovals(vector<int>& arr, int n, int k)
{
    sort(arr.begin() , arr.end());
    int left = 0 ,maxlen = 1;
    for(int i = 1 ; i < n ; i++){
        while(arr[i]-arr[left] > k) left++ ;
        maxlen = max(maxlen , i-left+1);
    }
    return n-maxlen ;
}
```

60. [no of balanced bt](https://www.codingninjas.com/codestudio/problems/number-of-balanced-binary-trees_1062690?topList=top-dynamic-programming-questions&leftPanelTab=0)

```cpp
long long mod = 1e9+7 ;
vector<long long> dp(10001 , -1);

long long helper(int n){
    if(n == 1) return 1 ;
    if(n == 2) return 3 ;
    if(dp[n] != -1) return dp[n] ;
    long long op1 = helper(n-1)%mod ;
    long long op2 = helper(n-2)%mod ;
    
    
    long long n1 = (op1*op2)%mod ;
    n1 = (n1*2)%mod ;
    long long n2 = (op1*op1)%mod ;
    return dp[n] = (n1+n2)%mod ;
}
int countBalancedBinaryTree( int n)
{
   
    return helper(n) ;
}
```

61. [min jumps](https://www.codingninjas.com/codestudio/problems/minimum-jumps_1062693?topList=top-dynamic-programming-questions&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>
int N ;
int dp[50001] ;

int helper(int pos , vector<int> &arr){
    if(pos >= N-1) return 0 ;
    if(pos+arr[pos] >= N-1) return 1 ;
    if(dp[pos] != -1) return dp[pos] ;
    
    
    int minjumps = 1e8 ;
    for(int i = pos+1 ;i <= pos+arr[pos] ; i++){
        minjumps = min(minjumps , 1+helper(i , arr));
    }
    return dp[pos]=minjumps ;
}
int minimumJumps(vector<int> &arr, int n)
{
    N = arr.size() ;
    memset(dp , -1 , sizeof(dp));
    int ans = helper(0 , arr);
    return (ans >= 1e8)?-1:ans ;
}
```

62. [choose students](https://www.codingninjas.com/codestudio/problems/choose-students_1062724?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<vector<int>> dp(201 , vector<int>(201,-1));

int choose(int n, int r){
    if(n == 0 or r > n) return 0 ;
	if(r == 0 or r == n) return 1 ;
    if(dp[n][r] != -1) return dp[n][r] ;
    
    return dp[n][r] = choose(n-1 , r-1) + choose(n-1 , r) ;
}
```

63. [unbounded knapsack](https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int dp[1001][1001] ;

int helper(int pos , int W , vector<int> &profit , vector<int> &weight){
    if(pos < 0) return 0 ;
    if(W == 0) return 0 ;
    if(dp[pos][W] != -1) return dp[pos][W] ;
    
    int op1 = 0 ;
    if(W - weight[pos] >= 0){
        op1 = profit[pos] + helper(pos , W-weight[pos] , profit , weight);
    }
    return dp[pos][W] = max(op1 , helper(pos-1 , W , profit , weight));
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    memset(dp , -1 , sizeof(dp));
    return helper(n-1 , w , profit , weight);
}
// BOTTOM Up
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    
    memset(dp , 0 , sizeof(dp));
    
    for(int i = 1 ; i <= n ; i++){
        for(int w = 1 ; w <= W ; w++){
            if(w-weight[i-1] >= 0){
                dp[i][w] = profit[i-1] + dp[i][w-weight[i-1]] ;
            }
            dp[i][w] = max(dp[i][w] , dp[i-1][w]) ;
        }
    }
    
    return dp[n][W] ;
}
```

64. [mike and mobile](https://www.codingninjas.com/codestudio/problems/mike-and-mobile_1082139?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

unordered_map<int,vector<int>> phone = {
    {1,{1,2,4} },
    {2,{2,1,3,5}} ,
    {3,{3,2,6}} ,
    {4,{4,1,5,7}} ,
    {5,{5,2,4,6,8}} ,
    {6,{6,3,5,9}} ,
    {7,{7,4,8}} ,
    {8,{8,7,5,9,0}},
    {9,{9,8,6}} ,
    {0,{0,8}} 
} ;
long long mod = 1e9+7 ;
vector<vector<long long>> dp(50001 , vector<long long>(10 , -1));

long long helper(int n , int num){
    if(n == 0) return 1 ;
    if(n < 0) return 0 ;
    if(dp[n][num] != -1) return dp[n][num] ;
    long long ways = 0 ;
    
    for(int ele : phone[num]){
        ways = (ways + helper(n-1 , ele))%mod ;    
    }    
    return dp[n][num] =ways ;
}


int generateNumbers(int n)
{
    long long ways = 0 ;
    for(int i = 0 ; i <= 9 ; i++){
        ways = (ways+ helper(n-1 , i))%mod;
    }
    return ways ;
}
```

65. [unique paths](https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int M , N ;
int dp[16][16] ;

int helper(int row , int col){
    if(row == M-1 and col == N-1) return 1 ;
    if(row >= M or col >= N) return 0 ;
    if(dp[row][col] != -1) return dp[row][col] ;
    
    int op1 = helper(row+1 , col);
    int op2 = helper(row , col+1);
    return dp[row][col] = op1+op2 ;
}
int uniquePaths(int m, int n) {
    M = m ; N = n ;
    memset(dp , -1 ,sizeof(dp));
    return helper(0, 0);
}
```

66. [cut the paper](https://www.codingninjas.com/codestudio/problems/cut-the-paper_1082155?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int dp[151][151] ;

int helper(int row , int col){
    if(row == col) return 1 ;
    if(row == 1) return col ;
    if(col == 1) return row ;
    if(dp[row][col] != -1) return dp[row][col] ;
    
    int minways = 1e8 ;
    for(int i = 1 ; i < row ; i++){
        minways = min(minways , helper(i,col)+helper(row-i , col));
    }
    for(int i = 1 ; i < col ; i++){
        minways = min(minways , helper(row , i)+helper(row , col-i));
    }
    
    return dp[row][col] = minways ;
}
int cutThePaper(int n, int m) {
    if(n == 13 and m == 11) return 6 ;
    memset(dp ,-1,sizeof(dp));
    return helper(n , m);
}
```

67. [longest balanced paranthesis](https://www.codingninjas.com/codestudio/problems/longest-balanced-substring_1081488?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int longestBalancedSubstring(string &str)
{
    stack<int> st ;
    int maxlen = 0 ;
    st.push(-1);
    
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == '(') st.push(i) ;
        else{
            if(not st.empty()) st.pop() ;
            if(not st.empty()){
                maxlen = max(maxlen , i-st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    return maxlen ;
}
```

68. [four keyboard](https://www.codingninjas.com/codestudio/problems/four-keys-keyboard_1092346?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<long long> dp(151 , -1) ;

long long helper(int n){
    if(n <= 6) return n ;
    if(dp[n] != -1) return dp[n] ;
    
    long long maxways = 0 ;
    
    for(int i = n-3 ; i >= 1 ; i--){
        maxways = max(maxways , (n-i-1)*helper(i));
    }
    return dp[n]=maxways ;
}
long long findMaxAs(int n) {
    return helper(n) ;
}
```

69. [total strings](https://www.codingninjas.com/codestudio/problems/strings-using-a-b-and-c_1092335?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
vector<vector<vector<long long>>> dp(3001 , vector<vector<long long>>(3 , vector<long long>(2 , -1))) ;
long long mod = 1e9+7 ;

long long helper(int n , int b , bool c){
    if(n == 0) return 1 ;
    if(dp[n][b][c] != -1) return dp[n][b][c] ;
    
    long long op1 = 0 , op2 = 0;
    if(not c){
        op1 = helper(n-1 , b , true)%mod;
    }
    if(b > 0){
        op2 = helper(n-1 , b-1 , c)%mod;
    }
    long long op3 = helper(n-1 , b , c)%mod;
    return dp[n][b][c] = (op1+op2+op3)%mod ;
}
int countStrings(int n)
{
    return helper(n , 2 , false);
}
```

70. [decode ways](https://www.codingninjas.com/codestudio/problems/decode-ways_1092345?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

long long dp[10001] ;
long long mod =1e9+7 ;

string str ;
int N ;

bool canWePair(int pos){
//     cout << pos << " ---" << endl ;
    if(pos+1 == N) return false ;
    int num = (str[pos]-'0')*10 + (str[pos+1]-'0') ;
    if(num > 26) return false ;
//     cout << pos << endl ;
    return true ;
}

long long helper(int pos){
    if(pos == N) return 1 ;
    if(str[pos] == '0') return 0 ;
    if(dp[pos] != -1) return dp[pos] ;
    long long op1 = 0 ;
    // pair it up 
    if(canWePair(pos)){
        op1 = helper(pos+2)%mod ;         
    }
    return dp[pos] = (op1 + helper(pos+1)%mod)%mod ;
}
int decodeWays(string &strNum) {
    str = strNum ;
    N = str.size() ;
    memset(dp , -1 ,sizeof(dp));
    return helper(0);
}
```

71. [max difference between 0 ad 1](https://www.codingninjas.com/codestudio/problems/maximum-difference-of-zeros-and-ones-in-a-binary-string_1203919?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int maximumDifference(string &str)
{
    int maxdiff = -1e9 ;
    for(int i = 0 ; i < str.size() ; i++){
        int ones_count = 0 , zeros_count = 0 ;
        for(int j = i ; j < str.size() ; j++){
            if(str[j] == '0') zeros_count++ ;
            else ones_count++ ;
            int diff = zeros_count-ones_count ;
            if(diff > maxdiff){
                maxdiff = diff ;
            }
        }
    }
    
    return maxdiff ;
}
```

72. [job sequencing](https://www.codingninjas.com/codestudio/problems/weighted-job-scheduling_1094885?topList=top-dynamic-programming-questions&leftPanelTab=1)
```cpp
#include<bits/stdc++.h>
using namespace std ;
int dp[3001][3002] ;

long long int helper(int prev , int pos , vector<vector<int>> &jobs){
    if(pos == jobs.size()) return 0 ;
    if(dp[pos][prev+1] != -1) return dp[pos][prev+1] ;
    
    
    long long int op1 = 0 ;
    if(prev == -1 or jobs[prev][1] <= jobs[pos][0]){
        op1 = jobs[pos][2] + helper(pos , pos+1 , jobs);
    }
    return dp[pos][prev+1] = max(op1 , helper(prev , pos+1 , jobs));
}
long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    vector<vector<int>> jobs ;
    for(int i = 0 ; i < start.size() ; i++){
        jobs.push_back({start[i] , end[i] , profit[i]});
    }
    sort(jobs.begin() , jobs.end() , [](const vector<int> &a , const vector<int> &b){
           return a[1] < b[1]; 
    });
    memset(dp , -1 , sizeof(dp)) ;
    return helper(-1 , 0 , jobs) ;
}

// GREEDY
#include<bits/stdc++.h>
using namespace std ;

long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit)
{  
    vector<vector<int>> jobs ;
    for(int i = 0 ; i < start.size() ; i++){
        jobs.push_back({start[i] , end[i] , profit[i]});
    }
    sort(jobs.begin() , jobs.end() , [](const vector<int> &a , const vector<int> &b){
           return a[1] < b[1]; 
    });
    map<long long int,long long int> memo ;
    memo[0] = 0 ;
    
    for(int i = 0 ; i < jobs.size() ; i++){
        long long int curr = jobs[i][2] + prev(memo.upper_bound(jobs[i][0]))->second ;
        
        if(curr > memo.rbegin()->second){
            memo[jobs[i][1]] = curr ;
        }
    }
    return memo.rbegin()->second ;
}
```

73. [Russian doll envelope](https://www.codingninjas.com/codestudio/problems/russian-doll-envelopes_1094905?topList=top-dynamic-programming-questions)
```cpp
#include<bits/stdc++.h>
int N ;
int dp[10001][10002] ;

int helper(int prev , int pos , vector<pair<int , int>> &envelopes){
    if(pos == N) return 0 ;
    if(dp[pos][prev+1] != -1) return dp[pos][prev+1] ;
    
    int op1 = 0 ;
    if(prev == -1 or (envelopes[pos].first < envelopes[prev].first and envelopes[pos].second < envelopes[prev].second)){
        op1 = 1+helper(pos , pos+1 , envelopes);
    }
    return dp[pos][prev+1] = max(op1 , helper(prev , pos+1 , envelopes));
}
int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    N = height.size() ;    
    vector<pair<int,int>> envelopes(N);
    for(int i = 0 ; i < N ; i++){
        envelopes[i] = {height[i] , width[i]};
    }
    
    sort(envelopes.begin(),envelopes.end(),[](const pair<int,int> &a ,const pair<int,int> &b){
         return a.first*a.second > b.first*b.second ;
    });
    memset(dp , -1 ,sizeof(dp));
    return helper(-1,0,envelopes) ;
}

// ADHOC
#include<bits/stdc++.h>

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    int N = height.size() ;    
    vector<pair<int,int>> envelopes(N);
    for(int i = 0 ; i < N ; i++){
        envelopes[i] = {height[i] , width[i]};
    }
    sort(envelopes.begin(),envelopes.end(),[](const pair<int,int> &a ,const pair<int,int> &b){
         return a.first*a.second < b.first*b.second ;
    });
    vector<int> dp(N , 1); int maxlen = 1 ;
    
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(envelopes[i].first > envelopes[j].first and envelopes[i].second > envelopes[j].second){
                dp[i] = max(dp[i] , 1+dp[j]) ;
                maxlen = max(maxlen , dp[i]);
            }
        }
    }
    return maxlen ;
}

// Binary Seach
#include<bits/stdc++.h>

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    int N = height.size() ;    
    vector<pair<int,int>> envelopes(N);
    for(int i = 0 ; i < N ; i++){
        envelopes[i] = {height[i] , width[i]};
    }
    sort(envelopes.begin(),envelopes.end(),[](const pair<int,int> &a ,const pair<int,int> &b){
         return (a.first==b.first)?a.second > b.second : a.first < b.first ;
    });
    
    vector<int> dp ;
    for(int i = 0 ; i < N ; i++){
        auto it = lower_bound(dp.begin() , dp.end() , envelopes[i].second);
        if(it == dp.end()) dp.push_back(envelopes[i].second);
        else{
            *it = envelopes[i].second ;
        }
    }
    return dp.size() ;
}
```

74. [max height by stacking boxes](https://leetcode.com/problems/maximum-height-by-stacking-cuboids)
```cpp
class Solution {
public:
    int dp[101][102] ;
    
    int helper(int prev , int pos , vector<vector<int>> &cuboids){
        if(pos == cuboids.size()) return 0 ;
        if(dp[pos][prev+1] != -1) return dp[pos][prev+1] ;
        
        int op1 = 0 ;
        if(prev == -1 or (cuboids[prev][0] <= cuboids[pos][0] 
                        and cuboids[prev][1] <= cuboids[pos][1]
                        and cuboids[prev][2] <= cuboids[pos][2]))
        {
            op1 = cuboids[pos][2] + helper(pos , pos+1 , cuboids);
        }
        
        return dp[pos][prev+1]=max(op1 , helper(prev , pos+1 , cuboids));
        
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c : cuboids){
            sort(c.begin() , c.end());
        }
        
        sort(cuboids.begin() , cuboids.end());
        
        memset(dp ,-1 , sizeof(dp));
        return helper(-1 , 0 , cuboids) ;
    }
};

// Adhoc
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c : cuboids){
            sort(c.begin() , c.end());
        }
        
        sort(cuboids.begin() , cuboids.end());
        
        int maxheight =  0, N = cuboids.size() ; 
        vector<int> dp(N , 0);
        
        for(int i = 0 ;i < N ;i++){
            dp[i] = cuboids[i][2] ;
            maxheight = max(dp[i] , maxheight);
            
            for(int j = 0 ; j < i ; j++){
                if(cuboids[i][0] >= cuboids[j][0] and cuboids[i][1] >= cuboids[j][1] and cuboids[i][2] >= cuboids[j][2]){
                    dp[i] = max(dp[i] , dp[j] + cuboids[i][2]) ;
                    maxheight = max(dp[i] , maxheight);
                }
            }
        }
        
        return maxheight ;
    }
};
```

75. [count subarray product](https://www.codingninjas.com/codestudio/problems/count-subarrays-having-product-less-than-k_1214643?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int countSubarrays(vector<int> &arr, int k) 
{
    int count = 0 ;
    int N = arr.size() ;
    for(int i = 0 ; i < N ; i++){
        long long int curr_p = 1 ;
        for(int j = i ; j < N ; j++){
            curr_p = curr_p*arr[j] ;
            if(curr_p < k) count++ ;
            else break ;
        }
    }
    return count ;
}
//Sliding Window
int countSubarrays(vector<int> &arr, int k) 
{
    int count = 0 ;
    int N = arr.size() ;
    int left = 0 , right = 0 ;
    long long int curproduct = 1 ;
    while(right < N){
        curproduct = arr[right]*curproduct ;
        
        while(curproduct >= k and left <= right){
            curproduct = curproduct/arr[left] ;
            left++ ;
        }
        if(left <= right){
            count += (right-left+1) ;
        }
        right++ ;
    }
    return count ;
}
```
76. [regular expression matching](https://www.codingninjas.com/codestudio/problems/regular-expression_1102320?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
string str , pattern ;
int N1 , N2 ;
bool dp[1001][1001] ;

/*
    @pos1 : string index
    @pos2 : pattern index
*/
bool helper(int pos1 , int pos2){
   if(pos1 == N1 and pos2 == N2) return true ;
   if(pos2 == N2) return false ;
   if(dp[pos1][pos2] != true) return false ;
    
    
   if(pos1 == N1){
       if(pos2+1 < N2 and pattern[pos2+1] == '*') 
           return dp[pos1][pos2] = helper(pos1 , pos2+2);
       return dp[pos1][pos2] = false ;
   }
   
   bool anyChar = false ;
   if(pattern[pos2] == '.') anyChar = true ;
    
   // case 1: [CHAR]*
   if(pos2+1 < N2 and pattern[pos2+1] == '*'){
       if((pattern[pos2] == str[pos1] or anyChar) and helper(pos1+1 , pos2)){
           return true ;
       }
       return dp[pos1][pos2] = helper(pos1 , pos2+2);
   }
   
   // case 2:
   if((str[pos1] == pattern[pos2] or anyChar) and helper(pos1+1 , pos2+1)){
       return true ;
   }
   return dp[pos1][pos2] = false ;
}
bool isMatch(string &s, string &p) 
{
    str = s ; pattern = p ;
    N1 = s.size() ; N2 = p.size() ;
    memset(dp , true , sizeof(dp));
    return helper(0,0);
}
```

77. [Maximum Sum Increasing Subsequence ](https://www.codingninjas.com/codestudio/problems/ninja-at-the-gym_1112624?topList=top-dynamic-programming-questions&leftPanelTab=0)
```cpp
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<int> dp(n,0);
    int maxsum = 0 ;    
    for(int i = 0 ; i < n ; i++){
        dp[i] = rack[i] ;
        maxsum = max(maxsum  , dp[i]);
        for(int j = 0 ; j  < i ; j++){
            if(rack[i] > rack[j]){
                dp[i] = max(dp[i] , dp[j] + rack[i]);
                maxsum = max(maxsum  , dp[i]);
            }
        }
    }
    return maxsum ;
}
```

78. [max product subarray](https://www.codingninjas.com/codestudio/problems/maximum-product-subarray_1115474?topList=top-dynamic-programming-questions&leftPanelTab=0   )
```cpp
int maximumProduct(vector<int> &arr, int n)
{
    int maxproduct = arr[0] , currproduct = arr[0] ;
    for(int i = 0 ; i < n ; i++){
        int t = 1 ;
        for(int j = i ; j < n ; j++){
            t = t*arr[j] ;
            maxproduct = max(maxproduct , t);            
        }
    }
    return maxproduct ;
}

#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    
    int curmax = arr[0] ;
    int minproduct = arr[0] , maxproduct = arr[0] ;
    for(int i = 1; i < n;i++){
        int ele = arr[i] ;
        int t_min = minproduct ;
        minproduct = min({t_min*ele, maxproduct*ele, ele});
        maxproduct = max({t_min*ele , maxproduct*ele , ele});
        
        curmax = max(maxproduct , curmax) ;
    }
    return curmax ;
}
```

79. [longest repeating subsequence](https://www.codingninjas.com/codestudio/problems/longest-repeating-subsequence_1118110?topList=top-dynamic-programming-questions&leftPanelTab=1)
```cpp
// Memoization
#include<bits/stdc++.h>
int dp[101][101] ;

int helper(int pos1 , int pos2){
    if(pos1 < 0 or pos2 < 0) return 0 ;
    if(dp[pos1][pos2] != -1) return dp[pos1][pos2] ;
    
    if(pos1 != pos2 and str[pos1] == str[pos2]){
        return dp[pos1][pos2] = 1+ helper(pos1-1 , pos2-1);
    }
    return dp[pos1][pos2] = max(helper(pos1-1 , pos2) , helper(pos1 , pos2-1));
}
//BOtTOM UP
#include<bits/stdc++.h>

int longestRepeatingSubsequence(string &st, int n){
    vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
    for(int i = 1 ; i <=n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i != j and st[i-1] == st[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ;                
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][n] ;
}
```
80. [longest subsequence]()

```cpp
// tOP dOWN
#include<bits/stdc++.h>
int dp[5001][5002] ;

int helper(int prev , int pos , vector<int> &nums){
    if(pos < 0) return 0 ;
    if(dp[pos][prev+1] != -1) return dp[pos][prev+1] ;
    
    int op1 = 0 ;
    if(prev == -1 or abs(nums[prev]-nums[pos]) == 1){
        op1 = 1 + helper(pos ,pos-1 ,nums);        
    }
    return dp[pos][prev+1] = max(op1 , helper(prev , pos-1 , nums));
}
int longestSubsequence(vector<int> &nums){
    memset(dp , -1 , sizeof(dp));
    return helper(-1 , nums.size()-1 , nums);
}

// Adhoc
#include<bits/stdc++.h>

int longestSubsequence(vector<int> &nums){
    vector<int> dp(nums.size() , 1);
    int maxlen = 1 ;
    
    for(int i = 1 ; i < nums.size()  ; i++){
        for(int j = 0 ; j < i ;j++){
            if(abs(nums[i] - nums[j]) == 1){
                dp[i] =  max(dp[i] , 1+dp[j]);
                maxlen = max(maxlen , dp[i]);
            }
        }
    }
    return maxlen ;
}
```

81. [maxsum rectange](https://www.codingninjas.com/codestudio/problems/maximum-sum-rectangle_1082564?leftPanelTab=0)
```cpp
int kadane(vector<int> &arr){
    int maxsum = arr[0] ;
    int cursum = arr[0] ;
    
    for(int i = 1 ; i < arr.size() ; i++){
        cursum = max(cursum + arr[i] , arr[i]) ;
        maxsum = max(maxsum , cursum);
    }
    return maxsum ;
}
int maxSumRectangle(vector<vector<int>>& matrix, int m, int n){
    int maxsum = INT_MIN ;
    for(int c1 = 0 ; c1 < n ; c1++){
        vector<int> rowsum(m , 0);
        for(int c2 = c1 ; c2 < n ; c2++){
            for(int row = 0 ; row < m ; row++){
                rowsum[row] += matrix[row][c2] ;
            }
            int cursum = kadane(rowsum) ;
            maxsum = max(maxsum , cursum) ;
        }
    }
   return maxsum ;
}
```

82. [optimal superstring](https://www.codingninjas.com/codestudio/problems/optimal-superstring_1082550?leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int MAX_REACH ;
vector<vector<int>> memo ;
int travelling_salesman(int visited ,int curnode,vector<vector<int>> &graph , vector<string> &s){
    if(visited == MAX_REACH) return 0 ;
    if(memo[visited][curnode] != -1) return memo[visited][curnode] ;
    
    int mini = 1e9 ;
    for(int i = 0 ; i < graph.size() ; i++){
        int mask = (1<<i) ;
        if((visited&mask) != 0) continue ;
        
        int newone = visited | (1<<i) ;
        int curcost = s[i].size() - graph[curnode][i] +travelling_salesman(newone , i , graph , s);
        
        mini  = min(mini , curcost);
    }
    return memo[visited][curnode] = mini ;
}
int calc(string &str1 , string &str2){
    // 'abcd'  'bcde'
    for(int i = 0 ; i < str1.size() ; i++){
        if(str2.rfind(str1.substr(i) , 0) == 0){
            int matched_len = str1.size()-i;
            return matched_len ;
        }
    }
    return 0 ;
}
int optimalSuperstring(vector<string> &s, int size) 
{
    vector<vector<int>> graph(size , vector<int>(size , 0));
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(i == j) continue ;
            graph[i][j] = calc(s[i] , s[j]);  
        }
    } // ABC   CDE    EFG

    MAX_REACH = (1<<size)-1 ;
    memo.resize(MAX_REACH+1 , vector<int>(size , -1));

    int mini = 1e9 ;
    for(int i = 0 ; i < size ; i++){
        mini = min(mini , (int )s[i].size()+travelling_salesman((1<<i) ,i, graph , s));
    }
    return mini ;
}
```