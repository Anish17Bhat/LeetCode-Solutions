#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            int num = nums[i];
            int found = 0;
            for(int j = 0 ; j < num ; j++){
                if((j | j + 1) == nums[i]){
                    found = 1;
                    ans.push_back(j);
                    break;
                }
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums = {2,3,5,7};
    vector<int>ans = s.minBitwiseArray(nums);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}