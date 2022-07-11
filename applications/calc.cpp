#include<bits/stdc++.h>
using namespace std ;

// CALC 1  https://leetcode.com/problems/basic-calculator/
class CALC1 {
public:
    int N ;
    
    int evaluate(string &s , int &ptr){
        int sum = 0 , oper = 1 ;
        
        while(ptr < N and s[ptr] != ')'){
            if(s[ptr] == '('){
                ptr++ ;
                sum = sum + oper*evaluate(s , ptr) ;
                ptr++ ;
            }
            else if(s[ptr] == ' '){
                ptr++ ; continue ;
            }
            else if(s[ptr] == '+'){
                oper = 1 ;
                ptr++ ;
            }
            else if(s[ptr] == '-'){
                oper = -1 ;
                ptr++ ;
            }
            else{
                //build the numbers 
                string num = "" ;
                while(ptr < N and isdigit(s[ptr])){
                    num.push_back(s[ptr++]);
                }
                sum = sum + oper*stoi(num);
            }
        }
        return sum ;
    }
    int calculate(string s) {
        int ptr = 0 ;
        N = s.size() ;    
        return evaluate(s , ptr);
    }
};

// CALC2 https://leetcode.com/problems/basic-calculator-ii/
class CALC2 {
public:
    int calculate(string s) {
        stack<int> st ;
        char op = '+' ;
        
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i] == ' ') continue ;
            if(s[i] == '+') op = '+' ;
            else if(s[i] == '-') op = '-' ;
            else if(s[i] == '*') op = '*' ;
            else if(s[i] == '/') op = '/' ;
            else{
                int num = 0 ;
                while(i < s.size() and isdigit(s[i])){
                    num = num*10 + (s[i++]-'0');
                }
                i-- ; 
                if(op == '-') num = num*-1 ;
                else if(op == '*'){
                    num = num*st.top() ; st.pop() ;   
                }
                else if(op == '/'){
                    num = st.top()/num ; st.pop() ;
                }
                st.push(num) ;
            }
        }
        int sum = 0 ;
        while(not st.empty()){
            sum = sum + st.top() ;
            st.pop() ;
        }
        return sum ;
    }
};

// CALC 3