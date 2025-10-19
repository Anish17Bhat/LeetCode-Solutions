#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void min2maxHeap(vector<int>&nums,int n, int i){
        int max = i;
        int left = 2 * i + 1;
        int right = 2* i + 2;
        if(left < n && nums[left] > nums[max]) max = left;
        if(right < n && nums[right] > nums[max]) max = right;
        if(max != i){
            swap(nums[max],nums[i]);
            min2maxHeap(nums,n,max);
        }
    }
};

int main(){
    vector<int>nums = {10,20,30,21,23};
    Solution s;
    int n = nums.size();
    for(int i = (n/2)-1 ; i >= 0 ; i--){
        s.min2maxHeap(nums,n,i);
    }
    for(int ele : nums){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
