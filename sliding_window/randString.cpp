#include<iostream>
#include<bits/stdc++.h>
#include <cstdlib> 
#include <ctime> 

using namespace std  ;

int main(int argc , char **argv){
    long start , end ;
    
    srand((unsigned)time(0)); 

    if(argc == 1){
        end = 1000 ;
    }
    else if(argc == 2){
        end = stol(argv[1]);
    }
    string alphabetical = "abcdefghijklmnopqrstuvwxyz" ;
    
    for(int i = 0 ; i < end ; i++){
        cout << alphabetical[(rand()%26)]  ; 
    }
    cout << endl ;
    return 0;
}