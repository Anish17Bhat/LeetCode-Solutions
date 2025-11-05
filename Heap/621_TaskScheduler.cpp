#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int leastInterval(vector<char>&tasks, int n){
            unordered_map<char,int>mp;
            priority_queue<int>maxHeap;
            int time = 0;
            
            for(char ch : tasks){
                mp[ch]++;
            }

            for(auto ele : mp){
                maxHeap.push(ele.second);
            }

            while(!maxHeap.empty()){
                vector<int>temp;
                int i = 0;
                int cycle = n + 1;

                while(i < cycle && !maxHeap.empty()){
                    int task = maxHeap.top();
                    maxHeap.pop();
                    task--;
                    time++;
                    if(task > 0) temp.push_back(task);
                    i++;
                }

                for(int ele : temp){
                    maxHeap.push(ele);
                }
                
                if(maxHeap.empty()) break;
                
                time += cycle - i;
            }

            return time;
        }
};

int main(){
    Solution s;
    vector<char>tasks = {'A','A','A','B','C'};
    cout<<s.leastInterval(tasks,3);
    cout<<endl;
    return 0;
}
