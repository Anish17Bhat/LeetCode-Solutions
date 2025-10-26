#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
         int secLar = -1;
         int lar = nums[0];
         for(int ele : nums){
            if(ele > lar){
                lar = ele;
            }
            else if(ele < lar && ele > secLar){
                secLar = ele;
            }
         }
         return secLar;
    }
};

int main(){
    vector<int>nums = {10,10,10};
    Solution s;
    cout<<s.secondLargestElement(nums);
    cout<<endl;
    return 0;
}
