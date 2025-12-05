#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findMaxInd(int l , int r, vector<int>&nums){
        int maxind = 0;
        for(int i = l ; i <= r ; i++){
            if(i + nums[i] >= maxind){
                maxind = i + nums[i];
            }
        }
        return maxind;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if(n == 1) return count;
        int l = 0;
        int r = 0;
        while(l < n-1 && r < n-1){
            int temp = l;
            l = r + 1;
            r = findMaxInd(temp,r,nums);
            count++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,1,1,2,0,3,4,1,1,1,2};
    cout<<s.jump(nums);
    cout<<endl;
    return 0;
}
