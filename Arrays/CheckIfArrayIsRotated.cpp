#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int spikes = 0;
        if(nums[0] < nums[n-1]) spikes++;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < nums[i-1]) spikes++;
            if(spikes >= 2) return false;
        }
        return true;
    }
};

int main(){
    vector<int>nums = {2,1,3,4};
    Solution s;
    cout<<s.check(nums);
    cout<<endl;
    return 0;
}
