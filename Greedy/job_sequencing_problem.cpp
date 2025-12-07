#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comparison(tuple<int,int,int>job1, tuple<int,int,int>job2){
    return get<2>(job1) > get<2>(job2);
}

class Soluiton{
    public:
        pair<int,int> findMaxProfit(vector<tuple<int,int,int>>&jobs, int n){
            sort(jobs.begin(),jobs.end(),comparison);
            int maxi = -1;
            for(int i = 0 ; i < n ; i++){
                maxi = max(maxi,get<1>(jobs[i]));
            }
            vector<int>slots(maxi+1,-1);
            int count = 0;
            int maxProfit = 0;
            for(int i = 0 ; i < n ; i++){
                for(int j = get<1>(jobs[i]) ; j > 0 ; j--){
                    if(slots[j] == -1){
                        slots[j] = i;
                        count++;
                        maxProfit += get<2>(jobs[i]);
                        break;
                    }
                }
            }
            return make_pair(count,maxProfit);
        }
};

int main(){
    vector<tuple<int,int,int>>jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    Soluiton s;
    pair<int,int> result = s.findMaxProfit(jobs,jobs.size());
    cout<<result.first<<" "<<result.second;
    cout<<endl;
    return 0;
}
