#include <iostream>

#include <bits/stdc++.h>
using namespace std ;

string graphColoring(vector<vector<int>>& adj, int n, int m)
{
    // two coloring problem
    vector<vector<int>> graph(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(adj[i][j] == 1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    vector<int> colored(n , 1);
    int maxColor = 1 ;
    vector<bool> visited(n , false);
    
    for(int node = 0 ; node < n ; node++){
        if(visited[node]) continue ;
        visited[node] = true ;
        // Do BFS
        queue<int> q ;
        q.push(node) ;
        while(not q.empty()){
            int curr = q.front() ; q.pop() ;
            for(int neigh : graph[curr]){
                if(colored[curr] == colored[neigh]){
                    colored[neigh] += 1 ;
                    maxColor = max({maxColor ,colored[neigh] , colored[curr]});
                    if(maxColor > m) return "No" ;
                }
                if(not visited[neigh]){
                    visited[neigh] = true ;
                    q.push(neigh);
                }
            }
        }   
        
    }
    return "Yes" ;
}
int main()
{
    vector<vector<int>> gg = {
        {0,0,0,0,0} ,
        {0,0,0,0,0} ,
        {0,0,0,1,0} ,
        {0,0,1,0,1} , 
        {0,0,0,1,0} , 
    }; 

    cout <<  graphColoring(gg , 5 , 2) ;

}