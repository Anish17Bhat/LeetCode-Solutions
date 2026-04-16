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
        // if(n < 0 ){
        //     return helper(1/x,-1*n);
        // }
        // else{
        //     return helper(x,n);
        // }
        // return -1;
        if(n == 1) return x;
        int sign = 1;
        if(n < 0) {
            x = 1/x;
            sign = -1;
        }
        if(n % 2 == 0) return myPow(x*x,sign * (n/2));
        else return x * myPow(x*x,sign * (n/2));
    }
};

int main(){
    Solution s;
    cout<<s.myPow(2,6)<<endl;
    return 0;
}