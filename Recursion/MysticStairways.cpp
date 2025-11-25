#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int helper(int ind, int count, int n, vector<int>&broken, vector<int>&temp, vector<vector<int>>&result){
        if(ind == n){
            result.push_back(temp);
            count++;
            return count;
        }
        for(int j = ind + 1 ; j <= n ; j++){
            if(find(broken.begin(),broken.end(),j) != broken.end()){
                continue;
            }
            if(j - ind > 3) return count;
            temp.push_back(j);
            count = helper(j,count,n,broken,temp,result);
            temp.pop_back();
        }
        return count;
    }
    public:
        pair<int,vector<vector<int>>> MysteicStaiways(int n, vector<int>&broken){
            int count = 0;
            int ind = 1;
            vector<vector<int>>result;
            vector<int>temp;
            for(int i = ind ; i <= 3 ; i++){
                if(find(broken.begin(),broken.end(),i) != broken.end()){
                    continue;
                }
                temp.push_back(i);
                count = helper(i,count,n,broken,temp,result);
                temp.pop_back();
            }
            return make_pair(count,result);
        }
};

int main(){
    vector<int>broken = {3};
    Solution s;
    pair<int,vector<vector<int>>>ans = s.MysteicStaiways(6,broken);
    cout<<ans.first<<endl<<endl;
    for(vector<int> e1 : ans.second){
        for(int e2 : e1){
            cout<<e2<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
