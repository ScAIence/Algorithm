#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
bool vis[103][103];
bool light[103][103];

vector<pair<int, int>> board[103][103];

queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    q.push({1, 1});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        // cout << cur.first << ' ' << cur.second << '\n';
        for (pair<int, int> c : board[cur.first][cur.second])
        {
            bool isConnect = false;

            if (vis[c.first][c.second])
                continue;

            for (int i = 0; i < 4; i++)
            {
                int nx = c.first + dx[i];
                int ny = c.second + dy[i];
                if (nx <= 0 || nx > n || ny <= 0 || ny > n)
                    continue;
                if (vis[nx][ny] == 1)
                    isConnect = true;
            }
            if (isConnect)
            {
                vis[c.first][c.second] = 1;
                q.push(c);
            }
            light[c.first][c.second] = true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            if (vis[nx][ny]||light[nx][ny] == 0)
                continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        board[x][y].push_back({a, b});
    }

    light[1][1] = true;
    vis[1][1] = true;
    bfs();

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (light[i][j])
                ans++;
        }
    }

    cout << ans;
}