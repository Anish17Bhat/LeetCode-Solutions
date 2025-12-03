#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findMinCoin(int V, vector<int>&denominations){
            int Value= V;
            int count = 0;
            int n = denominations.size();
            for(int i = n - 1; i >= 0 ; i--){
                while(Value >= denominations[i]){
                    Value = Value - denominations[i];
                    count++;
                }
            }
            return count;
        }
};

int main(){
    Solution s;
    vector<int>denominations = {1,2,5,10,20,50,100,500,1000};
    cout<<s.findMinCoin(121,denominations);
    cout<<endl;
    return 0;
}
