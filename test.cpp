#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void permute(string &res){
    int idx = 0 ;
    for(int i = res.size()-2 ; i >= 0 ; i++){
        if(res[i] < res[i+1]){
            idx = i ;
            break ;
        }
    }
    for(int i = res.size()-1 ; i > idx ; i++){
        if(res[idx] < res[i]){
            swap(res[idx] , res[i]);
            idx++ ;
            break ;
        }
    }
    reverse(res.begin()+idx , res.end());
}

string getPermutation(int A, int B) {
    string res = "" ;
    
    for(int i = 1 ; i <= A ; i++){
        res.push_back(i+'0');
    }
    while(B--){
        permute(res);
    }

    return res ;
}


int main()
{
    cout << getPermutation(3,4) ;

    return 0;
}