#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class  Solution{
    public:
        vector<int> MaxNumMeetings(vector<int>&start,vector<int>&end,int n){
            map<pair<int,int>,int>meetings;
            for(int i = 0 ; i < n ; i++){
                meetings.insert({make_pair(end[i],start[i]),i+1});
            }
            cout<<endl;
            for(auto meet : meetings){
                cout<<"( "<<meet.first.first<<","<<meet.first.second<<" )"<<"  "<<meet.second<<endl;
            }
            cout<<endl;
            vector<int>ans;
            auto t = *(meetings.begin());
            pair<int,int>temp = t.first;
            ans.push_back(t.second);
            for(auto meet : meetings){
                if(meet.first.second >= temp.first){
                    ans.push_back(meet.second);
                    temp = meet.first;
                }
            }
            return ans;
        }
    };
    
    int main(){
        Solution s;
        vector<int>start = {1,3,0,5,8,5};
        vector<int>end = {5,4,5,9,9,7};
        int n = 6;
        vector<int>result = s.MaxNumMeetings(start,end,n);
        for(int ele : result){
            cout<<ele<<" ";
        }
        cout<<endl;
    return 0;
}
