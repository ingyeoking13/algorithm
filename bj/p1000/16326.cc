#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

struct myFish
{
    int x, y, size, cnt;
    myFish(int x, int y, int size)
    : x(x), y(y), size(size), cnt(0) {}
};

int d[10][10];
int map_fish[10][10];
bool v[10][10];
int dx[4] ={-1, 1, 0, 0}, dy[4] ={0, 0, -1, 1};

bool myfunc(const myFish& a, const myFish& b)
{
    if (d[a.x][a.y] == d[b.x][b.y])
    {
        if (a.x == b.x)  return a.y < b.y;
        else return a.x < b.x;
    }
    return d[a.x][a.y] < d[b.x][b.y];
};

int main()
{
    int n; scanf("%d", &n);
    int sx, sy;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &map_fish[i][j]);
            if (map_fish[i][j] == 9) 
            {
                sx=i, sy=j, map_fish[i][j]=0;
            }
        }
    }

    int ans=0;
    queue<pair<int, int>> q;
    myFish me = myFish(sx, sy, 2);

    while(1)
    {
        bool eat = 0;
        q.push({me.x, me.y});

        memset(d, -1, sizeof(d));
        d[me.x][me.y]=0;
        v[me.x][me.y]=1;

        while(!q.empty())
        {
            auto now = q.front(); q.pop();
            int x = now.first, y = now.second;
            for (int i=0; i<4; i++)
            {
                int nx = now.first + dx[i], ny = now.second + dy[i];
                if ( 0<= nx && nx <n && 0<= ny && ny<n)
                {
                    if ( v[nx][ny]) continue;

                    v[nx][ny]=1;
                    q.push({nx, ny});
                    d[nx][ny] = d[now.first][now.second] +1;
                }
            }
        }

        vector<myFish> vv;
        int gooddist = 1e9;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if ( map_fish[i][j] <= me.size)
                {
                    if (d[i][j] >= 0) 
                    {
                        vv.push_back({i, j, map_fish[i][j]});
                        if (map_fish[i][j]< me.size) 
                        {
                            gooddist= min(gooddist, map_fish[i][j]);
                        }
                    }
                }
            }
        }

        sort(vv.begin(), vv.end(), myfunc);
        for (auto i : vv)
        {
            if (i.size < me.size)
            {
                if (d[i.x][i.y]== gooddist)
                {
                    eat=1;
                    map_fish[i.x][i.y]=0;
                    me.cnt++;
                    if (me.cnt == me.size) me.cnt=0, me.size++;
                    ans += gooddist;
                    me.x = i.x, me.y = i.y;
                }
            }
        }

        if (!eat) break;
    }
    printf("%d\n", ans);

}