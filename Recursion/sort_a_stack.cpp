#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void insert(stack<int>&s, int ele){
        if(s.empty() || s.top() <= ele){
            s.push(ele);
            return;
        }

        int temp = s.top();
        s.pop();
        insert(s,ele);

        s.push(temp);
    }
    public:
        void sortStack(stack<int>&s){
            if(s.empty()) return;

            int ele = s.top();
            s.pop();

            sortStack(s);

            insert(s,ele);
        }
};

int main(){
    stack<int>s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    Solution s1;
    s1.sortStack(s);
    for( ; !s.empty() ; ){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    return 0;
}
