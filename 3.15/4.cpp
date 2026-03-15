//P1333 ÈðÈðµÄÄ¾¹÷ hierholzer 0.5h
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct edge
{
	LL to;
	int id;
};
typedef long long LL;
LL b_table[15];
const LL b = 133;
const LL m = 1e9 + 7;
void get_b_table()
{
	b_table[0] = 1;
	for (int i = 1; i < 11; i++)
	{
		b_table[i] = b * b_table[i - 1];
	}
}
LL hash_function(string s)
{
	int n = s.size();
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += s[i] * b_table[n - i - 1];
	}
	return ans;
}
const int MAX_n = 500;
const int MAX_e = 250000;
vector<string>s_adj;
vector<edge>adj[MAX_n];
int cur[MAX_n];
int degree[MAX_n] = { 0 };
bool used[MAX_e];
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
	path.push(u)
}
int solve()
{
	int m;
	cin >> m;
	get_b_table();
	for (int i = 0; i < m; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		s_adj.push_back(s1 + "---" + s2);
		LL u = hash_function(s1);
		LL v= hash_function(s2);
		adj[u].push_back({ v,i });
		adj[v].push_back({ u,i });
		degree[u]++;
		degree[v]++;

	}
	for (int i = 1; i < MAX_n; i++)
	{
		sort(adj[i].begin(), adj[i].end(), [](const edge& a, const edge& b) {
			return a.to < b.to;
			});

	}
	int start = 1;
	for (int i = 0; i < MAX_n; i++)
	{
		if (degree[i] % 2)
		{
			start = i;
			break;
		}
	}

	
}