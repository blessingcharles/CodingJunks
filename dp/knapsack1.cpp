#include<iostream>
#include<bits/stdc++.h>


using namespace std ;
void logger(string s){
    cout << s << endl;
}

int memoisation_nquantity(int W , vector<int> &weights , vector<int> &values ,  unordered_map<int,int> &memo){
    //each item can be included any number of times
    if(W == 0)
        return 0;
    if(memo.find(W) != memo.end())
        return memo[W];

    int max_val = 0 ;
    for(int i = 0 ; i < weights.size() ; i++){
        if(W-weights[i] < 0) continue ;
        int val = memoisation_nquantity(W-weights[i] , weights , values ,memo);
        max_val = max(max_val , val + values[i]);
    }

    return memo[W] = max_val ;
}

int memoisation(int W ,int pos,vector<int> &weights , vector<int> &values ,  unordered_map<int,int> &memo ){
    //each quantity can be included only one time
    if(memo.find(W) != memo.end())
        return memo[W];

    if(pos < 0 || W == 0){
        return 0;
    };
    if(W-weights[pos] < 0)
        return memoisation(W,pos-1,weights,values,memo);

    int include_weight = values[pos] + memoisation(W-weights[pos] , pos-1 ,weights , values , memo);
    int exclude_weight = memoisation(W ,pos-1,weights,values,memo );

    return memo[W] = max(exclude_weight,include_weight);

}

int main(){
    vector<int> weights = {3,4,5};
    vector<int> values = {30,50,60};
    unordered_map<int,int> memo;

    cout << memoisation(8,weights.size()-1,weights,values,memo) << endl ;

    return 0;
}