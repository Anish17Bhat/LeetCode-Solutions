#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool heapify(vector<int>&nums, int n, int i){
        int max = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && nums[left] < nums[max]) return false;
        if(right < n && nums[right] < nums[max]) return false;
        return true;
    }
};

int main(){
    Solution s;
    vector<int>nums = {15,5,20,1,17,10,30};
    int n = nums.size();
    bool ans;
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        ans = s.heapify(nums,n,i);
        if(!ans) break;
    }
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}
