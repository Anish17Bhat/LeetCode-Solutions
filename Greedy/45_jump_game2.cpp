#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if(n == 1) return count;
        int l = 0;
        int r = 0;
        while(r < n-1){
            int maxind = 0;
            for(int ind = l ; ind <= r ; ind++){
                maxind = max(ind+nums[ind],maxind);
            }
            l = r + 1;
            r = maxind;
            count++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int>nums = {3,1,1,2,0,3,4,1,1,1,2};
    cout<<s.jump(nums);
    cout<<endl;
    return 0;
}
