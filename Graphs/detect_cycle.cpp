#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //dfs
    // void dfs(int i , int parent, vector<int>adj[] , vector<int>&visited, bool &check){
    //     visited[i] = 1;
    //     for(int ele : adj[i]){
    //         if(!visited[ele]){
    //             dfs(ele,i,adj,visited,check);
    //         }
    //         else if(parent != ele) check = true;  // if it is visited and not its parent
    //     }
    // }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        bool check = false;
        // for(int i = 0 ; i < V ; i++){
        //     if(!visited[i]){
        //         dfs(i,-1,adj,visited,check);
        //     }
        // }
        queue<pair<int,int>>q;
        q.push({0,-1});
        visited[0] = 1;
        while(!q.empty()){
            pair<int,int>ele = q.front();
            q.pop();
            for(int v : adj[ele.first]){
                if(!visited[v]){
                    q.push({v,ele.first});
                    visited[v] = 1;
                }
                else if(v != ele.second){     //if it is visited and not its parent
                    check = true;
                }
            }
        }
        return check;
    }
};

int main(){
    vector<int> adj[] = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};  
    Solution s;
    cout<<s.isCycle(6,adj)<<endl;
    return 0;
}
