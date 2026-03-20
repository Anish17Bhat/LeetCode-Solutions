#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void buildGraph(int n, int m, vector<int>adj[],vector<vector<int>>&adjacency){
        for(int i = 0 ; i < m ; i++){
            int vertex1 = adj[i][0];
            int vertex2 = adj[i][1];
            adjacency[vertex1].push_back(vertex2);
            adjacency[vertex2].push_back(vertex1);
        }
    }
  public:
    vector<int> dfsOfGraph(int V, int m, vector<int> adj[]) {
        vector<int>res;
        vector<vector<int>>adjacency(V);
        buildGraph(V,m,adj,adjacency);
        vector<int>visit(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!visit[i]){
                dfs(i,visit,adjacency,res);
            }
        }
        return res;
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
    
    vector<int> bfsOfGraph(int V, int m,vector<int> adj[]) {
        vector<int>res;
        vector<vector<int>>adjacency(V);
        buildGraph(V,m,adj,adjacency);
        vector<int>visit(V,0);
        queue<int>q;
        for(int i = 0 ; i < V ; i++){
            if(!visit[i]){
                q.push(i);
                visit[i] = 1;
                res.push_back(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int ele : adjacency[node]){
                        if(!visit[node]){
                            visit[ele] = 1;
                            res.push_back(ele);
                        }
                    }
                }
            }
        }
        return res;
    }
};



int main(){
    Solution s;
    int m = 4;
    vector<int> input[] = {{0,1},{0,2},{0,3},{2,4}};
    int V = 5;
    vector<int>dfs = s.dfsOfGraph(V,m,input);
    cout<<"DFS: ";
    for(int ele : dfs){
        cout<<ele<<" ";
    }
    vector<int>bfs = s.bfsOfGraph(V,m,input);
    cout<<endl;
    cout<<"BFS: ";
    for(int ele : bfs){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
