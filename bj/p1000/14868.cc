#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
int a[2000][2000], d[2000][2000];
bool vv[2000][2000];

int dx[4]={-1, 1, 0, 0}, dy[4] ={0, 0,-1,1};

struct pos
{
    int x, y;
    pos(int x, int y) : x(x), y(y) {};
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k; 
    cin >> n >> k;

    vector<pos> v;
    while(k--)
    {
        int x, y;
        cin >> y >> x;
        x--, y--;
        v.push_back({x,y});
    }

    memset(d, -1,sizeof(d));

    queue<pos> q;
    for (int i=0; i<v.size(); i++) 
    {
        q.push(v[i]);
        d[v[i].x][v[i].y] = 0;
    }

    while(!q.empty())
    {
        pos cur = q.front();
        q.pop();

        int x = cur.x, y = cur.y;
        for (int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny =y+dy[i];
            if ( nx < 0 || ny <0 || nx >= n || ny >=n) continue;
            if ( d[nx][ny] >=0 ) continue;
            d[nx][ny] = d[x][y] +1;
            q.push({nx,ny});
        }
    }

    int ans = -1;
    int l = 0, r = 2*n;
    while(l <=r )
    {
        int m = (l+r)/2;
        memset(vv, 0 ,sizeof(vv));

        q.push(v[0]);
        vv[ v[0].x ][ v[0].y ] = true;

        while(!q.empty())
        {
            pos cur = q.front();
            q.pop();

            int x = cur.x, y = cur.y;
            for (int i=0; i<4; i++)
            {
                int nx = x+dx[i], ny =y+dy[i];
                if ( nx < 0 || ny <0 || nx >= n || ny >=n) continue;
                if ( d[nx][ny] > m) continue;
                if ( vv[nx][ny] ) continue;

                vv[nx][ny] = true;
                q.push({nx,ny});
            }
        }

        bool fine =true;
        for (int i=0; i<v.size(); i++)
        {
            int x = v[i].x, y= v[i].y;
            if ( !vv[x][y])  
            {
                fine = false;
                break;
            }
        }
        if ( fine) 
        {
            r= m-1;
            ans = m;
        }
        else l = m+1;
    }
    cout << ans <<"\n";
}