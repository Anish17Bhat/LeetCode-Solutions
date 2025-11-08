#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxLen = 0;
        int len = 1;
        if(nums.size() == 1) return len;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - nums[i-1] == 1) len++;
            else if(nums[i] == nums[i-1]){
                maxLen = max(len,maxLen);
                continue;
            } 
            else len = 1;
            maxLen = max(len,maxLen);
        }
        return maxLen;
    }
};

int main(){
    vector<int>nums = {100,4,200,1,3,2};
    Solution s;
    cout<<s.longestConsecutive(nums);
    cout<<endl;    
    return 0;
}
