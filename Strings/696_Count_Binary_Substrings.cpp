#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, strk = 1;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == s[i-1]){
                strk++;
            }
            else{
                prev = strk;
                strk = 1;
            }
            if(strk <= prev) res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "000111";
    cout<<s.countBinarySubstrings(str)<<endl;
    return 0;
}
