#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> buildGraph(vector<vector<int>>& edges, int N, int M){
        vector<vector<int>> adj(N);
        for(int i = 0 ; i < M ; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        return adj;
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<vector<int>> adj = buildGraph(edges,N,M);
        vector<int>distance(N,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,0});
        distance[0] = 0;
        while(!q.empty()){
            int v = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(int e : adj[v]){
                int newDist = dist + 1;
                if(newDist < distance[e]){
                    distance[e] = newDist;
                    q.push({e,newDist});
                }
            }
        }
        return distance;
    }
};


int main(){
    Solution s;
    vector<vector<int>>edges = { {0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    vector<int>ans = s.shortestPath(edges,9,10);
    for(int e : ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
