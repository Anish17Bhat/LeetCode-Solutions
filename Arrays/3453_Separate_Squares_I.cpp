#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 2e9;
        double high = 0;

        for(auto s : squares){
            double y = s[1];
            double h = s[2];
            low = min(low,y);
            high = max(high,y+h);
            totalArea += h * h;
        }

        double targetArea = totalArea / 2.0;

        for(int i = 0 ; i < 100 ; i++){
            double mid = (low + high) / 2.0;

            double currentArea = 0.0;

            for(auto s : squares){
                double y = s[1];
                double h = s[2];
                double h_below = max(0.0,min(h,mid-y));
                currentArea += h_below * h;
            }

            if(currentArea < targetArea){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};

int main(){
    Solution s;
    vector<vector<int>>squares = {{0,0,2},{1,1,1}};
    cout<<s.separateSquares(squares)<<endl;
    return 0;
}
