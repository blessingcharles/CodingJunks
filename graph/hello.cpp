#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

int shortestPathGrid(vector<vector<int>> &grid){
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        
        distance[0][0] = grid[0][0];
        set<Node,Compare> q;

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        q.insert(Node(0 , 0,distance[0][0]));
        
        while(!q.empty()){
            auto it = q.begin();
            int cx = it->x ;
            int cy = it->y ;
            int cd = it->dist;
            q.erase(it);

            for(int i = 0 ; i < 4 ; i++){
                int x = cx + dx[i];
                int y = cx + dy[i];
                
                if(x >= 0 and y >= 0 && x < m && y < n &&  cd + grid[x][y] < distance[x][y] ){
                    Node temp(x,y,distance[x][y]);
                    if(q.find(temp) != q.end()){
                        q.erase(q.find(temp));
                    }

                    distance[x][y] = cd + grid[x][y] ;
                    cout << x << " " << y << " " << distance[x][y] << endl ; 
                    q.insert(Node(x,y,distance[x][y]));
                }
            }
        }
        return distance[m-1][n-1];
    }    


int main(){
    vector<vector<int>> grid = {{31,100,65,12,18},
                                {10,13,47,157,6},
                                {100,113,174,11,33},
                                {88,124,41,20,140},
                                {99,32,111,41,20}};
                        
    cout << shortestPathGrid(grid);
	return 0;
}