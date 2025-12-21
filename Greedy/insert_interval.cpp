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
        bool overlap = false;
        while(i < n){
            if(intervals[i][0] <= start && start <= intervals[i][1]){
                overlap = true;
                start = intervals[i][0];
                while(i < n){
                    if(intervals[i][0] <= end && end <= intervals[i][1]){
                        end = intervals[i][1];
                        break;
                    }
                    i++;
                }
                ans.push_back({start,end});
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }    
        if(!overlap) ans.push_back({start,end});  
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
