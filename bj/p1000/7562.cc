#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int d[300][300];
int dx[8] ={1, 1, -1, -1, 2, 2, -2, -2}, dy[8] ={2, -2, 2, -2, 1, -1, 1, -1};
int main()
{
    int T;
    cin >> T;
    while (T-- )
    {
        int n;
        cin >> n;
        memset(d, -1, sizeof(d));

        int x, y;
        cin >> x >> y;

        int ex, ey;
        cin >> ex >> ey;

        queue<pair<int, int>> q;
        q.push({x, y});
        d[x][y] = 0;

        while(!q.empty())
        {
            auto now = q.front();
            q.pop();

            int x = now.first, y = now.second;
            
            for (int i=0; i<8; i++)
            {
                int nx = x+dx[i], ny = y+dy[i]; 
                if ( nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
                if ( d[nx][ny] >=0) continue;
                d[nx][ny] = d[x][y] +1;
                q.push({nx, ny});
            }
        }
        cout << d[ex][ey] <<"\n";
    }
}