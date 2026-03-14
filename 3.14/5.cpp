//UVA12604 Caesar Cipher 1h
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;



unordered_map<string, int> get_w(string a,string w)
{
	int n = a.size();
	vector<int>w_site(w.size());
	unordered_map<string,int>wstr;
	for (int i = 0; i < w.size(); i++)
	{
		w_site[i] = a.find(w[i]);
	}
	string S = a;
	for (int i = 0; i < n; i++)
	{
		string w_changed;
		for (int j = 0; j < w_site.size(); j++)
		{
			w_changed += a[(w_site[j] + i) % n];
		}
		if (!wstr.count(w_changed))
			wstr.emplace(w_changed,i);
	}
	return wstr;
}
vector<int>prefix(string s)
{
	int n = s.size();
	vector<int>pi(n);
	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])j = pi[j - 1];
		if (s[i] == s[j])j++;
		pi[i] = j;
	}
	return pi;
}
vector<int> KMP(string text, string pattern)
{
	string cur = pattern + '#' + text;
	int sz1 = text.size();
	int sz2 = pattern.size();
	vector<int> v;
	vector<int>pi = prefix(cur);
	for (int i = sz2 + 1; i <= sz1 + sz2; i++)
	{
		if (pi[i] == sz2)v.push_back(i-2*sz2);
	}
	return v;
}
int solve(string a, string w, string s)
{
	unordered_map<string, int>wstr=get_w(a, w);
	for (int i = 0; i < wstr.size(); i++)
	{
		vector<int> res = KMP( s,wstr[i] );
		if (res.size() == 0)cout << "no solution" << endl;
		else if(res.size()==1)cout<<"unique: "<<find

	}

}