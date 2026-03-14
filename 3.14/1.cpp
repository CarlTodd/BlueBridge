//prefix function's application: count the appearance number of every prefix. 0.5h
#include<iostream>
#include<vector>
using namespace std;
vector<int> prefix_function(string s)
{
	int n = (int)s.size();
	vector<int>pi(n);
	for (int i = 0; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])j = pi[j - 1];
		if (s[i] == s[j])j++;
		pi[i] = j;

	}
	return pi;
}
int q1(string s)
{
	int n= (int)s.size();
	vector<int>pi = prefix_function(s);
	vector<int>ans(n,0);
	for (int i = 0; i < n; i++)
	{
		int j = pi[i];
		ans[j]++;
	}//forget to add the second prefix:included by the first(biggest) prefix,j=pi[j-1]. 
}
