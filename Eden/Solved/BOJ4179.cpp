#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

char miro[1003][1003];
int f_miro[1003][1003];
int j_miro[1003][1003];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> f_q;
queue<pair<int, int>> j_q;

int r, c;

void ppp(int m[][1003])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
}

void f_bfs()
{
    while (!f_q.empty())
    {
        pair<int, int> cur = f_q.front();
        f_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                continue;
            }
            if (miro[nx][ny] == '#')
            {
                continue;
            }
            if (f_miro[nx][ny] != -1)
            {
                continue;
            }

            f_miro[nx][ny] = f_miro[cur.first][cur.second] + 1;
            f_q.push({nx, ny});
        }
    }
}

void j_bfs()
{
    while (!j_q.empty())
    {
        pair<int, int> cur = j_q.front();
        j_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                continue;
            }
            if (miro[nx][ny] == '#' || miro[nx][ny] == 'F')
            {
                continue;
            }
            if (j_miro[nx][ny] != -1)
            {
                continue;
            }

            j_miro[nx][ny] = j_miro[cur.first][cur.second] + 1;
            j_q.push({nx, ny});
        }
    }
}

pair<int, int> find_coord(char a)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (miro[i][j] == a)
            {
                j_miro[i][j] = 0;
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        fill(f_miro[i], f_miro[i] + c, -1);
        fill(j_miro[i], j_miro[i] + c, -1);
    }

    for (int i = 0; i < r; i++)
    {
        cin >> miro[i];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (miro[i][j] == 'F')
            {
                f_miro[i][j] = 0;
                f_q.push({i, j});
            }
        }
    }
    f_bfs();
    j_q.push(find_coord('J'));
    j_bfs();

    // cout << "j_miro\n";
    // ppp(j_miro);
    // cout << "\nf_miro\n";
    // ppp(f_miro);

    int ans = INT32_MAX;

    for (int i = 0; i < r; i++)
    {
        if (j_miro[i][0] == -1)
        {
        }
        else if (j_miro[i][0] < f_miro[i][0] || f_miro[i][0] == -1)
            ans = min(ans, j_miro[i][0] + 1);
        if (j_miro[i][c - 1] == -1)
        {
        }
        else if (j_miro[i][c - 1] < f_miro[i][c - 1] || f_miro[i][c - 1] == -1)
            ans = min(ans, j_miro[i][c - 1] + 1);
    }

    for (int i = 0; i < c; i++)
    {
        if (j_miro[0][i] == -1)
        {
        }
        else if (j_miro[0][i] < f_miro[0][i] || f_miro[0][i] == -1)
            ans = min(ans, j_miro[0][i] + 1);
        if (j_miro[r - 1][i] == -1)
        {
        }
        else if (j_miro[r - 1][i] < f_miro[r - 1][i] || f_miro[r - 1][i] == -1)
            ans = min(ans, j_miro[r - 1][i] + 1);
    }
    if (ans == INT32_MAX)
        cout << "IMPOSSIBLE";
    else
        cout << ans;
}