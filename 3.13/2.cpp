//luogu P2324 [SCOI2005] 骑士精神 IDDFS/双向搜索 2h
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

