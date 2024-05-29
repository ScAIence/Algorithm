#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Lake {
    private: 
        int R, C;
        char** lake;
        bool** vis;
        bool** vis_swan;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        pair<int,int> init_swan;
        pair<int,int> dest_swan;
        queue<pair<int,int>> melt;
        
    public:
        Lake(int R, int C) {
            this->R = R;
            this->C = C;
            lake = (char**)malloc(sizeof(char*)*R);
            vis = (bool**)malloc(sizeof(bool*)*R);
            vis_swan = (bool**)malloc(sizeof(bool*)*R);

            for (int i = 0; i < R; i++) {
                lake[i] = (char*)malloc(sizeof(char)*C);
                vis[i] = (bool*)malloc(sizeof(bool)*C);
                vis_swan[i] = (bool*)malloc(sizeof(bool)*C);
            }
        }

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
                            init_swan = make_pair(i,j);
                            flag = false;
                        }
                        else
                            dest_swan = make_pair(i,j);
                    }
                    bool queueflag = false;
                    if (lake[i][j] == '.') {
                        for (int d = 0; d < 4; d++)
                        {
                            if (lake[i+dx[d]][j+dy[d]] == 'X'){
                                queueflag = true;
                                break;
                            }
                        }
                        if (queueflag) {
                            this->melt.push(make_pair(i,j));
                        }
                    }
                }
                fill(vis[i], vis[i]+C, 0);
                fill(vis_swan[i], vis_swan[i]+C, 0);
            }
        }

        void printLake() {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    cout << lake[i][j];
                }
                cout << '\n';
            }
        }
        void printSwanVis() {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                    cout << vis_swan[i][j];
                cout << '\n';
            }
        }

        void tomorrow() {
            // TODO: change this area into queue impl
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (lake[i][j] != '.' || vis[i][j])
                        continue;
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = i+dx[d];
                        int ny = j+dy[d];
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                            continue;
                        if (lake[nx][ny] == 'X' && !vis[nx][ny])
                        {
                            lake[nx][ny] = '.';
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
            for (int i = 0; i < R; i++)
            {
                fill(vis[i], vis[i]+C, 0);
            }
        }
        bool isConnected() {
            queue<pair<int,int> > q;
            q.push(init_swan);
            vis_swan[init_swan.first][init_swan.second] = 1;

            while(!q.empty())
            {
                pair<int,int> p = q.front();
                q.pop();
                init_swan = p;
                if (p == dest_swan)
                    return true;

                for (int d = 0; d < 4; d++)
                {
                    int nx = p.first + dx[d];
                    int ny = p.second + dy[d];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;
                    if (lake[nx][ny] == 'X')
                        continue;
                    if (vis_swan[nx][ny])
                        continue;
                    
                    q.push(make_pair(nx,ny));
                    vis_swan[nx][ny] = 1;
                }
            }
            // this->printSwanVis();
            // for (int i = 0; i < R; i++)
            // {
            //     fill(vis_swan[i], vis_swan[i]+C, 0);
            // }
            return false;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    Lake l = Lake(r, c);
    l.init();
    
    int ans = 0;
    // cout << l.isConnected() << '\n';

    while (true) {
        if (l.isConnected())
            break;
        l.tomorrow();
        ans++;
    }

    cout << ans;

}