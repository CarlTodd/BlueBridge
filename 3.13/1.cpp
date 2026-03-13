//luogu UVA529 Addition Chains IDDFS(basic) 1.5h
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
int best_v = INF;
vector<int>ans;
queue<vector<int>>q;
int max_depth = 1;
void bfs(int n)//wrong. 
{
	for (; 1; max_depth++)
	{
		q.push({ 1 });
		while (!q.empty())
		{
			vector<int>now = q.front();
			q.pop();
			if (now.size() > max_depth)
			{
				q = queue<vector<int>>();
				break;
			}
			for (int i = now.size() - 1; i >= 0; i--)
			{
				for (int j = i; j >= 0; j--)
				{
					if (now[i] + now[j] < n && now[i] + now[j] >now.back() && find(now.begin(), now.end(), now[i] + now[j]) == now.end())
					{
						vector<int>new_v;
						new_v = now;
						new_v.push_back(now[i] + now[j]);
						q.push(new_v);

					}
					else if (now[i] + now[j] == n)
					{
						now.push_back(n);
						if (now.size() < best_v)
						{
							best_v = now.size();
							ans = now;
							return;
						}
					}
				}
			}
		}
	}
}
int n;
vector<int>path = { 1 };

bool dfs(int max_depth) {
	// path.back() 是当前序列最大的数
	// max_depth - path.size() 是你还能再添加的数字个数
	// 如果最大的数翻倍这么多轮都到不了n，直接剪掉
	if ((path.back() << (max_depth - path.size() + 1)) < n) return false;

	// 终止条件：已经达到目标n
	if (path.back() == n) return true;

	// 如果当前长度已经达到最大深度，但还没到n，说明此路不通
	if (path.size() >= max_depth) return false;

	// 星链法：只用最后一个数去加前面的数（从大到小枚举）
	for (int i = path.size() - 1; i >= 0; i--) {
		int next_val = path.back() + path[i];

		if (next_val > n) continue; // 超过n了
		// 这里不需要判断 next_val > path.back()，因为我们是从后往前加，且 path[i] >= 1

		path.push_back(next_val);
		if (dfs(max_depth)) return true; // 只要有一条路通了，立刻返回
		path.pop_back(); // 回溯
	}
	return false;
}
void solve()
{
	for (; 1; max_depth++)
	{
		if (dfs(max_depth))
		{
			for (int i : path)
			{
				cout << i << " ";
			}
			return;
		}
	}
}
int main()
{
	cin >> n;
	solve();
	
}