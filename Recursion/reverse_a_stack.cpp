#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void SpecialInsert(stack<int>st, int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }

        int temp = st.top();
        st.pop();

        SpecialInsert(st,ele);

        st.push(temp);
    }
    public:
        void reverseStack(stack<int>st){
            if(st.empty()) return;
            
            int ele = st.top();
            st.pop();

            reverseStack(st);

            SpecialInsert(st,ele);
        }
};

int main(){
    stack<int>s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    Solution s1;
    s1.reverseStack(s);
    for( ; !s.empty() ; ){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    return 0;
}
