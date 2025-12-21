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
        while(i < n){
            if(intervals[i][0] <= start <= intervals[i][1]){
                start = intervals[i][0];
                while(i < n){
                    if(intervals[i][0] <= end <= intervals[i][1]){
                        cout<<end<<endl;
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
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>>intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int>newInterval = {4,8};
    vector<vector<int>>ans = s.insert(intervals,newInterval);
    for(auto v : ans){
        cout<<"( "<<v[0]<<","<<v[1]<<" )"<<"   ";
    }
    cout<<endl;
    return 0;
}
