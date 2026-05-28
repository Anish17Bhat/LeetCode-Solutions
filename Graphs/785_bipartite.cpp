#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& color){
        for(int e : graph[v]){
            if(color[e] == -1){
                color[e] = !color[v];
                if(!dfs(e,graph,color)) return false;
            }
            else if(color[e] == color[v]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i,graph,color)) return false;         
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>>graph = {{1,3},{0,2},{1,3},{0,2}};
    cout<<s.isBipartite(graph)<<endl;
    return 0;
}
