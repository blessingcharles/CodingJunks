#include<bits/stdc++.h>

using namespace std ;

class LFUCache
{
    unordered_map<int , list<pair<int,int>>> bucket ;
    unordered_map<int  , int> frequency ;
    unordered_map<int , list<pair<int,int>>::iterator > memo ;
public:
    int size = 0 ;
    int count = 0 ;
    int l_freq = 1 ;
    LFUCache(int capacity){
        size = capacity ;
    }
    int get(int key)
    {
        if(memo.find(key) == memo.end()) return -1 ;
        int last_freq = frequency[key] ;
        frequency[key]++ ;
        list<pair<int,int>>::iterator it = memo[key] ;
        pair<int,int> itp = *it ;
        
        bucket[last_freq+1].push_back({itp.first , itp.second}) ;
        memo[key] = --(bucket[last_freq+1].end()) ;
        
        bucket[last_freq].erase(it) ;
        if(bucket[last_freq].size() == 0 and l_freq == last_freq){
            l_freq++ ;
        }
        return itp.second ;
    }
    void put(int key, int value)
    {
        if(memo.find(key) != memo.end()){
            int last_freq = frequency[key] ; frequency[key]++ ;
            list<pair<int,int>>::iterator it = memo[key] ;
            
            bucket[last_freq+1].push_back({key , value}) ;
            
            memo[key] = --(bucket[last_freq+1].end()) ;
            
            bucket[last_freq].erase(it) ;
            if(bucket[last_freq].size() == 0 and l_freq == last_freq){
                l_freq++ ;
            }
            return ;
        }
        if(count == size){
//             remove the least frequent guy
            list<pair<int,int>>::iterator it = bucket[l_freq].begin() ;
            pair<int,int> itp = bucket[l_freq].front() ;
            bucket[l_freq].pop_front();
            memo.erase(itp.first);
            frequency.erase(itp.first);
            count-- ;
        }
        
        count++ ;
        bucket[1].push_back({key,value}) ;
        frequency[key] = 1 ;
        memo[key] = --(bucket[1].end()) ;
        l_freq = 1 ;
    }
};
