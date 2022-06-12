### Practise 

1. [max-non-neg-subarray](https://www.interviewbit.com/problems/max-non-negative-subarray/)
```cpp
vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans ;
    vector<int> temp ;
    
    long long maxsum = 0 ;
    long long cursum = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] < 0){
            cursum = 0 ;
            temp = {} ;
        }     
        else if(A[i] >= 0){
            temp.push_back(A[i]);
            cursum += A[i] ;
            
            if(cursum > maxsum){
                ans = temp ;
                maxsum = cursum ;
            }
            else if(cursum == maxsum and temp.size() > ans.size()){
                ans = temp ;
                maxsum = cursum ;
            }
        }
    }
    
    return ans ;
}
```

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

8. [flip-bits](https://www.interviewbit.com/problems/flip/)
```cpp
vector<int> Solution::flip(string str) {
        int left_ptr = -1 , right_ptr = -1 ;
        vector<int> memo(str.size()+1 , 0);
        int ltemp = 0 , count = 0 , maxlen = 0 ;
        
        bool flag = true ;
        
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '0'){
                count++ ;
            }
            else{
                count-- ;
            }
            if(count < 0){
                ltemp = i+1 ;    
                count = 0 ;
            }
            else if(count > maxlen){ 
                flag = false ;
                right_ptr = i ;
                left_ptr = ltemp ;
                maxlen = count ;
            }
        }
        
        if(flag){
            return {} ;
        }
        
        return {left_ptr+1 , right_ptr+1} ;
}
```

### value ranges

1. [max-min](https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/)
```cpp
int Solution::solve(vector<int> &A) {
    int max_ele = A[0] , min_ele = A[0] ;
    
    for(int i = 1 ; i < A.size() ; i++){
        max_ele = max(max_ele , A[i]);
        min_ele = min(min_ele , A[i]);
    }
    return max_ele + min_ele ;
}
```

2. [merge-intervals](https://www.interviewbit.com/problems/merge-intervals/)
```cpp
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res ;
    intervals.push_back(newInterval);
    
    sort(intervals.begin() , intervals.end() , [](const Interval &a , const Interval &b){
        return a.start <= b.start ; 
    });
    
    res.push_back(intervals[0]);
    int ptr = 0 ;
    
    for(int i = 1 ; i < intervals.size() ; i++){
        if(res[ptr].end >= intervals[i].start){
            if(res[ptr].end < intervals[i].end){
                res[ptr].end = intervals[i].end ;
            }
        }   
        else{
            res.push_back(intervals[i]);
            ptr++ ;
        } 
    }
    
    return res ;
}
```

3. [sort-array](https://www.interviewbit.com/problems/sort-array-with-squares/)
```cpp
vector<int> Solution::solve(vector<int> &A) {
    int N = A.size();
    vector<int> res(N);
    int left = 0 , right = N-1 ;
    
    int res_ptr1 = N-1 ; 
    
    while(left <= right){
        if(abs(A[left]) > abs(A[right])){
            res[res_ptr1] = A[left]*A[left] ;
            left++ ;
        }
        else{
            res[res_ptr1] = A[right]*A[right] ;
            right-- ;
        }
        res_ptr1-- ;
    }
    
    return res ;
}
```

4. [largest-number](https://www.interviewbit.com/problems/largest-number/)
```cpp
string Solution::largestNumber(const vector<int> &A) {
    vector<string> temp ;
    bool flag = true ;
    for(int ele : A){
        if(ele != 0){
            flag = false ;
        }
        temp.push_back(to_string(ele));
    }
    if(flag){
        return "0" ;
    }
    sort(temp.begin(), temp.end(), [](const string &a , const string &b){
        string t = a + b ;
        string tt = b + a ;

        return t > tt ;
    });
    
    string res = "";
    for(string &st : temp){
        res += st ;
    }
    return res ;
}
```

5. [rotate-clockwise](https://www.interviewbit.com/problems/rotate-matrix/)
```cpp
void Solution::rotate(vector<vector<int> > &A) {
    reverse(A.begin() , A.end());
    
    int N = A.size() ;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = i+1 ; j < N ; j++){
            swap(A[i][j] , A[j][i]);
        }
    }
    
}
```

6. [next-permutation](https://www.interviewbit.com/problems/next-permutation/)
```cpp
vector<int> Solution::nextPermutation(vector<int> &A) {
    int before_peak = 0 ;
    int N = A.size() ;
    for(int i = N-2 ; i >= 0 ; i--){
        if(A[i] < A[i+1]){
            // i+1 is peak
            before_peak = i;
            break ;
        }
    }
    
    for(int i = N-1 ; i > before_peak ; i--){
        if(A[before_peak] < A[i]){
            swap(A[before_peak] , A[i]);
            before_peak++ ;
            break ;
        }   
    }
    
    reverse(A.begin()+before_peak , A.end());
    return A ;
}
```

7. [find-permutation](https://www.interviewbit.com/problems/find-permutation/)
```cpp
vector<int> Solution::findPerm(const string A, int B) {
    vector<int> arr(B);
    int l = 1 , r = B ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == 'I'){
            arr[i] = l ;
            l++ ;
        }    
        else{
            arr[i] = r ;
            r-- ;
        }
    }
    arr[B-1] = l ;
    
    return arr ;
}
```

### Sorting

1. [Noble integer](https://www.interviewbit.com/problems/noble-integer/)
```cpp
int Solution::solve(vector<int> &A) {
    sort(A.begin() , A.end());
    int N = A.size() ;
    for(int i = 0 ; i < N ; i++){
        while(i < N-1 and A[i] == A[i+1]){
            i++ ;
        }
        
        if(A[i] == N-i-1){
            return 1 ;
        }
    }
    return -1 ;
}
```

2. [wave-array](https://www.interviewbit.com/problems/wave-array/)
```cpp
vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin() , A.end());
    int l = 0 , r = 1;
    vector<int> res(A.size());
    int idx = 0 ;
    int N = A.size() ;
    
    while(l < N){
        if(r < N and idx%2 == 0){
            res[idx] = A[r];
            r += 2 ;
        }   
        else{
            res[idx] = A[l];
            l += 2 ;
        } 
        idx++ ;
    }
    
    return res ;
}
```

3. [hotel-booking-available](https://www.interviewbit.com/problems/hotel-bookings-possible/)
```cpp
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin() , arrive.end());
    sort(depart.begin() , depart.end());
    
    int N = arrive.size() ;
    int ptr1 = 0 , ptr2 = 0 ;
    int req_rooms = 0;
    
    
    while(ptr1 < N and ptr2 < N){
        if(arrive[ptr1] <= depart[ptr2]){
            req_rooms++ ;
            ptr1++ ;
            
            if(req_rooms > K){
                return false ;
            }
        }
        else{
            ptr2++ ;
            req_rooms-- ;
        }
    }
    return true ;
}
```

4. [max-dist](https://www.interviewbit.com/problems/max-distance/)
```cpp
int Solution::maximumGap(const vector<int> &A) {
    int N = A.size() ;
    vector<pair<int,int>> memo(N) ;
    
    for(int i = 0 ; i < N ; i++){
        memo[i] = {A[i] , i}; 
    }
    sort(memo.begin() , memo.end());
    
    vector<int> precalc(N);
    precalc[N-1] = memo[N-1].second ;
    
    for(int i = N-2 ; i >= 0 ; i--){
        precalc[i] = max(memo[i].second , precalc[i+1]);
    }
    
    int maxdist = 0 ;
    for(int i = 0 ; i < N-1 ; i++){
        maxdist = max(maxdist ,precalc[i+1] - memo[i].second) ;
    }
    
    return maxdist ;
}
```

5. [maxx-unsorted-subarray](https://www.interviewbit.com/problems/maximum-unsorted-subarray/)
```cpp

vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> arr = A ;
    
    sort(arr.begin() , arr.end());
        
    int N = A.size() ;
    int left_ptr = 0 , right_ptr = N-1 ;
    
    int idx ;
    
    while(left_ptr < N and A[left_ptr] == arr[left_ptr]){
        left_ptr++ ;
    }
    if(left_ptr == N){
        return {-1} ;
    }
    while(A[right_ptr] == arr[right_ptr]){
        right_ptr-- ;
    }
    
    return {left_ptr , right_ptr};
}
```

### Simulation Array

1. [perfect-peak-arr](https://www.interviewbit.com/problems/perfect-peak-of-array/)

```cpp
int Solution::perfectPeak(vector<int> &A) {
    int N = A.size() ;
    
    vector<int> prefix(N) ; // stores previous larger elements
    vector<int> suffix(N) ; // contains smaller future elements
    
    prefix[0] = INT_MIN ;
    suffix[N-1] = INT_MAX ;
    for(int i = 1 , j = N-2 ; i < N ; i++ , j--){
        prefix[i] = max(A[i-1] , prefix[i-1]);
        suffix[j] = min(A[j+1] , suffix[j+1]);
    } 
    for(int i = 1 ; i < N-1 ; i++){
        if(A[i] > prefix[i] and A[i] < suffix[i]){
            return 1 ;
        }
    }
    return 0 ;
}
```
2. [kth-row-pascal](https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/)
```cpp
vector<int> Solution::getRow(int A) {
    vector<vector<int>> memo(A+1) ;
    memo[0] = {1} ;
    for(int i = 1 ; i <= A ; i++){
        vector<int> temp ;
        temp.push_back(1);
        for(int j = 1 ; j < i ; j++){
            temp.push_back(memo[i-1][j] + memo[i-1][j-1]);
        }
        temp.push_back(1);
        memo[i] = temp ;
    }
    return memo[A] ;
}
```

3. [spiral-order-matrix](https://www.interviewbit.com/problems/spiral-order-matrix-ii/)
```cpp
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> matrix(A , vector<int>(A));
    int cur_val = 1 ;
    int rowBegin = 0 , rowEnd = A-1 ;
    int colBegin = 0 , colEnd = A-1 ;
    
    while(rowBegin <= rowEnd and colBegin <= colEnd){
        // traverse colBegin to colEnd on rowBegin
        for(int i = colBegin ; i <= colEnd ; i++){
            matrix[rowBegin][i] = cur_val ;
            cur_val++ ;
        }    
        rowBegin++ ;
        
        // traverse rowBegin to rowEnd on colEnd
        for(int i = rowBegin ; i <= rowEnd ; i++){
            matrix[i][colEnd] = cur_val ;
            cur_val++ ;
        }
        colEnd-- ;
        
        // traverse colEnd to colBegin on rowEnd 
        if(rowEnd >= rowBegin){
            for(int i = colEnd ; i >= colBegin ; i--){
                matrix[rowEnd][i] = cur_val ;
                cur_val++ ;
            }
        }
        rowEnd-- ;
        // traverse rowEnd to rowBegin on colBegin
        if(colBegin <= colEnd){
            for(int i = rowEnd; i >= rowBegin ; i--){
                matrix[i][colBegin] = cur_val ;
                cur_val++ ;
            }
        }
        colBegin++ ;
    }
    
    return matrix ;
}
```
4. pascals-traingle : already done

5. [anti-diagonals](https://www.interviewbit.com/problems/anti-diagonals/)
```cpp
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    N = A.size() ;
    
    vector<vector<int>> res((N*2)-1);
    int idx = 0 ;
    
    int cur_row , cur_col ;
    // traverse the top row
    for(int col = 0 ; col < N ; col++){
        cur_row = 0 ;
        cur_col = col ;
        vector<int> temp ;        
        while(not isInValid(cur_row , cur_col)){
            temp.push_back(A[cur_row][cur_col]);
            cur_row += 1 ;
            cur_col -= 1 ;        
        }
        res[idx++] = temp ;
    }
    
    // traverse the last col
    for(int row = 1 ; row < N ; row++){
        cur_row = row ;
        cur_col = N-1 ;
        vector<int> temp ;
        while(not isInValid(cur_row , cur_col)){
            temp.push_back(A[cur_row][cur_col]);
            cur_row += 1 ;
            cur_col -= 1 ;  
        }        
        res[idx++] = temp ;
    }
    
    return res ;
}
```

### Arrays bucketing

1. [triplets-range](https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/)
```cpp
int Solution::solve(vector<string> &A) {
    int left = 0 , right = A.size()-1 , mid ;
    sort(A.begin() , A.end());
    while(right-left >= 2){
        mid = left + (right-left)/2 ;
        double sum = stof(A[left]) + stof(A[mid]) + stof(A[right]) ;
        if(sum >= 2){
            right-- ;
        }
        else if(sum <= 1){
            left++ ;
        }
        else{
            return 1 ;
        }
    }
    return 0 ; 
}
```

2. [balance-array](https://www.interviewbit.com/problems/balance-array/)
```cpp
int Solution::solve(vector<int> &A) {
    int N = A.size() ;
    vector<int> even_sum(N , 0);
    vector<int> odd_sum(N,0);
    
    even_sum[0] = A[0] ;
    
    for(int i = 1 ; i < N ; i++){
        if(i%2 == 0){
            even_sum[i] = A[i] + even_sum[i-1];
            odd_sum[i] = odd_sum[i-1];
        }
        else{
            odd_sum[i] = A[i] + odd_sum[i-1] ;
            even_sum[i] = even_sum[i-1] ;
        }
    }
    
    int count = 0 , e_sum , o_sum ;
    for(int i = 0 ; i < N ; i++){
        int prev_odd_sum = 0 , prev_even_sum = 0 ;
        if(i%2 == 0){
            
            if(i-1 >= 0){
                prev_odd_sum = odd_sum[i-1];
            }
            if(i-2 >= 0){
                prev_even_sum = even_sum[i-2] ;
            }
            // adding the next even sum 
            e_sum = prev_even_sum + odd_sum[N-1] - odd_sum[i] ;
            o_sum = prev_odd_sum + even_sum[N-1] - even_sum[i] ;

        }
        else{
            if(i-1 >= 0){
                prev_even_sum = even_sum[i-1];
            }
            if(i-2 >= 0){
                prev_odd_sum = odd_sum[i-2] ;
            }
            
            e_sum = prev_even_sum + odd_sum[N-1] - odd_sum[i];
            o_sum = prev_odd_sum + even_sum[N-1] - even_sum[i] ;    
        }
        if(e_sum == o_sum){
                count++ ;
        }
    }
    return count ;
}
``` 

3. [duplicate-in-arr](https://www.interviewbit.com/problems/find-duplicate-in-array/)
```cpp
int Solution::repeatedNumber(const vector<int> &A) {
    //* floyd cycle detection
    
    int slow = A[0] , fast = A[0] ; 
    
    do{
        slow = A[slow] ;
        fast = A[A[fast]];
    }while(slow != fast);
    
    fast = A[0] ;
    // set the fast to the begining
    while(slow != fast){
        slow = A[slow] ;
        fast = A[fast] ;
    }
    return slow ;
}
```


### Space Recycle

1. [set matrix zero](https://www.interviewbit.com/problems/set-matrix-zeros/)
```cpp
void Solution::setZeroes(vector<vector<int> > &A) {
    bool isCol0 = false ;
    int M = A.size() , N = A[0].size() ;
    
    for(int i = 0 ; i < M ; i++){
        if(A[i][0] == 0){
            isCol0 = true ;
        }
        for(int j = 0 ; j < N ; j++){
            if(A[i][j] == 0){
                A[i][0] = 0 ;
                if(j != 0)
                    A[0][j] = 0 ;
            }
        }
    }
    
    for(int i = M-1 ; i >= 0 ; i--){
        for(int j = N-1 ; j > 0 ; j--){
            if(A[i][0] == 0 or A[0][j] == 0){
                A[i][j] = 0 ;
            }
        }
        if(isCol0){
            A[i][0] = 0 ;
        }
    }
}
```

2. [first-missing-positve](https://www.interviewbit.com/problems/first-missing-integer/)
```cpp

int Solution::firstMissingPositive(vector<int> &A) {
    N = A.size() ;
    /*
        The answer must be in the rangle og 1..N+1
        
        1. Make all negatives 0
        2. take abs(A[i]) and then map it to A[A[i]-1] , mark that place negative
    */
    
    // make all negatives zero
    for(int i = 0 ; i < N ; i++){
        if(A[i] < 0){
            A[i] = 0 ;
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        int cur_idx = abs(A[i])-1 ;
        if(isInvalid(cur_idx)){
            continue ;
        }
        if(A[cur_idx] == 0){
            A[cur_idx] = -(cur_idx+1) ;
        }        
        else if(A[cur_idx] != -(cur_idx+1)){
            A[cur_idx] = A[cur_idx]*-1 ;
        }
    }
}
```

3. [matrix-sum-square-sub](https://www.interviewbit.com/problems/maximum-sum-square-submatrix/)
```cpp

int Solution::solve(vector<vector<int> > &A, int B) {
    // initiate 0 th row and 0th col
    N = A.size() ;
    for(int i = 1 ; i < N ; i++){
        A[i][0] += A[i-1][0] ;
        A[0][i] += A[0][i-1] ;
    }
    
    for(int row = 1 ; row < N ; row++){
        for(int col = 1 ; col < N ; col++){
            A[row][col] = A[row][col] + A[row-1][col] + A[row][col-1] - A[row-1][col-1] ;
        }
    }
    int maxsum = INT_MIN ;
    for(int row = B-1 ; row < N ; row++){
        for(int col = B-1 ; col < N ; col++){
            bool flag1 = isValid(row-B);
            bool flag2 = isValid(col-B);
            int suber = 0 ;
            if(flag1 and flag2){
                suber += A[row-B][col-B]; 
            }        
            if(flag1){
                suber -= A[row-B][col] ;
            }
            if(flag2){
                suber -= A[row][col-B] ;
            }
            
            maxsum = max(maxsum , A[row][col] + suber) ;
        }
    }
    
    return maxsum ;
}
```

### Missing / repeated number

3. [N/3 repeated](https://www.interviewbit.com/problems/n3-repeat-number/)
```cpp
int Solution::repeatedNumber(const vector<int> &A) {
    // Boyer Moore Voting algorithm
    
    int candidate1 = 0 , candidate2 = 0 , count1 = 0 , count2 = 0;
    int N = A.size() ;
    
    for(int i = 0 ; i < N ; i++){
        if(A[i] == candidate1){
            count1++ ;
        }
        else if(A[i] == candidate2){
            count2++ ;
        }
        else if(count1 == 0){
            candidate1 = A[i] ;
            count1 = 1 ;
        }
        else if(count2 == 0){
            candidate2 = A[i] ;
            count2 = 1 ;
        }
        else{
            count1-- ;
            count2-- ;
        }
    }
    
    count1 = 0 ; count2 = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        if(A[i] == candidate1){
            count1++ ;
            if(count1 > N/3){
                return candidate1 ;
            }
        }
        else if(A[i] == candidate2){
            count2++ ;
            if(count2 > N/3){
                return candidate2 ;
            }
        }
        
    }
    return -1 ;
}
```