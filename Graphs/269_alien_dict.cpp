#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> buildGraph(string dict[], int N, int K,vector<int>&indegree){
        vector<vector<int>> adj(K);
        for(int i = 0 ; i < N-1 ; i++){
            string string1 = dict[i];
            string string2 = dict[i+1];
            int l1 = 0, l2 = 0;
            int n1 = string1.size(), n2 = string2.size();
            while(l1 < n1 && l2 < n2){
                if(string1[l1] != string2[l2]){
                    adj[string1[l1] - 'a'].push_back(string2[l2] - 'a');
                    indegree[string2[l2] - 'a']++;
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
        vector<int>indegree(K,0);
        vector<vector<int>> adj = buildGraph(dict,N,K,indegree);
        queue<int>q;
        for(int i = 0 ; i < K ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        string ans = "";
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans += 'a' + v;
            for(int e : adj[v]){
                indegree[e]--;
                if(indegree[e] == 0) q.push(e);
            }
        }
        for(int i : indegree) if(i != 0) return "";
        return ans;
	}
};


int main(){
    Solution s;
    // string dict[5] = {"baa","abcd","abca","cab","cad"};                       // valid testcase   return bdac
    string dict[7] = {"baa","bad","bac","abcd","abca","cab","cad"};             // invalid testcase  return ""
    cout<<s.findOrder(dict,7,4)<<endl;
    return 0;
}
