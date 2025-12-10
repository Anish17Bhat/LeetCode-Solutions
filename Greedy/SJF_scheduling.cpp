#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        float SJF(vector<int>&nums){
            sort(nums.begin(),nums.end());
            int n = nums.size();
            int totwt = 0;
            float avgwt;
            int sum = 0;
            for(int i = 0 ; i < n ; i++){
                sum += nums[i];
                totwt += sum - nums[i];
            }
            return (float)totwt/n;
        }
};

int main(){
    Solution s;
    vector<int>nums = {2,5,4};
    cout<<s.SJF(nums)<<endl;
    return 0;
}
