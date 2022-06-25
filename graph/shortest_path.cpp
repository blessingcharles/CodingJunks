#include<iostream>
#include<bits/stdc++.h>

/*
Problems
Shortest Path:
    https://leetcode.com/problems/network-delay-time/
    https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
    https://leetcode.com/problems/cheapest-flights-within-k-stops/

*/
using namespace std ;

class Node{
public:
	int x;
	int y;
	int dist;

	Node(int x,int y,int dist){
		this-> x = x;
		this->y = y;
		this->dist = dist;
	}
};

//comparator should return boolean value, 
// indicating whether the element passed as 
// first argument is considered to go before the second in the specific strict weak ordering
class Compare{
public:
	bool operator()(const Node &a,const Node &b){
		return a.dist <= b.dist;
	}
};

/*
1) BFS (sssp on unweighted graph)
2) djisktra (sssp on weighted graph)
3) bellman ford (sssp on weighted graph with -ve edges)[but doesnot work for graph with -ve cycled edges]
4) floyd warshall (apsp on all graphs)
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

    int djisktra(int src , int dest , bool verbose = true){
        /*
            Greedy Algorithm
                visit src node and add its neighbour to the set
                    select shortest edge from the queue and visit it
        */
        
        set<pair<int,int>> q;
        vector<int> dist(this->V , INT_MAX);

        dist[src] = 0;
        q.insert({0,src});

        while(!q.empty()){
            auto it = q.begin();
            int distance = it->first;
            int node = it->second;
            q.erase(it);

            for(auto neighbour : this->l[node]){
                if(neighbour.first + distance < dist[neighbour.second]){
                    if(q.find({dist[neighbour.second] , neighbour.second}) != q.end()){
                        q.erase({dist[neighbour.second] , neighbour.second});
                    }

                    dist[neighbour.second] = neighbour.first + distance ;
                    q.insert({dist[neighbour.second],neighbour.second});
                }
            }
        }

        if(verbose){
            for(int i = 0 ; i < this->V ; i++){
                cout << src << " -- " << i << " = " << dist[i] << endl ;
            }
        }

        return dist[dest];
    }

    int bellmanFord(int src , int dest , bool verbose = true){
        
        //can handle negative edges
        // but can't handle cycle with negative edges
        /*
            Relax V-1 times of all edges
                Relaxation if dist[v] > dist[u] + wt(u,v)
        */

        vector<int> dist(this->V , INT_MAX);
        dist[src] = 0;

        for(int n = 0 ; n < this->V-1 ; n++){
           // relax all the edges
           for(int i = 0 ; i < this->V ; i++){
               
                if(dist[i] == INT_MAX) continue;

                for(auto neighbours : this->l[i]){
                    int weight = neighbours.first ;
                    int y = neighbours.second ;

                    if(dist[y] > dist[i] + weight ){
                        dist[y] = dist[i] + weight ;
                    }
                }
           }
        }

        if(verbose){
            for(int i = 0 ; i < this->V ; i++){
                cout << src << " -- " << i << " = " << dist[i] << endl ;
            }
        }
       return dist[dest] ;
       
    }

    vector<vector<int>> floydWarshall(bool verbose = true){
        /*
            iterate vertices times :
                represent k as the intermediate vertice for (i)---(k)---(j)
                    update if dist[i][j] > dist[i][k] + dist[k][j]

        */

        vector<vector<int>> dp(this->V , vector<int>(this->V , INT_MAX));

        // updating the weights src --> dst dp[src][dst] = weight 
        for(uint16_t i = 0 ; i < this->V ; i++){
            for(auto ele : this->l[i]){
                dp[i][ele.second] = ele.first ;
            }
        }

        for(uint16_t k = 0 ; k < this->V ;k++ ){
            for(uint16_t i  = 0 ; i < this->V ; i++){
                for(uint16_t j = 0 ; j < this->V ; j++){
                    if(i == j){
                        dp[i][j] = 0;
                        continue;
                    }
                    if(dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) continue;
                    if(i == k || j == k) continue;
                    if(dp[i][j] > dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] + dp[k][j] ;
                    }
                }
            }
        } 

        if(verbose){
            for(uint16_t i = 0 ; i < this->V ; i++){
                cout << "SRC " << i << endl ;
                for(uint16_t j = 0 ; j < this->V ; j++){
                    cout << j << " = " << dp[i][j] << " | " ;
                }
                cout << endl ;
            }
        }

        return dp;

    }

    int shortestPathGrid(vector<vector<int>> &grid){
        //return the shortest path len
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m , vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];
        set<Node,Compare> s;
        s.insert(Node(0,0,dist[0][0]));
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!s.empty()){
            auto it = s.begin();
            int cx = it->x;
            int cy = it->y;
            int cd = it->dist;
            s.erase(it);
            for(int k = 0 ; k < 4 ; k++){
                int x = cx + dx[k];
                int y = cy + dy[k];
                
                if(x >= 0 and x < m and y >= 0 and x < n and cd + grid[x][y] < dist[x][y]){
                    
                    Node temp(x,y,dist[x][y]);
                    if(s.find(temp)!=s.end()){
                        s.erase(s.find(temp));
                    }
                    dist[x][y] =  cd + grid[x][y] ;
                    s.insert(Node(x,y,dist[x][y]));
                }
            }
        }

        return dist[m-1][n-1];
    }

};

int main(int argc ,char  **argv){
    WeightedGraph *g = new WeightedGraph(5);

    g->addEdge(0,1,1);
    g->addEdge(1,2,1);
    g->addEdge(0,2,4);
    g->addEdge(0,3,7);
    g->addEdge(3,2,2);
    g->addEdge(3,4,3);

    vector<vector<int>> grid = {{31,100,65,12,18},
                                {10,13,47,157,6},
                                {100,113,174,11,33},
                                {88,124,41,20,140},
                                {99,32,111,41,20}};
                        
    cout << g->shortestPathGrid(grid);

    return 0;
}