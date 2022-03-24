#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

class Solution {
    int N = 0 ;
    int K = 0 ;
    int possible_sum = 0 ;
    vector<int> subsets ;
    
    bool solve(vector<int> &nums , int cur_idx){
        if(cur_idx == this->N){
            for(int i = 0 ; i < this->K ; i++){
                if(subsets[i] != this->possible_sum) return false ;
            }
            return true ;
        }
        
        for(int i = 0  ; i < this->K ; i++){
            // try to include the cur idx in each subset
            if(this->subsets[i] + nums[cur_idx] <= this->possible_sum){
                this->subsets[i] += nums[cur_idx] ;
                if(solve(nums , cur_idx+1))
                    return true ;
                this->subsets[i] -= nums[cur_idx] ;
            }
        }
        return false ;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin() , nums.end() , 0);
        this->N = nums.size() ;
        this->K = k ;
        
        if(this->N < k or sum%k != 0) return false ;
        
        this->possible_sum = sum/this->K ;
        
        subsets.resize(k,0) ;
        return solve(nums , 0);
    }
};

int main(){
    vector<int> arr = {18,20,39,73,96,99,101,111,114,190,207,295,471,649,700,1037} ;
    int k = 4 ;
    Solution *s = new Solution();
    cout << s->canPartitionKSubsets(arr , k);

    return 0 ;
}