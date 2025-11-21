#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>result;
        priority_queue<tuple<int,int,int>>maxHeap;
        set<pair<int,int>>visited;
        sort(nums1.begin(),nums1.end(),greater<int>());
        sort(nums2.begin(),nums2.end(),greater<int>());
        int i = 0 , j = 0;
        maxHeap.push({nums1[0]+nums2[0],0,0});
        visited.insert({0,0});
        while(k > 0 && !maxHeap.empty()){
            auto [sum,i,j] = maxHeap.top();
            result.push_back(sum);
            maxHeap.pop();

            if(i + 1 < n && !visited.count({i+1,j})){
                maxHeap.push({nums1[i+1]+nums2[j],i+1,j});
                visited.insert({i+1,j});
            }

            if(j + 1 <  m && !visited.count({i,j+1})){
                maxHeap.push({nums1[i]+nums2[j+1],i,j+1});
                visited.insert({i,j+1});
            }
            k--;
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
