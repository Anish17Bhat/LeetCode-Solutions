#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int func(vector<int>&nums, int k){
        int n = nums.size();
        int l = 0;
        int count = 0;
        unordered_map<int,int>mp;
        for(int r = 0 ; r < n ; r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]] -= 1;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            if(mp.size() <= k){
                count++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};

int main(){
    vector<int>nums = {1,2,1,2,3};
    Solution s;
    cout<<s.subarraysWithKDistinct(nums,2);
    return 0;
}