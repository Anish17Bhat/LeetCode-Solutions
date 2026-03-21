#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxDiff(string s){
            int ans = 0;
            int n = s.size();
            string s1 = s;
            sort(s.begin(),s.end());
            int count = 0;
            for(int i = 0 ; i < n ; i++){
                if(s1[i] != s[i]) count++; 
            }
            ans = max(ans,count);
            count = 0;
            while(next_permutation(s.begin(),s.end())){
                for(int i = 0 ; i < n ; i++){
                    if(s1[i] != s[i]) count++; 
                }
                ans = max(ans,count);
                count = 0;
            }
            return ans;
        }
};

int main(){
    Solution sol;
    int n ;
    cin>>n;
    string s;
    for(int i = 0 ; i < n ; i++){
        cin>>s;
        cout<<sol.maxDiff(s)<<endl;
    }
    return 0;
}
