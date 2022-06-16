### String Simulation

1. [isPalindrome](https://www.interviewbit.com/problems/palindrome-string/)
```cpp
int Solution::isPalindrome(string A) {
    int left = 0 , right = A.size()-1 ;
    
    while(left < right){
        if(not iswalnum(A[left])){
            left++ ;
        }
        else if(not iswalnum(A[right])){
            right-- ;
        }
        else if(isdigit(A[left])){
            if(A[left] != A[right]){
                return 0 ;
            }
            left++ ;
            right-- ;
        }
        else if( tolower(A[left]) != tolower(A[right]) ){
            return 0 ;
        }
        else{
            left++ ;
            right-- ;
        }
    }
    return 1 ;
}
```

2. [vowel-consonant-str](https://www.interviewbit.com/problems/vowel-and-consonant-substrings/)
```cpp
bool isVowel(char ch){
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' ;
}

int Solution::solve(string A) {
    int count = 0 ;
    int N = A.size() ;
    bool flag ;
    int mod = 1e9+7 ;
    
    vector<int> m_vowel(N , 0);
    vector<int> m_consonants(N,0);
    
    if(isVowel(A[N-1])){
        m_vowel[N-1] = 1 ;
    }
    else{
        m_consonants[N-1] = 1;
    }
    
    for(int i = N-2 ; i >= 0 ; i--){
        if(isVowel(A[i])){
            m_vowel[i] = 1+m_vowel[i+1];
            m_consonants[i] = m_consonants[i+1];
            
        }
        else{
            m_consonants[i] = 1+m_consonants[i+1] ;
            m_vowel[i] = m_vowel[i+1] ;
        }
    }
    
    for(int i = 0 ; i < N-1 ; i++){
        if(isVowel(A[i])){
            count  = (count + m_consonants[i+1])%mod ;
        }
        else{
            count = (count + m_vowel[i+1])%mod ;
        }
    }
    return count ;
}
```

3. [remove-consecutive-chars](https://www.interviewbit.com/problems/remove-consecutive-characters/)
```cpp
string Solution::solve(string A, int B) {
    string res ;
    if(B == 1){
        return res ;
    }
    
    int right = 1 , left = 0 ;
    int N = A.size() ;
    
    while(right < N){
        while(right < N and A[left] == A[right]){
            right++ ;
        }
        
        if(right-left != B){
            // add these characters to res
            for(int i = left ; i < right ; i++){
                res.push_back(A[left]);
            }
        }
        left = right ;
        right++ ;
    }  
    if(left < N){
       res.push_back(A[left]); 
    }
    return res ;
}
```

4. [longest-common-prefix](https://www.interviewbit.com/problems/longest-common-prefix/)
```cpp

string helper(string prev_matched , vector<string> &strs , int pos){
    if(pos == strs.size() || prev_matched.size() == 0){
        return prev_matched ;
    }
    //match the prev_matched with strs[pos];
    int ptr = 0 , maxlen = max(prev_matched.size() , strs[pos].size());
    while(ptr < maxlen and prev_matched[ptr] == strs[pos][ptr] ){
        ptr++ ;
    }
    
    return helper(prev_matched.substr(0,ptr) , strs , pos+1);
}

string Solution::longestCommonPrefix(vector<string> &strs) {
    return helper(strs[0] , strs , 1);
}
```

5. [count-say](https://www.interviewbit.com/problems/count-and-say/)
```cpp
string Solution::countAndSay(int A) {
    string prev = "1" ;
    int ptr = 0 ;
    char cur_char ;
    int count = 0 ;
    
    A-- ;
    
    while(A--){
        string temp ;
        ptr = 0 ;
        while(ptr < prev.size()){
            cur_char = prev[ptr] ;
            ptr++ ;

            count = 1 ;
            while(ptr < prev.size() and prev[ptr] == cur_char){
                ptr++ ;
                count++ ;
            }    
            
            temp.push_back(count+'0');
            temp.push_back(cur_char);
        }
        prev = temp ;
    }
    
    return prev ;
}
```

### String search

1. [Amazing subarrays](https://www.interviewbit.com/problems/amazing-subarrays/)
```cpp

bool isVowel(char ch){
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' ;
}

int Solution::solve(string A) {
    int N = A.size() ;
    long long count = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        if(isVowel(tolower(A[i]))){
            count = (count+ (N-i) )%10003 ;
        }
    }
    return count ;
}
```

2. [strstr](https://www.interviewbit.com/problems/implement-strstr/l)
```cpp
vector<int> table ;

void lps(const string &pattern){
    // a a b a a b a a a 
    int ptr = 0 , i = 1 ;
    
    while(i < pattern.size()){
        if(pattern[i] == pattern[ptr]){
            ptr++ ;
            table[i] = ptr ;
            i++ ;
        }
        else{
            if(ptr != 0){
                ptr = table[ptr-1];
            }
            else{
                // table[i] = 0 ;
                i++ ;
            }
        }
    }
}

int kmp(const string &haystack, const string &pattern){
    int ptr1 = 0 , ptr2 = 0 ;
    
    while(ptr1 < haystack.size()){
        if(haystack[ptr1] == pattern[ptr2]){
            ptr1++ ;
            ptr2++ ;
        }
        else{
            if(ptr2 != 0){
                ptr2 = table[ptr2-1];
            }
            else{
                ptr1++ ;
            }
        }
            if(ptr2 == pattern.size()){
                return ptr1-ptr2 ;
            }
    }
    return -1 ;
}

int Solution::strStr(const string A, const string B) {
    if(B.size() == 0 || A.size() == 0){
        return -1 ;
    }
    table.resize(B.size() , 0) ;
    lps(B);
    return kmp(A , B);
}
```