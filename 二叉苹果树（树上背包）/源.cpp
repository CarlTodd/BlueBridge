#include<iostream>
#include<vector>
using namespace std;
const int maxnode = 100;
int N, M;
vector<int> adj[maxnode];
int siz[maxnode] = { 0 };
int dp[maxnode][maxnode];
int cost[maxnode];

int dfs(int u)
{
	for (int v = 0; v < sz[u]; v++)
	{
		dp[u][1] += max(0, dp[v][1]);
	}
}