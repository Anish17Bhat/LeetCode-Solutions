#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        if(temp == nums) return count;
        while(true){
            int i = 1;
            int min1 = 0;
            int min2 = 0;
            int mini = INT_MAX;
            int n = nums.size();
            while(i < n){
                if(nums[i] + nums[i-1] < mini){
                    mini = nums[i] + nums[i-1];
                    min1 = i - 1;
                    min2 = i;
                }
                i++;
            }
            nums.erase(nums.begin()+min2);
            nums[min1] = mini;
            count++;
            temp = nums;
            sort(temp.begin(),temp.end());
            if(temp == nums) return count;
        }
        return count;
    }
};

int main(){
    vector<int>nums = {4,6,1,4,7,0};
    Solution s;
    cout<<s.minimumPairRemoval(nums);
    cout<<endl;
    return 0;
}
