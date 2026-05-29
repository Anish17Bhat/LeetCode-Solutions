#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool dfs(int v, vector<int>&visited, vector<int>&pathVisited, vector<vector<int>>&graph){
        visited[v] = 1;
        pathVisited[v] = 1;
        for(int e : graph[v]){
            if(!visited[e]){
                if(dfs(e,visited,pathVisited,graph)) return true;
            }
            else if(pathVisited[e]) {
                return true;
            }
        }
        pathVisited[v] = 0;
        return false;
    }
    public:
        bool detectCycle(vector<vector<int>>graph){
            int n = graph.size();
            vector<int>visited(n,0);
            vector<int>pathVisited(n,0);
            for(int i = 0 ; i < n ; i++){
                if(!visited[i]){
                    if(dfs(i,visited,pathVisited,graph)) return true;
                }
            }
            return false;
        }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{2},{3},{4,7},{5},{6},{},{5},{9},{10},{8}};
    cout<<s.detectCycle(graph)<<endl;
    return 0;
}
