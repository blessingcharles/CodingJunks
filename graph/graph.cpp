#include<iostream>
#include<bits/stdc++.h>
#include "graph.h"
using namespace std ;

Graph::Graph(int V){
        this->V = V ;
        this->l = new vector<int>[V];
    }

void Graph::addEdge(int v1 , int v2 ,bool undirected){
        this->l[v1].push_back(v2) ;
        if(undirected){
            this->l[v2].push_back(v1);
        }
    }
    
void Graph::bfs(int start,bool print_distance){
    
        queue<int> q;
        vector<bool> visited(this->V ,false );

        //helpful for finding the shortest path for all node from start
        vector<int> dist(V,0);
        
        q.push(start);
        visited[start] = true ;

        while(!q.empty()){
            int ele = q.front();

            for(auto vertice : this->l[ele] ){
                if(!visited[vertice]){
                    
                    dist[vertice] = dist[ele] + 1 ; // distance[parent] + 1 
                    
                    q.push(vertice);
                    visited[vertice] = true ;
                }
            }

            cout << ele << " " ;
            
            q.pop();
        }

        if(print_distance){
            cout << "\n\n[+]Shortest Path" << endl ;

            for(int i = 0 ; i < this->V ; i++){
                cout << start << " -- " << i << " = " << dist[i] << endl ;
            }
        }
    }

void Graph::dfshelper(int start , vector<bool> &visited , bool verbose){
    
    visited[start] = true ;

    if(verbose)
        cout << start << " -- " ;

    for(auto ele : this->l[start]){
        if(!visited[ele])
            Graph::dfshelper(ele , visited , verbose);
    }

}
void Graph::dfs(int start ,  bool verbose){
    
    vector<bool> visited(this->V , false) ;
    Graph::dfshelper(start , visited , verbose);

}

bool Graph::cyclic_find_helper(vector<bool> &visited, int node , int parent){

    visited[node] = true ;
    for(auto v : this->l[node]){
        if(!visited[v]){
            bool is_cycle = this->cyclic_find_helper(visited , v , node);
            if(is_cycle)
                return true ;
        }
        else if(v != parent)
            return true ;
    }

    return false ;
}

bool Graph::is_cyclic(){
    vector<bool> visited(this->V , false);
    return cyclic_find_helper(visited , 0 , -1);
}

void Graph::print(){

        for(int i = 0 ; i < V ; i++){
            cout << i << " = { " ;

            for(auto &ele : this->l[i]){
                    cout << ele << " , " ;
            }
            cout << " } " << endl ;
        }
    }

bool Graph::contains_cycle(){
    //directed graph
    vector<bool> visited(this->V , false);
    vector<bool> stack(this->V , false);

    for(uint16_t i = 0 ; i < this->V ; i++){
        if(!visited[i]){
            if(this->contains_cycle_helper(i,visited , stack)){
                return true ;
            }
        }
    }

    return false ;
}

bool Graph::contains_cycle_helper(int node , vector<bool> &visited , vector<bool> &stack){

    visited[node] = true ;
    stack[node] = true ;

    for(auto v : this->l[node]){
        if(stack[v])
            return true;
        else if(!visited[v]){
            if(this->contains_cycle_helper(v , visited , stack)){
                // if its descendent contains cycle
                return true ;
            }
        }
    }

    stack[node] = false ;
    return false ;
}

bool Graph::is_birpartite(){
    // check for odd number of nodes in a cycle
    vector<int> visited(this->V , 0);

    for(uint16_t i =0 ; i < this->V ;i++){
        if(!visited[i]){
            if(!this->is_bipartite_helper(i , visited ,1)){
                return false ;
            }
        }
    }

    return true ;
}

bool Graph::is_bipartite_helper(int node , vector<int > &visited , int color){


    visited[node] = color ;

    for(auto neighbour : this->l[node]){
        if(!visited[neighbour]){
            if(!this->is_bipartite_helper(neighbour , visited , 3-color)){
                return false ;
            }
        }
        else if(visited[neighbour] == color){
            return false ;
        }
    }
    return true ;
}

void Graph::topological_sort(){

    //kahn's algorithm (based on number of indegree if indegree == 0 --> no dependency )
    
    vector<int> indegree(this->V , 0);
    queue<int> q ;

    for(uint32_t i = 0 ; i < this->V ; i++){
        for(auto neighbour : this->l[i]){
            indegree[neighbour]++ ;
        }
    }

    //finding nodes with degree 0 ie. no dependency

    for(uint32_t i = 0 ; i < this->V ; i++ ){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    cout << "[+]Topological Sorting " << endl ;

    while(!q.empty()){
        int node = q.front();
        cout << node << " - " ;

        for(auto neighbour : this->l[node]){
            indegree[neighbour]-- ;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
        q.pop();
    }
}

void Graph::topological_sort_dfs(){
    vector<bool> visited(this->V , false);
    list<int> ordering;

    for(uint32_t i = 0 ; i < this->V ;i++){
        if(!visited[i]){
            this->topological_sort_dfs_helper(i,visited , ordering);
        }
    }

    cout << "[+] TOPOLOGICAL SORT USING DFS" << endl ;

    for(auto ele : ordering){
        cout << ele << "  " ;
    }
    cout << endl ;

}

void Graph::topological_sort_dfs_helper(int node , vector<bool> &visited , list<int> &ordering){
    visited[node] = true ;

    for(auto neighbour : this->l[node]){
        if(!visited[neighbour]){
            this->topological_sort_dfs_helper(neighbour , visited , ordering);
        }
    }

    ordering.push_front(node);

}
