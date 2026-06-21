#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
        int n = matrix.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == -1) matrix[i][j] = 1e9;
            }
        }

        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    matrix[i][j] = min(matrix[i][via] + matrix[via][j],matrix[i][j]);
                }
            }
        }

        //check negative cycles
        for(int i = 0 ; i < n ; i++){
            if(matrix[i][i] < 0){
                cout<<"negative cycle present"<<endl;
                exit(0);
            } 
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 1e9) matrix[i][j] = -1;
            }
        }
	}
};

int main(){
    Solution s;
    vector<vector<int>>matrix = {{0,2,-1,-1},{1,0,3,-1},{-1, -1, 0, 1},{3, 5, 4, 0}};
    s.shortestDistance(matrix);
    for(auto v : matrix){
        for(int e : v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}
