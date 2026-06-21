#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>distance(V,1e9);
        distance[S] = 0;
        int n = edges.size();
        int i;
        for(i = 1 ; i <= V - 1 ; i++){
            for(int j = 0 ; j < n ; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if(distance[u] != 1e9 && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                }
            }
        }

        for(int j = 0 ; j < n ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(distance[u] != 1e9 && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
                return {-1};
            }
        }

        return distance;
	}
};


int main(){
    vector<vector<int>> edges = {{3, 2, 6}, {5, 3, 1}, {0, 1, 5}, {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3}};
    Solution s;
    vector<int>ans = s.bellman_ford(6,edges,0);
    for(int e : ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
