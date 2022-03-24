#include<iostream>
#include<bits/stdc++.h>

#include "graph.h"

using namespace std ;

int snake_and_ladders(int size, vector<pair<int,int>> &snakes ,vector<pair<int,int>> &ladders ){

    //board starts from 1 to size
    vector<int> board(size+1 , 0);

    for(int i = 0 ; i < size+1 ; i++){
        board[i] = i ;
    }

    for(auto &snake : snakes){
        int s = snake.first ;
        int e = snake.second ;
        board[s] = e ;
    }

    for(auto &ladder : ladders){
        int s = ladder.first ;
        int e = ladder.second ;
        board[s] = e ;
    }

    Graph *g = new Graph(size+1);
    for(uint16_t i = 1 ; i < size+1 ; i++){
        for(uint8_t dice = 1 ; dice <= 6 ; dice++){
            int v = dice + i ;
            if(v < size+1)
                g->addEdge(i,board[v]);
        }
    }

    g->bfs(1,true);

    return 0 ;
}

int main(){
    vector<pair<int,int>> snakes = {{17,4},{20,6},{34,12},{24,16},{32,30}} ;
    vector<pair<int,int>> ladders = {{2,15} , {5,7} , {9,27} , {18,29} , {23,35}} ;

    int n = snake_and_ladders(36,snakes , ladders);

    return 0 ;
}