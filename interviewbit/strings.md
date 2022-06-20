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

### Words

1. [length-of-last-word](https://www.interviewbit.com/problems/length-of-last-word/)
```cpp
int Solution::lengthOfLastWord(const string A) {
    int N = A.size()-1 ;
    int slen = 0 ;
    while(N >= 0 and A[N] == ' ') N-- ;
    
    while(N >= 0 and A[N] != ' '){
        N-- ; slen++ ;
    }
    
    return slen ;
}
```

### string tricks

1. [min-char-insert-to-make-pal](https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/)

```cpp
void computeLPS(vector<int> &lps , string &str){
    int ptr = 0 , right = 1 ;
    
    while(right < str.size()){
        if(str[ptr] == str[right]){
            ptr++ ;
            lps[right] = ptr ;
            right++ ; 
        }
        else{
            if(ptr != 0){
                ptr = lps[ptr-1] ;
            }
            else{
                right++ ;
            }
        }
    }
}

int Solution::solve(string A) {
    string str = A ;
    reverse(str.begin() , str.end()) ;
    str = A + "$" + str ;
    
    vector<int> lps(str.size() , 0);    
    computeLPS(lps , str);
    return A.size()-lps[str.size()-1] ;
    
}
```

2. [convert-to-pal](https://www.interviewbit.com/problems/convert-to-palindrome/)
```cpp

int helper(string &str ,int left , int right , int choice){
    if(left >= right){
        return 1 ;
    }

    if(str[left] != str[right]){
        if(choice == 0)
            return 0 ;
        else{
            return (helper(str ,left+1 , right , 0) || helper(str ,left, right-1 , 0) ) ;
        }
    }
    
    return helper(str , left+1 , right-1 , choice) ;
}

int Solution::solve(string A) {
    
    return helper(A , 0 , A.size()-1 , 1);
}
```

3. [minimum-appends-pal](https://www.interviewbit.com/problems/minimum-appends-for-palindrome/)
```cpp
void computeLPS(string &str , vector<int> &lps){
    int ptr = 0 , right = 1;
    
    while(right < str.size()){
        if(str[right] == str[ptr]){
            ptr++ ;
            lps[right] = ptr ;
            right++ ;
        }
        else{
            if(ptr != 0 ){
                ptr = lps[ptr-1] ;
            }
            else{
                right++ ;
            }
        }
    }
}

int Solution::solve(string A) {
    string str = A ;
    reverse(str.begin() , str.end());
    
    str = str + "$" + A ;
    vector<int> lps(str.size() , 0);
    computeLPS(str , lps);    
    
    return A.size() - lps[str.size()-1] ;
}
```

4. [min-paranthesis](https://www.interviewbit.com/problems/minimum-parantheses/)

```cpp
int Solution::solve(string A) {
    int count = 0 ;
    stack<char> st ;
    
    for(char ch : A){
        if(ch == '('){
            st.push(ch) ;
        }
        else{
            if(st.empty()){
                count++ ;
            }
            else{
                st.pop() ;
            }
        }
    }
    
    return count + st.size() ;
}
```

5. [Longest-pal-substr](https://www.interviewbit.com/problems/longest-palindromic-substring/)

```cpp
bool isPalindrome(string &A ,  int left , int right){
    if(left >= right){
        return true ;
    }
    if(A[left] != A[right]){
        return false ;
    }
    
    return isPalindrome(A , left+1 , right-1);
}

string Solution::longestPalindrome(string A) {
    int left = 0 , maxlen = 1 ;
    int N = A.size() ;
    
    for(int i = 0 ;  i < A.size()-1 ; i++){
        if(N-i <= maxlen) break ;
        
        for(int j = A.size()-1 ; j > i ; j--){
            if(isPalindrome(A , i , j) and j-i+1 > maxlen){
                maxlen = j-i+1 ;
                left = i ;
                break ;
            }
        }
    }    
    
    return A.substr(left , maxlen) ;
}
```