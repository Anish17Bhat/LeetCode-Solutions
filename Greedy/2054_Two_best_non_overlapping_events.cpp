#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        if(events.size() == 2 && events[1][0] <= events[0][1]) return max(events[0][2],events[1][2]);  
        int maxValue = INT_MIN;
        int value = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(events[j][0] > events[i][1]){
                    value = events[i][2] + events[j][2];
                }
                else{
                    value = events[i][2];
                }
                maxValue = max(maxValue,value);
            }
        }      
        return maxValue;
    }
};

int main(){
    Solution s;
    vector<vector<int>>events = {{1,3,2},{4,5,2},{2,4,3}};
    cout<<s.maxTwoEvents(events)<<endl;
    return 0;
}
