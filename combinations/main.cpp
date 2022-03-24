#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


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

void get_subarray_recursion(vector<int> &arr , int start = 0 , int end = 0){
    if(end == arr.size()) return ;

    if(start > end) get_subarray_recursion(arr , 0 , end+1) ; // new window to explore 
    else{
        for(uint32_t i = start ; i < end ; i++){
            cout << arr[i] << " " ;
        }
        cout << arr[end] << endl;
        get_subarray_recursion(arr , start+1 , end );
    }
}

void get_subsequence_recursion1(vector<int> &arr , int cur_start , vector<int> &temp){
	print_1d(temp);
	for(int i = cur_start ; i < arr.size() ; i++){
		temp.push_back(arr[i]);
		get_subsequence_recursion1(arr , i+1 , temp) ;
		temp.pop_back();
	}
}

void get_subarray_iterative(vector<int> &arr){
    /*
        subarray / substring --> iterative approach
        [a , b , c , d , e , f]
             |           |
            start       end

        [i(start) -- j(end)] iterate through the range 
        with k as index 
    */    

    for(uint32_t i = 0 ; i < arr.size() ; i++){
        for(uint32_t j = i ; j < arr.size() ; j++){
            for(uint32_t k = i ; k <= j ; k++){
                cout << arr[k] << " " ; 
            }
            cout << endl ;
        }
    }
}

void get_subsequence_recursion(vector<int> &arr ,vector<int> &holder , vector<vector<int>> &results , int start = 0){
    if(start == arr.size()){
        print_1d(holder);
        return ;
    }
    get_subsequence_recursion(arr ,holder , results , start+1);
    holder.push_back(arr[start]);
    get_subsequence_recursion(arr ,holder , results , start+1);
    holder.pop_back();
}

void get_subsequence_iterative(vector<int> &arr){
    __uint128_t power_set = pow(2 , arr.size());

    for(__uint128_t i = 1 ; i < power_set ; i++){
        for(uint32_t j = 0 ; j < arr.size() ; j++){
            if(i&(1<<j)){
                cout << arr[j] << " " ;
            }
        }
        cout << endl ;
    }
}

int main(){
    vector<vector<int>> results ;
    vector<int> holder ;
    vector<int> arr = {1,1,2};
   // get_subsequence_iterative(arr);
    get_subsequence_recursion(arr , holder , results) ;
    return 0 ;
}
