#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        //build graph
        vector<pair<int,int>> adj[V+1];
        int M = edges.size();
        for(int i = 0 ; i < M ; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            int d = edges[i][2];
            adj[v1].push_back({v2,d});
            adj[v2].push_back({v1,d});
        }

        vector<int>distance(V+1,1e9);
        distance[S] = 0;
        set<pair<int,int>>st;
        st.insert({0,S});
        vector<int>parent(V+1);
        for(int i = 1 ; i <= V ; i++){
            parent[i] = i;
        }
        parent[S] = S;

        while(!st.empty()){
            auto ele = *st.begin();
            int dist = ele.first;
            int v = ele.second;
            st.erase(ele);
            for(pair<int,int> p : adj[v]){
                int e = p.first;
                int newDist = dist + p.second;
                if(newDist < distance[e]){
                    if(distance[e] != 1e9){
                        st.erase({distance[e],e});
                    }
                    distance[e] = newDist;
                    parent[e] = v;
                    st.insert({newDist,e});
                }
            }
        }
        vector<int>ans;
        int e = V;
        while(parent[e] != e){
            ans.push_back(e);
            e = parent[e];
        }
        ans.push_back(S);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{1,2,2},{1,4,1},{2,1,2},{2,3,4},{2,5,5},{3,2,4},{3,4,3},{3,5,1},{4,1,1},{4,3,3},{5,2,5},{5,3,1}};
    vector<int>path = s.dijkstra(5,edges,1);
    for(int ele : path){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
