//CF808G Anthem of Berland DP+KMP(hard) 2h
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> prefix(string s)
{
	int n = s.size();
	vector<int>pi(n);
	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])j = pi[j - 1];
		if (s[i] == s[j])j++;
		pi[i] = j;
	}
	return pi;
}
int solve()
{
	string s, t;
	cin >> s >> t;
	string cur = t + '#' + s;
	vector<int>pi = prefix(cur);
	int sz1 = s.size(); int sz2 = t.size();
	vector<vector<int>>trans(sz2, vector<int>(26));//KMP构成的状态机，只需要模板S和前缀函数数组就可以计算出在i处如果填入字母c对应的pi改变。trans[i][c]代表有前i个字母已经匹配上，c代表此处填入的字符
	for (int i = 0; i < sz2; i++)
	{
		for (int c = 0; c < 26; c++)
		{

			int j = i;//注意此处状态机和prefix不同的地方：i在此处的含义是前面有多少个字母已经匹配上。
			while (j > 0 && (c + 'a') != t[j])j = pi[j - 1];
			if ((c + 'a') == t[j])j++;
			trans[i][c] = j;
		}

	}
	vector<vector<int>>dp(sz1+1, vector<int>(sz2+1,-1));
	dp[0][0] = 0;//dp[i][j]i意思是进行到第几个字符，j的意思是前面有j个字符已经匹配上。注意一定要dp初始化！
	for (int i = 0; i < sz1; i++)
	{
		for (int j = 0; j < sz2; j++)//dp本质上是个全排列问题，先把所有可能的状态列举出来。
		{
			if (dp[i][j] == -1) continue;
			if (s[i] == '?')
			{
				for (int k = 0; k < 26; k++)//？时可以填入任意字符，全部枚举
				{
					if (trans[j][k] == sz2)//如果构成了一个字符串，则就在前一个的基础上（dp[i][j]）+1.
					{
						dp[i+1][pi[sz2 - 1]] = max(dp[i+1][pi[sz2 - 1]], dp[i][j] + 1);
						//注意此处的j下标！因为已知构成了一个目标字符串，就要判断这个目标字符串的后缀能不能被接下来的字符使用作为前缀来继续构成新字符串。所以使用pi[sz2-1]
					}
					else
					{
						dp[i+1][trans[j][k]] = max(dp[i+1][trans[j][k]], dp[i][j]);
					}
						
				}
			}
			else
			{
				if (trans[j][s[i] - 'a'] == sz2)//同理上面，只是固定写死了s[i]
				{
					dp[i+1][pi[sz2-1]] = max(dp[i+1][pi[sz2 - 1]], dp[i][j] + 1);
				}
				else
				{
					dp[i+1][trans[j][s[i] - 'a']] = max(dp[i+1][trans[j][s[i] - 'a']], dp[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < sz2; i++)
	{
		if (dp[sz1][i] > ans)
			ans = dp[sz1][i];
	}
	return ans;
}
