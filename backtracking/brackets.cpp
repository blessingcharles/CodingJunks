#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void logger(string s){
    cout << s << endl;
}

/*
ALGORITHM
func(str , open_b , closed_b)

if(str.size() == n)
    results.append(str)
    return 
    
if(closed_b > open_b)
    func(str + ')' , open_b , closed_b-1)

if(open_b > 0)
    func(str + '(' , open_b-1 , closed_b)
*/

void generate_paranthesis(int open_b , int closed_b ,int n ,string &s, vector<string> &results){
    if(s.size() == n){
        results.push_back(s);
        return ;
    }

    if(closed_b > open_b){
        s.push_back(')');
        generate_paranthesis(open_b,closed_b-1,n,s, results);
        s.pop_back();
    }
    if(open_b > 0){
        s.push_back('(');
        generate_paranthesis(open_b-1,closed_b,n,s , results);
        s.pop_back();
    }
}
int main(){
    vector<string> results ;
    string s = "";

    generate_paranthesis(3,3,6,s,results);

    for(auto ele : results){
        cout << ele << endl ;
    }
    return 0;
}