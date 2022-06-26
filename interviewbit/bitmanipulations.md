# BIT MANIPULATIONS

### Bit Play

1. [numberof set bits](https://www.interviewbit.com/problems/number-of-1-bits/)
```cpp
int Solution::numSetBits(unsigned int A) {
    int count = 0 ;
    int isbitset = 0 ;
    
    while(A != 0){
        isbitset = A & 1 ;
        if(isbitset) count++ ;
        A = A >> 1 ;   
    }
    return count ;
}
```

2. [trailing zeros](https://www.interviewbit.com/problems/trailing-zeroes/)
```cpp
int Solution::solve(int A) {
    int count = 0 ;
    int isbitset ;
     
    while(A != 0){
        isbitset = A & 1 ;
        if(isbitset) break ;
        count++ ;
        A = A >> 1 ;    
    }
    return count ;
}
```

3. [reverse-bits](https://www.interviewbit.com/problems/reverse-bits/hints/)
```cpp
unsigned int Solution::reverse(unsigned int A) {
    bitset<32> bt(A);
    string str = bt.to_string() ;
    for(int i  = 31 , j = 0 ; i > j ; i-- , j++){
        swap(str[i] , str[j]);
    }
    
    bitset<32> bt1(str);
    return bt1.to_ulong() ;
}
// 2nd approach

unsigned int Solution::reverse(unsigned int A) {
    int idx = 0 ;
    int isbitset ;
    unsigned int res = 0 ;
    
    while(A != 0){
        isbitset = (A&1);
        
        if(isbitset){
            res = res | (1 << (31-idx)) ;
        }
        A = (A >> 1) ;
        idx++ ;
    }
    return res ;
}
```

4.  [different-bits-sumwise-pair](https://www.interviewbit.com/problems/different-bits-sum-pairwise/)
```cpp
int mod = 1e9+7 ;

int Solution::cntBits(vector<int> &A) {
        long sum = 0 ;
        
    for(int i = 0 ; i < 32 ; i++){
        long ones_count = 0 , zeros_count = 0 ;
        int mask = (1 << i) ;
        int N = A.size() ;

        for(int j = 0 ; j < A.size() ; j++){
             
             if((A[j] & mask) != 0){
                 ones_count++ ;
             }
        }
        sum = (sum + (ones_count*(N-ones_count))%mod)%mod ;
    }
    
    return (2*sum)%mod  ;
}
```

### bit array

1. [single-numer-1](https://www.interviewbit.com/problems/single-number/)
```cpp
int Solution::singleNumber(const vector<int> &A) {
    int xor_value = 0 ;
    
    for(int ele : A){
        xor_value = xor_value ^ ele ;
    }
    return xor_value ;
}
```

2. [single number 2](https://www.interviewbit.com/problems/single-number-ii/)
```cpp
int Solution::singleNumber(const vector<int> &A) {
    // counting the bits ;
    // set bit for idx should be multiple of 3 otherwise the single element bit had occured
    int res = 0 ; 
    for(int i=0;i<32;i++){
        int count = 0 ;
        int mask = (1<<i);
        
        for(int j=0;j<A.size();j++){
            if(A[j]&mask) count++;
        }
        if(count%3 != 0){
            res = res | mask ;
        }
    }
    
    return res ;
}
```

### Bit tricks

1. [min-xor-value]()
```cpp
int Solution::findMinXor(vector<int> &A) {
    int minvalue = INT_MAX ;
    sort(A.begin() , A.end());
    
    for(int i = 0 ; i < A.size()-1 ; i++){
        minvalue = min(minvalue , A[i]^A[i+1]);
    }
    
    return minvalue ;
}
```

3. [palindromic-bin-repr](https://www.interviewbit.com/problems/palindromic-binary-representation/)
```cpp
#include<bits/stdc++.h>

int Solution::solve(int A) {
    if(A == 1) return 1 ;
    
    queue<string> q ;
    q.push("11");
    
    string curr ;
    A-- ;
    string temp1 , temp2 ;
    
    while(A--){
        curr = q.front() ; q.pop() ;
        int mid = curr.size()/2 ;
        if(curr.size()&1 == 1){
            //odd size so find the middle and insert the middle character
            string tt(1 , curr[mid]);
            temp1 = curr ;
            temp1.insert(mid , tt); 
            q.push(temp1);
        }
        else{
            temp1 = curr ; temp2 = curr ;
            temp1.insert(mid , "0");
            temp2.insert(mid , "1");
            q.push(temp1);
            q.push(temp2);
        }
    }
    bitset<32> bt(curr);
    
    return (int )bt.to_ulong() ;
}

```

4. [xoring-subarrays](https://www.interviewbit.com/problems/xor-ing-the-subarrays/)
```cpp
int Solution::solve(vector<int> &A) {
    if(A.size() == 1) return A[0] ;
    int N = A.size() ;
    
    if(N&1 == 0) return 0 ;
    
    int xor_val = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        int freq = (i+1)*(N-i);
        if(freq&1 == 1){
            xor_val = xor_val ^ A[i];
        }    
    }
    return xor_val ;
}
```

