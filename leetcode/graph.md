1. [redundant connection 2](https://leetcode.com/problems/redundant-connection-ii/)
```cpp
class DSU{
public:
    vector<int> parent ;
    vector<int> rank ;
    
    DSU(int n){
        parent.resize(n , -1);
        rank.resize(n ,1);
    }
    
    int getParent(int node){
        if(parent[node] == -1)
            return node ;
        
        return parent[node] = getParent(parent[node]);
    }
    
    bool union_set(int node1 , int node2){
        int p1 = getParent(node1) ;
        int p2 = getParent(node2) ;
        
        if(p1 != p2){
            int r1 = rank[p1] ;
            int r2 = rank[p2] ;
            
            if(r1 >= r2){
                parent[p2] = p1 ;
                rank[p1] += rank[p2] ;
            }
            else{
                parent[p1] = p2 ;
                rank[p2] += rank[p1] ;
            }
            return true ;
        }
        return false ;
    }
} ;
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(edges.size()+1 , 0) ;
        
        int edgeRemoved = -1 ;
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] ;
            
            if(parent[v] != 0){
                edgeRemoved = i ;
                break ;
            }
            else{
                parent[v] = u ;
            }
        }
        
        DSU *d = new DSU(edges.size()+1) ;
        int cyclic_edge = -1 ;
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] ;
            if(i == edgeRemoved) 
                continue ;
            if(not d->union_set(u , v)){
                cyclic_edge = i ;
                break ;
            }
        }
        if(edgeRemoved == -1)
            return edges[cyclic_edge] ;
        
        // cout << edgeRemoved << " " << cyclic_edge << endl ;
        if(cyclic_edge != -1){
            int v = edges[edgeRemoved][1] ;
            int u = parent[v] ;
            return {u , v} ;
        }
        return edges[edgeRemoved] ;
    }
};
```