# Backtracking

1. [maximal-string](https://www.interviewbit.com/problems/maximal-string/)
```cpp
void helper(string &str , int pos , int B , string& max_string){
    if(B == 0 || pos == str.size()){
        max_string = max(max_string , str);
        return  ;
    }
    // move without swapping
    helper(str , pos+1 , B , max_string);
    for(int i = pos+1 ; i < str.size() ; i++){
        if(str[pos] < str[i]){
            swap(str[pos] , str[i]);
            helper(str , 0 , B-1 , max_string);
            swap(str[pos] , str[i]);
        }
    }
    return ;
}

string Solution::solve(string A, int B) {
    string max_string = A ;
    helper(A , 0 , B , max_string);
        
    return max_string ;
}
```

2. [kth-permutation](https://www.interviewbit.com/problems/kth-permutation-sequence/)
```cpp
void permute(vector<int> &arr){
    // 1 3 5 4 2 (find a element after peak from backwards)
    // 1 4 5 3 2 (swap the above element with element thats greater than current)
   //  1 4 2 3 5 (reverse it from pos)

    if(arr.size() < 2) return ;

    int pos = 0 ;
    for(int i = arr.size()-2 ; i >= 0 ; i--){
        if(arr[i] < arr[i+1]){
            //find a peak element
            pos = i ;
            break ;
        }
    }

    for(int i = arr.size()-1 ; i > pos ; i--){
        if(arr[pos] < arr[i]){
            swap(arr[pos] , arr[i]);
            pos++ ;
            break ;
        }
    }
    reverse(arr.begin()+pos , arr.end());
}

string Solution::getPermutation(int A, int B) {
    vector<int> arr ;
    
    for(int i = 1 ; i <= A ; i++){
        arr.push_back(i);
    }
    B-- ;
    while(B--){
        permute(arr);
    }
    string res = "" ;
    
    for(int i = 0 ; i < arr.size() ; i++){
        res += to_string(arr[i]);
    }
    
    return res ;
}
```

3. [gray-code](https://www.interviewbit.com/problems/gray-code/)
```cpp
vector<int> Solution::grayCode(int A) {
    vector<int> sol ;
    for(int i = 0 ; i < (1 << A) ; i++){
        int val = i^(i>>1) ;
        sol.push_back(val);        
    }
    return sol ;
}
```

### Subsets

1. [subset-generation](https://www.interviewbit.com/problems/subset/)
```cpp

void helper(vector<int> &A , vector<int> &storage , int pos , vector<vector<int>> &res){
    if(pos == A.size()){
        res.push_back(storage);
        return  ;
    }
    
    //include the element
    storage.push_back(A[pos]);
    helper(A , storage , pos+1 , res);
    storage.pop_back();
    helper(A , storage , pos+1 , res);
        

}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> res ;
    sort(A.begin(),A.end());
    vector<int> storage ;
    helper(A , storage , 0 , res);    
    
    sort(res.begin(),res.end());
    return res ;
}
```

2. [combination-sum](https://www.interviewbit.com/problems/combination-sum/)
```cpp
void helper(vector<int> &arr , int pos,int cur, int req , vector<int> &storage , set<vector<int>> &res){
    if(req == cur){
        res.insert(storage);
        return ;
    }
    if(req < cur or pos == arr.size()){
        return ;
    }
    
    storage.push_back(arr[pos]);
    
    helper(arr , pos , cur+arr[pos] , req , storage , res);
    storage.pop_back();
    helper(arr , pos+1 , cur,req , storage , res);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<vector<int>> res ;
    vector<int> storage ;
    sort(A.begin() ,A.end());
    helper(A , 0 , 0 ,B, storage , res);
    return vector<vector<int>>(res.begin() , res.end()) ;
}
```

3. [combination-sum-2](https://www.interviewbit.com/problems/combination-sum-ii/)
```cpp
void helper(int pos , int curr , int req , vector<int> &arr , vector<int> &storage , set<vector<int>> &res){
    if(curr == req){
        res.insert(storage);
        return ;
    }
    if(curr > req or pos == arr.size()){
        return ;
    } 
    storage.push_back(arr[pos]);
    helper(pos+1 , curr+arr[pos] , req , arr , storage , res);
    storage.pop_back();
    
    helper(pos+1 , curr , req , arr , storage , res);
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<vector<int>> res ;
    vector<int> storage ;
    sort(A.begin(),A.end());
    helper(0 , 0 , B , A , storage , res);
    
    return vector<vector<int>>(res.begin() , res.end());
}
```

4. [combinations](https://www.interviewbit.com/problems/combinations/)
```cpp
void helper(int ele ,int target, int count , vector<int> &storage , vector<vector<int>> &res){
    if(count == 0){
        res.push_back(storage);
        return ;
    }
    if(count < 0 or ele > target){
        return  ;
    }
    
    storage.push_back(ele);
    helper(ele+1,target , count-1 ,storage , res);
    storage.pop_back();
    
    helper(ele+1,target, count , storage , res);
    
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> res ;
    vector<int> storage ;
    
    helper(1,A, B , storage , res);    
    return res ;    
}
```

5. [subsets-2](https://www.interviewbit.com/problems/subsets-ii/)
```cpp
void helper(int pos , vector<int> &arr , vector<int> &storage , set<vector<int>> &res){
    if(pos == arr.size()){
        res.insert(storage);
        return ;
    }
    helper(pos+1 , arr , storage , res);
    storage.push_back(arr[pos]);
    helper(pos+1 , arr,storage,res);
    storage.pop_back();
    
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    set<vector<int>> res ;
    sort(A.begin() , A.end());
    vector<int> storage;
    
    helper(0 , A , storage , res);
    return vector<vector<int>>(res.begin() , res.end()) ;
}
```

### Bruteforce Builder

1. [letter-phone](https://www.interviewbit.com/problems/letter-phone/)
```cpp
unordered_map<char , string> phone = {
    {'0'  , "0"},
    {'1'  , "1"},
    {'2' ,  "abc"} ,
    {'3' , "def"} ,
    {'4' , "ghi" },
    {'5' , "jkl" },
    {'6' , "mno" },
    {'7' , "pqrs" },
    {'8' , "tuv" },
    {'9' , "wxyz"}
};
void helper(int pos , string &str , string &container , vector<string> &res){
    if(pos == str.size()){
        res.push_back(container);
        return  ;
    }
    
    for(char ch : phone[str[pos]]){
        container.push_back(ch);
        helper(pos+1 , str, container,res);
        container.pop_back();
    }        
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> res ;
    string storage = "";
    helper(0,A,storage,res);
    return res ;
}
```

2. [palindrome-partitioning](https://www.interviewbit.com/problems/palindrome-partitioning/)
```cpp
bool isPalindrome(string &st){
    int left = 0 , right = st.size()-1 ;
    
    while(left < right){
        if(st[left] != st[right]){
            return false ;
        }
        left++ ; right-- ;
    }
    return true ;
}
vector<vector<string>> helper(string &str , int pos){
    if(pos == str.size()){
        return vector<vector<string>>(1) ;
    }
    vector<vector<string>> res ;
    string temp = "" ;
    
    for(int i = pos ; i < str.size() ; i++){
        temp.push_back(str[i]);
        if(isPalindrome(temp)){
            vector<vector<string>> tt = helper(str , i+1);
            
            for(vector<string> &v : tt){
                v.insert(v.begin() , temp);
                res.insert(res.end() , v);
            }
            
        }
    }
    
    return res ;
}
vector<vector<string> > Solution::partition(string A) {
    return helper(A , 0);
}
```

3. [generate-parenthesis](https://www.interviewbit.com/problems/generate-all-parentheses-ii/)
```cpp
void helper(int open_paren , int closed_paren , int total,int cur ,string &container , vector<string> &res){
    if(2*total == cur){
        res.push_back(container);
        return ;
    }    
    
    if(open_paren < total){
        container.push_back('(');
        helper(open_paren+1 , closed_paren , total , cur+1 , container , res);
        container.pop_back();
    }
    
    if(closed_paren < open_paren){
        container.push_back(')');
        helper(open_paren , closed_paren+1 , total , cur+1 , container , res);
        container.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> res ;
    string container = "" ;
    helper(0 , 0 , A , 0 , container , res);
    return res ;
}
```

### permutation

1. [permute](https://www.interviewbit.com/problems/permutations/)
```cpp
void permute(vector<int> &arr){
     if(arr.size() < 2) return ;

    int pos = 0 ;
    for(int i = arr.size()-2 ; i >= 0 ; i--){
        if(arr[i] < arr[i+1]){
            //find a peak element
            pos = i ;
            break ;
        }
    }

    for(int i = arr.size()-1 ; i > pos ; i--){
        if(arr[pos] < arr[i]){
            swap(arr[pos] , arr[i]);
            pos++ ;
            break ;
        }
    }
    reverse(arr.begin()+pos , arr.end());
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<int> init = A ;
    vector<vector<int>> res ;
    
    do{
        res.push_back(A);
        permute(A);
    }while(init != A);
    
    return res ;
}
```

### game solving

1. [nqueen](https://www.interviewbit.com/problems/nqueens/)
```cpp
bool canIPlace(int row , int col , vector<string> &board){
    //check the rows 
    int N = board.size() ;
    
    for(int r = 0 ; r < N ; r++){
        if(board[r][col] == 'Q'){
            return false ;
        }
    }
    // check for cross cut
    bool flag = true ;
    int move = 1 ;
    
    while(flag){
        flag = false ;
        
        if(row+move < N and col+move < N){
            flag = true ;
            if(board[row+move][col+move] == 'Q'){
                return false ;
            }
        }
        if(row+move < N and col-move >= 0){
            flag = true ;
            if(board[row+move][col-move] == 'Q'){
                return false ;
            }
        }
        if(row-move >= 0 and col+move < N){
            flag = true ;
            if(board[row-move][col+move] == 'Q'){
                return false ;
            }
        }
        if(row-move >= 0 and col-move >= 0){
            flag = true ;
            if(board[row-move][col-move] == 'Q'){
                return false ;
            }
        }
        move++ ;
    }
    
    return true ;
}
void solver(int row , vector<string> &board , vector<vector<string>> &res){
    if(row == board.size()){
        res.push_back(board);
        return ;
    }
    
    for(int col = 0 ; col < board.size() ; col++){
        if(canIPlace(row , col , board)){
            board[row][col] = 'Q';
            solver(row+1 , board , res);
            board[row][col] = '.';
        }
    }
    
}
vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> res ;
    vector<string> board(A , string(A , '.')) ;

    solver(0 , board , res);
    
    return res ;
}
```

2. [sudoku](https://www.interviewbit.com/problems/sudoku/)
```cpp
string possible = "123456789" ;
bool canIPlace(char ch , int row , int col , vector<vector<char>> &board){
    // check the row and col
    for(int i = 0 ; i < board.size() ; i++){
        if(board[row][i] == ch) return false ;
        if(board[i][col] == ch) return false ;
    }
    
    // check 3*3 matrix ;
    int i_row = floor(row/3)*3 ;
    int i_col = floor(col/3)*3 ;
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[i+i_row][j+i_col] == ch){
                return false ;
            }
        }
    }
    return true ;
}

bool helper(int row , int col , vector<vector<char>> &A){
    if(row == A.size()){
        return true;
    }
    if(A[row][col] != '.'){
        col++ ;
        if(col == A.size()){
            col = 0 ;
            row++ ;
        }
        return helper(row , col , A);
    }
    
    int cur_col = col ;
    int cur_row = row ;
    
    for(char ch : possible){
        if(canIPlace(ch , row , col , A)){
            
            
            A[row][col] = ch ;
            col++ ;
            if(col == A.size()){
                col = 0 ; row++ ;
            }
            if(helper(row , col , A)){
                return true ;
            }
            
            row = cur_row ; 
            col = cur_col ;
            A[row][col] = '.' ;
        }
    }    
    
    return false ;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    helper(0,0,A);
}
```