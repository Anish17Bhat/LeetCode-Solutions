#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct meet{
    int start;
    int end;
    int pos;
};

bool comp(struct meet m1, struct meet m2){
    if(m1.end < m2.end) return true;
    if(m1.end > m2.end) return false;
    if(m1.pos < m2.pos) return true;
    return false;
}

class  Solution{
    public:
        vector<int> MaxNumMeetings(vector<int>&start,vector<int>&end,int n){
            vector<int>ans;
            struct meet m[n];
            for(int i = 0 ; i < n ; i++){
                m[i].start = start[i];
                m[i].end = end[i];
                m[i].pos = i+1; 
            }
            sort(m,m+n,comp);
            int whenFin = m[0].end;
            ans.push_back(m[0].pos);
            for(int i = 1 ; i < n ; i++){
                if(m[i].start > whenFin){
                    ans.push_back(m[i].pos);
                    whenFin = m[i].end;
                }
            }
            return ans;
        }
    };
    
    int main(){
        Solution s;
        vector<int>start = {1,3,0,5,8,5};
        vector<int>end = {2,4,5,7,9,9};
        int n = 6;
        vector<int>result = s.MaxNumMeetings(start,end,n);
        for(int ele : result){
            cout<<ele<<" ";
        }
        cout<<endl;
    return 0;
}
