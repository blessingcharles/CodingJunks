## Graphs

#### Graph vs tree

-   Trees doesnot have cycles
-   Only one path exists between two nodes
-   Root node present in tree
-   Tree is a basically a subset of graph

#### Representations

1. Adjacency Matrix
2. Adjacency List
3. Edge List

#### Usage of dfs

1. Detecting cycle in a graph

    - directed graph [make use of stack to keep track of ancestors]
    - undirected graph [if visited and also not parent]

2. path finding
    - help to find all possible paths between src node and dst node
3. Topological Sorting [Graph should be DAG] (_kahn's algorithm can also be used_)

    - mostly used to solve dependency order

4. Bipartite Graph
    - Coloring a graph with two colors , with neither two adjacent neighbors have same color
5. Strongly connected components
    - In a Directed Graph how many components can be formed [A component is nothing but , a node in a
      component can reach all nodes in the component]

#### Union-Find

1. undirect graph cyclic detection

#### Minimum Spanning Tree

-   Spanning Tree of a graph is a subgraph than connects all Vertices in (V-1) edges , where minimum spanning
    tree the weight of total V-1 edges is minimised .
-   No. of Spanning tree = E\*C(v-1) - no of cycles .

-   Algorithms
    1. Kruskals Algorithm
    2. Prims Algorithm

#### Shortest Path

1. BFS (sssp on unweighted graph)
2. djisktra (sssp on weighted graph)
3. bellman ford (sssp on weighted graph with -ve edges)[but doesnot work for graph with -ve cycled edges]
4. floyd warshall (apsp on all graphs)
