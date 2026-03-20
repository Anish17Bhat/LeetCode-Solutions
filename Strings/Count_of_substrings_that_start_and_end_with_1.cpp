#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countOneSubstring(string s){
        int ones = 0;
        for(char c : s){
            if(c == '1'){
                ones++;
            }
        }

        return ones * (ones - 1) / 2;
    }
};

int main(){
    Solution sol;
    string s = "00100101";
    cout<<sol.countOneSubstring(s)<<endl;
    return 0;
}
