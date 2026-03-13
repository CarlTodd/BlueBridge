//luogu P1763 °£¼°·ÖÊý IDDFS 1.5h
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long LL;
LL a, b;
vector<LL>ans;
vector<LL>path;
LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}
bool dfs(int step,int limit, LL a, LL b)
{
	if (!path.empty()&&b * (limit - step) < a* path.back())
		return false;
	if (step == limit)
		return a==0;
	for (LL i = path.empty() ? 2 : path.back(); 1; i++)
	{
		if (b * (limit - step) < a * i)
			return false;
		if (b <= a*i)
		{
			path.push_back(i);
			LL g = gcd(a * i - b, b * i);
			if (!dfs(step + 1, limit, (a*i-b)/g,(b*i)/g))
			{
				path.pop_back();
			}
			else
			{
				return true;
			}

		}
	}
	return false;
}
void solve()
{
	if (a == 1)
	{
		path.push_back(b);
		return;
	}
	for (int limit = 1; 1; limit++)
	{
		if (dfs(0,limit,a,b))
		{
			
			for (LL i : path)
				cout << i << " ";
			return;
		}
	}
}
int main()
{
	cin >> a >> b;
	solve();
}