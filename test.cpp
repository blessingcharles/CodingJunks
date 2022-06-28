#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

vector<string> combine(string &temp, vector<string> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i] + " " + temp;
    }

    return arr;
}

vector<string> helper(string s, unordered_set<string> &dict, unordered_map<string, vector<string>> &memo)
{
    vector<string> results;
    if (memo.find(s) != memo.end())
        return memo[s];

    if (dict.find(s) != dict.end())
    {
        results.push_back(s);
    }

    for (int i = 1; i < s.size(); i++)
    {
        string temp = s.substr(i);
        if (dict.find(temp) != dict.end())
        {
            vector<string> local = combine(temp, helper(s.substr(0, i), dict, memo));

            for (string &st : local)
            {
                cout << st << endl ;
                results.push_back(st);
            }
        }
    }
    return memo[s] = results;
}

vector<string> wordBreak(string A, vector<string> &B)
{
    N = A.size();
    unordered_set<string> dictionary(B.begin(), B.end());
    unordered_map<string, vector<string>> memo;

    vector<string> res = helper(A, dictionary, memo);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    string A = "cats";
    vector<string> arr = {"cat", "cats", "and", "sand", "dog"};

    for(auto str : wordBreak(A, arr)){
        cout << str << endl ;
    }

    return 0;
}