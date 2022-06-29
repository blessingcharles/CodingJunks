#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int mod = 1e9 + 7;

int solve(vector<vector<int>> &A)
{
    int M = A.size(), N = A[0].size();
    int target = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            A[i][j] += A[i][j - 1];
        }
    }
    // have c1 and c2 as the axis calculate the sums
    int count = 0;

    for (int c1 = 0; c1 < N; c1++)
    {
        for (int c2 = c1; c2 < N; c2++)
        {
            unordered_map<int, int> memo;
            memo[0] = 1;
            int sum = 0;

            for (int row = 0; row < M; row++)
            {
                int cursum = A[row][c2] - ((c1 > 0) ? A[row][c1 - 1] : 0);
                sum += cursum;
                if (memo.find(cursum) != memo.end())
                {
                    count += memo[cursum];
                }
                memo[cursum]++;
            }
        }
    }

    return count;
}

int main()
{
    //     string A = "T^T^T^F|F&F^F|T^F^T";
    //     vector<string> arr = {"cat", "cats", "and", "sand", "dog"};

    //     vector<int> cuts = {1,2,5} ;
    //    rodCut(6 , cuts) ;
    vector<vector<int>> arr = {{0, 0}};
    cout << solve(arr) << endl;
    // for(auto str : wordBreak(A, arr)){
    //     cout << str << endl ;
    // }

    return 0;
}