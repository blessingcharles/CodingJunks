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

