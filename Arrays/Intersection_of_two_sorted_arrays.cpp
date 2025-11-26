#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> Intersection_of_two_sorted_arrays(vector<int>arr1,vector<int>arr2){
        vector<int>result;
        int i = 0;
        int j = 0;
        int n = arr1.size();
        int m = arr2.size();
        while(i < n && j < m){
            if(arr1[i] == arr2[j]){
                result.push_back(arr1[i]);
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};

int main(){
    vector<int>arr1 = {1,1,2,3,4,5,7};
    vector<int>arr2 = {1,4,6,7,8};
    Solution s;
    vector<int>result = s.Intersection_of_two_sorted_arrays(arr1,arr2);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
