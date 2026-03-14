//luogu UVA455 ÖÜÆÚ´® Periodic Strings 0.5h
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> prefix_function(string s)
{
	int n = (int)s.size();
	vector<int>pi(n);
	for (int i = 1; i < n; i++)//i==1,attention!!
	{
		int j = pi[i-1];//attention!!
		while (j > 0 && s[i] != s[j])j = pi[j - 1];
		if (s[i] == s[j])j++;
		pi[i] = j;
		
	}
	return pi;
}
int min_round(string s)
{
	vector<int>pi = prefix_function(s);
	int n = (int)s.size();
	int k= n - pi[n - 1];//the definition of border. n%k. attention!!
	return n % k ? n : k;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cout << min_round(s) << endl;
	}
}