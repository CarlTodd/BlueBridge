//UVA11452 Dancing the Cheeky-Cheeky  the min round of string. 0.5h
#include<iostream>
#include<vector>
#include<string>
#include<string_view>
using namespace std;
vector<int> prefix_function(string s)
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

int min_round(string s)
{
	int n = s.size();
	vector<int>pi=prefix_function(s);
	int k = n - pi[n - 1];
	return k;
}
void post_sequeue(string s)
{
	int min = min_round(s);;
	int n = s.size();
	int rem = n % min;
	int j = rem;
	for (int i = 0; i < 8; i++)
	{
		
		cout << s[j++];
		j = j % min;

	}
	cout << "..." << endl;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		post_sequeue(s);
	}
}