#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct timings{
    int at;
    int dt;
};

bool comp(struct timings t1, struct timings t2){
    if(t1.at < t2.at) return true;
    if(t1.at > t2.at) return false;
    return false;
}

class Solution{
    public:
        int minPlatforms(vector<int>&arr, vector<int>&dep, int n){
            struct timings tm[n];
            for(int i = 0 ; i < n ; i++){
                tm[i].at = arr[i];
                tm[i].dt = dep[i];
            }          
            sort(tm,tm+n,comp);
            int count = 1;
            int maxCount = 1;
            int prevDep = tm[0].dt;
            for(int i = 1 ; i < n ; i++){
                if(tm[i].at < prevDep){
                    count++;
                    prevDep = tm[i].dt;
                }
                else{
                    count = 1;
                    prevDep = tm[i].dt;
                }
                maxCount = max(count,maxCount);
            }
            return maxCount;
        }
};

int main(){
    Solution s;
    vector<int>arr = {1020,1200,1200}; 
    // {900,945,955,1100,1500,1800};
    vector<int>dep = {1050,1230,1220};
    // {920,1200,1130,1150,1900,2000};
    cout<<s.minPlatforms(arr,dep,6);
    cout<<endl;
    return 0;
}
