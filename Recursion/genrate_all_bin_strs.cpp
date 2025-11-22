#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(int ind, int n, string str, vector<string>&binStr){
        if(ind == n) {
            binStr.push_back(str);
            return;
        }
        str.push_back('0');
        helper(ind+1,n,str,binStr);
        str.pop_back();
        if(ind > 0 && str[ind-1] == '1') return;
        str.push_back('1');
        helper(ind+1,n,str,binStr);
    }
    public:
    vector<string>generateBinStrs(int n){
        vector<string>binStr;
        helper(0,n,"",binStr);
        return binStr;
    }
};

int main(){
    Solution s;
    vector<string>v = s.generateBinStrs(5);
    for(string str : v){
        cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}
