#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>result;
        priority_queue<int>maxHeap;
        int i = 0 , j = 0;
        while(i < n){
            while(j < n){
                maxHeap.push(nums1[i]+nums2[j]);
                j++;
            }
            if(j == n) j = 0;
            i++;
        }
        while(!maxHeap.empty() && j < k){
            result.push_back(maxHeap.top());
            maxHeap.pop();
            j++;
        }
        return result;
  }
};

int main(){
    Solution s;
    vector<int>nums1 = {3,4,5};
    vector<int>nums2 = {2,6,3};
    vector<int>ans = s.maxSumCombinations(nums1,nums2,2);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
