#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
class Animal{

    public:
        string name = "animal" ;
        void display(){
            cout << "Animal" ;
        }

        // virtual void move() = 0 ;
};

class Dog : public Animal {
public:
string name ;
    
    static void display(){
        cout << "Dog" << endl ;
    }

    string operator ()(string mm){
        cout << mm  << endl ;
      
        return "hello" ; 
    }

    void move() ;
};

void Dog::move(){

}

int main(){

    Dog d1 = Dog() ;

    d1.name = "d1" ;
    Dog d2 = d1 ;

    long long a = 1LL ;

    cout << a ;
    // cout << d->name << endl ;
}