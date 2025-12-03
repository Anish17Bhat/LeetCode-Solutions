#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class  Solution{
    public:
        vector<int> MaxNumMeetings(vector<int>&start,vector<int>&end,int n){
            map<pair<int,int>,int>meetings;
            vector<int>result;
            for(int i = 0 ; i < n ; i++){
                meetings.insert({make_pair(start[i],end[i]),i+1});
            }
            cout<<endl;
            for(auto meet : meetings){
                cout<<"( "<<meet.first.first<<","<<meet.first.second<<" )"<<"  "<<meet.second<<endl;
            }
            cout<<endl;
            for(auto meet : meetings){
                pair<int,int>duration = meet.first;
                if(duration.first == duration.second) continue;
                vector<int>ans;
                ans.push_back(meet.second);
                for(auto nxtmeet : meetings){
                    if(nxtmeet.first.first >= duration.second){
                        ans.push_back(nxtmeet.second);
                        duration = nxtmeet.first;
                    }
                }
                if(ans.size() > result.size()){
                    result = ans;
                }
            }
            return result;
        }
    };
    
    int main(){
        Solution s;
        vector<int>start = {1,3,0,5,8,5};
        vector<int>end = {1,4,5,9,9,7};
        int n = 6;
        vector<int>result = s.MaxNumMeetings(start,end,n);
        for(int ele : result){
            cout<<ele<<" ";
        }
        cout<<endl;
    return 0;
}
