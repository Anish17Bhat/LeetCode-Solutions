#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int countNegatives(vector<vector<int>>&grid){
            int m = grid.size();
            int n = grid[0].size();
            int i = m - 1;
            int j = 0;
            int ans = 0;
            while(i >= 0 && j < n){
                if(grid[i][j] < 0){
                    ans += n - j ;
                    i--;
                }
                else 
                    j++;
            }
            return ans;
        }
};

int main(){
    Solution s;
    vector<vector<int>>grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout<<s.countNegatives(grid)<<endl;
    return 0;
}
