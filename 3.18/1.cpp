//×îÐ¡Æ¿¾±Â· 
#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int data;
	int cost;
	node* parent;
	node* lchild;
	node* rchild;
};
struct edge
{
	int u;
	int v;
	int cost;
};
vector<int>parent;
vector<int>ranking;
void init(int n)
{
	parent.resize(n);
	ranking.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
}
int find(int i)
{
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}
void unite(int i, int j)
{
	int root_i = find(i);
	int root_j = find(j);
	if (root_i != root_j)
	{
		if (ranking[root_i] < ranking[root_j])
		{
			parent[root_i] = root_j;
		}
		else if (ranking[root_i] > ranking[root_j])
		{
			parent[root_j] = root_i;
		}
		else
		{
			parent[root_i] = root_j;
			ranking[root_j]++;
		}
	}
}
vector<int>head, nxt, to;
int cnt = -1;
void init_link(int n)
{
	head.resize(n);
	nxt.resize(n);
	to.resize(n);
}
void add(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
void link_star()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
}

int kruskal()
{

}