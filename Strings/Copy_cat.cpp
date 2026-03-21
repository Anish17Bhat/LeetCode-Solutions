#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxDiff(string s){
            // TC : O(n x n!) (very slow) 
            int ans = 0;
            // int n = s.size();
            // string s1 = s;
            // sort(s.begin(),s.end());
            // int count = 0;
            // for(int i = 0 ; i < n ; i++){
                // if(s1[i] != s[i]) count++; 
            // }
            // ans = max(ans,count);
            // count = 0;
            // while(next_permutation(s.begin(),s.end())){
                // for(int i = 0 ; i < n ; i++){
                    // if(s1[i] != s[i]) count++; 
                // }
                // ans = max(ans,count);
                // count = 0;
            // }
            unordered_map<char,int>hash;
            int n = s.size() ;
            int max_freq = 0;
            int rem_chars;
            for(int i = 0 ; i < n ; i++){
                hash[s[i]]++;
            }
            int sum = 0;
            for(auto ele : hash){
                max_freq = max(max_freq,ele.second);
                sum += ele.second;
            }
            rem_chars = sum - max_freq;
            ans = n - (max_freq - rem_chars);
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
