#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> sortKsortedArray(vector<int>&nums, int k){
            priority_queue<int,vector<int>, greater<int>>minHeap;
            vector<int>ans;
            for(int i = 0 ; i <= k ; ++i){
                minHeap.push(nums[i]);
            }
            ans.push_back(minHeap.top());
            for(int i = k + 1 ; i < nums.size() ; ++i){
                minHeap.pop();
                minHeap.push(nums[i]);
                ans.push_back(minHeap.top());
            }
            minHeap.pop();
            for(; !minHeap.empty() ; minHeap.pop()){
                ans.push_back(minHeap.top());
            }
            return ans;
        }
};

int main(){
    vector<int>nums = {1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    Solution s;
    vector<int>temp = s.sortKsortedArray(nums,3);
    for(int ele : temp){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
