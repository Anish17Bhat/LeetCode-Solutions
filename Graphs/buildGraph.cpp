#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> builGraph(vector<vector<int>>&input){
            int m = input[0][0];
            vector<vector<int>>graph(m+1,vector<int>(m+1,0));
            for(int i = 1 ; i < input.size() ; i++){
                graph[input[i][0]][input[i][1]] = 1;
                graph[input[i][1]][input[i][0]] = 1;
            }
            return graph;
        }
};

int main(){
    Solution s;
    vector<vector<int>> input = {{5,6},{1,2},{1,3},{2,4},{3,4},{3,5},{4,5}};
    vector<vector<int>>result = s.builGraph(input);
    for(int i = 1 ; i < result.size() ; i++){
        for(int j = 1 ; j < result[0].size() ; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}