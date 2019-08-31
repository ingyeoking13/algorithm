#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int a[50][50];
bool v[50][50];

int go(int x, int y)
{
    int ret = 1;
    if ( v[x][y]) return 0;
    v[x][y] = true;

    if ( (a[x][y] & 1) == false) ret += go(x, y-1);
    if ( (a[x][y] & 2) == false) ret += go(x-1, y);
    if ( (a[x][y] & 4) == false) ret += go(x, y+1);
    if ( (a[x][y] & 8) == false) ret += go(x+1, y);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row, col;
    cin >> col >> row;

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cin >> a[i][j];
        }
    }

    int cnt=0, mx = 0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if ( v[i][j]) continue;
            cnt++;
            int ret = go(i, j);
            mx = max(mx, ret);
        }
    }

    int wall =0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {

            if ( a[i][j] & 1 )
            {
                if( j>0)
                {
                    a[i][j]  ^=1;
                    memset(v, 0, sizeof(v));
                    wall = max(wall, go(i,j));
                    a[i][j]  ^=1;
                }
            }

            if ( a[i][j]& 2)
            {
                if ( i > 0)
                {
                    a[i][j]^=2;
                    memset(v, 0, sizeof(v));
                    wall = max(wall, go(i,j));
                    a[i][j]^=2;
                }
            }

            if ( a[i][j]& 4)
            {
                if ( j<col-1)
                {
                    a[i][j]^=4;
                    memset(v, 0, sizeof(v));
                    wall = max(wall, go(i,j));
                    a[i][j]^=4;
                }
            }

            if ( a[i][j] & 8)
            {
                if (i <row-1)
                {
                    a[i][j]^=8;
                    memset(v, 0,sizeof(v));
                    wall = max(wall, go(i,j));
                    a[i][j]^=8;
                }
            }
        }
    }

    cout << cnt <<"\n" << mx << "\n"  << wall <<"\n";

}