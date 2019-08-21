//2583 bfs
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool a[100][100];
int dx[4] ={-1, 1, 0, 0}, dy[4] ={0, 0, -1, 1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row, col, q;
    cin >> row >> col >> q;
    while(q--)
    {
        int sx, sy, ex, ey;
        cin >> sy >> sx >> ey >>ex;

        for (int i=sx; i<ex; i++)
        {
            for (int j=sy; j<ey; j++)
            {
                a[i][j] =true;
            }
        }
    }

    int cnt =0;
    vector<int> ans;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col;j++)
        {
            if (a[i][j]) continue;

            cnt++;
            ans.push_back(0);

            a[i][j] =true;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty())
            {
                auto cur = q.front();
                ans[ans.size()-1]++;
                q.pop();
                int x = cur.first, y= cur.second;
                for (int k=0; k<4; k++)
                {
                    int nx = x+dx[k], ny = y+dy[k];
                    if (nx <0 ||  ny <0 || nx>= row || ny>= col) 
                        continue;
                    if (a[nx][ny]) continue;
                    a[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << cnt <<"\n";
    sort(ans.begin(), ans.end());
    for (int i=0; i<cnt; i++)
    {
        cout << ans[i] <<" " ;
    }
    cout <<"\n";
}