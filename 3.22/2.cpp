//Ê÷×´Êý×é
#include<iostream>
#include<vector>
using namespace std;
vector<int>c;
vector<int>a;
int lowbit(int a)
{
	return a & (-a);
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		c[i] += a[i];
		int j = i + lowbit(i);
		if (j <= n)
			c[j] += c[i];
	}
}
void erase_one(int n,int x,int k)
{
	
	for (; x <= n; x+=lowbit(x))
	{
		c[x] = c[x] + k;
	}
}
void erase_many(int n, int l, int r, int k)
{
	for (; l <= r; l += lowbit(l))
	{
		if (l + lowbit(l) <= r)
		{
			c[l + lowbit(l)] += lowbit(l) * k;
		}
		else
		{
			c[r] += (r - l + 1) * k;
		}
	}
}
int check(int l,int r)
{
	int ans = 0;
	for (; r >= l;)
	{
		if (r - lowbit(r) < l)
		{
			ans = c[r] - c[l];
		}
		else
		{
			ans += c[r];
			r -= lowbit(r);
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	c.resize(n);
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	init(n);
}