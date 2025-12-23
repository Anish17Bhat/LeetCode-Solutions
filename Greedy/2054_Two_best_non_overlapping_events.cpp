#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> computeMaxSuffix(vector<vector<int>>&events){
        int n = events.size();
        vector<int>maxSuffix(n);
        int value = events[n-1][2];
        for(int i = n - 1; i >= 0 ; i--){
            value = max(value,events[i][2]);
            maxSuffix[i] = value;
        }
        return maxSuffix;
    }

    int binSearch(vector<vector<int>>&events,int end, int n){
        int l = 0 ; 
        int h = n - 1;
        int mid = (l+h)/2;
        int ans = -1;
        while(l <= h){
            if(events[mid][0] > end){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
            mid = (l+h)/2;
        }
        return ans;
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<int>maxSuffix = computeMaxSuffix(events);
        int maxValue = INT_MIN;
        int value = 0;
        for(int i = 0 ; i < n ; i++){
            int ind = binSearch(events,events[i][1],n);
            if(ind == -1) maxValue = max(maxValue,events[i][2]);
            else{
                value = events[i][2] + maxSuffix[ind];
                maxValue = max(maxValue,value);
            }
        }
        return maxValue;
    }
};

int main(){
    Solution s;
    vector<vector<int>>events = {{18,54,58}, {55,61,81}, {97,98,15}, {17,76,88}, {40,59,71}, {58,60,74}, {22,71,11}, {84,85,42}, {32,95,32}, {46,52,55}, {47,56,47}, {46,65,15}, {60,99,54}, {54,95,54}, {52,57,21}, {66,99,79}, {81,99,98}, {90,95,22}, {86,86,10}, {92,100,33}, {10,92,87}, {19,33,58}, {13,75,69}, {68,69,3}, {66,93,9}, {55,80,73}, {84,89,50}, {14,87,64}, {31,84,90}, {1,95,31}, {4,96,23}, {23,71,93}};

    cout<<s.maxTwoEvents(events)<<endl;
    return 0;
}
