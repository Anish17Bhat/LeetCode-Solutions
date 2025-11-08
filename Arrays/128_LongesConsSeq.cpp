#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        int len = 1;
        set<int>s;
        for(int ele : nums){
            s.insert(ele);
        }
        for(int ele : s){
            if(s.find(ele-1) == s.end()){
                len = 1;
                int temp = ele+1;
                while(s.find(temp) != s.end()){
                    len++;
                    temp++;
                }
                maxLen = max(len,maxLen);
            }
        }
        return maxLen;
    }
};

int main(){
    vector<int>nums = {100,4,200,1,3,2};
    Solution s;
    cout<<s.longestConsecutive(nums);
    cout<<endl;    
    return 0;
}
