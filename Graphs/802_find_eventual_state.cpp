#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int v, vector<int>&visited, vector<int>&pathVisited, vector<vector<int>>&graph, vector<int>&vec){
        visited[v] = 1;
        pathVisited[v] = 1;
        vec.push_back(v);
        for(int e : graph[v]){
            if(!visited[e]){
                if(dfs(e,visited,pathVisited,graph,vec)) return true;
            }
            else if(pathVisited[e]) {
                return true;
            }
        }
        pathVisited[v] = 0;
        vec.pop_back();
        return false;
    }    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            unordered_set<int>st;
            vector<int>cycleVisited(n,0);
            vector<int>visited(n,0);
            vector<int>pathVisited(n,0);
            for(int j = 0 ; j < n ; j++){
                if(!cycleVisited[j]){
                            vector<int>vec;
                            if(!dfs(j,visited,pathVisited,graph,vec)) {
                                cout<<j<<endl;
                                st.insert(j);
                            }
                            else{
                                for(int ele : vec){
                                    cycleVisited[ele] = 1;
                                }
                            }
                }
            }
            vector<int>ans(st.begin(),st.end());  
            sort(ans.begin(),ans.end());  
            return ans;        
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int>ans = s.eventualSafeNodes(graph);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
