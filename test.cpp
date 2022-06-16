#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> table ;

void lps(const string &pattern){
    // a a b a a b a a a 
    int ptr = 0 , i = 1 ;
    
    while(i < pattern.size()){
        if(pattern[i] == pattern[ptr]){
            ptr++ ;
            table[i] = ptr ;
            i++ ;
        }
        else{
            if(ptr != 0){
                ptr = table[ptr-1];
            }
            else{
                // table[i] = 0 ;
                i++ ;
            }
        }
    }
}

int kmp(const string &haystack, const string &pattern){
    int ptr1 = 0 , ptr2 = 0 ;
    
    while(ptr1 < haystack.size()){
        if(haystack[ptr1] == pattern[ptr2]){
            ptr1++ ;
            ptr2++ ;
        }
        else{
            if(ptr2 != 0){
                ptr2 = table[ptr2-1];
            }
            else{
                ptr1++ ;
            }
        }
            if(ptr2 == pattern.size()){
                return ptr1-ptr2 ;
            }
    }
    return -1 ;
}

int strStr(const string A, const string B) {
    if(B.size() == 0 || A.size() == 0){
        return -1 ;
    }
    table.resize(B.size() , 0) ;
    lps(B);

    for(int ele : table){
        cout << ele << " " ;
    }

    return kmp(A , B);
}


int main()
{
    string A = "hello world" ;
    
    int N = A.size()-1 ;
    int slen = 0 ;
    
    while(N >= 0 and A[N] != ' '){
        N-- ; slen++ ;
    }

    cout << slen << endl ;

	return 0;
}