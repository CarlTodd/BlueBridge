//UVA11022 String Factoring DP 1h(bad)
#include<iostream>
#include<string>
using namespace std;
/*
确定区间 DP 的三层循环结构：
第一层：枚举区间长度（从 1 到 N）。
第二层：枚举起点（从 0 开始）。
第三层：枚举中间切分点 或者 循环周期。
代码骨架（背下来）：
// 1. 枚举区间长度
for (int len = 1; len <= n; len++) {
	// 2. 枚举起点 i
	for (int i = 0; i <= n - len; i++) {
		int j = i + len - 1; // 终点

		// 3. 初始值（一个字符当然就是长度1）
		dp[i][j] = len;

		// 4. 枚举：尝试所有可能的切分点
		for (int k = i; k < j; k++) {
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
		}

		// 5. 枚举：尝试所有可能的压缩周期
		// ... 判断能否循环压缩，如果能，更新 dp[i][j] ...
	}
	*/
int dp[80][80];
bool can_compress(const string& s, int i, int j, int len) {
	int total_len = j - i + 1;
	if (total_len % len != 0) return false;
	for (int k = i + len; k <= j; ++k) {
		if (s[k] != s[k - len]) return false;
	}
	return true;
}
int dynamic_plan(string s)
{
	int n = s.size();
	for (int len = 1; len < n; len++)
	{
		for (int i = 0; i < n-len; i++)
		{
			int j = i + len - 1;
			dp[i][j] = len;
			for (int k = 0; k < len / 2; k++)
			{
				if (len % k)continue;
				else
				{
					if (can_compress(s, i, j, k))
					{
						dp[i][j] = min(dp[i][j], dp[i][i + k - 1]);
					}
				}
			}
			for (int k = 0; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
		}
	}
	return dp[0][n - 1];
}