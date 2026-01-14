#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        if(s1 == s2) return sum;
        int m = s1.size();
        int n = s2.size();
        if(m < n) swap(s1,s2);
        vector<int>visited(n,0);
        
        for(int i = 0 ; i < m ; i++){
            int flag = 0;
            for(int j = 0 ; j < n ; j++){
                if(s1[i] == s2[j] && visited[j] == 0){
                    // cout<<s2[j]<<endl;
                    visited[j] = 1;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                sum += s1[i];
                if(i == m - 1) cout<<"al;skdfjalks";
                // cout<<s1[i]<<endl;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.minimumDeleteSum("delete","leet");
    cout<<endl;
    return 0;
}
