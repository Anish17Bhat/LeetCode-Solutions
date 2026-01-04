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
            for(int j = 1 ; j <= sqrt(nums[i]) ; j++){
                if(nums[i] % j == 0){
                    int num = nums[i] / j;
                    if(num == j){
                        num = 0;
                        count++;
                    }
                    else count += 2;
                    sum += j + num;
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
    vector<int>nums = {21,21};
    cout<<s.sumFourDivisors(nums)<<endl;
    return 0;
}
