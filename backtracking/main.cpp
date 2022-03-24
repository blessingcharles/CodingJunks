#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void modifier(string h){
    h += " changes" ;
}

int main(){
    string t = "hello" ;
    cout << t << endl ;
    modifier(t);
    cout << t << endl ;
    return 0 ;
}