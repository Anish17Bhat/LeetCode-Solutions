#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
        void heapify(vector<int>&nums,int n, int i){
            int max = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if(left < n && nums[left] > nums[max]) max = left;
            if(right < n && nums[right] > nums[max]) max = right;
            if(max != i){
                int temp = nums[i];
                nums[i] = nums[max];
                nums[max] = temp;
                cout<<nums[i]<<endl;
                heapify(nums,n,max);
            }
        }
    public: 
        vector<int> heap_sort(vector<int>&nums,int n){
            for(int i = (n/2)-1 ; i >= 0 ; i--){
                heapify(nums,n,i);
            }
            for(int i = n - 1 ; i >= 0 ; i--){
                swap(nums[0],nums[i]);
                heapify(nums,i,0);
            }
            return nums;
        }
};

int main(){
    Solution s;
    vector<int>nums = {15,5,20,1,17,10,30};
    int n = nums.size();
    vector<int>ans = s.heap_sort(nums,n);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}