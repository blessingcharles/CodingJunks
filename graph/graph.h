#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#include<bits/stdc++.h>

class Graph{
    //adjacency list
private:
    int V = 0;
    std::vector<int> *l ;
public:

    Graph(int V);
    void addEdge(int v1 , int v2 ,bool undirected = true);
    void bfs(int start = 0,bool print_distance = false );
    void dfshelper(int start , std::vector<bool> &visited , bool verbose = false);
    void dfs(int start ,bool verbose = false);
    bool is_cyclic();  // for undirected graph
    bool contains_cycle(); //directed graph
    bool is_birpartite();
    void topological_sort();
    void topological_sort_dfs();
    void print();

private:
    bool cyclic_find_helper(std::vector<bool> &visited, int node , int parent); // for undirected graph
    bool contains_cycle_helper(int node , std::vector<bool> &visited , std::vector<bool> &stack ); // for directed graph
    bool is_bipartite_helper(int node , std::vector<int> &visited , int color);
    void topological_sort_dfs_helper(int node , std::vector<bool> &visited , std::list<int> &order);

};
#endif