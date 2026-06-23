#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int bfs(int v, int n, vector<pair<int,int>>adj[], int threshold){
        vector<int>visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,v});
        int count = 0;
        vector<int>distance(n,INT_MAX);
        distance[v] = 0;
        visited[v] = 1;
        while(!q.empty()){
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto e : adj[node]){
                int newDist = dist + e.second;
                int ele = e.first;
                if(newDist < distance[ele] && newDist <= threshold){
                    if(visited[ele]) count--;
                    count++;
                    q.push({newDist,ele});
                    distance[ele] = newDist;
                    visited[ele] = 1;
                }
            }
        }
        cout<<count<<endl;
        return count;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int minNoOfCities = n;
        int maxCity = -1;
        for(int i = 0 ; i < n ; i++){
            int num = bfs(i,n,adj,distanceThreshold);
            if(num <= minNoOfCities){
                minNoOfCities = num;
                maxCity = max(maxCity,i);
            }
        }
        return maxCity;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    // vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout<<s.findTheCity(4,edges,4)<<endl;
    return 0;
}
