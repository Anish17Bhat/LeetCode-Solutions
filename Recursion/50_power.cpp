#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double helper(double x, long long n){
        if(n == 1) return x;
        if(n % 2 == 0) return helper(x*x,n/2);
        else return x * helper(x*x,n/2);   
    }
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;
        if(n < 0 ){
            return helper(1/x,-1*n);
        }
        else{
            return helper(x,n);
        }
        return -1;
    }
};

int main(){
    int n = -2;
    int x = 2.0000;
    Solution s;
    cout<<s.myPow(x,n);
    cout<<endl;
    return 0;
}
