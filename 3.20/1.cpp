//P1993 小 K 的农场 bellman-ford
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 500;
const int MAXM = 10005;
const int INF = 0x3f3f3f3f;
struct edge
{
	int v;
	int w;
};
vector<edge>e[MAXN];
int dis[MAXN], vis[MAXN] = { 0 }, cnt[MAXN] = { 0 };
queue<int>q;
void add(int u, int v, int w)
{
	e[u].push_back({ v,w });
}
bool spfa(int n)
{
	memset(dis, INF, (n + 1) * sizeof(int));
	dis[0] = 0;
	vis[0] = 1;
	q.push(0);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (edge ed : e[u])
		{
			int v = ed.v;
			int w = ed.w;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n)
					return false;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return true;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	dis[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		add(0, i, 0);
	}
	for (int i = 0; i < m; i++)
	{
		int j;
		cin >> j;
		if (j == 1)
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(a,b, -c);//a-b>=c,b-a<=-c
		}
		else if (j == 2)
		{
			int a, b, c;
			cin >> a >> b >> c;//a-b<=c
			add(b, a, c);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			add(a, b, 0);
			add(b, a, 0);
		}
	}
	spfa(n + 1);
}