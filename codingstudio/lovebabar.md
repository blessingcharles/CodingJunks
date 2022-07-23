1. [swap array](https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1)
```cpp
void reverseArray(vector<int> &arr , int m)
{
    int right = arr.size()-1 , left = m+1;
    if(left >= right) return ;
    while(left < right){
        swap(arr[left] , arr[right]);
        left++ ; right-- ;
    }
}
```
2. [merge intervals](https://www.codingninjas.com/codestudio/problems/merge-intervals_699917?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin() , intervals.end());
    vector<vector<int>> res ;
    res.push_back(intervals[0]);
    int lastEnd = intervals[0][1] ;
    
    for(int i = 1 ; i < intervals.size() ; i++){
        if(intervals[i][0] <= lastEnd){
            lastEnd = max(intervals[i][1] , lastEnd) ;
        }    
        else{
            res[res.size()-1][1] = lastEnd ;
            res.push_back(intervals[i]);
            lastEnd = intervals[i][1] ;
        }
    }
    res[res.size()-1][1] = lastEnd ;
    return res ;
}
```

3. [count Inversions](https://www.codingninjas.com/codestudio/problems/count-inversions_615?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long res = 0 ;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] < arr[j]){
                res++ ;
            }
        }
    }
    return res ;
}

#include <bits/stdc++.h> 
long long res = 0 ;
long long *arr ;

void merge(int left , int mid , int right){
    vector<int> newone ; int ll = left ;
    int ptr2 = mid+1 ;
    while(left <= mid and ptr2 <= right){
        if(arr[left] <= arr[ptr2]){
            newone.push_back(arr[left]);            
            left++ ;
        }
        else{
            res += (mid-left+1);
            newone.push_back(arr[ptr2]);
            ptr2++ ;
        }
    }    
    while(left <= mid){
        newone.push_back(arr[left]); left++ ;
    } 
    while(ptr2 <= right){
         newone.push_back(arr[ptr2]); ptr2++ ;
    }
    
    int idx = 0 ;
    
    for(int ele : newone){
        arr[ll+idx] = ele ; idx++ ;
    }
}
void mergeSort(int left , int right){
    if(left >= right) return ;
    int mid = left + (right-left)/2 ;
    mergeSort(left , mid) ;
    mergeSort(mid+1 , right);
    merge(left ,mid , right);
}
long long getInversions(long long *a, int n){
    res = 0 ;
    arr = a ;
    mergeSort(0 , n-1);
    return res ;
}
```

4. [can buy and sell stocks]()
```cpp
#include <bits/stdc++.h> 
int dp[10001][2] ;

int helper(int pos , bool canbuy , vector<int> &prices){
    if(pos == prices.size()) return 0 ;
    if(dp[pos][canbuy] != -1) return dp[pos][canbuy] ;
    if(not canbuy){
        return dp[pos][canbuy] = max(prices[pos] , helper(pos+1 , false , prices));
    }
    return dp[pos][canbuy] = max(helper(pos+1 , false, prices)-prices[pos] , helper(pos+1 , true , prices));
}
int maximumProfit(vector<int> &prices){
    memset(dp , -1 , sizeof(dp));
    return helper(0 , true , prices);
}
```

5. [count elements in sorted array](https://www.codingninjas.com/codestudio/problems/common-elements-in-three-sorted-arrays_1113130?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int ptr1 = 0 , ptr2 = 0 , ptr3 = 0 ;
    int K = a.size() , M = b.size() , N = c.size() ;
    vector<int> res ;
    while(ptr1 < K and ptr2 < M and ptr3 < N){
        int min_ele = min({a[ptr1] , b[ptr2] , c[ptr3]});
        
        if(a[ptr1] == b[ptr2] and b[ptr2] == c[ptr3]){
            res.push_back(a[ptr1]) ;
            ptr1++ ; ptr2++ ; ptr3++ ;
            while(ptr1 < K and 
                  ptr2 < M and 
                  ptr3 < N and
                  a[ptr1] == a[ptr1-1] and 
                  b[ptr2] == b[ptr2-1] and
                  c[ptr3] == c[ptr3-1]){
                ptr1++ ; ptr2++ ; ptr3++ ;
            }
        }
        else if(min_ele == a[ptr1]) ptr1++ ;
        else if(min_ele == b[ptr2]) ptr2++ ;
        else ptr3++ ;
    }
    return res ;
}
```

6. [subset sum equal k](https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
bool dp[1001][1001] ;

bool helper(int pos , int target ,vector<int> &arr){
    if(target == 0) return true ;
    if(target < 0 or pos < 0 or dp[pos][target] == false) 
        return false;
    
    if(helper(pos-1 , target-arr[pos] , arr)) return true ;
    
    return dp[pos][target] = helper(pos-1 , target , arr);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    memset(dp , true , sizeof(dp));
    return helper(n-1 , k , arr);
}
```

7. [factorial of large numbers](https://www.codingninjas.com/codestudio/problems/factorial-of-a-large-number_1115471?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
void mult(string &res , int num){
    int carry = 0 ;
    for(int i = 0 ; i < res.size() ; i++){
        int digit = num*(res[i]-'0') + carry ;
        res[i] = (digit%10)+'0' ;
        carry = digit/10 ;
    }
    while(carry){
        int digit = carry%10 ;
        res.push_back(digit+'0');
        carry = carry/10 ;
    }
}
string calculateFactorial(int n)
{
    string res = "1" ; 
    for(int x = 2 ; x <= n ; x++){
        mult(res , x);        
    }
    reverse(res.begin() , res.end());
    return res ;
}
```
8. [length Of Longest Consecutive Sequence](https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_759408?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3)
```cpp
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin() , arr.end());
    int left = 0 , right = 1 , maxlen = 1 , duplicates = 0;
    while(right < n){
        while(right < n){
            if(arr[right] == arr[right-1]){
                duplicates++ ;
            }
            else if(arr[right]-1 != arr[right-1])
                break ;
            right++ ;
        }
        maxlen = max(maxlen , right-left-duplicates) ;
        duplicates = 0 ;
        left = right ;
        right++ ;
    }
    return maxlen ;
}

// OPTIMAL
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int,int> memo , dp ;
    for(int ele : arr) memo[ele] = 1 ;
    int maxlen = 1 ;
    for(int ele : arr){
       if(memo.find(ele-1) != memo.end()) continue ;
       else{
           //I'm the starting point of my sequence
           int curr = ele+1 , count = 1 ;
           while(memo.find(curr) != memo.end()){
               curr++ ; count++ ;
           }
           maxlen = max(maxlen , count);
       }
    }
    return maxlen ;
}
```

9. [major element 3](https://www.codingninjas.com/codestudio/problems/elements-occur-more-than-n-k-times_1113146?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3)
```cpp
#include<bits/stdc++.h>
vector<int> countTheNumber(vector<int> &arr, int n, int k) {
    unordered_map<int,int> memo ;
    int req = n/k ;
    vector<int> res ;
    for(int ele : arr){
        memo[ele]++ ;
        if(memo[ele] == req)
            res.push_back(ele);
    }
    return res ;
}
```

10. [best time to buy and sell stock 3](https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

int dp[50001][3][2] ;

int helper(int pos , int transactions , bool canbuy ,vector<int> &prices){
    if(pos == prices.size() or transactions == 0) return 0 ;
    if(dp[pos][transactions][canbuy] != -1)
        return dp[pos][transactions][canbuy] ;
    
    if(canbuy){
        int op1 = -prices[pos] + helper(pos+1 , transactions , false , prices) ;
        int op2 = helper(pos+1 , transactions , true , prices);
        
        return  dp[pos][transactions][canbuy]=max(op1 , op2);
    }
    int op1 = prices[pos]+helper(pos+1 , transactions-1 , true , prices);
    
    int op2 = helper(pos+1 , transactions , false , prices);
    return dp[pos][transactions][canbuy]=max(op1 , op2);
}
int maxProfit(vector<int>& prices, int n)
{
    memset(dp , -1 ,sizeof(dp));
    return helper(0  , 2,true,prices) ;
}
```

11. [3 sum](https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int target) {
    vector<vector<int>> res ;
    sort(arr.begin() , arr.end());
    
    for(int i = 0 ; i < n ; i++){
        if(i != 0 and arr[i] == arr[i-1]) continue ;
        int j = i+1 , k = n-1 ;
        while(j < k){
            int currsum = arr[i]+arr[j]+arr[k] ;
            if(currsum > target){
                k-- ;                
            }
            else if(currsum < target){
                j++ ;
            }
            else{
                res.push_back({arr[i] , arr[j] , arr[k]});
                j++ ; k-- ;
                while(j < k and arr[j] == arr[j-1]) j++ ;
                while(k > j and arr[k] == arr[k+1]) k-- ;
            }
        }
    }
    return res ;
}
```

12. [min chocolates](https://www.codingninjas.com/codestudio/problems/chocolate-problem_893280?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3)
```cpp
int findMinDiff(int n, int m, vector<int> chocolates) {
    sort(chocolates.begin() , chocolates.end());
    int left = 0 , right = m-1 ;
    int mindiff = 1e9 ;
    while(right < n){
        mindiff = min(mindiff , chocolates[right]-chocolates[left]) ;
        left++ ; right++ ;
    }
    return mindiff ;
}
```

13. [minlen subarray sum](https://www.codingninjas.com/codestudio/problems/rahul-and-minimum-subarray_1551987?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
int minSubArrayLen(vector<int>& arr, int target, int n) {
    int minlen = 1e9 ;
    int left = 0 , right = 0 , cursum = 0 ;
    while(right < n){
        cursum += arr[right] ;
        while(cursum > target){
            minlen = min(minlen , right-left+1) ;
            cursum -= arr[left] ;
            left++ ;
        }
        right++ ;
    }
    return (minlen==1e9)?0:minlen ;
}
```
14. [3 way partition](https://www.codingninjas.com/codestudio/problems/three-way-partition_1170519?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> threeWayPartition(vector<int> &arr, int n, int a, int b)
{
    int ptr1 = 0 , ptr2 = 0 , ptr3 = n-1 ;
    while(ptr2 < ptr3){
        if(arr[ptr2] >= a and arr[ptr2] <= b){
            ptr2++ ;
        }
        else if(arr[ptr2] < a){
            swap(arr[ptr1] , arr[ptr2]);
            ptr1++ ;
            ptr2++ ;
        }
        else{
            swap(arr[ptr3] , arr[ptr2]) ;
            ptr3-- ;
        }
    }
    return arr ;
}
```

15. [minimum swaps](https://www.codingninjas.com/codestudio/problems/minimum-swaps-to-bring-all-elements-less-than-or-equal-to-k-together_1112657?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
int minimumSwaps(vector<int> &arr, int n, int k)
{
    int count = 0 , minswaps = 1e9 ;
    for(int ele : arr){
        if(ele <= k) count++ ;
    }
    int curwind = 0 ;
    int right = 0 , left = 0;
    while(right < count){
        if(arr[right] <= k){
            curwind++ ;
        }
        right++ ;
    }
    
    minswaps = min(minswaps , count-curwind);
    while(right < n){
        if(arr[right] <= k) curwind++ ;
        if(arr[left] <= k) curwind-- ;
        right++ ; left++ ;
        minswaps = min(minswaps , count-curwind);
    }
    return minswaps ;
}
```

16. [make it palindrome](https://www.codingninjas.com/codestudio/problems/make-it-palindrome_3189160?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
int palindrome(vector<int> &arr){
   int ans = 0 , n  = arr.size() ;
    long long int left = arr[0] , right = arr[n-1] ;
    
    for (int i=0,j=n-1; i<j;){
        if (left == right){
            i++;
            j--;
            left = arr[i] ; right = arr[j] ;
        }
        else if (left > right){
            right += arr[j-1] ;
            j--;
            ans++;
        }
        else{
            left += arr[i+1];
            i++;
            ans++;
        }
    }
    return ans;
}
```
17. [find medians of subarray](https://www.codingninjas.com/codestudio/problems/find-the-median-of-all-subarrays-of-a-particular-size_1229069?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<double> findMedian(vector<int> &arr, int n, int m)
{
    bool iseven = true ;
    if((m&1) == 1) iseven = false ;
    vector<double> res ;
    multiset<int> st ;
    int right = 0 , left = 0 ;
    while(right < m){
        st.insert(arr[right]) ; right++ ;
    }
    multiset<int>::iterator it = next(st.begin() , m/2);
    
    while(right <= n){
        if(iseven == true){
            auto prev_it = prev(it) ;
            res.push_back((double )(*it + *(prev_it) )/2) ;         
        }
        else{
            res.push_back(*it);            
        }
        if(right == n) break ;
        int add_it = arr[right++] ;
        int remove_it = arr[left++] ;
        
        if(add_it == *it){
            it = st.insert(it , add_it);
        }
        else{
            st.insert(add_it) ;
            if(add_it < *it){
                it-- ;
            }
        }
        if(remove_it == *it){
            it = st.erase(it);
        }
        else{
            st.erase(st.find(remove_it));
            if(remove_it < *it){
               it++ ;                
            }
        }
    }
    
    return res ;
}
```

18. [search in a row wise and column wise sorted matrix](https://www.codingninjas.com/codestudio/problems/search-in-a-row-wise-and-column-wise-sorted-matrix_839811?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int row = 0 , col = matrix[0].size()-1 ;
    while(row >= 0 and col >= 0 and row < matrix.size() and col < matrix[0].size()){
        if(matrix[row][col] == x) return {row , col} ;
        if(matrix[row][col] > x) col-- ;
        else row++ ;
    }
    return {-1,-1} ;
}
```

19. [row with max 1's](https://www.codingninjas.com/codestudio/problems/row-with-maximum-1-s_1112656?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
int binsearch(vector<int> &arr){
    int left = 0 , right = arr.size()-1 , mid ;
    if(arr[right] != 1) return 0 ;
    
    while(left < right){
        mid = left + (right-left)/2 ;
        if(arr[mid] < 1){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    return arr.size()-right ; 
}
int rowMaxOnes(vector<vector<int>>& mat, int n, int m) {
    int maxones = 0 , row = 0 ;
    
    for(int i = 0 ; i < n ; i++){
        int currones = binsearch(mat[i]);
        if(maxones < currones){
            maxones = currones ; row = i ;
        }
    }
    return row ;
}
```

20. [maximal Area Of SubMatrix Of All](https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int maxRectangle(vector<int> &arr){
    stack<pair<int,int>> st ;
    st.push({-1,0});
    int maxarea = 0 ;
    for(int i = 0 ; i < arr.size() ; i++){
        int idx = i ;
        while(not st.empty() and st.top().second >= arr[i]){
            pair<int,int> tt = st.top() ; st.pop() ;
            idx = tt.first ;
            maxarea = max(maxarea , tt.second*(i-idx));
        }
        st.push({idx , arr[i]});
    }
    int N = arr.size() ;
    while(not st.empty()){
        pair<int,int> tt = st.top() ; st.pop() ;
        maxarea = max(maxarea , tt.second*(N-tt.first));
    }
    return maxarea ;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j] == 1){
                mat[i][j] += mat[i-1][j] ; 
            }
        }
    }
    int maxarea = 0 ;
    for(int i = 0 ; i < n ; i++){
        maxarea = max(maxarea , maxRectangle(mat[i]));
    }
    return maxarea ;
}
```

21. [move all negative to begin](https://www.codingninjas.com/codestudio/problems/move-all-negative-numbers-to-beginning-and-positive-to-end_1112620?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
vector<int> separateNegativeAndPositive(vector<int> &nums){
    int ptr1 = 0 , ptr2 = 0 ;
    while(ptr2 < nums.size()){
        if(nums[ptr2] < 0){
            swap(nums[ptr1] , nums[ptr2]) ;
            ptr1++ ;
        }
        ptr2++ ;
    }
    return nums ;
}
```

22. [find similarities between array](https://www.codingninjas.com/codestudio/problems/find-similarities-between-two-arrays_1229070?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
    unordered_set<int> memo(arr1.begin() , arr1.end());
    int count = 0 ;
    for(int ele : arr2){
        if(memo.find(ele) != memo.end()) count++ ;
    }
    
    return {count , n+m-count} ;
}
```

23. [duplicate in array](https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
int findDuplicate(vector<int> &arr) 
{
    int total_xor = 0 , cur_xor = 0 ;
    for(int ele : arr) cur_xor = cur_xor ^ ele ;
    for(int i = 1 ; i < arr.size() ; i++) total_xor = total_xor^i ;
    
    return cur_xor^total_xor ;
}
```

24. [pair sum](https://www.codingninjas.com/codestudio/problems/rearrange-alternatively_873851?topList=love-babbar-dsa-sheet-problems)
```cpp
int pairSum(vector<int> &arr, int n, int target){
    int left_ptr = 0 , right_ptr = n-1 ;
    int count = 0 ;
    while(left_ptr < right_ptr){
        int cursum = arr[left_ptr] + arr[right_ptr] ;
        
        if(cursum == target){
            count++ ;
            left_ptr++ ; right_ptr-- ;
            while(left_ptr < right_ptr and arr[left_ptr] == arr[left_ptr-1]) left_ptr++ ;
            while(left_ptr < right_ptr and arr[right_ptr] == arr[right_ptr+1]) right_ptr-- ;
        }
        else if(cursum < target) left_ptr++ ;
        else right_ptr-- ;
    }
    return (count== 0)?-1:count  ;
}
```

25. [rearrange alternatively](https://www.codingninjas.com/codestudio/problems/rearrange-alternatively_873851?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp

void rearrange(vector<int> &arr)
{
    int ptr1 = 0 , ptr2 = 0 ;
    while(ptr2 < arr.size()){
        if(arr[ptr2] < 0){
            swap(arr[ptr2] , arr[ptr1]);
            ptr1++ ;
        }
        ptr2++ ;
    }
    // ptr1 points to the first non negative integer
    ptr2 = ptr1 ;
    ptr1 = 1 ;
    while(ptr2 < arr.size() and arr[ptr1] < 0 and ptr1 < ptr2){
        swap(arr[ptr1] , arr[ptr2]);
        ptr1 += 2 ;
        ptr2++ ;
    }
}
```

26. [is subset](https://www.codingninjas.com/codestudio/problems/check-subset_762948?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3)
```cpp
#include<bits/stdc++.h>
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
    unordered_map<int,int> memo ;
    for(int ele : arr1) memo[ele]++ ;
    for(int ele : arr2){
        if(memo.find(ele) == memo.end()) return false ;
        memo[ele]-- ;
        if(memo[ele] == 0) memo.erase(ele) ;
    }
    return true ;
}
```

27. [sorted matrix](https://www.codingninjas.com/codestudio/problems/sorted-matrix_758931?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> sortedMatrix(vector<vector<int>> &mat, int n) {
    priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq ;
    for(int i = 0 ; i < n ; i++){
        pq.push({mat[i][0] , i , 0});
    }
    vector<int> res ;
    vector<int> curr ;
    while(not pq.empty()){
        curr = pq.top() ; pq.pop() ;
        res.push_back(curr[0]) ;
        if(curr[2]+1 < n){
            int row = curr[1] ;
            int col = curr[2]+1 ; 
            pq.push({mat[row][col], row , col});
        }
    }
    
    return res ;
}
```

28. [specific pair in matrix](https://www.codingninjas.com/codestudio/problems/find-a-specific-pair-in-the-matrix_1115467?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
int findMaxValue(vector<vector<int>>& mat, int n) {
    int maxans = -1e9 ;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            int min_ele = mat[i][j] ;
            for(int row = i+1 ; row < n ; row++){
                for(int col = j+1 ; col < n ; col++){
                    maxans = max(maxans , mat[row][col] - min_ele);
                }
            }
        }
    }
    return maxans ;
}
#include<bits/stdc++.h>
int N ;
int dp[101][101] ;

int helper(int row , int col , vector<vector<int>> &mat){
    if(row >= N or col >= N) return -1e9 ;
    if(dp[row][col] != -1) return dp[row][col] ;
    
    int curmax = -1e9 ;
    for(int i = row ; i < N ; i++){
        curmax = max(curmax , mat[i][col]) ;
    }
    for(int j = col ; j < N ; j++){
        curmax = max(curmax , mat[row][j]);
    }
    return dp[row][col] = max(curmax , helper(row+1 , col+1 , mat));
}
int findMaxValue(vector<vector<int>>& mat, int n) {
    int maxans = -1e9 ;
    memset(dp , -1 , sizeof(dp));
    N = n ;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            maxans = max(maxans , helper(i+1 , j+1 , mat)-mat[i][j]);
        }
    }
    return maxans ;
}
```

29. [rotate anticlockwise](https://www.codingninjas.com/codestudio/problems/inplace-rotate-matrix-90-degree_839734?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
void inplaceRotate(vector<vector<int>> &arr)
{
    /*
        clockwise --> transpose -- reverse rows
        Anticlockwise --> reverse rows --- transpose
    */
    for(vector<int> &vec : arr) reverse(vec.begin(),vec.end());
    
    // transpose
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = i+1 ; j < arr.size() ; j++){
            swap(arr[i][j] , arr[j][i]) ;
        }
    }
}
```

30. [K min floor]()
```cpp
#include<bits/stdc++.h>
int kMinFloor(vector<vector<int>> &arr, int n, int k) {
    priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq ;
    for(int i = 0 ; i < n ; i++){
        pq.push({arr[i][0] , i , 0});
    }
    vector<int> curr ;
    while(k--){
        curr = pq.top() ; pq.pop() ;
        if(curr[2]+1 < n){
            pq.push({arr[curr[1]][curr[2]+1] , curr[1] , curr[2]+1}) ;
        }
    }
    return curr[0] ;
}
```
31. [find common elements](https://www.codingninjas.com/codestudio/problems/common-elements-present-in-all-rows-of-a-matrix_1118111?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1)
```cpp
#include<bits/stdc++.h>
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_set<int> prev(mat[0].begin() , mat[0].end());
    for(int i = 1 ; i < mat.size() ; i++){
        unordered_set<int> curr ;
        for(int j = 0 ; j < mat[0].size() ; j++){
            if(prev.find(mat[i][j]) != prev.end()){
                curr.insert(mat[i][j]);
            }
        }
        
        if(curr.size() == 0) return {} ;
        prev = curr ;
    }
    return vector<int>(prev.begin() , prev.end());
}
```

32. [is palindrome](https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

bool isUpper(int ch){
    return ch >= 65 and ch <= 90 ;
}
bool isLower(int ch){
    return ch >= 97 and ch <= 122 ;
}
char toLower(char ch){
    if(isUpper(ch))
        return ch+32 ;
    return ch ;
}
bool isdigit(char ch){
    return ch >= '0' and  ch <= '9' ;
}
bool checkPalindrome(string s){
    int left = 0 , right = s.size()-1 ;
    while(left < right){
         if(not isUpper(s[left]) and not isLower(s[left]) and not isdigit(s[left])){
             left++ ; continue ;
         }   
         if(not isLower(s[right]) and not isUpper(s[right]) and not isdigit(s[right])){
             right-- ; continue ;
         }         
         char ch1 = s[left] , ch2 = s[right] ;
        
         if(toLower(ch1) != toLower(ch2)) return false ;
         left++ ; right-- ;
    }    
    return true ;
}
```

33. [duplicate characters](https://www.codingninjas.com/codestudio/problems/duplicate-characters_3189116?topList=love-babbar-dsa-sheet-problems)
```cpp
vector<pair<char,int>> duplicate_char(string s, int n){
    vector<pair<char,int>> res ;
    int memo[256] = {0} ;
    
    for(char ch : s) memo[ch]++ ;
    for(int i = 0 ; i < 256 ; i++){
        if(memo[i] > 1){
            res.push_back({i , memo[i]});
        }
    }
    return res ;
}
```

34. [is rotation of string](https://www.codingninjas.com/codestudio/problems/check-if-one-string-is-a-rotation-of-another-string_1115683?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
void gen_lps(string &str , vector<int> table){
    int left = 0 , ptr = 1 ;
    while(ptr < str.size()){
        if(str[ptr] == str[left]){
            left++ ;
            table[ptr] = left ;
            ptr++ ;
        }
        else{
            if(left != 0){
                left = table[left-1] ;
            }
            else{
                ptr++ ;
            }
        }
    }
}
int kmp(string &str , string &pattern){
    vector<int> table(pattern.size() , 0);
    gen_lps(pattern , table);
    int left = 0 , ptr = 0 ;
    while(ptr < str.size()){
        if(str[ptr] == pattern[left]){
            left++ ; ptr++ ;
            if(left == pattern.size()) return 1 ;
        }
        else{
            if(left != 0) left = table[left-1];
            else ptr++ ;
        }
    }
    return 0 ;
}
int isCyclicRotation(string &p, string &q) 
{
    p = p+p ;
    return kmp(p , q);
}
```

35. [shuffle two strings]()
```cpp
string str1 , str2 , target ; 
int N1 , N2 , N3;

bool helper(int pos1 , int pos2 ,int pos3){
    if(pos3 == N3) return true ;
    
    if(pos1 < N1 and pos2 < N2 and str1[pos1] == target[pos3] and str2[pos2] == target[pos3]){
        return helper(pos1+1 , pos2 , pos3+1) or helper(pos1 , pos2+1 , pos3+1);
    }
    if(pos1 < N1 and str1[pos1] == target[pos3]){
        return helper(pos1+1 , pos2 , pos3+1);
    }
    if(pos2 < N2 and str2[pos2] == target[pos3]){
        return helper(pos1 , pos2+1 , pos3+1);
    }
    return false ;
}
bool isInterleave(string &a, string &b, string &c){
    N1 = a.size() ; N2 = b.size() ;
    N3  = c.size() ;
    if(N1+N2 != N3) return false ;
    str1 = a ; str2 = b ; target = c ;
        
    return helper(0,0,0) ;
}
```