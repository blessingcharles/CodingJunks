#include <iostream>

#include<bits/stdc++.h>
using namespace std ;

void repeat(string &word , long count){
    count-- ;
    string ww = word ;
    while(count--){
        word += ww ;
    }
}
bool isNum(char ch){
    return ch >= '0' and ch <= '9' ;
}

string decodeString(string s)
{
    stack<string> st ;
    stack<string> res ;

    int ptr = s.size()-1 ;
    int closing_brackets = 0 ;
    while(ptr >= 0){
        if(s[ptr] == ']'){
            st.push("]");
            closing_brackets++ ;
            ptr-- ;
        }
        else if(s[ptr] == '['){
            closing_brackets-- ;
            //pop the strings untill ']' occurs
            string words = "" ;
            while(not st.empty() and st.top() != "]"){
                words += st.top() ; st.pop() ;
            }
            st.pop() ;
            ptr-- ;
            
            // get the count repeat it and push it onto the stack
            string count = "" ;
            while(ptr >= 0  and isNum(s[ptr])){
                count.push_back(s[ptr--]);
            }
            reverse(count.begin() , count.end());
            long cc = 1 ;
            if(count.size() > 0) cc = stol(count);
            repeat(words , cc);
            if(closing_brackets > 0)
                st.push(words);
            else
                res.push(words) ;
        }
        else{
            //form the strings
            int len = 0 ;
            while(ptr >= 0 and s[ptr] != '['){
                ptr-- ; len++ ;
            }
            st.push(s.substr(ptr+1 , len));
        }
    }
    string ans = "" ;
    while(not res.empty()){
        ans += res.top() ; res.pop() ;
    }
    return ans ;
}

int main()
{
    string exp = "3[a2[b]]" ;
    string exp1 = "abc2[abcd]2[z]" ;

    cout << decodeString(exp1);
}