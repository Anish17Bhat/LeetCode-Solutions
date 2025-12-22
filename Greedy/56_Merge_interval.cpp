#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>tempInterval = intervals[0];
        for(auto it : intervals){
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1],tempInterval[1]);
            }
            else{
                ans.push_back(tempInterval);
                tempInterval = it;
            }
        }
        ans.push_back(tempInterval);
        return ans;     
    }
};

int main(){
    Solution s;
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18},{17,20}};
    vector<vector<int>>result = s.merge(intervals);
    for(auto interval : result){
        cout<<"( "<<interval[0]<<","<<interval[1]<<" )"<<"   ";
    }
    cout<<endl;
    return 0;
}
