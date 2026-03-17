//P2504 [HAOI2006] 聪明的猴子 prim+链式前向星 1h
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

struct edge
{
	int to;
	int cost;
	int nxt;
};
int n;

vector<int>head(n, -1);
vector<edge>store(n* (1 + n) / 2, { -1,-1,-1 });
int cnt = -1;
void add(int u, int v,int co)
{
	store[++cnt] = { v,co,head[u] };
	head[u] = cnt;
}
struct pq
{
	int u;
	int cost;
};
bool operator<(const pq& a, const pq& b)
{
	return a.cost < b.cost;
}

priority_queue<pq>q;
vector<int> dis(n, 0x3f3f3f3f);
vector<bool> vis(n,false);
int res = 0, cnte = 0;
int max_n = 0;
void prim()
{
	dis[1] = 0;
	q.push({ 1,0 });
	while (!q.empty())
	{
		if (cnte >= n)
		{
			break;
		}
		int u = q.top().u;
		int cost = q.top().cost;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		++cnte;
		res += cost;
		if (cost > max_n)
			max_n = cost;
		for (int i = head[u]; i != -1; i = store[i].nxt)
		{
			int to = store[i].to;
			int cost = store[i].cost;
			if (cost < dis[to])
			{
				dis[to] = cost;
				q.push({ to,cost });
			}
		}
	}

}


void solve()
{
	int m;
	cin >> m;
	vector<int>monkey(m);
	for (int i = 0; i < m; i++)
	{
		cin >> monkey[i];
	}
	cin >> n;
	vector<int>x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int u = 0; u < n; u++)
	{
		for (int v = u; v < n; v++)
		{
			int cost = (x[v] - x[u]) * (x[v] - x[u]) + (y[v] - y[u]) * (y[v] - y[u]);
			add(u, v, cost);
			add(v, u, cost);
		}
	}
	prim();
	if (cnt == n)
	{
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			if (monkey[i] <= max_n)
				ans++;
		}
		cout << ans << endl;
	}
}
int main()
{
	solve();
}
