#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Here i have simply implemented dijkstra algorithm
// idea to find distance from c to every node and find
// distance from d to every node
//  and then simply calculate the ans by distance from
// c to e[0] and distance between d to e[1] + distance
//  of the e[0] to e[1] and vice versa i.e. c to e[1]
// and d to e[0] + distance of the e[0] to e[1]
//  this will give you ans

void fun(int src, vector<int> &dist, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int dst = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            if (dist[it.first] > dist[node] + it.second)
            {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

int solve(int A, vector<vector<int>> &B, int C, int D, vector<vector<int>> &E)
{
    vector<int> dist1(A + 1, INT_MAX);
    vector<int> dist2(A + 1, INT_MAX);
    vector<pair<int, int>> adj[A + 1];

    for (int i{0}; i < B.size(); i++)
    {
        adj[B[i][0]].push_back({B[i][1], B[i][2]});
        adj[B[i][1]].push_back({B[i][0], B[i][2]});
    }

    fun(C, dist1, adj);
    fun(D, dist2, adj);
    // for(int i{1}; i<dist1.size(); i++)cout<<dist2[i]<<" ";
    int ans = INT_MAX;
    if (dist1[D] != INT_MAX)
        ans = dist1[D];
    for (int i{0}; i < E.size(); i++)
    {
        if (dist1[E[i][0]] != INT_MAX && dist2[E[i][1]] != INT_MAX)
            ans = min({ans, dist1[E[i][0]] + dist2[E[i][1]] + E[i][2], dist1[E[i][1]] + dist2[E[i][0]] + E[i][2]});
        // cout<<dist1[E[i][0]]<<" "<<dist2[E[i][1]]<<" "<<E[i][2]<<endl;
    }
    if (ans == INT_MAX)
    {
        if (dist1[D] != INT_MAX)
            return dist1[D];
        return -1;
    }
    return ans;
}

int main()
{

    vector<vector<int>> my_board = {{0, 3}, {1, 2}};

    Solution s;
    vector<string> grid = {"@..aA", "..B#.", "....b"};

    cout << s.shortestPathAllKeys(grid) << endl;

    // fsor(auto arr : my_board){
    // 	for(auto ele : arr){
    // 		cout << ele ;
    // 	}
    // 	cout << endl ;
    // }

    return 0;
}