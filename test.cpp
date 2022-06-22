#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, int B)
{
    // atmost b distincts 
    
    int left = 0 , right = 1 ;
    int N = nums.size() ;
    unordered_map<int,int> memo ;
    memo[nums[left]]++ ;
    int current_distincts = 1 ;
    int ans = 1 ;
    
    while(right < N){
        if(memo.find(nums[right]) == memo.end()){
            current_distincts++ ;
        }    
        memo[nums[right]]++ ;
        while(left < right and current_distincts > B){
            if(memo[nums[left]] == 1){
                memo.erase(nums[left]);
                current_distincts-- ;
                break ;
            }
            else{
                memo[nums[left]]-- ;
            }
            left++ ;
        }
        cout << left << " " << right << endl ;
        ans += (right - left+1);
        right++ ;
    }
    
    return ans ;
}

int main()
{
    vector<int> arr = { 5, 3, 5, 1, 3};

    cout << solve(arr, 3) << endl;
    cout << solve(arr, 2) << endl;

    return 0;
}