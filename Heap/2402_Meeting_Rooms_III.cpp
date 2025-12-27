#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>>free;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>busy;
        vector<int>count(n,0);
        sort(meetings.begin(),meetings.end());
        for(int i = 0 ; i < n ; i++){
            free.push(i);
        }

        for(auto m : meetings){
            int start = m[0];
            int duration = m[1] - m[0];
            
            while(!busy.empty() && busy.top().first <= start){
                free.push(busy.top().second);
                busy.pop();
            }

            if(!free.empty()){
                int r = free.top();
                busy.push({m[1],r});
                free.pop();
                count[r]++;
            }
            else{
                auto [end,room] = busy.top();
                busy.pop();
                busy.push({end + duration, room});   
                count[room]++;
            }
        }
        return max_element(count.begin(),count.end()) - count.begin(); 
    }
};

int main(){
    Solution s;
    vector<vector<int>> meetings = {{1,20},{2,10},{4,9},{3,5},{6,8}};
    cout<<s.mostBooked(3,meetings)<<endl;
    return 0;
}
