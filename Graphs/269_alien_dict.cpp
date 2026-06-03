#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> buildGraph(string dict[], int N, int K, unordered_map<char,int>&mp, vector<int>&indegree){
        vector<vector<int>> adj(K);
        for(int i = 0 ; i < N-1 ; i++){
            string string1 = dict[i];
            string string2 = dict[i+1];
            int l1 = 0, l2 = 0;
            int n1 = string1.size(), n2 = string2.size();
            while(l1 < n1 && l2 < n2){
                if(string1[l1] != string2[l2]){
                    adj[mp[string1[l1]]].push_back(mp[string2[l2]]);
                    indegree[mp[string2[l2]]]++;
                    break;
                }
                l1++;
                l2++;
            }
        }
        return adj;
    }
public:
	string findOrder(string dict[], int N, int K) {
        unordered_map<char,int> mp1;
        unordered_map<int,char> mp2;
        int num = 0;
        for(char c = 'a' ; c < 'a' + K ; c++){
            mp1[c] = num;
            mp2[num] = c;
            num++;
        }
        vector<int>indegree(K,0);
        vector<vector<int>> adj = buildGraph(dict,N,K,mp1,indegree);
        queue<int>q;
        for(int i = 0 ; i < K ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        string ans = "";
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans += mp2[v];
            for(int e : adj[v]){
                indegree[e]--;
                if(indegree[e] == 0) q.push(e);
            }
        }
        return ans;
	}
};


int main(){
    Solution s;
    string dict[5] = {"baa","abcd","abca","cab","cad"};
    cout<<s.findOrder(dict,5,4)<<endl;
    return 0;
}
