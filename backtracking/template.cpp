#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void logger(string s){
    cout << s << endl;
}

int main(){

    for(int i = 0 ; i < 8 ; i++){
        int x = (i>>1) ;

        bitset<4> b(x) ;
        cout << b << " " ;

        x = i ^x ;  
        cout << x << endl ;

    }
    return 0;
}