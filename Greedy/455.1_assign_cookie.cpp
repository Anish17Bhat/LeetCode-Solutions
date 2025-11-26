#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute force O(nm) results TLE
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        int i = 0; 
        int j = 0;
        int n = g.size();
        int m = s.size();
        vector<int>assigned(m,-1);
        int count = 0;
        sort(s.begin(),s.end());
        while(i < n){
            j = 0;
            while(j < m){
                if(g[i] <= s[j] && assigned[j] == -1){
                    count++;
                    assigned[j] = 1;
                    break;
                }
                j++;
            }
            i++;
        }        
        return count;
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