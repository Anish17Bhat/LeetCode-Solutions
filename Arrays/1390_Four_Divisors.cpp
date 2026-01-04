#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int m = nums.size();
        int FinSum = 0;
        for(int i = 0 ; i < m ; i++){
            int count = 0;
            int sum = 0;
            for(int j = 1 ; j <= nums[i] ; j++){
                if(nums[i] % j == 0){
                    count++;
                    sum += j;
                }
                if(count > 4) break;
            }
            if(count == 4) FinSum += sum;   
        }
        return FinSum;
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,2,3,4,21,24};
    cout<<s.sumFourDivisors(nums)<<endl;
    return 0;
}
