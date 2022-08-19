#include<bits/stdc++.h>
#include<iostream>
#define MAXI 10 

using namespace std ;

// SEPERATE CHAINING
template<typename T>
class MyObject{
public:
    MyObject<T>* nxt ;
    int key ;
    T value ;
    MyObject(int k , T v){
        key = k  ;
        value = v ;
        nxt = NULL ;
    }
};

template<typename T>
class Hasher{
public:
    const int MAX_SIZE ;
    vector<MyObject<T> *> table ;
    int k ;
    Hasher(int s = 10 ): MAX_SIZE(s){
        table.resize(s) ;
    }

    int genHash(int key){
        return key%MAX_SIZE ;
    }
    void insert(int key , T value){
        int hash_idx = genHash(key) ;
        if(table[hash_idx] == NULL){
            table[hash_idx] = new MyObject<T>(key , value) ;
            return ;
        }

        MyObject<T>* curr = table[hash_idx] , *prev = NULL ;

        while(curr){
            if(curr->key == key){
                curr->value = value ;
                return ;
            }
            prev = curr ;
            curr = curr->nxt ;
        }
        prev->nxt = new MyObject<T>(key , value);
    }

    bool erase(int key){
        int hash_idx = genHash(key) ;
        MyObject<T>* curr = table[hash_idx] , *prev  = NULL ;

        while(curr){
            if(curr->key == key){
                break ;
            }
            prev = curr ;
            curr = curr->nxt ;
        }

        if(not curr){
            return false ;
        }
        if(prev == NULL){
            table[hash_idx] = NULL ;
        }
        else{
            prev->nxt = curr->nxt ;
        }
        delete curr ;
    }
    MyObject<T>* find(int key){
        int hash_idx = genHash(key) ;
        MyObject<T>* curr = table[hash_idx] , *prev ;

        while(curr){
            if(curr->key == key){
                break ;
            }
            prev = curr ;
            curr = curr->nxt ;
        }
        if(not curr){
            return NULL ;
        }
        return curr ;
    }
};

int main(){

    Hasher<string> *h = new Hasher<string>() ;

    h->insert(3, "ihufbef") ;
    h->insert(7 , "uibrifb") ;
    h->insert(17, "jibefib") ;

    cout << h->find(7)->value ;
    return 0 ;
}