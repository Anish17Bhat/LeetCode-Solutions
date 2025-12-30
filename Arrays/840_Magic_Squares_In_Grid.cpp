#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> magicSquares = {
                                                    {{8,1,6},{3,5,7},{4,9,2}},
                                                    {{6,1,8},{7,5,3},{2,9,4}},
                                                    {{4,9,2},{3,5,7},{8,1,6}},
                                                    {{2,9,4},{7,5,3},{6,1,8}},
                                                    {{8,3,4},{1,5,9},{6,7,2}},
                                                    {{4,3,8},{9,5,1},{2,7,6}},
                                                    {{6,7,2},{1,5,9},{8,3,4}},
                                                    {{2,7,6},{9,5,1},{4,3,8}}
                                                   };
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        if(m < 3 || n < 3) return 0;
        for(int i = 0 ; i <= m-3 ; i++){
            for(int k = 0 ; k <= n - 3 ; k++){
                vector<vector<int>>temp(3,vector<int>(3));
                int p = 0;
                int q = 0;
                for(int x = i ; x < i + 3 ; x++){
                    for(int y = k ; y < k + 3 ; y++){
                        cout<<grid[x][y]<<" ";
                        temp[p][q++] = grid[x][y]; 
                    }
                    cout<<endl;
                    p++;
                    q = 0;
                }
                cout<<endl;
                if(find(magicSquares.begin(),magicSquares.end(),temp) != magicSquares.end()){
                    ans++;
                } 
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    Solution s;
    cout<<s.numMagicSquaresInside(grid)<<endl;
    return 0;
}
