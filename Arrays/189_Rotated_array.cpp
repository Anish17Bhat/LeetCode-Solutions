#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void miniRotate(vector<int>&nums,int l , int r){
        while(l < r){
            nums[r] = nums[l] ^ nums[r];
            nums[l] = nums[l] ^ nums[r];
            nums[r] = nums[l] ^ nums[r];
            l++;
            r--;
        }
    }
    public:
    void rotate(vector<int>& nums, int k) {
        int realK = k % nums.size();
        miniRotate(nums,0,nums.size()-1);
        miniRotate(nums,0,realK-1);
        miniRotate(nums,realK,nums.size()-1);
    }
};

int main(){
    vector<int>nums = {1,2,3,4,5,6,7};
    Solution s;
    s.rotate(nums,3);
    for(int ele : nums){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
