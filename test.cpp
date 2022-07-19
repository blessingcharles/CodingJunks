#include<bits/stdc++.h>

using namespace std;

template<typename T>
void print_1d(vector<T> &container){
    for(auto ele : container) cout << ele << " " ;
    cout << "--" << endl ;
}

void get_subsequence_recursion1(vector<int> &arr , int cur_start , vector<int> &temp){
	print_1d(temp);
	for(int i = cur_start ; i < arr.size() ; i++){
		temp.push_back(arr[i]);
		get_subsequence_recursion1(arr , i+1 , temp) ;
		temp.pop_back();
	}
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    get_subsequence_recursion1(arr , 0 ,vector<int>() = {});
}
