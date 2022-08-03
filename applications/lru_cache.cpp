#include<bits/stdc++.h>
using namespace std ;

class LRUCache
{
public:
unordered_map<int , list<pair<int,int>>::iterator > memo ;
    list<pair<int,int>> dl ;
    int capacity ;
    
    LRUCache(int capacity)
    {
        this->capacity = capacity ;
    }
    int get(int key){
         unordered_map<int , list<pair<int,int>>::iterator>::iterator it = memo.find(key) ;
        
        if(it == memo.end())
            return -1 ;
        
        dl.splice(dl.begin() ,dl,it->second);
        return it->second->second ;
        
    }
    void put(int key, int value){
          unordered_map<int , list<pair<int,int>>::iterator>::iterator it = memo.find(key);
        if(it != memo.end()){
            it->second->second = value ;
            dl.splice(dl.begin() , dl , it->second);
            return ;
        }
        if(memo.size() == capacity){
            memo.erase(dl.back().first) ;
            dl.pop_back() ;
        }
        dl.push_front({key,value});
        memo[key] = dl.begin();
    }
};
