#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n);
        left[0] = 1;
        int cur = 1;
        int prev = 1;
        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else{
                left[i] = 1;
            }
        }        
        int sum = max(left[n-1],1);
        for(int i = n - 2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                cur = prev + 1;
            }
            else{
                cur = 1;
            }
            prev = cur;
            sum += max(left[i],cur);
        }
        return sum;
    }
};


int main(){
    Solution s;
    vector<int>ratings = {1,0,2,4,1,3,1,2,2};
    cout<<s.candy(ratings)<<endl;
    return 0;
}
