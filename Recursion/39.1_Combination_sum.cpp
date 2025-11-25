#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printF(vector<int>&temp){
    for(int ele : temp){
        cout<<ele<<" ";
    }
}

class Solution {
    void helper(int i , int target, vector<int>&temp, vector<vector<int>>&result, vector<int>&candidates, int n){
        //uncomment to trace
        // cout<<"( "<<i<<" , "<<target<<" , ";
        // printF(temp);
        // cout<<" )"<<endl<<endl;
        if(i == n){
            if(target == 0){
                result.push_back(temp);
                return;
            }
            else return;
        }

        if(candidates[i] <= target){
            target -= candidates[i];
            temp.push_back(candidates[i]);
            helper(i,target,temp,result,candidates,n);
            target += candidates[i];
            temp.pop_back();
        }
        helper(i+1,target,temp,result,candidates,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;
        int sum = 0;
        helper(0,target,temp,result,candidates,n);      
        return result;
    }
};

int main(){
    vector<int>candidates = {2,3,6,7};
    int target = 7;
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
