#include<iostream>
#include<bits/stdc++.h>
#include "helper.h"

using namespace std ;
int set_m_bits_in_number(int n , int m , int i , int j){
    n = clearRangeOfBits(n,i,j);
    int mask = (m << i) ;
    return (n|mask) ;
}

int bin(int n){
    int ans = 0;
    int pow = 1;
    while(n > 0){

        int last_bit = n&1;
        ans = ans + pow*last_bit;
        pow = pow*10 ;

        n >>= 1 ;
    }

    return ans ;
}


int unique_number_1(vector<int> &arr){
    //2n+1 find the number which doesnot repeat twice {1,2,3,8,8,1,3,9,0,9,0};

    int xor_value = 0 ;
    for(auto ele : arr){
        xor_value ^= ele ;
    }
    return xor_value ;
}
void process_bits(int ele , vector<int> &helper){
    for(uint8_t i = 0 ; i < 32 ; i++){
        helper[i] += (ele&1) ;
        ele = ele>>1 ;
    }
}
int bin_to_dec(vector<int> &helper){
    int result = 0 ;

    for(uint8_t i = 0 ; i < 32 ;i++){
        result += helper[i]*(1<<i);
    }
    return result ;
}
int unique_number_2(vector<int> &arr){
    //mn+1 [m = 3,4,5...] find the unique which does repeat m times 
    /*
        loop arr :
            sum each ith bit of all elements of array and store it in help[32]
        loop help:
            ele%m
        bin_to_number(help)
    */

   // eg : 3n+1  {1,2,2,2,3,5,3,3,5,5};

   vector<int> helper(32,0);
   for(auto ele : arr){
       process_bits(ele,helper);
   }
   for(uint8_t i = 0 ; i < 32 ;i++){
       helper[i] %= 3 ;
   }

   return bin_to_dec(helper);

}


void overlay(string &s , int number){
    int i = 0;
    while(number > 0){
        uint8_t last_bit = (number&1);
        if(last_bit){
            cout << s[i] ;
        }
        i++ ;
        number >>= 1 ;
    }
    cout << endl ;

}
void find_subset(string &s){
    int n = (1<<s.size());

    for(uint32_t i = 0 ; i < n ; i++){
        overlay(s , i);
    }
}

int main(int argc , char **argv ){

    vector<int> arr =  {1,2,2,2,3,5,3,3,5,5};

    string s = "abc";

    find_subset(s);

    return 0 ;
}