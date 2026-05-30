#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> topoSort(vector<vector<int>> &adj){
            int n = adj.size();
            vector<int>indegree(n,0);
            for(int i = 0 ; i < n ; i++){
                for(int e : adj[i]){
                    indegree[e]++;
                }
            }
            queue<int>q;
            for(int i = 0 ; i < n ; i++){
                if(indegree[i] == 0) q.push(i);
            }
            vector<int>res;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                res.push_back(v);
                for(int e : adj[v]){
                    indegree[e]--;
                    if(indegree[e] == 0) q.push(e);
                }
            }
            return res;
        }
};

int main(){
    Solution s;
    vector<vector<int>> adj =  {{},{},{3},{1},{0,1},{0,2}};
    vector<int>ans = s.topoSort(adj);
    for(int e : ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
