#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int left = 0 , right = 0;
        
        while(right < nums.size()){
            //check the current window
            int cur_ele = nums[right];
			// cout << left << endl ;
            nums[left] = cur_ele ;
            
            int count = 1;
			right++ ;
            while(right < nums.size() && cur_ele == nums[right]){
				count++;
				right++ ;
			}
			cout << left << " " << right << "--" << nums[left] << endl ;
            if(count >= 2){
                nums[++left] = cur_ele;
            }
            left++ ;
        }
        return left;
    }
};

int main()
{
	vector<int> arr = { 0,0,0,1,1,1,1, 2,2,2,4,5,6,6};

	Solution s;

	cout << s.removeDuplicates(arr) << endl ;
	for(auto ele : arr){

		cout << ele << endl ;
	}
	return 0;
}
