#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n*(n+1)/2 - accumulate(nums.begin(),nums.end(),0);
    }
};

int main(){
    vector<int>nums = {3,0,1};
    Solution s;
    cout<<s.missingNumber(nums);
    cout<<endl;  
    return 0;
}
