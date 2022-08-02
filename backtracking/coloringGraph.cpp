#include<bits/stdc++.h>
using namespace std ;

int N ;
bool canIPlace(int cc , int node , vector<int> &color , vector<vector<int>> &adj){
    for(int i = 0 ; i < N ; i++){
        if(adj[i][node] == 1 or adj[node][i] == 1){
            if(color[i] == cc) return false ;
        }
    }
    return true ;
}
bool canColor(int node , vector<vector<int>> &adj , int m , vector<int> &color){
    if(node == N) return true ;
    for(int c = 1 ; c<= m ; c++){
        if(canIPlace(c , node , color , adj)){
            color[node] = c ;
            if(canColor(node+1 , adj , m , color)){
                return true ;
            }
            color[node] = 0 ;
        }
    }
    return false ;
}
string graphColoring(vector<vector<int>> &adj, int m) {
    N = adj.size() ;
    vector<int> color(N , 0 );
    return (canColor(0 , adj , m , color))?"YES":"NO" ;
}