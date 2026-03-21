//P2471 [SCOI2007] Ωµ”Í¡ø ST±Ì
#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<vector<int>>st;
void ST(const map<int, int> m)
{
	int n = m.max_size();
	int lgn = log2(m.max_size());
	st.resize(lgn + 1, vector<int>(n));
	for (int i = 1; i <= lgn; i++)
	{
		for (int j = 1; j <= n - (1 << i)+1; j++)
		{
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
}
int query(int l, int r)
{
	int s = log2(r - l+1);
	return max(st[s][l], st[s][r - (1 << s - 1) + 1]);
}
void solve()
{
	int n;
	cin >> n;
	map<int, int>m;
	for (int i = 0; i < n; i++)
	{
		int y, r;
		cin >> y >> r;
		m.try_emplace(y, r);

	}
	ST(m);

}