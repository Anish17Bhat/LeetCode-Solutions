#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpfreq;
        multimap<int,int,greater<int>>ans;
        vector<int>result;
        int count = k;
        for(int ele : nums){
            mpfreq[ele]++;
        }
        for(auto ele : mpfreq){
            ans.insert({ele.second,ele.first});
        }
        for(auto i = ans.begin() ; i != ans.end() ; i++){
            if(count > 0){
                result.push_back(i->second);
                count--;
            }
            else break;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,0,1,0};
    vector<int>result = s.topKFrequent(nums,1);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
