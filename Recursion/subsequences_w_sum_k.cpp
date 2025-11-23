#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int helper(int ind, vector<int>&nums, int n, int count, int k,int sum){
        if(ind == n){
            if(sum == k) count++;
            return count;
        }
        sum += nums[ind];
        count = helper(ind+1,nums,n,count,k,sum);
        sum -= nums[ind];
        count = helper(ind+1,nums,n,count,k,sum);
        return count;
    }
    public:
    int countSubSeqK(vector<int> nums,int k){
        return helper(0,nums,nums.size(),0,k,0);
    }
};

int main(){
    vector<int>nums = {3,1,2};
    Solution s;
    cout<<s.countSubSeqK(nums,5);
    cout<<endl;
    return 0;
}
