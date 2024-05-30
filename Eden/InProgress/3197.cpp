#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

class Lake {
    private: 
        int R, C;
        char** lake;
        int*** vis;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        pair<int,int> init_swan;
        pair<int,int> dest_swan;
        
    public:
        Lake(int R, int C) {
            this->R = R;
            this->C = C;
            lake = (char**)malloc(sizeof(char*)*R);
            vis = (int***)malloc(sizeof(int**)*R);

            for (int i = 0; i < R; i++) {
                lake[i] = (char*)malloc(sizeof(char)*C);
                vis[i] = (int**)malloc(sizeof(int*)*C);
                for (int j = 0; j < C; j++)
                {
                    vis[i][j] = (int*)malloc(sizeof(int)*max(R,C));
                }
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
                }
                for (int j = 0; j < C; j++)
                {
                    fill(vis[i][j], vis[i][j]+max(R,C), -1);
                }
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
                    cout << vis[i][j];
                cout << '\n';
            }
        }
        int isConnected() {
            queue<tuple<int,int,int> > q;
            q.push({init_swan.first, init_swan.second, 0});
            vis[init_swan.first][init_swan.second] = 0;

            while(!q.empty())
            {
                tuple<int,int,int> cur = q.front();
                q.pop();
                for (int i = 0; i < max(R,C); i++)
                {
                    if (vis[dest_swan.first][dest_swan.second][i] != -1)
                    {
                        return i;
                    }
                }

                for (int d = 0; d < 4; d++)
                {
                    int nx = get<0>(cur) + dx[d];
                    int ny = get<1>(cur) + dy[d];
                    int nz = get<2>(cur);

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;
                    if (vis[nx][ny][nz] != -1)
                    {
                        continue;
                    }
                    
                    if (lake[nx][ny] == 'X') {
                        q.push(tuple(nx,ny,nz+1));
                        vis[nx][ny][nz+1] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];
                    }
                    else
                    {
                        q.push(tuple(nx,ny,nz));
                        vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];
                    }
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
    ans = ceil((double)l.isConnected()/2);
    // l.printSwanVis();

    cout << ans;

}