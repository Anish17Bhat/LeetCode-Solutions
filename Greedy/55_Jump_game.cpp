#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxind = 0;
        while(i < n){
            if(i > maxind) return false;
            if(nums[i] + i >= maxind){
                maxind = i + nums[i];
            }
            i++;
        }
        return true;
    }
};

int main(){
    vector<int>nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    Solution s;
    cout<<s.canJump(nums)<<endl;
    return 0;
}
