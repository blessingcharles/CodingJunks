#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<typename T> class Node{
public:
    T val ;
    Node* nxt ;
    Node(){
        this->nxt = NULL ;
    };
    Node(T value){
        this->val = value ;
        this->nxt = NULL ;
    }
};

template<typename T> class MyStack{

public:
    Node<T> *head ;
    MyStack(){
        head = NULL ;
    }    
    void push(T val){
        if(not head){
            head = new Node<T>(val);
        }else{
            Node<T>* temp = new Node<T>(val);
            temp->nxt = head ;
            head = temp ;
        }
    }    
    void pop(){
        if(not head){
            return ;
        }
        Node<T> *temp = head ; 
        head = head->nxt ;
        delete temp ; 
    }
    int top(){
        if(not head){
            return -1 ;
        }
        return head->val ;
    }
    bool isEmpty(){
        return head == NULL ;
    }
};


int main()
{
    MyStack<int> *st = new MyStack<int>(); 

    st->push(5);
    st->push(10);
    cout << st->top() ;

    return 0;
}