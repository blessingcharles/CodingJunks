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

### Medium Greedy

1. [minimum-rooms](https://www.interviewbit.com/problems/meeting-rooms/)
```cpp

// Method 1
int Solution::solve(vector<vector<int> > &A) {
    int minrooms = 1 ;
    int current_req = 1 ;
    
    sort(A.begin() , A.end());
    
    priority_queue<int , vector<int> , greater<int>> pq ;
    pq.push(A[0][1]);
    
    for(int i = 1 ; i < A.size() ; i++){
        // check the most early finishing meeting finishes before current meeting
        
        while(not pq.empty() and pq.top() <= A[i][0]){
            pq.pop() ;
            current_req-- ;
        }
        current_req++ ;
        minrooms = max(current_req , minrooms) ;
        pq.push(A[i][1]);
    }
    return minrooms ;
}

// Method 2

int Solution::solve(vector<vector<int> > &A) {
    int minrooms = 0 ;
    int current_req = 0 ;
    int N = A.size() ;
    
    vector<int> start_time(N) , end_time(N);
    
    for(int i = 0 ; i < N ; i++){
        start_time[i] = A[i][0] ;
        end_time[i] = A[i][1] ;
    }
    
    sort(start_time.begin() , start_time.end());
    sort(end_time.begin() , end_time.end());
    
    int s_idx = 0 , e_idx = 0 ; 
    
    while(s_idx < N){
        if(start_time[s_idx] < end_time[e_idx]){
            current_req++ ;
            s_idx++ ;
        }
        else{
            current_req-- ;
            e_idx++ ;
        }
        minrooms = max(minrooms , current_req);
    }
    return minrooms ;
}
```

2. [distribute-candies](https://www.interviewbit.com/problems/distribute-candy/)
```cpp
int Solution::candy(vector<int> &A) {
    int N = A.size() ;
    
    vector<int> candies(N , 1);
    
    for(int i = 1 ; i < A.size() ; i++){
        if(A[i] > A[i-1] and candies[i] <= candies[i-1]){
            candies[i] = candies[i-1]+1 ;
        }
    }
    int cursum = candies[N-1] ;
    
    for(int i = N-2 ; i >= 0 ; i--){
        if(A[i] > A[i+1] and candies[i] <= candies[i+1]){
            candies[i] = 1+candies[i+1];       
        }
        cursum += candies[i] ;
    }
    
    return cursum ;
}
```

3. [seats](https://www.interviewbit.com/problems/seats/)
```cpp
int Solution::seats(string A) {
    // find the largest group 
    int N = A.size();
    vector<int> groups;
    long swaps_count = 0 ;
    int count = 0 ;
    
    // calculate for moving all x to start 
    for(int i = 0 ; i < N ; i++){
        if(A[i] == 'x'){
            groups.push_back(i - count);
            count++ ;
        }
    }
    int mod = 10000003 ;
    if(count == 0 or count == N) return 0 ;
    
    // min moves to make all together is moving all with median as the start
    int mid = (groups.size()-1)/2 ;
    int median = groups[mid] ;
    
    for(int i = 0 ; i < count ; i++){
        swaps_count = (swaps_count + abs(median - groups[i]))%mod ;
    }
    
    return swaps_count ;
}
```

4. [Assign mice to holes](https://www.interviewbit.com/problems/assign-mice-to-holes/)
```cpp
int Solution::mice(vector<int> &A, vector<int> &B) {
    int mintime = -1 ;
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());
    
    for(int i = 0 ; i < A.size() ; i++){
        mintime = max(mintime , abs(A[i] - B[i]));
    }
    return mintime ;
}
```

5. [majority-element](https://www.interviewbit.com/problems/majority-element/)
```cpp
// we can also use moore voting algorithm
int Solution::majorityElement(const vector<int> &A) {
    unordered_map<int,int> memo ;
    int N = A.size() ;
    for(int ele : A){
        memo[ele]++ ;
        if(memo[ele] > N/2){
            return ele ;
        }
    }
    return -1 ;
}
```

6. [gas stations](https://www.interviewbit.com/problems/gas-station/)
```cpp
#include<bits/stdc++.h>

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int total_gas = accumulate(A.begin() , A.end() , 0);
    int total_cost = accumulate(B.begin() , B.end() , 0);
    
    if( (total_gas - total_cost) < 0) return -1 ;
    
    // if at a particular station if gas becomes negative previous all starting points
    // are invalidate
    int gas_rem = 0 ;
    int starting_point = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        gas_rem = gas_rem + A[i] - B[i] ;
        
        if(gas_rem < 0){
            starting_point = i+1 ;
            gas_rem = 0 ;        
        }    
    }
    
    return starting_point ;
}
```