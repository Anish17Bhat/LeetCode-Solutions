#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> builGraph(vector<vector<int>> &input)
    {
        int vtx = input[0][0];
        int e = input[0][1];
        vector<vector<int>> graph(vtx + 1);

        for (int i = 1; i <= e; i++)
        {
            int u = input[i][0];
            int v = input[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input = {{7, 4}, {0, 1}, {1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> result = s.builGraph(input);
    for (int i = 0; i < result.size(); i++)
    {
        cout << i << " -> ";
        for (int j : result[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}