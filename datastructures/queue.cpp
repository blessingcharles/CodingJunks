#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue {
// using stacks
    stack<int> st1 ;
    stack<int> st2 ;
    public:
    Queue() {}
    void enQueue(int val) {
        st1.push(val);
    }
    void fillMe(){
        while(not st1.empty()){
            st2.push(st1.top()) ; st1.pop();
        }
    }
    int deQueue() {
        if(isEmpty()) return -1 ;
        if(st2.empty()){
             fillMe();
        }
        int ele = st2.top() ;
        st2.pop() ;
        return ele ;
    }

    int peek() {
        if(isEmpty()) return -1 ;
        if(st2.empty()){
             fillMe();
        }
        int ele = st2.top() ;
        return ele ;
    }

    bool isEmpty() {
       return (st1.empty() and st2.empty()) ;
    }
};