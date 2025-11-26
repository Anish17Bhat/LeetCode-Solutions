#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        for(int i = 0 ; i < nums.size() ; i++){
            int rem = target - nums[i];
            if(hash.find(rem) != hash.end()){
                return {hash[rem],i};
            }
            hash[nums[i]] = i;
        }        
        return {};
    }
};


int main(){
    vector<int>nums = {3,2,4};
    Solution s ;
    vector<int>ans = s.twoSum(nums,6);
    for(int ele: ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}