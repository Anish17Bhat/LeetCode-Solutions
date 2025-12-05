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
            int platforms = 1;
            struct timings p[n];
            p[0].at = tm[0].at;
            p[0].dt = tm[0].dt;
            for(int i = 1 ; i < n ; i++){
                int free = -1;
                for(int j = 0 ; j < platforms ; j++){
                    if(p[j].dt < tm[i].at){
                        free = j;
                        break;
                    }
                }
                if(free == -1){
                    platforms++;
                    p[platforms-1].at = tm[i].at;
                    p[platforms-1].dt = tm[i].dt;
                } 
                else{
                    p[free].dt = tm[i].dt;
                }
            }
            return platforms;
        }
};

int main(){
    Solution s;
    vector<int>arr = {900,945,955,1100,1500,1800}; 
    // {900,945,955,1100,1500,1800};
    vector<int>dep = {920,1200,1130,1150,1900,2000};
    // {920,1200,1130,1150,1900,2000};
    cout<<s.minPlatforms(arr,dep,6);
    cout<<endl;
    return 0;
}
