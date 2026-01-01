#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9){
            digits[n-1] += 1;
            return digits;
        }

        int i = n - 1;
        while(i >= 0){
            if(digits[i] != 9){
                digits[i] += 1;
                break;
            }
            digits[i] = 0;
            i--;
        }
        vector<int>ans;
        if(digits[0] == 0){
            ans.push_back(1);
            for(int i = 0 ; i < n ; i++){
                ans.push_back(digits[i]);
            }
            return ans;
        }
        return digits;
    }
};

int main(){
    Solution s;
    vector<int>digits = {9,9,9,8};
    vector<int> result = s.plusOne(digits);
    for(int ele : result){
        cout<<ele;
    }
    cout<<endl;
    return 0;
}
