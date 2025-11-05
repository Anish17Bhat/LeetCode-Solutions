#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int>&nums){
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0,1,1,2,2,3,4};
    cout<<s.removeDuplicates(nums);
    return 0;
}
