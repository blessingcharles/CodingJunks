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

2. [reverse-words](https://www.interviewbit.com/problems/reverse-the-string/)

```cpp
string Solution::solve(string A) {
    stringstream ss(A);
    vector<string> arr ;
    string res ;

    while(getline(ss ,res , ' ')){
        if(res == "") continue ;
        arr.push_back(res);
    }
    res = "" ;
    if(arr.size() == 0){
        return res ;
    }

    for(int i = arr.size()-1 ; i > 0 ; i--){
        res += arr[i] ;
        res += " " ;
    }
    res += arr[0] ;
    return res ;
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

### String Parsing

2. [compare-version](https://www.interviewbit.com/problems/compare-version-numbers/)

```cpp
int find_first_nonzero(string &str){
    int idx = 0 ;
    while(idx < str.size() and str[idx] == '0'){
        idx++ ;
    }
    return idx ;
}
int comparator(string &str1 , string &str2){
    // remove trailing zeros ;
    int idx1 = find_first_nonzero(str1) ;
    str1 = str1.substr(idx1 , str1.size()-idx1);

    idx1 = find_first_nonzero(str2) ;
    str2 = str2.substr(idx1 , str2.size()-idx1);

    if(str1.size() > str2.size()){
        return 1 ;
    }
    if(str2.size() > str1.size()){
        return -1 ;
    }

    if(str1 > str2){
        return 1 ;
    }
    if(str1 < str2){
        return -1;
    }
    return 0 ;
}
int Solution::compareVersion(string A, string B) {
    stringstream s1(A) ;
    stringstream s2(B) ;
    string t1 , t2 ;
    while(getline(s1 , t1 , '.') and getline(s2 , t2 , '.')){
       int res = comparator(t1, t2);
       if(res != 0 ){
           return res ;
       }
    }
    if(getline(s1 , t1 , '.')){
        return 1 ;
    }
    if(getline(s2 , t2 , '.')){
        return -1 ;
    }
    return 0 ;
}
```

3. [atoi](https://www.interviewbit.com/problems/atoi/)

```cpp
int Solution::atoi(const string A) {
    long long ans = 0 ;
    int temp = 0 ;
    int i = 0 ;
    bool isnegative = false ;
    if(A[0] == '-'){
        isnegative = true ;
        i = 1 ;
    }
    if(A[0] == '+'){
        i = 1 ;
    }
    for( ; i < A.size() ; i++ ){
        if(not isdigit(A[i])) break ;

        temp = A[i] - '0' ;
        ans = ans*10 + temp ;

        if(ans > INT_MAX){
            return (isnegative)?INT_MIN:INT_MAX ;
        }

    }
    return (isnegative)?ans*-1:ans ;
}
```

4. [valid-ip](https://www.interviewbit.com/problems/valid-ip-addresses/)

```cpp

void helper(string &A , int pos , int dots_left , string &cur , vector<string> &res){
    if(pos == A.size() and dots_left == 0){
        res.push_back(cur);
        return ;
    }
    if(dots_left == 0){
        return ;
    }

    if(pos != 0){
        cur.push_back('.');
    }
    if(A[pos] == '0'){
        // only one chance
        cur.push_back('0');
        helper(A,pos+1 , dots_left-1 , cur,res);
        cur.pop_back();
        if(pos != 0){
            cur.pop_back();
        }
        return ;
    }

    int temp = 0 ;
    int counter = 0 ;

    for(int i = pos ; i < A.size() and i < pos+3 ;i++){
        temp = temp*10 + A[i]-'0' ;
        if(temp > 255) continue ;

        cur.push_back(A[i]);
        helper(A , i+1 , dots_left-1 , cur,res);
        counter++ ;
    }

    while(counter--){
        cur.pop_back();
    }

    if(pos != 0){
        cur.pop_back() ;
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> res ;
    string curr = "" ;
    helper(A , 0 , 4 , curr,res);
    return res ;
}
```

### pretty print

1. [zigzag-string](https://www.interviewbit.com/problems/zigzag-string/)

```cpp
string Solution::convert(string s, int numRows) {
        if(numRows == 1) return s ;
        // read row by row
        vector<string> memo(min(numRows , int(s.size()))) ;

        string res ;
        bool isgoingdown = false ;

        int row =  0 ;

        for(char c : s){

            if(row == 0 or row == numRows-1)
                isgoingdown = !isgoingdown ;
            memo[row] += c ;
            row +=(isgoingdown)?1:-1 ;
        }
        for(string &n : memo){
            res += n ;
        }
        return res ;
}
```

3. [pretty-json](https://www.interviewbit.com/problems/pretty-json/)

```cpp
string generate_indents(int count){
    int indent = 0 ;
    string temp = "" ;
    while(indent < count){
        temp.push_back('\t');
        indent++ ;
    }
    return temp ;
}

bool canStopToken(char ch){
    return ch == '{' or ch == '}' or ch == '[' or ch == ']' or ch == ',' ;
}

vector<string> Solution::prettyJSON(string A) {
    int current_indent = 0 ;
    vector<string> res ;

    int ptr = 0 ;
    int N = A.size() ;

    while(ptr < N){
        string temp = "" ;

        if(A[ptr] == '{' or A[ptr] == '['){
            temp += generate_indents(current_indent);
            temp.push_back(A[ptr]);
            ptr++ ;
            current_indent++ ;
        }
        else if(A[ptr] == '}' or A[ptr] == ']'){
            current_indent-- ;
            temp += generate_indents(current_indent);
            temp.push_back(A[ptr]);
            ptr++ ;
            if(ptr < N and A[ptr] == ','){
                temp.push_back(',');
                ptr++ ;
            }
        }
        else{
            temp += generate_indents(current_indent);
            // delimiters  , and [ and {
            while(not canStopToken(A[ptr])){
                temp.push_back(A[ptr]);
                ptr++ ;
            }
            if(A[ptr] == ','){
                temp.push_back(',');
                ptr++ ;
            }
        }
        res.push_back(temp) ;
    }
    return res ;
}
```

### String math

1. [integer-to-roman](https://www.interviewbit.com/problems/integer-to-roman/)

```cpp
string Solution::intToRoman(int A) {
    vector<int> nums = {1000 , 900 , 500 , 400 , 100 , 90,50 , 40 , 10 ,9 , 5 , 4 , 1};
    vector<string> nums_map = {
        "M" ,
        "CM" ,
        "D" ,
        "CD" ,
        "C" ,
        "XC" ,
        "L" ,
        "XL" ,
        "X" ,
        "IX" ,
        "V" ,
        "IV" ,
        "I"
    };
    int ptr = 0 ;
    string res = "" ;
    int temp ;

    while(A){
        temp = A/nums[ptr] ;
        if(temp == 0){
            ptr++ ;
            continue ;
        }
        while(temp--){
            res += nums_map[ptr] ;
        }

        A = A%nums[ptr] ;
        ptr++ ;
    }

    return res ;
}
```

2. [roman-to-integer](https://www.interviewbit.com/problems/roman-to-integer/)

```cpp
int Solution::romanToInt(string A) {
    vector<int> nums = {1000 , 900 , 500 , 400 , 100 , 90,50 , 40 , 10 ,9 , 5 , 4 , 1};
    vector<string> nums_map = {
        "M" ,
        "CM" ,
        "D" ,
        "CD" ,
        "C" ,
        "XC" ,
        "L" ,
        "XL" ,
        "X" ,
        "IX" ,
        "V" ,
        "IV" ,
        "I"
    };
    
    int ptr = 0 ;
    int N = A.size() ;
    int idx = 0 ;
    
    int res = 0 ;
    
    while(idx < N){
        int sz = nums_map[ptr].size() ;
        int count = 0 ;
        
        if(sz == 1){
            char ch = nums_map[ptr][0] ;
            
            while(idx < N and ch == A[idx]){
                count++ ;
                idx++   ;      
            }
        }
        else{
            if(idx < N-1 and nums_map[ptr] == A.substr(idx , 2)){
                count++ ;
                idx += 2 ;
            }
        }

        res = res + nums[ptr]*count ;
        ptr++ ;
        
    }
    
    return res ;
}
```

3. [add-bin-strings](https://www.interviewbit.com/problems/add-binary-strings/)

```cpp
string Solution::addBinary(string A, string B) {
    string res = "" ;
    int carry = 0 ;
    
    reverse(A.begin() , A.end());
    reverse(B.begin() , B.end());
    int ptr = 0 , N = min(A.size() , B.size());
    
    int temp ;
    
    while(ptr < N){
        temp = (A[ptr] - '0') + (B[ptr] - '0') + carry ;
        carry = temp/2 ;
        res.push_back('0'+(temp%2));    
        ptr++ ;
    }    
    
    while(ptr < A.size()){
        temp = (A[ptr] - '0') + carry ;
        carry = temp/2 ;
        res.push_back('0'+(temp%2));    
        ptr++ ; 
    }
    
    while(ptr < B.size()){
        temp = (B[ptr] - '0') + carry ;
        carry = temp/2 ;
        res.push_back('0'+(temp%2));    
        ptr++ ; 
    }
    if(carry){
        res.push_back('1');
    }
    
    reverse(res.begin() , res.end());
    return res ;
}
```

4. [multiply](https://www.interviewbit.com/problems/multiply-strings/)
```cpp
string Solution::multiply(string A, string B) {
    int N = A.size() , M = B.size() ;
    if(A == "0" or B == "0"){
        return "0" ;
    }
    
    vector<int> memo(max(N*M,2) , 0) ;
    
    int place_holder = 0 ;
    int temp ;
    int maxii = 0 ;
    
    for(int i = N-1 ; i >= 0 ; i-- , place_holder++){
        int mult = A[i] - '0' ;
        int carry = 0 ;
        int idx = 0 ;
        
        for(int j = M-1 ; j >= 0 ; j-- , idx++ ){
            temp = mult*(B[j]-'0') + carry ;
            carry = temp/10 ;
            temp = temp%10 ;
            
            temp = memo[place_holder+idx] + temp ;
            carry = carry + temp/10 ;
            memo[place_holder+idx] = temp%10 ;
            maxii = max(maxii , place_holder+idx) ;
        }
        
        // adding the carry
        while(carry){
            memo[place_holder+idx] += (carry%10);
            maxii = max(maxii , place_holder+idx) ;
            carry = carry/10 ;
            idx++ ;
        }
    }
    string res ;
    for(int i = 0 ; i <= maxii ; i++){
        res.push_back(memo[i]+'0');
    }
    reverse(res.begin(),res.end());
    // find first non zero idx 
    int idx = 0 ;
    for( ; idx < res.size() ; idx++){
        if(res[idx] != '0') break ;
    }
    
    return res.substr(idx , res.size()-idx) ;
}
```