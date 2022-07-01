#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Point{
public:
    int x ;
    int y ;
    int cost ;   
};

struct Comparator{
    bool operator()(const Point &p1 , const Point &p2){
        return p1.cost > p2.cost ;
    }    
};
int RM , CM ;
bool isInvalid(int row , int col){
    return row < 0 or col < 0 or row >= RM or col >= CM ;
}

int knight(int ROW, int COL, int C, int D, int E, int F) {
    if(ROW == 1 and COL == 1) return 0 ;
    
    RM = ROW+1 ; CM = COL+1 ;
    
    vector<vector<int>> board(ROW+1 , vector<int>(COL+1 , INT_MAX));
    board[C][D] = 0 ;
    priority_queue<Point , vector<Point> , Comparator> pq ; 
    pq.push({C , D , 0 });
    
    int dx[] = {2,1,-1,-2,2,1,-2,-1};
    int dy[] = {-1,-2,-2,-1,1,2,1,2};
    Point curnode ;
    
    while(not pq.empty()){
        curnode = pq.top() ; pq.pop() ;
        if(curnode.x == E and curnode.y == F) return curnode.cost ;
        
        for(int i = 0 ; i < 8 ; i++){
            int neigh_x = curnode.x + dx[i] ;
            int neigh_y = curnode.y + dy[i] ;
            int cost = curnode.cost + 1 ;
            
            if(isInvalid(neigh_x , neigh_y) or board[neigh_x][neigh_y] <= cost) continue ;
            
            if(neigh_x == E and neigh_y == F){
                cout << curnode.x << " " << curnode.y << endl ;
            }
            board[neigh_x][neigh_y] = cost ;
            
            pq.push({neigh_x , neigh_y , cost});
        }           
        
    }
    
    return (board[E][F] == INT_MAX)?-1:board[E][F] ;
}
int main()
{

    cout << knight(2,20,1,18,1,5);

    return 0;
}