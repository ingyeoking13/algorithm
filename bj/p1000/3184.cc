#include <bits/stdc++.h>
using ll = long long;

using namespace std;
char m[250][253];
bool v[250][250];
int dx[4]={-1, 1, 0, 0}, dy[4]={0,0,-1,1};

int row , col;
bool closed;
int sheep, wolf;
int ans1, ans2;

void go(int x, int y)
{
    v[x][y] = true;
    if ( m[x][y] == 'o') sheep++;
    else if (m[x][y] == 'v') wolf++;

    for (int i=0; i<4; i++)
    {
        int nx = x+dx[i], ny=y+dy[i];
        if (0 > nx || nx >= row || ny <0 || ny >=col )
        {
            continue;
        }

        if ( v[nx][ny] ) continue;
        if ( m[nx][ny] == '#' ) continue;
        go(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;

    for (int i=0;i<row; i++)
        cin  >> m[i];

    for (int i=0; i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            if (v[i][j]) continue;
            if (m[i][j] =='#') continue;

            go(i, j);
            if( sheep > wolf) ans1 += sheep;
            else ans2+= wolf;
            sheep=wolf=0; 
        }
    }
    cout << ans1 << " " << ans2<<"\n";
}