#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int singleNumber(vector<int>&nums){
            int n = nums.size();
            int Xor = 0;
            for(int i = 0 ; i < n ; i++){
                Xor ^= nums[i];
            }
            return Xor;
        }
};

int main(){
    vector<int>nums = {2,2,1};
    Solution s;
    cout<<s.singleNumber(nums);
    cout<<endl;
    return 0;
}
