#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<pair<int,int>>> buildGraph(int N, int M, vector<vector<int>>&edges){
        vector<vector<pair<int,int>>> adj(N);
        for(int i = 0 ; i < M ; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            int d = edges[i][2];
            adj[v1].push_back({v2,d});
        }
        return adj;
    }

    void dfs(int v, vector<int>&visited, vector<vector<pair<int,int>>>&adj, stack<int>&topSort){
        visited[v] = 1;
        for(pair<int,int> e : adj[v]){
            if(!visited[e.first]){
                dfs(e.first,visited,adj,topSort);
            }
        }
        topSort.push(v);
    }

    public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<vector<pair<int,int>>>adj = buildGraph(N,M,edges);
        stack<int> topSort;
        vector<int>visited(N,0);
        dfs(6,visited,adj,topSort);
        vector<int>distance(N,INT_MAX);
        distance[6] = 0;
        while(!topSort.empty()){
            int v = topSort.top();
            topSort.pop();
            for(pair<int,int> p : adj[v]){
                int e = p.first;
                int d = p.second;
                distance[e] = min(distance[e],distance[v] + d);
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(distance[i] == INT_MAX) distance[i] = -1; 
        }
        return distance;
    }
};



int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1,2},{1,3,1},{2,3,3},{4,0,3},{4,2,1},{5,4,1},{6,4,2},{6,5,3}};
    vector<int> ans = s.shortestPath(7,edges.size(),edges);
    for(int e : ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
