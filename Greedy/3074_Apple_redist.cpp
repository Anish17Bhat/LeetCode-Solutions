#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int m = capacity.size();
        int cap = 0;
        int sum = accumulate(apple.begin(),apple.end(),0);
        int boxes = 0;
        for(int i = 0 ; i < m ; i++){
            cap += capacity[i];
            boxes++;
            if(cap >= sum){
                break;
            }
        }
        return boxes;
    }
};

int main(){
    Solution s;
    vector<int>apple = {1,2,3};
    vector<int>capacity = {4,3,1,5,2};
    cout<<s.minimumBoxes(apple,capacity)<<endl;  
    return 0;
}
