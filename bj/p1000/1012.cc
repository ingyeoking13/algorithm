#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int a[50][50];
int dx[4] ={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int col, row, k;
        cin  >> col >> row >> k;
        memset(a, 0, sizeof(a));

        while ( k--)
        {
            int x, y;
            cin >> x >> y;
            a[y][x] = 1;
        }

        int ans = 0;
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if (a[i][j] == 0) continue;

                ans++;

                queue<pair<int, int>> q;
                q.push({i,j});
                a[i][j] = 0;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    int x = cur.first, y =cur.second;
                    for (int k=0; k<4; k++)
                    {
                        int nx = x+dx[k], ny =y+dy[k];
                        if ( nx <0 || ny <0 || nx>= row || ny >= col) 
                            continue;
                        if ( a[nx][ny] == 0 ) continue;
                        
                        a[nx][ny] = 0;
                        q.push({nx,ny});
                    }
                }
            }
        }
        cout << ans <<"\n";
    }
}