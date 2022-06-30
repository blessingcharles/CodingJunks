#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7 ;

int findSums(int  curnode , vector<vector<int>> &graph ,vector<int> &pathsum ,int parent , vector<int> &cost){
    int totalsum = 0 ;
    
    for(int neigh : graph[curnode]){
        if(neigh == parent) continue ;
        totalsum = (totalsum + findSums(neigh , graph ,pathsum , curnode , cost)%mod)%mod ;
    }
    
    return pathsum[curnode] = (totalsum + cost[curnode-1]%mod)%mod ;
    
}
int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A.size()+1);
    
    for(int i = 0 ; i < B.size() ; i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    vector<int> pathsum(A.size()+1 , 0);
    long totalsum = findSums(1 , graph , pathsum , -1 , A);
    long maxsum = 0 ;
    
    for(int i = 0 ; i < B.size() ; i++){
        int node1 = B[i][0] ;
        int node2 = B[i][1] ;

        if(totalsum != pathsum[node1]){
            long sum1 = totalsum - pathsum[node1]%mod ;
            long sum2 = pathsum[node1]%mod ;

            maxsum = max(maxsum , (sum1*sum2)%mod) ;
        }
        else{
            long sum1 = totalsum - pathsum[node2]%mod ;
            long sum2 = pathsum[node2]%mod ;

            maxsum = max(maxsum , (sum1*sum2)%mod) ;
        }
    }
    return maxsum ;
}
int main(){
    vector<int> arr = {10, 5, 12, 6};
    vector<vector<int>> edges = {
        {1, 2},
        {1, 4},
        {4, 3}
    };
    cout << deleteEdge(arr , edges);

    return  0 ;
}