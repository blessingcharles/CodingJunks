#include<iostream>
#include<bits/stdc++.h>
#include <cstdlib> 
#include <ctime> 

using namespace std  ;

int main(int argc , char **argv){
    long start , end ;
    
    srand((unsigned)time(0)); 

    if(argc == 1){
        start = 1 ;
        end = 1000 ;
    }
    else if(argc == 2){
        start = 1 ;
        end = stol(argv[1]);
    }
    else if(argc == 3){
        start =  stol(argv[1]) ;
        end = stol(argv[2]);
    }

    for(int i = start ; i < end ; i++){
        cout << (rand()%end) << "," ; 
    }
    cout << endl ;
    return 0;
}