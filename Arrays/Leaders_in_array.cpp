#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> leaderArray(vector<int>&nums){
        int n = nums.size();
        int leader = nums[n-1];
        vector<int>leaders;
        leaders.push_back(leader);
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] > leader){
                leader = nums[i];
                leaders.push_back(leader);
            }
        }
        return leaders;
    }
};

int main(){
    Solution s;
    vector<int>nums = {10,22,12,0,6};
    vector<int>result = s.leaderArray(nums);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
