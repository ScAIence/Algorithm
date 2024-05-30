#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
char lake[1501][1501];
bool vis[1501][1501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
pair<int,int> init_swan;
pair<int,int> dest_swan;

queue<pair<int,int>> swan;
queue<pair<int,int>> melt;
queue<pair<int,int>> temp_swan;
queue<pair<int,int>> temp_melt;


void init() {
    bool flag = true;
    for (int i = 0; i < R; i++)
    {
        cin >> lake[i];
        for (int j = 0; j < C; j++)
        {
            if (lake[i][j] == 'L')
            {
                if (flag)
                {
                    init_swan = {i,j};
                    flag = false;
                }
                else
                    dest_swan = {i,j};
            }
            bool queueflag = false;
            if (lake[i][j] == '.' || lake[i][j] == 'L') {
                melt.push({i,j});
            }
        }
        fill(vis[i], vis[i]+C, 0);
    }
    swan.push(init_swan);
    vis[init_swan.first][init_swan.second] = 1;
}

void tomorrow() {
    while(!melt.empty())
    {
        pair<int,int> cur = melt.front();
        melt.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = cur.first+dx[d];
            int ny = cur.second+dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (lake[nx][ny] == 'X')
            {
                lake[nx][ny] = '.';
                temp_melt.push({nx, ny});
            }
        }
    }

    melt = temp_melt;

    while(!temp_melt.empty())
        temp_melt.pop();
}

bool isConnected() {
    while(!swan.empty())
    {
        pair<int,int> cur = swan.front();
        swan.pop();
        vis[cur.first][cur.second] = 1;

        for (int d = 0; d < 4; d++)
        {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (vis[nx][ny])
                continue;
            if (lake[nx][ny] == 'X')
            {
                temp_swan.push({nx,ny});
                vis[nx][ny] = 1;
                continue;
            }
            else if (lake[nx][ny] == 'L')
            {
                return true;
            }
            
            swan.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }

    swan = temp_swan;
    while(!temp_swan.empty())
        temp_swan.pop();
    
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    init();
    
    int ans = 0;

    while (true) {
        if (isConnected())
            break;
        // break;
        tomorrow();
        ans++;
    }

    cout << ans;

}