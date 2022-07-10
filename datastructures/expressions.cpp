/*
 Infix to postfix

    1. If operand print it
    2. If operator
        if prec(stack.top()) >= prec(operator) print(st.pop())
        stack.push(operator)
*/

/*
    Infix to prefix
    1. Reverse infix expression
    2. perform postfix
    3. Reverse the postfix
*/

/*
    Prefix to infix
    1. Reverse prefix
    2. 
        a. if operand push to stack
        b. if operator
            ele1 = st.pop() ;
            ele2 = st.pop() ;
            push --> (ele1 operator ele2)
*/


#include<bits/stdc++.h>
using namespace std ;
bool isOperator(char ch){
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' ;
}

string prefixToInfixConversion(string &s)
{
	reverse(s.begin() , s.end());
    stack<string> st ;
    for(char ch : s){
        if(isOperator(ch)){
            string ele1 = st.top() ; st.pop() ;
            string ele2 = st.top() ; st.pop() ;
            
            string exp = "(" + ele1 + ch + ele2 + ")" ;
            st.push(exp) ;
        }
        else{
            st.push(string(1,ch));
        }
    }
    return st.top() ;
}
