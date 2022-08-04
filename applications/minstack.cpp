#include<bits/stdc++.h>
using namespace std ;

class minStack
{
    stack<int> st ;
    stack<int> mini ;
	public:
		minStack(){ 
		}
		void push(int num){
            st.push(num) ;
            if(mini.empty() or mini.top() >= num){
                mini.push(num);
            }
		}
		int pop()
		{
            if(isEmpty()) return -1 ;
            int ele = st.top() ; st.pop() ;
            if(mini.top() == ele){
                mini.pop() ;
            }
            return ele ;
        }
		int top()
		{
            if(isEmpty()) return -1 ;
            return st.top() ;
        }
		int getMin()
		{
            if(isEmpty()) return -1 ;
            return mini.top() ;
        }
        bool isEmpty(){
            return st.empty() ;
        }
};