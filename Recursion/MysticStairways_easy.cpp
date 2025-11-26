#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Soltuion{
    public:
        int mysticStairways(int n, vector<int>&broken, vector<int>dp){
            if(find(broken.begin(),broken.end(),n) != broken.end()){
                return 0;
            }
            if(n == 1 || n == 2){
                return n;
            }
            if(n == 3) return 4;
            if(dp[n] != -1) return dp[n];
            return dp[n] =  mysticStairways(n-1,broken,dp) + mysticStairways(n-2,broken,dp) + mysticStairways(n-3,broken,dp);
        }
};

int main(){
    Soltuion s;
    vector<int>broken = {3};
    int n = 10;
    vector<int>dp(n+1,-1);
    cout<<s.mysticStairways(n,broken,dp);
    cout<<endl;
    return 0;
}
