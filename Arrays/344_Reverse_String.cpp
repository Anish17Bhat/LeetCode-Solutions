#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0 ; 
        int r = s.size()-1;
        while(l < r){
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
};

int main(){
    vector<char>s = {'h','e','l','l','o'};
    Solution st;
    st.reverseString(s);
    for(char ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
