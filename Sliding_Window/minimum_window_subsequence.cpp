#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		int m = t.size();
		int n = s.size();
		int j = 0;
		int minL = INT_MAX;
		string minWindowString = "";
		for(int i = 0 ; i < n ; i++){
			if(s[i] == t[j]){
				j++;
			}
			if(j == m){
				int end = i;
				j--;
				while(j >= 0){
					if(s[i] == t[j]){
						j--;
					}
					i--;
				}
				i++;
				j++;
				if(end - i + 1 < minL){
					minL = end - i + 1;
					minWindowString = s.substr(i,minL);
				}
			}
		}
		return minWindowString;
	}
};

int main()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution s1;
	cout << endl
		 << endl
		 << s1.minWindow(s, t) << endl;
}
