#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int,int>mp;
        for(int ele : hand){
            mp[ele]++;
        }
        int count;
        for(auto ele : mp){
            if(ele.second == 0){
                continue;
            }
            count = ele.second;
            for(int i = 0 ; i < groupSize ; i++){
                if(mp[ele.first + i] < count) 
                    return false;
                mp[ele.first + i] -= count;
            }
        }
        return true;
    }
};

int main()
{
    vector<int>hand = {1,2,3,6,2,3,4,7,8};
    Solution s;
    cout<<s.isNStraightHand(hand,10);
    cout<<endl;   
    return 0;
}
