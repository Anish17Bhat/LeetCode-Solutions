#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int missingNumber(vector<int>&nums){
            int n = nums.size();
            int sum = n * (n + 1) / 2;
            int numsum = accumulate(nums.begin(),nums.end(),0);
            return sum - numsum; 
        }
};

int main(){
    vector<int>nums = {0,1,3};
    Solution s;
    cout<<s.missingNumber(nums);
    cout<<endl;
    return 0;
}
