#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n = s.size();
        int ans = 0;
        int i = n - 1;
        while(i >= 1){
            if(mp[s[i]] <= mp[s[i-1]]){
                ans += mp[s[i]];
                i--;
            }
            else{
                ans += mp[s[i]] - mp[s[i-1]];
                i-= 2;
            }
        }
        if(i == 0) ans += mp[s[0]];
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.romanToInt("MCMXCIV")<<endl;
    return 0;
}
