#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = m * n - 1;
        while(l <= h){
            int mid = ( l + h ) / 2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else if(matrix[mid/n][mid%n] > target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>>nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<s.searchMatrix(nums,3)<<endl;
    return 0;
}
