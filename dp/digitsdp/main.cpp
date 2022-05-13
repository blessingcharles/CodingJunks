#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


void gen_num(string num , int idx , bool islast , string &s){
    if(idx == s.size()){
        cout << num << endl ;
        return ;
    }

    int last_ele = (islast)?s[idx]-'0':9  ;
    for(int i = 0 ; i <= last_ele ; i++){
        gen_num(num + to_string(i) , idx+1 , (islast and (i == last_ele)) , s) ;
    }

}
int main(){

    freopen("inp.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    string s = "3219" ;

    gen_num("" , 0 , true , s);

    return 0 ;
}