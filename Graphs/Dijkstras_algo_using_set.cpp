#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        //build graph
        vector<pair<int,int>> adj[V];
        int M = edges.size();
        for(int i = 0 ; i < M ; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            int d = edges[i][2];
            adj[v1].push_back({v2,d});
            adj[v2].push_back({v1,d});
        }

        vector<int>distance(V,1e9);
        distance[S] = 0;
        set<pair<int,int>>st;
        st.insert({0,S});

        while(!st.empty()){
            pair<int,int> ele = *st.begin();
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
                    st.insert({newDist,e});
                }
            }
        }
        return distance;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1,4},{0,2,4},{1,2,2},{2,3,3},{2,4,1},{2,5,6},{3,5,2},{4,5,3}};
    vector<int>distance = s.dijkstra(6,edges,0);
    for(int ele : distance){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
