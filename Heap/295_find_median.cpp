#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (double)(maxHeap.top()+minHeap.top()) / 2;
        }
        return maxHeap.top();
    }
};

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param_1 = obj->findMedian();
    cout<<param_1<<" ";
    obj->addNum(3);
    double param_3 = obj->findMedian();
    cout<<param_3<<" ";
    cout<<endl;
    return 0;
}
