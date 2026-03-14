//luogu P2324 [SCOI2005] 骑士精神 IDDFS/双向搜索 2h
/*
1. 核心问题总结
性能瓶颈（最致命）： 频繁使用 string 进行字符串拼接、拷贝和查找，导致搜索过程中产生大量的内存开销，使得程序在深度搜索时变慢，极易超时。
逻辑漏洞（Bug）： 坐标判断只检查了一维下标是否在 0-24，忽略了马跳跃时的“跨行”逻辑（例如：从第一行右侧可能会跳到第二行左侧），这是不合法的。
IO 效率低： 大量使用 cin 读取字符串，相比 getchar 或 scanf 的效率差距明显。
2. 对应的解决方案（简单版）
问题点		解决方案
数据结构	弃用 string，改用 int mp[5][5] 数组，用 swap 操作代替字符串处理。
边界检查	精细化判断，使用 if (x >= 0 && x < 5 && y >= 0 && y < 5) 来确保不会跳出棋盘范围。
搜索剪枝	保持 h() 函数逻辑，但简化为“错误格子总数”，并确保搜索每一层都满足 当前深度 + 估价值 <= 最大限制。*/
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

//双向搜索（只适用于八数码问题，这个太大了）
/*
queue<string>q1,q2;
unordered_map<string, int>v1,v2;
const pair<int, int> dir[] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1}, { -2, -1} };
string move(string S,int s1,int s2)
{
	string new_state=S;
	swap(new_state[s1], new_state[s2]);
	return new_state;
}
pair<int, int> find_space(string S)
{
	int res=S.find('*');
	return { res / 5,res % 5 };
}
int extend(queue<string>& q, unordered_map<string, int>& v1, unordered_map<string, int>& v2)
{
	string S = q.front();
	pair<int, int>zero = find_space(S);
	int x = zero.first;
	int y = zero.second;
	for (pair<int, int>i : dir)
	{
		if ((x + i.first) * 5 + y + i.second >= 0 && (x + i.first) * 5 + y + i.second < 25)
		{
			
			string new_state = move(S,x*5+y, (x + i.first) * 5 + y + i.second);
			if (v2.count(new_state))
			{
				return v1[S] + 1 + v2[new_state];
			}
			if (!v1.count(new_state))
			{
				q.push(new_state);
				v1[new_state] = v1[S]+1;
			}
			
		}
	}
	return -1;

}
int bfs(string start, string end)
{
	q1.push(start);
	q2.push(end);
	v1[start] = 1;
	v2[end] = 1;
	while (!q1.empty() && !q2.empty())
	{
		int res;
		if (q1.size() > q2.size())
		{
			res=extend(q1, v1, v2);
		}
		else
		{
			res=extend(q2,v2, v1);
		}
		if (res != -1)return res;
		
	}
	return -1;

}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string matrix;
		for (int j = 0; j < width; j++)
		{
			string S;
			cin >> S;
			matrix += S;
		}
		cout << bfs(matrix, END)<<endl;
	}
}
*/

//IDDFS
const int width = 5;
const string END = "111110111100*110000100000";
string move(string S, int s1, int s2)
{
	swap(S[s1], S[s2]);
	return S;
}
pair<int, int> find_space(string S)
{
	int res = S.find('*');
	return { res / 5,res % 5 };
}
int h(string S)
{
	int diff = 0;
	for (int i=0;i<S.size();i++)
	{
		if (S[i] != END[i])
			diff++;
	}
	return (diff+1)/2;
}
string now;

const pair<int, int> dir[] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1}, { -2, -1} };
bool dfs(int step,int limit)
{
	if (h(now) > limit - step)
	{
		return false;
	}
	if (limit == step)
		return now == END;
	if (now == END)
		return true;
	if (step > limit)
		return false;

	pair<int, int>zero = find_space(now);
	int x = zero.first;
	int y = zero.second;
	for (int i = 0; i < 8; i++)
	{
		int ax = dir[i].first;
		int ay = dir[i].second;
		if ((x + ax) * 5 + y + ay >= 0 && (x + ax) * 5 + y + ay < 25)
		{
			now = move(now, 5 * x + y, (x + ax) * 5 + y + ay);
			if (!dfs(step + 1, limit))
			{
				now=move(now, 5 * x + y, (x + ax) * 5 + y + ay);
			}
			else
			{
				return true;
			}
		}
		
	}
	return false;


}
int solution()
{
	for (int limit = 1; limit<=15; limit++)
	{
		if (dfs(0, limit))
			return limit;
	}
	return -1;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string matrix;
		for (int j = 0; j < width; j++)
		{
			string S;
			cin >> S;
			matrix += S;
		}
		now = matrix;
		cout << solution() << endl;
	}
}

