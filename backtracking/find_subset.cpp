#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void logger(string s){
    cout << s << endl;
}


/*
ALGORITHM
"abc"
if(pos == n)
    result.append(str)
    return 
    
func(str , pos+1) // doesn't include a
str.append(s[i])
func(str , pos+1) //include a
*/

void find_subsets(int pos , string holder , vector<string> &results , string &s){
    if(pos == s.size()){
        results.push_back(holder);
        return ;
    }

    find_subsets(pos+1 , holder , results , s);
    find_subsets(pos+1 , holder+s[pos] , results , s);

}

int main(){

    string s = "abc";
    vector<string> results;
    string holder ;
    find_subsets(0,holder,results,s);

    for(auto ele : results){
        cout << ele << endl ;
    }

    return 0;
}