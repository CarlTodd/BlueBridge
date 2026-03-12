#include<iostream>
#include<vector>
using namespace std;
const int maxnode = 100;
int N, M;
vector<int> adj[maxnode];
int siz[maxnode] = { 0 };
int dp[maxnode][maxnode];
int cost[maxnode];
int weigh[maxnode];
int dfs(int u)
{
	siz[u] = 1;
	dp[u][1] = weigh[u] * cost[u];
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		dfs(v);
		for (int j = min(siz[u], M); j >= 1; j--)
		{
			for (int k = 0; k < min(M - j, siz[v]); k++)
			{
				dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[v][k]);
			}
		}
		sz[u] += sz[v];
	}

}