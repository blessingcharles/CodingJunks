#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

// subarray   --->   n*(n+1)/2 possible
// subsequence -->   (2^n)-1   possible

template <typename T>
void print_2d(vector<vector<T>> &container){
    for(auto &sub : container){
        for(auto ele : sub) cout << ele << " " ;
        cout << endl ;
    }
}

template<typename T>
void print_1d(vector<T> &container){
    for(auto ele : container) cout << ele << " " ;
    cout << endl ;
}
void compute_nxt_greater(vector<int> &arr){
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
void permute(vector<int> &arr){
    // can handle duplicates
    vector<int> initial_state(arr);

    do{
        print_1d(arr);
        compute_nxt_greater(arr);
    }while(initial_state != arr) ;
}

void permute_with_combinations(vector<int> arr , int cur_start ){

    // 1 1 2 3 3
    for(int i = 0 ; i < cur_start ; i++)
        cout << arr[i] ;

    cout << endl ;

    for(int i = cur_start ; i < arr.size() ; i++){
        if(i!=cur_start and arr[i] == arr[cur_start]) continue;

        swap(arr[i] , arr[cur_start]);
        permute_with_combinations(arr , cur_start+1);
    }
}
string kthPermutation(int n, int k) {
    string str = "" ;
    vector<int> arr ;
    int fact = 1 ;
    for(int i = 1 ; i < n ; i++){
        arr.push_back(i);
        fact *= i ;
    }
    arr.push_back(n);
    
    k-- ;
    while(true){
        int idx = k/fact ;
        str.push_back(arr[idx]+'0');
        arr.erase(arr.begin() + idx);
        if(arr.size() == 0) break ;
        k = k%fact ;
        fact = fact/arr.size();
    }
    return str ;
}
void permute_without_duplicates(vector<int> &arr , int cur_start = 0){
    // will not handle duplicates
    if(cur_start == arr.size()){
        print_1d(arr);
        return ;
    }

    for(int i = cur_start ; i < arr.size() ; i++){
        swap(arr[cur_start] , arr[i]);
        permute_without_duplicates(arr , cur_start+1);
        swap(arr[cur_start] , arr[i]);
    }
}
int main(){
    vector<int> arr = {1,2,3};
    permute_with_combinations(arr,0);

   return 0 ; 
}