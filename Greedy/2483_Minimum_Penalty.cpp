#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>Nprefix(n+1,0);
        vector<int>Ysufix(n+1,0);    
        //precomputation
        int count = 0;
        if(customers[0] == 'N') count++;
        for(int i = 1 ; i < n ; i++){
            Nprefix[i] = count;
            if(customers[i] == 'N') count++;
        }  
        Nprefix[n] = count;
        count = 0;
        if(customers[n-1] == 'Y') count++;
        for(int i = n - 2 ; i >= 0 ; i--){
            Ysufix[i] = count;
            if(customers[i] == 'Y') count++;
        }
 
        int ans;
        int penalty = 0;
        int minPenalty = INT_MAX;
        for(int i = 0 ; i < n+1 ; i++){
            if(i < n && customers[i] == 'Y') penalty = 1;
            penalty += Nprefix[i] + Ysufix[i];
            if(penalty < minPenalty){
                ans = i;
                minPenalty = penalty;
            }
            penalty = 0;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string customers = "YNNNNY";
    cout<<s.bestClosingTime(customers)<<endl;
    return 0;
}
