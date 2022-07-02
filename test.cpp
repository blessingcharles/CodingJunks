#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class DSU{
    vector<int> parents ;
    vector<int> ranks ;
    int N ;
public:
    DSU(int v){
        N = v ;
        parents.resize(N , -1);
        ranks.resize(N , 1);
    }
    int find_set(int node){
        if(parents[node] == -1){
            return node ;
        }
        return parents[node] = find_set(parents[node]);
    } 
    bool union_set(int n1 , int n2){
        int s1 = find_set(n1);
        int s2 = find_set(n2);
        if(s1 != s2){
            if(ranks[s1] > ranks[s2]){
                parents[s2] = parents[s1] ;
                ranks[s1] += ranks[s2] ;
            }
            else{
                parents[s1] = parents[s2]; 
                ranks[s2] += ranks[s1] ;
            }
            return true ;
        }
        return false ;
    }
};

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	// create a dummy point represents the well for each house with cost of well as the edge
    vector<vector<int>> edges ;
    
    for(int i = 0 ; i < pipes.size() ; i++){
        edges.push_back({pipes[i][2] , pipes[i][0]-1 , pipes[i][1]-1});
    }
    
    for(int i = 0 ; i < wells.size() ; i++){
        edges.push_back({wells[i],i,n}); // ith house to well of cost well[i]
    }
    sort(edges.begin() , edges.end());
    DSU *d = new DSU(wells.size()+1);
    int mstsum = 0 ;
    
    for(int i = 0 ; i < edges.size() ; i++){
        if(d->union_set(edges[i][1] , edges[i][2])){
            mstsum += edges[i][0] ;
        }    
    }
    return mstsum ;
}

int main()
{
    vector<int> wells = {1,4,4,4};
    vector<vector<int>> pipes = {{1,4,2},{1,2,1}};

    cout << supplyWater(4,2,wells,pipes);
    return 0 ;
}