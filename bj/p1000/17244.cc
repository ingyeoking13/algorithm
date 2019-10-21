#include <iostream>
#include <queue>
#include <string.h>
#define ll long long

using namespace std;
char s[50][53];
int d[50][50][1<<5];
int a[50][50];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1,1};
struct pos {
    int x, y, z;
    pos(){};
    pos(int x, int y, int z):x(x),y(y),z(z){};
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int col , row;
    cin >> col >> row;
    memset(d, -1, sizeof(d));

    int sx, sy;
    int cnt=0;
    for (int i=0; i<row; i++)
    {
        cin>> s[i];
        for (int j=0; j<col; j++)
        {
            if ( s[i][j] == 'S') sx=i, sy=j;
            if ( s[i][j] == 'X') a[i][j] = cnt++;
        }
    }

    d[sx][sy][0] = 0;

    queue<pos> q;
    q.push({sx,sy, 0});
    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        int x = now.x, y = now.y, z = now.z;
        for (int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = dy[i]+y;
            int nz =z;

            if ( nx<0 || ny <0 || nx >= row || ny >= col) continue;
            if ( s[nx][ny] == '#') continue;

            if ( s[nx][ny] == '.');
            else if ( s[nx][ny] == 'X') nz = (z | (1 << a[nx][ny]));

            if ( d[nx][ny][nz] >=0 ) continue;
            q.push({nx,ny,nz});
            d[nx][ny][nz] = d[x][y][z]+1;
        }
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if ( s[i][j] =='E')
            {
                cout << d[i][j][(1<<cnt)-1] <<"\n";
                return 0;
            }
        }
    }
}