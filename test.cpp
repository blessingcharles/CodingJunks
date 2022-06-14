#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string countAndSay(int A) {
    string prev = "1" ;
    int ptr = 0 ;
    char cur_char ;
    int count = 0 ;
    
    A-- ;
    
    while(A--){
        string temp ;
        ptr = 0 ;
        while(ptr < prev.size()){
            cur_char = prev[ptr] ;
            ptr++ ;

            count = 1 ;
            while(ptr < prev.size() and prev[ptr] == cur_char){
                ptr++ ;
                count++ ;
            }    
            
            temp.push_back(count+'0');
            temp.push_back(cur_char);
        }
        prev = temp ;
    }
    
    return prev ;
}


int main()
{
    string str = "inttnikjmjbemrberk" ;

    cout << countAndSay(4) ;
}