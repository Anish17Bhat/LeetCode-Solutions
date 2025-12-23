#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;
        sort(intervals.begin(),intervals.end());
        int ans = 0;
        vector<int>tempInterval = intervals[0];
        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] < tempInterval[1]){
                ans++;
                tempInterval[1] = min(intervals[i][1],tempInterval[1]);
            }
            else{
                tempInterval = intervals[i];
            }
        }
        return ans;     
    }
};

int main(){
    Solution s;
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18},{17,20}};
    int result = s.eraseOverlapIntervals(intervals);
    cout<<result<<endl;
    return 0;
}
