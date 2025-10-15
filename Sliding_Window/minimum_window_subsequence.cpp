#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string func(string s, string t, int n, int m, string str, int ind, string ans, int minL)
	{
		if (ind == n)
		{
			cout << str << endl;
			string temp = "";
			for (int i = 0; i < str.size(); i++)
			{
				if (t.find(str[i]) != string::npos)
				{
					temp += str[i];
				}
				if (temp == t)
				{
					if (str.size() < minL)
					{
						minL = str.size();
						ans = str;
					}
					break;
				}
			}
			return ans;
		}
		if (ind == 0)
			cout << "heloooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
		str.push_back(s[ind]);
		if (ind == 0)
			cout << "hello" << endl;
		if (ind == 1)
			cout << "hello" << endl;
		ans = func(s, t, n, m, str, ind + 1, ans, minL);
		str.pop_back();
		ans = func(s, t, n, m, str, ind + 1, ans, minL);
		return ans;
	}
	string minWindow(string s, string t)
	{
		int m = t.size();
		int n = s.size();
		return func(s, t, n, m, "", 0, "", INT_MAX);
	}
};

int main()
{
	string s = "ADBCO";
	string t = "ABC";
	Solution s1;
	cout << endl
		 << endl
		 << s1.minWindow(s, t) << endl;
}
