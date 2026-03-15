//P1127 ¥ ¡¥ hierholzer 0.5h
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct edge
{
	int to;
	int id;
};
vector<string>s_adj(20000);
vector<edge>adj[500];
int cur[500];
bool used[20000];
int degree[500];
stack<int>path;

void hierholzer(int u)
{
	for (int& i = cur[u]; i < adj[u].size(); i++)
	{
		edge& e = adj[u][i];
		if (!used[e.id])
		{
			used[e.id] = true;
			hierholzer(e.to);
		}
	}
	path.push(u);
}
int solve()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s_adj[i];
		int u = s_adj[i].front();
		int v = s_adj[i].back();
		adj[u].push_back({ v,i });
		adj[v].push_back({ u,i });
		degree[u]++;
		degree[v]++;

	}
	for (int i = 1; i < 500; i++)
	{
		sort(adj[i].begin(), adj[i].end(), [](const edge& a, const edge& b) {
			return a.to < b.to;
			});
	}
	int start = 1;
	for (int i = 1; i < 500; i++)
	{
		if (degree[i] % 2)
		{
			start = i;
			break;
		}
	}
	hierholzer(start);
}