#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(int ind, int n, vector<int>&temp, vector<vector<int>>&result, vector<int>&nums){
        if(ind == n){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        helper(ind+1,n,temp,result,nums);
        temp.pop_back();
        helper(ind+1,n,temp,result,nums);
    }
    public:
        vector<vector<int>> subsets(vector<int> nums){
            int n = nums.size();
            vector<vector<int>>result;
            vector<int>temp;
            helper(0,n,temp,result,nums);
            return result;
        }
};

int main(){
    vector<int>nums = {1,2,3};
    vector<vector<int>>result;
    Solution s;
    result = s.subsets(nums);
    for(vector<int>v : result){
        cout<<"{";
        for(int ele : v){
            cout<<ele<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}
