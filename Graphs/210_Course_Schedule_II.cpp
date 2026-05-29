#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> buildGraph(int n , vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(n);
        for(auto v : prerequisites){
            int v1 = v[0];
            int v2 = v[1];
            adj[v2].push_back(v1);
        }
        return adj;
    }

    bool dfs(int v, vector<int>&visited, vector<int>&pathVisited,vector<vector<int>>&adj,stack<int>&st){
        visited[v] = 1;
        pathVisited[v] = 1;
        for(int e : adj[v]){
            if(!visited[e]){
                if(!dfs(e,visited,pathVisited,adj,st)) return false;
            }
            else if(pathVisited[e]){
                return false;
            }
        }
        pathVisited[v] = 0;
        st.push(v);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = buildGraph(numCourses,prerequisites);
        vector<int>visited(numCourses,0);
        vector<int>pathVisited(numCourses,0);
        stack<int>st;
        vector<int>result;
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                if(!dfs(i,visited,pathVisited,adj,st)) return {};
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int>res = s.findOrder(4,prerequisites);
    for(int ele : res){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
