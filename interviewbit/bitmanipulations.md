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