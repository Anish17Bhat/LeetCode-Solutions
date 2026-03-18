#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(vector<int> v : edges){
            int vertex1 = v[0];
            int vertex2 = v[1];
            adj[vertex1].push_back(vertex2);
            adj[vertex2].push_back(vertex1);
        }

        vector<int>visit(n,0);

        int res = 0;

        for(int i = 0 ; i < n ; i++){
            if(!visit[i]){
                dfs(adj,visit,i);
                res++;
            }
        }

        return res;
    }

    void dfs(vector<int>adj[] , vector<int>&visit, int vertex){
        visit[vertex] = 1;
        for(int node : adj[vertex]){
            if(!visit[node]){
                dfs(adj,visit,node);
            }
        }
    }
};


int main(){
    Solution s;
    vector<vector<int>>edges = {{0,1},{1,2},{2,3},{4,5}};
    int vertices = 7;
    cout<<s.countComponents(vertices,edges);
    cout<<endl;
    return 0;
}
