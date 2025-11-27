#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int buyIndex = 0;
        int sell = 0;
        int profit = 0;
        for(int i = 0 ; i < n ; i++){
            if(prices[i] <= buy){
                buy = prices[i];
                buyIndex = i;
            }
            else{
                if(i > buyIndex){
                    sell = prices[i];
                    profit = max(profit,sell - buy);
                } 
            }
        }     
        return profit; 
    }
};

int main(){
    Solution s;
    vector<int>prices = {7,2,9,1,5};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
