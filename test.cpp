#include<bits/stdc++.h>
#define VIJAY main
using namespace std ;

class Object{
public:
    virtual void draw(){
        cout << "parent" ;
    }
    void eat(){
        cout << "parent eating" ;
    }
};

class Derived : public Object{
public:
    void draw(){
        cout << "child " ;
    }

    void eat(){
        cout << " child eating" ;
    }
};

int VIJAY(){
    Object *o = new Derived() ;
    o->draw() ;
    o->eat() ;
    
    return 0 ;
}