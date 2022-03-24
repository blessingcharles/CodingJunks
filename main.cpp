#include<iostream>
#include<bits/stdc++.h>


using namespace std ;

    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 0 ;
        int next1 ;
        for(int i = 0 ; i < points.size() ; i++){
            int x2 = points[i][1] ;
            arrows++ ;
            
            if(i+1 < points.size()){
                next1 = points[i+1][0] ; 
        
                while(next1 <= x2){
                    i++;
                    if(i+1 >= points.size())
                        break ;

                    next1 = points[i+1][0] ; 

                }
            }
        }
        
        return arrows ;
    }


int main(){

    vector<vector<int>> a = {{10,16},{2,8},{1,6},{7,12}};

    findMinArrowShots(a);
}