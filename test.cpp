#include <iostream>
#include<bits/stdc++.h>

using namespace std ;
bool isOperator(char ch){
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' ;
}
int mod = 1e9+7 ;

int calc(long num1 , long num2 , char op){
    if(op == '+'){
        return (num1+num2)%mod ;
    }   
    else if(op == '-'){
        return (num1-num2) ;
    }
    else if(op == '*'){
        return (num1*num2)%mod ;
    }
    else{
        return (num1/num2) ;
    }
    return 0 ;
}

int evaluatePostfix(string &exp) {
    stack<string> st ;
    int N = exp.size() ;
    if(N == 0) return 0 ;
    
    for(int i = 0 ; i < N ; i++){
        if(isOperator(exp[i])){
            long num2 = stol(st.top()) ; st.pop() ;
            long num1 = stol(st.top()) ; st.pop() ;
            
            int res = calc(num1 , num2 , exp[i]);
            st.push(to_string(res));
            i++ ;
        }
        else{
            //build the digits untill space character occurs
            string num = "" ;
            while(i < N and exp[i] != ' '){
                num.push_back(exp[i++]);
            }
            st.push(num);
        }
    }
    return stoi(st.top());
}

int main()
{
    string exp = "" ;
    cout << evaluatePostfix();
}