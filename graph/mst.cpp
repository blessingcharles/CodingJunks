#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

class DSU{
    // union by rank (optimise set union function)
    // path compression optimisation (optimise set finding function)

private:
    int V;
    vector<pair<int,int>> l;
    int *parents ;
    int *rank ;

public:
    DSU(int V){
        this->V = V;
        this->parents = new int[V];
        this->rank = new int[V];

        for(uint16_t i = 0 ; i < V ; i++){
            this->parents[i] = -1;
            this->rank[i] = 1;
        }
    
    }

    void addEdge(int x , int y){
        this->l.push_back({x,y});
    }

    int find_set(int node){
        if(this->parents[node] == -1){
            return node ;
        }

        //path compression
        this->parents[node] = this->find_set(this->parents[node]);
        return this->parents[node];
    }

    bool union_set(int node1 , int node2){
        int s1 = find_set(node1);
        int s2 = find_set(node2);
        if(s1 != s2){
            // union by rank
            if(this->rank[s1] > this->rank[s2]){
                this->parents[s2] = s1;
                this->rank[s1] += this->rank[s2] ;
            }
            else{
                this->parents[s1] = s2;
                this->rank[s2] += this->rank[s1] ;
            }
            return true ;
        }
        //failed to join because cycle present
        return false ;
    }

    bool is_cyclic(){
        //initialising parents to -1(itself) and rank to 1

        fill(this->parents , this->parents+sizeof(this->parents) , -1);
        fill(this->rank , this->rank + sizeof(rank) , 1);

        for(auto info : this->l){
            if(!union_set(info.first , info.second)){
                //cycle present
                return true ;
            }
        }
        return false ;
    }

};

/*
Greeedy Methods

    Kruskals Algorithm
    1. Sort the edgelist by weight 
    2. pick a element and add it , if it doesnot contains cycle 
    3. Repeat 1 and 2

    Prims Algorithm
    1. In a min heap the start element with weight 0
    2. Take an element from top of heap add its neighbour to the heap , if its not visited
    2. Repeat 2 

*/
class WeightedGraph{

private:
    vector<pair<int,int>> *l ;
    int V = 0;

public:
    WeightedGraph(int V){
        this->V = V ;
        this->l = new vector<pair<int,int>>[V] ;
    }
    void addEdge(int x , int y , int weight = 1 , bool directed = false){
        l[x].push_back({weight , y});
        if(!directed)
            l[y].push_back({weight , x});
    }

    int prims(int start = 0){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        vector<bool> visited(this->V,false);

        pq.push({0,start});

        int mst_sum = 0;
        while (!pq.empty())
        {
            int weight = pq.top().first ;
            int node = pq.top().second ;
            pq.pop();

            if(visited[node]) continue ;
            
            visited[node] = true ;

            mst_sum += weight ;
            for(auto ele : this->l[node]){
                if(!visited[ele.second]){
                    pq.push({ele.first,ele.second});
                }
            }
        }
        return mst_sum ;
    }

    int kruskals(){
        int mst_sum = 0;
        vector<vector<int>> edgeList ;

        // making an edgelist of form {weight,x,y} 
        for(int i = 0 ; i < this->V ; i++){
            for(auto info : this->l[i]){
                edgeList.push_back({info.first , i,info.second});
            }
        }

        sort(edgeList.begin(),edgeList.end());

        DSU *dsu = new DSU(this->V);

        for(auto info : edgeList){
            int weight = info[0];
            int node1 = info[1];
            int node2 = info[2];

            if(dsu->union_set(node1 , node2)){
                mst_sum += weight ;
            }
        }

        return mst_sum;
    }

};

int main(int argc ,char  **argv){

    WeightedGraph *g = new WeightedGraph(4);


    g->addEdge(0,1,1);
    g->addEdge(0,3,2);
    g->addEdge(0,2,2);
    g->addEdge(1,3,3);
    g->addEdge(1,2,2);
    g->addEdge(2,3,3);

    cout << g->kruskals()<< endl ;

    return 0;
}