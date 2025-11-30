#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool lemonadeChange(vector<int>& bills) {
            int n = bills.size();
            int five = 0;
            int ten = 0;
            for(int i = 0 ; i < n ; i++){
                if(bills[i] == 5) {
                    five++;
                }
                else if(bills[i] == 10){
                    if(five) five--;
                    else return false;
                    ten++;
                }
                // greedy because we are seeing first if we can give $10 bill first instead of giving three $5 bills so that we can save up the $5 bills for more upcoming customers
                else{
                    if(five && ten){
                        five--;
                        ten--;
                    }
                    else if(five >= 3){
                        five -= 3;
                    }
                    else return false;
                }
            }
            return true;
        }      
};

int main(){
    Solution s;
    vector<int>bills = {5,5,10,5,20,20,20,10,5,10};
    cout<<s.lemonadeChange(bills);
    cout<<endl;
    return 0;
}
