#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // void heapify(vector<int>&nums, int n , int i){
    //     int max = i;
    //     int left = 2 * i + 1;
    //     int right = 2 * i + 2;
    //     if(left < n && nums[left] > nums[max]) max = left;
    //     if(right < n && nums[right] > nums[max]) max = right;
    //     if(max != i){
    //         swap(nums[max],nums[i]);
    //         heapify(nums,n,max);
    //     }
    // }
    // void constructHeap(vector<int>&nums,int k){
    //     for(int i = (k/2)-1 ; i >= 0  ; i--)
    //         heapify(nums,k,i);
    // }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // constructHeap(nums,k);
        // for(int i = k ; i < n ; i++){
        //     if(nums[i] < nums[0]){
        //         swap(nums[0],nums[k-1]);
        //         nums[k-1] = nums[i];
        //         constructHeap(nums,k);
        //     }
        // }
        // return nums[0];
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0 ; i < k ; i++){
            pq.push(nums[i]);
        }
        for(int i = k ; i < n ; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

int main(){
    Solution s;
    vector<int>nums = {7,10,4,20,15};
    cout<<endl<<s.findKthLargest(nums,4)<<endl;
    for(int ele : nums){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
