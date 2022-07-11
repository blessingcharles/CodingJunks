#include <iostream>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReplace(int idx, string &target, string &stamp)
    {
        for (int i = 0; i < stamp.size(); i++)
        {
            if (target[i + idx] != '?' and target[i + idx] != stamp[i])
            {
                return false;
            }
        }
        return true;
    }
    void replace(int idx, string &target, int &count, int m)
    {
        for (int i = 0; i < m; i++)
        {
            if (target[i + idx] != '?')
            {
                count++;
                target[i + idx] = '?';
            }
        }
    }
    vector<int> movesToStamp(string stamp, string target)
    {
        int m = stamp.size(), n = target.size();
        vector<int> ans;
        // convert the target into "?"
        int count = 0;
        vector<int> visited(n, false);
        while (count != n)
        {
            bool modified_once = false;
            for (int i = 0; i <= n - m; i++)
            {
                if (not visited[i] and canReplace(i, target, stamp))
                {
                    replace(i, target, count, m);
                    cout << i << "Replcing "<< target << endl ;
                    visited[i] = true;
                    modified_once = true;
                    ans.push_back(i);
                    if (count == n)
                        break;
                }
            }
            if (not modified_once){
                return {-1};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string exp = "abc";
    string target = "ababc" ;
    Solution s ;
    for(int ele : s.movesToStamp(exp , target)){
        cout << ele << " " ;
    }
}