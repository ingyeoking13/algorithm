#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

char s[1000][1001];
int dist[1000][1000], ddist[1000][1000];
int dx[4]= {-1, 1, 0 , 0}, dy[4] ={0, 0, -1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >>T;
    while(T--)
    {
        int row, col;
        cin >> col >> row;
        for (int i=0; i <row; i++)
        {
            cin>> s[i];
        }

        queue<pair<int, int>> q;
        int sx, sy;

        memset(dist, -1,sizeof(dist));

        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if(s[i][j] == '*') 
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                else if ( s[i][j] =='@') sx = i, sy = j; 
            }
        }

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            for (int i=0; i<4; i++)
            {
                int nx = x + dx[i] , ny = y+dy[i];
                if (nx<0 || ny<0 || nx>=row || ny>=col) continue;
                if (dist[nx][ny] >= 0 ) continue;
                if (s[nx][ny] =='#') continue; 

                dist[nx][ny] = dist[x][y] +1;
                q.push({nx,ny});
            }
        }
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if (dist[i][j] <0) dist[i][j] =1e9;
            }
        }

        q.push({sx, sy});
        memset(ddist, -1, sizeof(ddist));
        ddist[sx][sy] = 0;

        int ans = 0;
        while(!q.empty() && ans ==0) 
        {
            auto cur = q.front();
            q.pop(); 
            int x = cur.first, y = cur.second;

            for (int i=0; i<4; i++)
            {
                int nx = x+dx[i], ny = y +dy[i];
                if ( nx< 0 || ny<0 || nx >= row || ny >= col ) 
                {
                    ans =  ddist[x][y]+1;
                    break;
                }
                if ( ddist[x][y] +1>= dist[nx][ny] ) continue;
                if ( s[nx][ny] == '#') continue;
                if ( ddist[nx][ny] >= 0 ) continue;
                ddist[nx][ny] = ddist[x][y] +1;
                q.push({nx,ny});
            }
        }

        if (ans == 0) cout <<"IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}