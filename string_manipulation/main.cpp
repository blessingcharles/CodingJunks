#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

void logger(string s){
    cout << s << endl;
}

void lps(vector<int> &table , string &s){
    int ptr = 0 , i = 1;

    while(i < s.size()){
        if(s[i] == s[ptr]){
            ptr++ ;
            table[i] = ptr;
            i++;
        }
        else{
            //not match
            if(ptr != 0){
                ptr = table[ptr-1];
            }
            else{
                table[i] = 0;
                i++ ;
            }
        }
    }
}

int kmp(string &s , string &pattern){
    int idx = -1;
    /* eg 
            string  : ababcabcababde

            pattern : a b a c a b d

            table   : 0 0 1 0 1 2 0 
    */

    vector<int> table(pattern.size() , 0);

    lps(table,pattern);

    for(auto ele : table){
        cout << ele << " " ;
    }
    int i = 0 , ptr = 0 ;
    while(i < s.size()){
        if(s[i] == pattern[ptr]){
            
            i++;
            ptr++;
            if(ptr == pattern.size()){
                return i-ptr ;
            }
        }
        else{
            if(ptr != 0) ptr = table[ptr-1];
            else i++ ;
        }
    }

    return idx ;
}

int main(int argc , char **argv){

    string s = "ababcabcababbde";
    string pattern = "abacabd";

    // cout << "hello world" ;
    cout << kmp( s,pattern ) << endl ;

    return 0;
}