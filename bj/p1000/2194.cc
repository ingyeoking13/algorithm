#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

bool a[500][500], v[500][500];
int d[500][500];
int dx[4] ={-1, 1, 0, 0} , dy[4] ={0, 0, -1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row , col , h, w , k;
    cin>> row >> col >> h >>w >> k;

    while(k--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y]= true;
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--,sy--,ex--,ey--;

    memset(d, -1, sizeof(d));

    queue<pair<int, int>> q;
    q.push({sx, sy});
    v[sx][sy] = true;
    d[sx][sy] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x= cur.first, y= cur.second;
        for (int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny =  y+ dy[i];

            if ( nx< 0 || ny<0 || nx+h-1>= row || ny+w-1>= col ) continue;

            bool fine = true;

            for (int j=nx; j<nx+h; j++)
            {
                for (int k =ny; k<ny+w; k++)
                {
                    if ( a[j][k] ) fine = false;
                    if (!fine) break;
                }
                if (!fine) break;
            }

            if ( !fine ) continue;
            if ( v[nx][ny] ) continue;

            v[nx][ny] = true;
            d[nx][ny] = d[x][y]+1;
            q.push({nx,ny});
        }
    }

    cout << d[ex][ey] <<"\n";
}