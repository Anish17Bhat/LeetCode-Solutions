#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>UnionOfSortedArrs(vector<int>&arr1,vector<int>&arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0 ;
        int j = 0;
        vector<int>result;
        while(i < n1 && j < n2){
            if(arr1[i] <= arr2[j]){
                if(result.size() == 0 || result.back() != arr1[i]){
                    result.push_back(arr1[i]);
                }
                i++;
            }
            else{
                if(result.size() == 0 || result.back() != arr2[j]){
                    result.push_back(arr2[j]);
                }
                j++;
            }
        }
        while(i < n1){
            if(result.size() == 0 || result.back() != arr1[i]){
                result.push_back(arr1[i]);
            }
            i++;
        }
        while(j < n2){
            if(result.size() == 0 || result.back() != arr2[j]){
                result.push_back(arr2[j]);
            }
            j++;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int>arr1 = {1,2,2,4,5};
    vector<int>arr2 = {2,2,3,5,6};
    vector<int>result = s.UnionOfSortedArrs(arr1,arr2);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
