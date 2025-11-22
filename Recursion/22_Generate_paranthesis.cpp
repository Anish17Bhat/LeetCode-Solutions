#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(int ind1, int ind2, string str, vector<string>&ans, int n){
        if(ind1 == n && ind2 == n){
            ans.push_back(str);
            return;
        }
        if(ind1 < n)
            helper(ind1+1,ind2,str + "(" , ans, n);
        if(ind2 < n && ind2 < ind1)
            helper(ind1,ind2+1,str + ")",ans,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(0,0,"",ans,n);      
        return ans;
    }
};

int main(){
    vector<string>result;
    Solution s;
    result = s.generateParenthesis(3);
    for(string ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
