#include<iostream>
#include<bits/stdc++.h>
#include "graph.h"

using namespace std ;


int main(int argc ,char  **argv){

    Graph *g = new Graph(6);

    g->addEdge(0,1,false);
    g->addEdge(0,4,false);
    g->addEdge(0,5,false);
    g->addEdge(1,2,false);
    g->addEdge(2,3,false);
    g->addEdge(5,4,false);

    g->topological_sort_dfs();
    return 0;
}