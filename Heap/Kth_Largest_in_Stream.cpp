#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int n,k ;
public:
    KthLargest(int k, vector<int>& nums) {
        n = nums.size();
        this->k = k;
        if(k > n){
            for(int i = 0 ; i < n ; i++){
                minHeap.push(nums[i]);
            }
            return;
        } 
        for(int i = 0 ; i < k ; i++){
            minHeap.push(nums[i]);
        }
        for(int i = k ; i < n ; i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(k > n) { 
            minHeap.push(val); 
            n++; 
            return minHeap.top();
        }
        if(minHeap.empty()) minHeap.push(val);
        cout<<endl;
        if(val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    vector<int>result;
    vector<int>nums = {5,-1};
    KthLargest* obj = new KthLargest(3, nums);
    int param_1 = obj->add(2);
    result.push_back(param_1);
    int param_2 = obj->add(1);
    result.push_back(param_2);
    int param_3 = obj->add(-1);
    result.push_back(param_3);
    int param_4 = obj->add(3);
    result.push_back(param_4);
    int param_5 = obj->add(4);
    result.push_back(param_5);

    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
