//luogu P1763 埃及分数 IDDFS 1.5h
/*
1. 性能问题：剪枝（Pruning）
解决方式： 必须在搜索的每一层、每一步都进行剪枝。
核心剪枝： (limit - step) * b < a * last_i（意为：剩下的步数全选当前能选的最大值，如果还不够目标值，直接废弃路径）。
2. 精度与数据溢出问题
你最初的代码： 使用了 double 或 int 进行运算。
解决方式： 绝对禁用 double（会有精度丢失）。使用 long long 维护分子分母，并通过 GCD（最大公约数） 进行实时约分。这不仅避免了精度误差，还防止了数字增长过快导致的溢出。
3. 逻辑与运算问题
主要错误： 递归公式（next_a 和 next_b 的计算）优先级写错；递归深度到达后未判断剩余分数是否为 0。
解决方式： 确保公式正确（加上括号），并在 step == limit 时检查 a == 0（即分数刚好填满，没有剩余）。
4. 最优解问题（寻找“最后一个分母最小”的解）
你最终的需求： 如何保证找到最好的解？
解决方式： 改变终止策略。
普通的 DFS 找到第一个解就立即 return true（速度快，但可能不是最好的）。
寻找最优解时，不能立即停止，而是要在这个深度下搜索完所有情况，将符合条件的 path 与当前的 best_ans 比较，选出最好的存下来。*/
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