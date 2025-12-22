#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;
        vector<vector<int>>ans;
        while(i < n && intervals[i][1] < start){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= end){
            start = min(start,intervals[i][0]);
            end = max(end,intervals[i][1]);
            i++;
        }
        ans.push_back({start,end});
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>>intervals = {{1,2},{3,4},{7,8}};
    vector<int>newInterval = {5,6};
    vector<vector<int>>ans = s.insert(intervals,newInterval);
    for(auto v : ans){
        cout<<"( "<<v[0]<<","<<v[1]<<" )"<<"   ";
    }
    cout<<endl;
    return 0;
}
