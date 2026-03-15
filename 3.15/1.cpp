//CF173B Chamber of Secrets BFS+deque 1.5h
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
enum dir { LEFT=0, RIGHT, UP, DOWN };
const int y[] = { -1,1,0,0 };
const int x[] = { 0,0,-1,1 };
const int INF=0x3f3f3f3f;
struct now
{
	int row;
	int line;
	dir face;
	int cost;
};
int solve()
{
	int row, line;
	cin >> row >> line;
	vector<vector<char>>matrix(row, vector<char>(line));
	vector<vector<vector<int>>>visited(row, vector<vector<int>>(line, vector<int>(4,INF)));
	deque<now>dq;
	dq.push_front({ 0,0,RIGHT });
	visited[0][0][RIGHT] = 0;
	while (!dq.empty())
	{
		now n = dq.front();
		dq.pop_front();
		if (matrix[n.row][n.line] == '.')
		{
			if (n.row + x[n.face] >= 0 && n.row + x[n.face] < row && n.line + y[n.face] >= 0 && n.line + y[n.face] < line
				&&visited[n.row + x[n.face]][n.line + y[n.face]][n.face]<= visited[n.row][n.line][n.face])
			{
				dq.push_front({ n.row + x[n.face] ,n.line + y[n.face] ,n.face });
				visited[n.row + x[n.face]][n.line + y[n.face]][n.face] = visited[n.row][n.line][n.face];
			}
		}
		else
		{
			int lrcost = n.face == LEFT || n.face == RIGHT ? 0 : 1;
			int udcost= n.face == UP || n.face == DOWN ? 0 : 1;
			if (n.row + x[n.face] >= 0 && n.row + x[n.face] < row && n.line + y[n.face] >= 0 && n.line + y[n.face] < line
				&& visited[n.row + x[n.face]][n.line + y[n.face]][n.face] > visited[n.row][n.line][n.face])
			{
				dq.push_front({ n.row + x[n.face] ,n.line + y[n.face] ,n.face });
				visited[n.row + x[n.face]][n.line + y[n.face]][n.face] = visited[n.row][n.line][n.face];
			}
			if (!lrcost)
			{
				if (n.row + x[UP] >= 0 && n.row + x[UP] < row && n.line + y[UP] >= 0 && n.line + y[UP] < line
					&& visited[n.row + x[UP]][n.line + y[UP]][UP] > visited[n.row][n.line][n.face]+1)
				{
					dq.push_back({ n.row + x[UP] ,n.line + y[UP] ,UP });
					visited[n.row + x[UP]][n.line + y[UP]][UP] = visited[n.row][n.line][n.face]+1;
				}
				if (n.row + x[DOWN] >= 0 && n.row + x[DOWN] < row && n.line + y[DOWN] >= 0 && n.line + y[DOWN] < line
					&& visited[n.row + x[DOWN]][n.line + y[DOWN]][DOWN] > visited[n.row][n.line][n.face] + 1)
				{
					dq.push_back({ n.row + x[DOWN] ,n.line + y[DOWN] ,DOWN });
					visited[n.row + x[DOWN]][n.line + y[DOWN]][DOWN] = visited[n.row][n.line][n.face] + 1;
				}
			}
			else
			{
				if (n.row + x[LEFT] >= 0 && n.row + x[LEFT] < row && n.line + y[LEFT] >= 0 && n.line + y[LEFT] < line
					&& visited[n.row + x[LEFT]][n.line + y[LEFT]][LEFT] > visited[n.row][n.line][n.face] + 1)
				{
					dq.push_back({ n.row + x[LEFT] ,n.line + y[LEFT] ,LEFT });
					visited[n.row + x[LEFT]][n.line + y[LEFT]][LEFT] = visited[n.row][n.line][n.face] + 1;
				}
				if (n.row + x[RIGHT] >= 0 && n.row + x[RIGHT] < row && n.line + y[RIGHT] >= 0 && n.line + y[RIGHT] < line
					&& visited[n.row + x[RIGHT]][n.line + y[RIGHT]][RIGHT] > visited[n.row][n.line][n.face] + 1)
				{
					dq.push_back({ n.row + x[RIGHT] ,n.line + y[RIGHT] ,RIGHT });
					visited[n.row + x[RIGHT]][n.line + y[RIGHT]][RIGHT] = visited[n.row][n.line][n.face] + 1;
				}
			}
		}
	}
	cout << (visited[row - 1][line - 1][RIGHT] == INF) ? -1 : visited[row - 1][line - 1][RIGHT] << endl;
}