#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void heapify(vector<int>&nums, int n , int i){
        int max = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && nums[left] < nums[max]) max = left;
        if(right < n && nums[right] < nums[max]) max = right;
        if(max != i){
            swap(nums[max],nums[i]);
            heapify(nums,n,max);
        }
    }
    void heap_sort(vector<int>&nums, int n){
        for(int i = (n/2)-1 ; i >= 0 ; i--){
            heapify(nums,n,i);
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        heap_sort(nums,n);
        return nums[k-1];
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,2,1,5,6,4};
    cout<<endl<<s.findKthLargest(nums,2)<<endl;
    for(int ele : nums){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
