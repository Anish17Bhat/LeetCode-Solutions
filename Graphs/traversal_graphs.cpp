#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void buildGraph(int n, vector<int>adj[],vector<vector<int>>&adjacency){
        int m = sizeof(adj)/sizeof(adj[0]);
        for(int i = 0 ; i < m ; i++){
            int vertex1 = adj[i][0];
            int vertex2 = adj[i][1];
            adjacency[vertex1].push_back(vertex2);
            adjacency[vertex2].push_back(vertex1);
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>res;
        vector<vector<int>>adjacency(V);
        buildGraph(V,adj,adjacency);
        vector<int>visit(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!visit[i]){
                dfs(V,visit,adjacency,res);
            }
        }
    }

    void dfs(int node , vector<int>&visit, vector<vector<int>>&adjacency, vector<int>&res){
        visit[node] = 1;
        res.push_back(node);
        for(int e : adjacency[node]){
            if(!visit[e]){
                dfs(e,visit,adjacency,res);
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
    }
};



int main(){

    return 0;
}
