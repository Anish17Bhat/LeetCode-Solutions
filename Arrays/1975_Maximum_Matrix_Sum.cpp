#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printff(vector<vector<int>>&matrix, int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

class Solution {
    pair<int,int> findLowest(vector<vector<int>>&matrix,int i , int j, int n){
        int lowest = INT_MAX;
        pair<int,int>p;
        int a;
        int b;
        if(i > 0 && matrix[i-1][j] <= lowest){
            lowest = matrix[i-1][j];
            a = i - 1;
            b = j;
        } 
        if(i < n - 1 && matrix[i+1][j] <= lowest){
            lowest = matrix[i+1][j];
            a = i + 1;
            b = j;
        } 
        if(j > 0 && matrix[i][j-1] <= lowest){
            lowest = matrix[i][j-1];
            a = i;
            b = j - 1;
        } 
        if(j < n - 1 && matrix[i][j+1] <= lowest){
            lowest = matrix[i][j+1];
            a = i;
            b = j + 1;
        } 
        p = make_pair(a,b);
        return p;
    }
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] < 0){
                    auto [a,b] = findLowest(matrix,i,j,n);
                    if(matrix[a][b] > 0 && matrix[a][b] > matrix[i][j] && matrix[a][b] != abs(matrix[i][j])) continue;
                    if(matrix[a][b] < 0 || matrix[a][b] <= abs(matrix[i][j])){
                        matrix[i][j] *= -1;
                        matrix[a][b] *= -1;
                    }
                }
            }
        }
        printff(matrix,n);
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,1,-1,2},{-2,2,-2,3},{1,4,1,4},{3,-1,-2,-3}};
    cout<<s.maxMatrixSum(matrix)<<endl;
    return 0;
}
