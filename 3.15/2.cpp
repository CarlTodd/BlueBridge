//CF1063B Labyrinth BFS+prune 1h (hard)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct site
{
	int row;
	int line;
};
const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;
const int dr[] = { 0,0,-1,1 };
const int dl[] = { -1,1,0,0 };
int solve()
{
	int n, m, r, c, x, y;
	cin >> n >> m >> r >> c >> x >> y;
	vector<string>zern(n);
	for (int i = 0; i < n; i++)
	{
		cin >> zern[i];
	}
	vector<vector<bool>>visited(n, vector<bool>(m, 0));
	vector<vector<int>>left(n, vector<int>(m, 0));
	vector<vector<int>>right(n, vector<int>(m, 0));
	queue<site>q;
	q.push({ r,c });
	visited[r][c] = 1;
	left[r][c] = 0;
	right[r][c] = 0;
	while (!q.empty())
	{
		site now = q.front();
		q.pop();
		int nr = now.row;
		int nl = now.line;
		int new_row;
		int new_line;
		if (left[nr][nl] <x)
		{
			new_row = nr + dr[LEFT];
			new_line = nl + dl [LEFT] ;
			if (new_row >= 0 && new_row < n && new_line >= 0 && new_line < m&&!visited[new_row][new_line])
			{
				q.push({ new_row,new_line });
				visited[new_row][new_line] = 1;
				left[new_row][new_line] = left[nr][nl]+1;
				right[new_row][new_line] = right[nr][nl];
			}
		}
		if (right[nr][nl] < y)
		{
			new_row = nr + dr[RIGHT];
			new_line = nl + dl[RIGHT];
			if (new_row >= 0 && new_row < n && new_line >= 0 && new_line < m && !visited[new_row][new_line])
			{
				q.push({ new_row,new_line });
				visited[new_row][new_line] = 1;
				left[new_row][new_line] = left[nr][nl];
				right[new_row][new_line] = right[nr][nl]+1;
			}
		}
		new_row = nr + dr[UP];
		new_line = nl + dl[UP];
		if (new_row >= 0 && new_row < n && new_line >= 0 && new_line < m && !visited[new_row][new_line])
		{
			q.push({ new_row,new_line });
			visited[new_row][new_line] = 1;
			left[new_row][new_line] = left[nr][nl];
			right[new_row][new_line] = right[nr][nl];
		}
		new_row = nr + dr[DOWN];
		new_line = nl + dl[DOWN];
		if (new_row >= 0 && new_row < n && new_line >= 0 && new_line < m && !visited[new_row][new_line])
		{
			q.push({ new_row,new_line });
			visited[new_row][new_line] = 1;
			left[new_row][new_line] = left[nr][nl];
			right[new_row][new_line] = right[nr][nl];
		}
	}
}