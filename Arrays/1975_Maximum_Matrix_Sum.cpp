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
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int count = 0;
        int smallest = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] < 0) count++;
                sum += abs(matrix[i][j]);
                smallest = min(abs(matrix[i][j]),smallest);
            }
        }
        if(count % 2 == 1){
            sum -= 2*smallest;
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
