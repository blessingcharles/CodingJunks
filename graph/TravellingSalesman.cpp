#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;

int TravellingSalesman(int curnode, int visited, vector<vector<int>> &distances, vector<vector<int>> &memo)
{

    if (visited == N)
    {
        return distances[curnode][0];
    }
    if (memo[curnode][visited] != -1)
    {
        return memo[curnode][visited];
    }

    int mincost = INT_MAX;

    for (int i = 0; i < distances.size(); i++)
    {
        if ((visited & (1 << i)) != 0)
            continue;
        // visit it
        int newv = (visited | (1 << i));
        mincost = min(mincost, distances[curnode][i] + TravellingSalesman(i, newv, distances, memo));
    }
    return memo[curnode][visited] = mincost;
}

int shortestRoute(vector<vector<int>> &distance)
{
    int m = distance.size();
    N = (1 << m) - 1;
    vector<vector<int>> memo(m, vector<int>(N + 1, -1));
    return TravellingSalesman(0, 1, distance, memo);
}

int main()
{
    vector<vector<int>> distance = { {0, 20, 42, 25},
                                     {20, 0, 30, 34},
                                     {42, 30, 0, 10},
                                     {25, 34, 10, 0} } ;

    cout << shortestRoute(distance) << endl ;
    
}