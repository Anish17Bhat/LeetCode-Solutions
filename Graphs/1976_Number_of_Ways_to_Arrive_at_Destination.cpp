#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        vector<pair<long long,long long>>adj[n];
        for(int i = 0 ; i < roads.size() ; i++){
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long t = roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<long long>ways(n,0);
        ways[0] = 1;
        vector<long long>distance(n,LONG_LONG_MAX);
        distance[0] = 0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            for(pair<long long,long long> p : adj[node]){
                long long v = p.first;
                long long t = p.second;
                long long newTime = time + t;
                if(newTime < distance[v]){
                    distance[v] = newTime;
                    pq.push({newTime,v});
                    ways[v] = ways[node] % MOD;
                }
                else if(newTime == distance[v]){
                    ways[v] = (ways[v] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};

int main(){
    vector<vector<int>>roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int n = 7;
    Solution s;
    cout<<s.countPaths(n,roads)<<endl;
    return 0;
}
