#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1 ;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak) sum += down - peak;
        }
        return sum;
    }
};


int main(){
    // {1,0,2,4,1,3,1,2,2}
    Solution s;
    vector<int>ratings = {1,2,2};
    cout<<s.candy(ratings)<<endl;
    return 0;
}
