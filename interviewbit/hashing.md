# HASHING

## Hash search

1. [colorful-number](https://www.interviewbit.com/problems/colorful-number/)
```cpp
int Solution::colorful(int A) {
    unordered_set<long long> memo ;
    vector<int> arr ;
    
    while(A){
        arr.push_back(A%10);
        A = A/10 ;
    }
    
    for(int i = 0 ;i<arr.size() ; i++){
        long long mult = 1 ;
        for(int j = i ; j < arr.size() ; j++){
            mult = mult*arr[j] ;
            if(memo.find(mult) != memo.end()){
                return 0 ;
            }
            memo.insert(mult);
        }
    }
    return 1 ;
}
```

2. [largest-contiguos-zero-seq](https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/)
```cpp
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int> memo ;
    memo[0] = -1 ;
    int maxlen = 0 ;
    
    if(A[0] != 0){
        memo[A[0]] = 0 ;
    }
    else{
        maxlen = 1 ;    
    }
    int left = 0 ;
    vector<int> arr = A ;
    
    
    for(int i = 1 ;i < A.size() ; i++){
        A[i] += A[i-1] ;
        if(memo.find(A[i]) == memo.end()){
            memo[A[i]] = i ;
        }
        else{
           int len = i - memo[A[i]] ;
           if(maxlen < len){
                left = memo[A[i]]+1 ;           
                maxlen = len ;
           } 
        }
    }
    
    if(maxlen == 0){
        return {} ;
    }
    return vector<int>(arr.begin()+left , arr.begin()+left+maxlen);
}
```

3. [longest-subarray-length](https://www.interviewbit.com/problems/longest-subarray-length/)
```cpp
int Solution::solve(vector<int> &arr) {
    unordered_map<int , int> memo ;

    // A : [ 0, 1, 1, 0, 0, 1 ]
    int maxlen = 0 , maxsum = 0 ;
    
   
    for(int i = 0 ; i < arr.size() ; i++){
        
        maxsum = (arr[i] == 0)?maxsum-1:maxsum+1 ;
                
        if(maxsum == 1){
            maxlen = i+1 ;
        }
        
        else if(memo.find(maxsum) == memo.end()){
            memo[maxsum] = i ;            
        }
        
        if(memo.find(maxsum-1) != memo.end()){
            maxlen = max(maxlen , i - memo[maxsum-1]);
        }            
    }
    return maxlen ;
}
```

4. [first-repeating](https://www.interviewbit.com/problems/first-repeating-element/)
```cpp
int Solution::solve(vector<int> &A) {
    int minidx = INT_MAX ;
    unordered_map<int,int> memo ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(memo.find(A[i]) != memo.end()){
            minidx = min(minidx , memo[A[i]]);
        }    
        else{
            memo[A[i]] = i ;
        }
    }
    return (minidx == INT_MAX)?-1:A[minidx] ;   
}
```

5. [2sum](https://www.interviewbit.com/problems/2-sum/)
```cpp
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> memo ;
    int minidx1 = INT_MAX , minidx2 = INT_MAX ;
    
    for(int i = 0 ; i < A.size() ; i++){
        int req = B - A[i] ;
        if(memo.find(req) != memo.end()){
            return {memo[req]+1 , i+1};
        }
        if(memo.find(A[i]) == memo.end())
            memo[A[i]] = i ;
    }
    return {} ;
}
```

6. [4sum](https://www.interviewbit.com/problems/4-sum/)
```cpp
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> res ;
    sort(A.begin() , A.end());
    
    for(int i = 0 ; i < A.size()-3 ; i++){
        // if same elements repeated 
        if(i != 0 and A[i] == A[i-1]) continue ;
        for(int j = i+1 ; j < A.size()-2 ; j++){
            if(j != i+1 and A[j] == A[j-1] ) continue ;
            int left = j+1 , right = A.size()-1; 
            
            while(left < right){
                int cursum = A[i] + A[j] + A[left] + A[right] ;
                
                if(cursum > B){
                    right-- ;
                }
                else if(cursum < B){
                    left++ ;
                }
                else{
                    //cursum is equal 
                    res.push_back({A[i],A[j],A[left],A[right]});
                    
                    //remove the duplicated on left and right
                    do{
                        left++ ;
                    }while(left < right and A[left] == A[left-1]);
                    do{
                        right-- ;
                    }while(left < right and A[right] == A[right+1]);
                }
            }
        }
        
    }
    return res ;
}
```

7. [valid-sudoku](https://www.interviewbit.com/problems/valid-sudoku/)
```cpp
int Solution::isValidSudoku(const vector<string> &A) {
    for(int row = 0 ; row < 9 ; row++){
        unordered_set<char> memo1 ;
        unordered_set<char> memo2 ;
        
        for(int col = 0 ; col < 9 ; col++){
            
            if(memo1.find(A[row][col]) != memo1.end()){
                return 0 ;
            }
            if(A[row][col] != '.')
                memo1.insert(A[row][col]);
            
            if(memo2.find(A[col][row]) != memo2.end()){
                return 0 ;
            }
            if(A[col][row] != '.')
                memo2.insert(A[col][row]);
        }
    }
    
    for(int i = 0 ; i < 9 ; i = i+3){
        for(int j = 0 ; j < 9 ; j = j+3){
            unordered_set<char> memo ;
            
            for(int row = 0 ; row < 3 ; row++){
                for(int col = 0 ; col < 3 ; col++){
                    if(memo.find(A[i+row][j+col]) != memo.end()){
                        return 0 ;
                    }
                    if(A[row+i][col+j] != '.')
                        memo.insert(A[i+row][j+col]);
                }
            }
        }
    }
    return 1 ;
}
```

8. [diffk-2](https://www.interviewbit.com/problems/diffk-ii/)
```cpp
int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> memo ;
    
    for(int i = 0 ; i < A.size() ; i++){
        int req = A[i] - B ;
        int req1 = B + A[i] ;
        
        if(memo.find(req) != memo.end()){
            return 1 ;
        }
        if(memo.find(req1) != memo.end()){
            return 1 ;
        }
        memo.insert(A[i]);
    }
    return 0 ;
}
```

## Incremental Hash

1. [Incremental-problem](https://www.interviewbit.com/problems/an-increment-problem/)
```cpp
vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,int> memo ;
    
    for(int i = 0 ; i < A.size() ; i++){
        if(memo.find(A[i]) != memo.end()){
            int idx = memo[A[i]] ;
            memo[A[i]] = i ;
            A[idx]++ ;
            memo[A[idx]] = idx ;
        }
        else{
            memo[A[i]] = i ;
        }
    }
    return A ;
}
```

2. [subarray-with-given-xor](https://www.interviewbit.com/problems/subarray-with-given-xor/)
```cpp
int Solution::solve(vector<int> &A, int k) {
    int count = 0 ;
    unordered_map<int,int> memo ;
    memo[0] = 1 ;
    int curxor = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        curxor = curxor ^ A[i] ;
        if(memo.find(curxor ^ k) != memo.end()){
            count += memo[curxor ^ k];
        }          
        memo[curxor]++ ;
    }
    
    return count ;
}
```

3. [two-out-of-three](https://www.interviewbit.com/problems/two-out-of-three/)
```cpp
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int,int> memo1 , memo2 , memo3 ;
    for(int ele : A){
        memo1[ele]++ ;
    }
    for(int ele : B){
        memo2[ele]++ ;
    }
    for(int ele : C){
        memo3[ele]++ ;
    }
    set<int> st ;
        
    for(int ele : A){
        if(memo2.find(ele) != memo2.end()){
            st.insert(ele);        
        }
        else if(memo3.find(ele) != memo3.end()){
            st.insert(ele);        
        }
    }
    for(int ele : B){
        if(memo1.find(ele) != memo1.end()){
            st.insert(ele);        
            memo1[ele]-- ;
            if(memo1[ele] == 0){
                memo1.erase(ele) ;
            }
        }
        else if(memo3.find(ele) != memo3.end()){
            st.insert(ele);        
            memo3[ele]-- ;
            if(memo3[ele] == 0){
                memo3.erase(ele) ;
            }
        }
    }
    return vector<int>(st.begin() , st.end());    
}
```

4. [substring-concatenation](https://www.interviewbit.com/problems/substring-concatenation/)
```cpp
bool helper(string &A , int pos , unordered_map<string,int> memo , int wordLen){
    string temp ;
    while(memo.size() and pos < A.size()){
        temp = A.substr(pos , wordLen);
        if(memo.find(temp) == memo.end()) return false ;
        memo[temp]-- ;
        if(memo[temp] == 0){
            memo.erase(temp);
        }
        pos = pos + wordLen ;
    }
    
    return (memo.size() == 0)?true:false ;
}
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int wordLen = B[0].size() ;
    unordered_map<string , int> memo ;
    
    for(const string &s : B){
        memo[s]++ ;    
    }
    string temp ;
    vector<int> res ;
    
        
    for(int i = 0 ; i < A.size() ; i++){
        temp = A.substr(i,wordLen);
        if(memo.find(temp) != memo.end()){
            //try to match it 
            if(helper(A , i , memo , wordLen)){
                res.push_back(i);
            }
        }
    }  
    return res ;
}

```

### Hashing two ptr

1. [exact-odd](https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/)
```cpp
int Solution::solve(vector<int> &A, int B) {
    queue<int> q ;
    int count = 0;
    int left = 0 , right = 0 ;
    while(right < A.size()){
        if(A[right] % 2 == 1){
            q.push(right);
        }
        
        while(q.size() > B){
            left = q.front()+1 ;
            q.pop();
        }
        
        if(q.size() == B){
            // how many subarray i can generate
            if(B == 0){
                count += (right-left+1);
            }
            else{
                count += (q.front() - left + 1);
            }
        }
        right++ ;
    }
    
    return count ;
}
```

2. [window-string](https://www.interviewbit.com/problems/window-string/)
```cpp
string Solution::minWindow(string A, string B) {
    int N = A.size() , M = B.size() ;
    
    if(N == M){
        return (A == B)?A:"" ;
    }
    if(N < M){
        return "" ;
    }
    int minlen = INT_MAX ;
    int left = 0 , right = 0 , minleft = -1 ;
    
    unordered_map<char,int> memo;
    unordered_map<char , int> window ;
    
    for(char ch : B){
        memo[ch]++ ;
    }
    int have = 0 , need = memo.size() ;
    
    while(right < N){
        window[A[right]]++ ;
        if(memo.find(A[right]) != memo.end() and memo[A[right]] == window[A[right]]){
            have++ ;
        }
        
        while(have == need){
            if(minlen > right-left+1){
                minlen = right-left+1 ;
                minleft = left ;
            }

            window[A[left]]-- ;
            if(memo.find(A[left]) != memo.end() and memo[A[left]] > window[A[left]]){
                have-- ;
            }
            left++ ;
        }
        right++ ;
    }
    return (minlen == INT_MAX)?"":A.substr(minleft , minlen) ;   
}
```

3. [longest-substr-without-repeat](https://www.interviewbit.com/problems/longest-substring-without-repeat/)
```cpp
int Solution::lengthOfLongestSubstring(string A) {
    int maxlen = 0 ;
    int left = 0 , right = 0 ;
    unordered_map<char , int > memo ;
    int N = A.size() ;
    
    while(right < N){
        while(memo.find(A[right]) != memo.end()){
            memo.erase(A[left]);
            left++ ;
        }    
        memo[A[right]]++ ;
        maxlen = max(maxlen , right-left+1);
        right++ ;
    }
    return maxlen ;
}
```


## Key information

1. [pair-xor](https://www.interviewbit.com/problems/pairs-with-given-xor/)
```cpp
int Solution::solve(vector<int> &A, int B) {
    int count = 0 ;
    unordered_set<int> memo(A.begin() , A.end());
    
    for(int ele : A){
        if(memo.find(ele ^ B) != memo.end()){
            count++ ;
            memo.erase(ele);
        }
        
    }
    return count ;
}
```

2. [Anagrams](https://www.interviewbit.com/problems/anagrams/)
```cpp
vector<vector<int> > Solution::anagrams(const vector<string> &arr) {
    unordered_map<string , vector<int>> memo ;
    vector<string> A = arr ;
    
    for(int i = 0 ; i < A.size() ; i++){
        sort(A[i].begin() , A[i].end());
        memo[A[i]].push_back(i+1) ;
    }
    
    vector<vector<int>> res ;
    for(int i = 0 ; i < A.size() ; i++){
        if(memo.find(A[i]) != memo.end()){
            res.push_back(memo[A[i]]);
            memo.erase(A[i]);
        }
    }
    return res ;
}
```

3. [equal](https://www.interviewbit.com/problems/equal/)
```cpp
bool isLexSmaller(int e1 , int e2 , int e3 , int e4 , int x1 , int x2 , int x3 , int x4){
    if(x1 != e1){
        return x1 < e1 ;
    }

    if(x2 != e2){
        return x2 < e2 ;
    }


    if(x3 != e3){
        return x3 < e3 ;
    }

    if(x4 != e4){
        return x4 < e4 ;
    }

    return false ;
}

vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int , pair<int,int>> memo ;
    int first = INT_MAX , second = INT_MAX , third = INT_MAX, fourth = INT_MAX ;
    pair<int,int> temp ;
    
    for(int i = 0 ; i < A.size()-1 ; i++){
        for(int j = i+1 ; j < A.size() ; j++){
            int cursum = A[i] + A[j] ;
                    
            if(memo.find(cursum) != memo.end()){
                    temp = memo[cursum] ;
                    if(temp.first == i or temp.first == j or temp.second == i  or temp.second == j){
                        continue ;
                    }
                    if(isLexSmaller(first , second , third , fourth , temp.first , temp.second , i , j)){
                        first = temp.first ;
                        second = temp.second ;
                        third = i ;
                        fourth = j ;
                    }
            }
            else{
                memo[cursum] = {i,j};
            }
        }
    }
    if(first == INT_MAX) return  {} ;
    
    return {first, second,third,fourth} ;
}
```

4. [copy-list](https://www.interviewbit.com/problems/copy-list/)
```cpp
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* head = new RandomListNode(0);
    RandomListNode* prev = head ;
    unordered_map<RandomListNode* , RandomListNode* > memo ;
    RandomListNode* cur = A ;
    while(cur){
        prev->next = new RandomListNode(cur->label);
        memo[cur] = prev->next ;
        
        prev = prev->next ;
        cur = cur->next ;
    }
    
    prev = head->next ;
    cur = A ;
    
    while(cur){
        
        if(cur->random){
            prev->random = memo[cur->random];
        }
        prev = prev->next ;
        cur = cur->next ;
    }
    return head->next ;
}
```

### Maths and Hashing

1. [is-pal](https://www.interviewbit.com/problems/check-palindrome/)
```cpp
int Solution::solve(string A) {
    unordered_map<char , int> memo ;
    
    for(char ch : A){
        memo[ch]++ ;
    }
    int odds_count = 0 ;
    
    for(unordered_map<char,int>::iterator it = memo.begin() ; it != memo.end() ; it++){
        if(it->second%2 == 1){
            if(odds_count == 1){
                return 0 ;
            }
            odds_count++ ;
        }    
    }
    return 1 ;
}
```

2. [fraction](https://www.interviewbit.com/problems/fraction/)
```cpp
string Solution::fractionToDecimal(int c, int d) {
    long a = c , b = d ;
    string res = "" ;
    if(a == 0){
        return "0" ;
    }
    
    long sign = ((a < 0) ^ (b < 0))?-1:1 ;
    
    a = abs(a);
    b = abs(b);
    long initital = a/b ;
    if(sign == -1){
        res += "-" ;
    }
    res += to_string(initital);
    
    long rem = a%b ;
    if(rem == 0){
        return res ;
    }
    
    bool isrepeated = false ; 
    long idx ;
    unordered_map<long,long> memo ;
    res += "." ;
    while(rem > 0){
        if(memo.find(rem) != memo.end()){
            isrepeated = true ;
            idx =memo[rem];
            break ;
        }
        else
            memo[rem] = res.size();
        
        rem = rem*10 ;
        res += to_string(rem/b) ;
        
        rem = rem%b ;
    }
    if(isrepeated){
        res += ")";
        res.insert(idx , "(");
    }
    
    return res ;
}

```

3. [points-on-stline](  https://www.interviewbit.com/problems/points-on-the-straight-line/)
```cpp
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size() == 0){
        return 0 ;
    }
    if(A.size() == 1){
        return 1 ;
    }
    
    int maxpoints = 0 ;
    double curslope = 0 ;
    
    for(int i = 0 ; i < A.size() ; i++){
        int i_max = 0 , samePoint = 1 ;
        
        unordered_map<double,int> slopes ;
        for(int j = i+1 ; j < A.size() ; j++){
            
            if(A[j] == A[i] and B[j] == B[i]){
                samePoint++      ;
            }
            else if(A[j]-A[i] == 0){
                slopes[INT_MAX]++;
                i_max = max(slopes[INT_MAX] ,i_max);        
            }
            else{
                curslope = (double )(B[j] - B[i])/(double )(A[j] - A[i]) ;
                slopes[curslope]++ ;
                i_max = max(slopes[curslope] ,i_max);        
            }
        }
        maxpoints = max(maxpoints ,i_max+samePoint);        
    }
    
    return maxpoints ;
}
```