#ifndef HELPER_H
#define HELPER_H
#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

/*
    //left shift  x << n ====  (x)2^n
    int a = 5 ;
    a = a<<2 ;    // a = 20    (4*5)

    //right shift   x >> 1 ===== (x)/2^n
    a = a>>1 ;  // a = 10     20/2

*/
bool is_power_of_two(int number){
    if((number & (number-1)) == 0 ){
        return true ;
    }
    return false ;
}

int count_bits(int number){
    
    int count = 0 ;

    while(number > 0){
        count += (number&1) ;
        number >>= 1 ;
    }
    return count ;
}

int getNthBit(int number , int n){

    int mask = (1<<n);
    return (number&mask > 0)?1:0 ;

    // if(n <= 0)
    //     return (number&1) ;

    // return (number >> n)&1 ;

}
int setNthBit(int number , int n){
    int mask = (1<<n) ;
    return (number|mask) ;
}   

int clearNthBit(int number , int n){

    int mask = ~(1 << n) ;
    return (number&mask) ;

}

int updateNthBit(int number , int n , int value){

    if(value == 1){
        return setNthBit(number , n) ;
    }
    return clearNthBit(number , n);
}

int clearLastNBits(int number , int n){
    int mask = (-1 << n) ;
    return (number&mask);

}

int clearRangeOfBits(int number , int i , int j){
    int mask1 = ~(-1 << i) ;
    int mask2 =  (-1 << j+1) ;

    return number&(mask1|mask2) ;
}


#endif