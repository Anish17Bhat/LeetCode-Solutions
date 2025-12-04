#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        int maxind = -1;
        int count = 0;
        while(i != 0){
            for(int j = i - 1; j >= 0 ; j--){
                if(i - j <= nums[j]){
                    maxind = j;
                }
            }
            count++;
            i = maxind;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int>nums = {2,3,1,1,4};
    cout<<s.jump(nums);
    cout<<endl;
    return 0;
}
