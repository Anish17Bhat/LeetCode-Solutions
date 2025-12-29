#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int>st;
        st.push(-1);
        int i = 0;
        int maxLen = 0;
        while(i < n){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxLen = max(maxLen,i-st.top());
                }
            }
            else{
                while(!st.empty()){
                    st.pop();
                }
                st.push(i);
            }
            i++;
        }      
        return maxLen;
    }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses("(43)()((()3()()()())()((()1))()")<<endl;
    return 0;
}
