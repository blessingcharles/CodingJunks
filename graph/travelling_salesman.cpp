#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &grid , int setOfCitities , int pos , vector<vector<int>> &memo){
    if(setOfCitities == (1 << grid.size()) - 1){
        //last city to starting point
        return grid[pos][0];
    }
    if(memo[setOfCitities][pos] != -1)
        return memo[setOfCitities][pos];

    int results = INT_MAX;

    for(int choice = 0 ; choice < grid.size() ; choice++){
        //if not visited
        if((setOfCitities & (1<<choice)) == 0){

            int temp = grid[pos][choice] + solve(grid,(setOfCitities|(1<<choice)),choice , memo);
            results = min(results,temp);
        }
    }
    return memo[setOfCitities][pos] =results ;
}

int main(){

    vector< vector<int> > dist = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
	};
    vector<vector<int>> memo((1<<dist.size()),vector<int>(dist.size(),-1));
    cout << solve(dist ,1,0,memo) << endl;

	return 0;
}