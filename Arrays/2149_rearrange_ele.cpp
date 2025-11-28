#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =  nums.size();
        vector<int>rearranged(n);
        int eve = 0;
        int odd = 1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
                if(eve > n-1) return nums;
                cout<<eve<<nums[i]<<endl;
                rearranged[eve] = nums[i];
                eve += 2;
            }
            else{
                if(odd > n-1) return nums;
                rearranged[odd] = nums[i];
                odd += 2;
            }
        }      
        return rearranged;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,3,-2,-1};
    vector<int>result = s.rearrangeArray(nums);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
