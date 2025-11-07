#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void moveZeroes(vector<int>& nums) {
            int l = 0 ; 
            int r = 1;
            while(l < nums.size() && r < nums.size()){
                if(nums[r] != 0 && nums[l] == 0){
                    swap(nums[l],nums[r]);
                }
                else if(nums[l] == 0 && nums[r] == 0){
                    r++;
                    continue;
                }
                l++;
                r++;
            }
        }        
};

int main(){
    vector<int>nums = {0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);
    for(int ele : nums){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
