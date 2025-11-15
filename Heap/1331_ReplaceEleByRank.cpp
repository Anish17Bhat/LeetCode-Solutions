#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n = arr.size();

        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        for(int i = 0 ; i < n ; i++){
            mp[temp[i]] = i + 1;
        }

        for(int ele : arr){
            ans.push_back(mp[ele]);
        }

        return ans;
    }
};

int main(){
    vector<int>nums = {40,20,10,30};
    Solution s;
    vector<int>ans = s.arrayRankTransform(nums);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
