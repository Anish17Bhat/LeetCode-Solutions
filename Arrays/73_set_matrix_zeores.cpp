#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int firstRowHasZeroes = 0;
        int firstColHasZeroes = 0;
        //check firstRowHasZeroes
        for(int i = 0 ; i < n ; i++){
            if(matrix[0][i] == 0){
                firstRowHasZeroes = 1;
                break;
            }
        }

        //check firstColHasZeroes
        for(int i = 0 ; i < m ; i++){
            if(matrix[i][0] == 0){
                firstColHasZeroes = 1;
                break;
            }
        }

        //set markers (use first row and col as markers)
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // set the marker rows as 0
        for(int i = 1; i < m ; i++){
            if(matrix[i][0] == 0){
                for(int j = 1 ; j < n ; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        //sest the marker cols as 0
        for(int i = 1 ; i < n ; i++){
            if(matrix[0][i] == 0){
                for(int j = 1 ; j < m ; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        //fill zeroes if first row or col has zeroes
        if(firstRowHasZeroes){
            for(int i = 0 ; i < n ; i++){
                matrix[0][i] = 0;
            }
        }

        if(firstColHasZeroes){
            for(int i = 0 ; i < m ; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
    for(vector<int> v : matrix){
        for(int e : v){
            cout<<e<<" ";
        }
        cout<<endl;
    }  
    return 0;
}
