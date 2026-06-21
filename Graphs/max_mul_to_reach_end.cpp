#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        if(start == end) return 0;
        int n = arr.size();
        vector<int>distance(100000,INT_MAX);
        distance[start] = 0;
        queue<pair<int,int>>q;
        q.push({0,start});
        while(!q.empty()){
            int steps = q.front().first;
            int v = q.front().second;
            q.pop();
            for(int i = 0 ; i < n; i++){
                int num = (v * arr[i]) % 100000;
                int newSteps = steps + 1;
                if(newSteps < distance[num]){
                    distance[num] = newSteps;
                    if(num == end) return newSteps;
                    q.push({newSteps,num});
                }
            }
        }
        return -1;
    }
};


int main(){
    vector<int> arr = {2,5,7};
    Solution s;
    cout<<s.minimumMultiplications(arr,3,30)<<endl;
    return 0;
}
