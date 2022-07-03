#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

#include<bits/stdc++.h>

vector<int> shortestAlternateColoredPath(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
{
    vector<bool> selfloops(n , false);
    
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0 ; i < redEdges.size() ; i++){
        if(redEdges[i][0] == redEdges[i][1]){
            selfloops[i] = true ;
        }
        graph[redEdges[i][0]].push_back({redEdges[i][1] ,1});
    }
    for(int i = 0 ; i < blueEdges.size() ; i++){
        if(blueEdges[i][0] == blueEdges[i][1]){
            selfloops[i] = true ;
        }
        graph[blueEdges[i][0]].push_back({blueEdges[i][1] ,2}) ;
    }
    vector<int> visited(n , -1);
    int curdist = 0 ;
    queue<pair<int,int>> q ; // {node , color}
    q.push({0,0});
    pair<int,int> curnode ;
    
    while(not q.empty()){
        int sz = q.size() ;

        while(sz--){
            curnode = q.front() ; q.pop() ;
            cout << curnode.first << " with color " << curnode.second << endl ;
            bool flag = true ;
            // special previlege
            if(visited[curnode.first] != -1 and selfloops[curnode.first]){
                cout << "[+] Settingprevilege \n";

                flag = false ;
                selfloops[curnode.first] = false ;
            }
            

            for(auto neigh : graph[curnode.first]){
                cout << "visiting " << neigh.first << "color " << neigh.second << endl ;
                // already visited
                if(flag and visited[neigh.first] != -1) continue ;
                //same color
                if(flag and curnode.second == neigh.second) continue ;
                
  
                cout << "pushing it" << endl ; 
                q.push(neigh);
            }
            if(visited[curnode.first] == -1)
                    visited[curnode.first] = curdist ;
            cout << "----------------\n" ;
        }
        curdist++ ;

    }
    visited[0] = 0 ;
    return visited ;
}
int main()
{
    vector<vector<int>> red  = {{0,1},{1,3}};
    vector<vector<int>> blue = {{1,1},{1,2}};

    for(auto ele : shortestAlternateColoredPath(4 , red , blue )){
        cout << ele <<  " " << endl ;
    }
    return 0 ;
}