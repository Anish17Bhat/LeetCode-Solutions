#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(int i , int sum, vector<int>&temp, vector<vector<int>>&result, vector<int>&candidates,int target, int n){
        if(sum == target) {
            result.push_back(temp);
            return true;
        }
        else if(sum > target) return false;

        for(int j = i ; j < n ; j++){
            sum += candidates[j];
            temp.push_back(candidates[j]);
            if(helper(j,sum,temp,result,candidates,target,n) == false){
                sum -= candidates[j];
                temp.pop_back();
                break;
            };
            sum -= candidates[j];
            temp.pop_back();
        }
        return true;
        // if(i == n){
        //     if(target == 0){
        //         result.push_back(temp);
        //         return;
        //     }
        //     else return;
        // }

        // if(candidates[i] <= target){
        //     target -= candidates[i];
        //     temp.push_back(candidates[i]);
        //     helper(i,target,temp,result,candidates,n);
        //     target += candidates[i];
        // }

        // helper(i+1,target,temp,result,candidates,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;
        int sum = 0;
        helper(0,sum,temp,result,candidates,target,n);      
        return result;
    }
};

int main(){
    vector<int>candidates = {1,4,2,6};
    int target = 6;
    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates,target);
    for(vector<int> ele : result){
        for(int e : ele){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
