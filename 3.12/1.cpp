//Âå¹È P1451,BFSÔÚµØÍ¼ÉÏ£¬¸´Ï°
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n, string(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }
    int ans = 0;
    queue<pair<int, int>> q;
    const pair<int, int> dir[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int prev = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j]&& matrix[i][j] != '0')
            {
                int now = matrix[i][j];
                int num = 1;
                q.push({ i, j });
                visited[i][j] = 1;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    visited[x][y] = 1;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int ax = dir[k].first;
                        int ay = dir[k].second;
                        if (x+ax>-1&&x+ax<n&&y+ay>-1&&y+ay<m&& !visited[x + ax][y + ay] && matrix[x + ax][y + ay] ==now)
                        {
                            q.push({ x + ax, y + ay });
                            visited[x + ax][y + ay] = 1;
                            num++;
                        }
                    }
                }
                if(num>1)
                    ans++;
            }
        }
    }
    cout << ans << endl;
}