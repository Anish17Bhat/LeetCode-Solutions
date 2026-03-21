// Problem Statement  :

// Here is about to introduce a new kind of number system. Where instead of 10 digits there is 20, from a to t, all in small. Now a means 1, b means 2 and t means 20, thenn aa means 21. Now for  a new number you have to print the decimal form it.

// Note that the letters in the input string will be lower case and from a to t. 

// Input Format:

// Single line containing the string of new number system’s number

// Output Format:

// Single line denoting the integer with the same decimal value as the input string

// Sample input 1: e

// Sample Output: 5

// Sample  Input 2: ac

// Sample Output: 23

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int helper(string s, int n , int i){
        if(n < 0) return 0;
        return (s[n] - 'a' + 1) * pow(20,i) + helper(s,n-1,i+1);
    }
    public:
        int NewNumberSystem(string s){
            return helper(s,s.size()-1,0);
        }
};

int main(){
    Solution s;
    string str = "ac";
    cout<<s.NewNumberSystem(str)<<endl;
    return 0;
}


