#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        int i = 0; 
        int j = 0;
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i < n && j < m){
            if(g[i] <= s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
            if(j == m){
                break;
            }
        }        
        return i;
    }
};


int main(){
    vector<int>g = {1,2};
    vector<int>s = {1,2,3};
    Solution s1;
    cout<<s1.findContentChildren(g,s);
    cout<<endl;
    return 0;
}
