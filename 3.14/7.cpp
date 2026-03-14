//UVA11475 Extend to Palindrome   manacher 0.5h
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	bool decide = 0;
	int mid=0;
	vector<int>d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++)
	{
		int k = (i > r) ? 1 : min(r - i + 1, d1[l + r - i]);
		while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
		{
			k++;
		}
		d1[i] = k;
		k--;
		if (i + k > r)
		{
			l = i - k;
			r = i + k;
			if (r == n-1)
			{
				mid = i;
				decide = 1;
				break;
			}
		}
	}
	vector<int>d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++)
	{
		int k = (i > r) ? 0 : min(r - i + 1, d2[l + r - i + 1]);
		while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
		{
			k++;
		}
		d2[i] = k--;
		if (i + k > r)
		{
			l = i - k - 1;
			r = i + k;
			if (r == n-1)
			{
				mid = i <= mid ? i : mid;
				decide = 0;
				break;
			}
		}
	}
	int len = n - mid;
	cout << s;
	for (int i = n - 2 * len + decide-1; i >=0 ; i--)
	{
		cout << s[i];
	}
	cout << endl;
}
int main()
{
	for(;1;)
		solve();
}