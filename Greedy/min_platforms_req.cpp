#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minPlatforms(vector<int>&arr, vector<int>&dep, int n){
            sort(arr.begin(),arr.end());
            sort(dep.begin(),dep.end());
            int a = 0;
            int d = 0;
            int platforms = 0;
            int maxplatforms = 0;
            while(a < n && d < n){
                if(arr[a] <= dep[d]){
                    platforms++;
                    a++;
                }
                else{
                    platforms--;
                    d++;
                }
                maxplatforms = max(platforms,maxplatforms);
            }
            return maxplatforms;
        }
};

int main(){
    Solution s;
    vector<int>arr = {900,945,955,1100,1500,1800}; 
    vector<int>dep = {920,1200,1130,1150,1900,2000};
    cout<<s.minPlatforms(arr,dep,6);
    cout<<endl;
    return 0;
}
