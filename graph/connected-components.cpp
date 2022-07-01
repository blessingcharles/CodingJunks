#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Strongly Connected Components (Kosaraju's Algorithm)

    Algo
    1) Use topological sort dfs to build a stack
    2) Reverse the edges of graph
    3) pop each element and explore it to make it a single component

    Intuition

    1) Each component doesn't have a cycle [because if they have , they can be combined into one]
    2) A component which have a path to other component , then atleast one element in the component
        should come at top of stack .
        [So reversing the edges , thus each component get explored seperately]
    
    Use Case
    1. Use to find whether a mother vertex exists (directed graph)
    2. group of strongly strongly connected components
*/

class Graph
{

public:
    int V;
    vector<int> *l;

    Graph(int V)
    {
        this->V = V;
        this->l = new vector<int>[V];
    }

    void addEdge(int src, int dst, bool directed = true)
    {
        this->l[src].push_back(dst);
        if (!directed)
            this->l[dst].push_back(src);
    }
    void print()
    {
        for (int i = 0; i < this->V; i++)
        {
            cout << i << "--> ";
            for (auto neighbours : this->l[i])
            {
                cout << neighbours << ",";
            }
            cout << endl;
        }
    }
    void fill_orderely(stack<int> &order_s,vector<bool> &visited , int node);
    void strongly_connected_components();
    void print_strong_components(vector<bool> &visited , stack<int> &order_s);
    void dfs(vector<bool> &visited , int node);
    Graph* reverse_graph();
};

void Graph::fill_orderely(stack<int> &order_s ,vector<bool> &visited , int node){
    visited[node] = true ;

    for(auto neigh : this->l[node]){
        if(!visited[neigh]){
            fill_orderely(order_s , visited , neigh);
        }
    }
    order_s.push(node);
    cout << node << " " ;
}

void Graph::strongly_connected_components(){
    
    /* Kosaraju's Algorithm */

    // fill orderely
    stack<int> order_s ;
    vector<bool> visited(this->V , false);

    this->fill_orderely(order_s ,visited , 0);
    Graph *reversed_graph = this->reverse_graph();
    for(int i = 0 ; i < this->V ; i++){
        visited[i] = false ;
    }
    reversed_graph->print_strong_components(visited , order_s);
}
void Graph::dfs(vector<bool> &visited , int node){
    visited[node] = true ;
    cout << node << "  " ;
    for(auto neigh : this->l[node]){
        if(!visited[neigh]){
            dfs(visited , neigh);
        }
    }
}
void Graph::print_strong_components(vector<bool> &visited , stack<int> &order_s){

    int components_count = 1 ;
    while(!order_s.empty()){
        int node = order_s.top();
        order_s.pop();
        if(!visited[node]){
            cout << "\nComponent " << components_count  << endl ;
            dfs(visited , node);
            components_count++ ;
        }

    }
}

Graph* Graph::reverse_graph(){
    Graph* reversed_graph = new Graph(this->V);

    for(int i = 0 ; i < this->V ; i++){
        for(auto neigh : this->l[i]){
            reversed_graph->addEdge(neigh , i) ;
        }
    }
    return reversed_graph ;
}

int main()
{
    freopen("inp.txt", "r", stdin);

    int vertice = 0, edges = 0;
    cin >> vertice >> edges;

    Graph *g = new Graph(vertice);
    int src, dst;
    for (int i = 0; i < edges; i++)
    {
        cin >> src >> dst;
        g->addEdge(src, dst);
    }
    g->print();

    g->strongly_connected_components();

    return 1;
}
