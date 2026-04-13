#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void merge(int l, int mid, int h, vector<int>&nums, int &count){
        int i = l;
        int j = mid + 1;
        vector<int>temp(nums.size());
        int ind = 0;
        while(i <= mid && j <= h){
            if(nums[i] <= nums[j]){
                temp[ind++] = nums[i];
                i++;
            }
            else{
                temp[ind++] = nums[j];
                count += mid - i + 1;
                j++;
            }
        }
        while(i <= mid){
            temp[ind++] = nums[i++];
        }
        while(j <= h){
            temp[ind++] = nums[j++];
        }
        for(int idx = l ; idx <= h ; idx++){
            nums[idx] = temp[idx - l]; 
        } 
    }
    void MergeSort(int l, int h, vector<int>&nums, int &count){
        int mid = (l+h)/2;
        if(l < h){
            MergeSort(l,mid,nums,count);
            MergeSort(mid+1,h,nums,count);
            merge(l,mid,h,nums,count);
        }
    }
    int countInversions(vector<int>nums){
        int count = 0;
        MergeSort(0,nums.size()-1,nums,count);
        return count;
    }
};

int main(){
    Solution s;
    vector<int>nums = {2, 3, 7, 1, 3, 5};
    cout<<s.countInversions(nums)<<endl;
    return 0;
}
