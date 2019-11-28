#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char a[100][101];
bool v[100][100];
int ans[100][100];
int dx[4] ={-1, 0, 1, 0}, dy[4] ={0, -1, 0, 1};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int r , c, k;
        cin >> r >> c >>k;

        memset(v, 0,sizeof(v));
        memset(ans, 0, sizeof(ans));
        for (int i=0;i<r ;i++)
            cin >> a[i];

        int cnt =0;
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if ( a[i][j] == 'R') cnt++;
            }
        }

        int div = cnt/k;
        int rem = cnt%k;
        int tik = 0;
        
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if ( tik == k) continue;
                if ( v[i][j]) continue;
                tik++;

                int tmp = a[i][j] == 'R';
                ans[i][j] = tik;
                v[i][j] = true;

                if (tmp == div + (rem>0)) 
                {
                    continue;
                }

                queue<pair<int, int >> q;
                q.push({i, j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int l=0; l<4; l++)
                    {
                        int nx = x+ dx[l], ny = y+dy[l];
                        if ( nx < 0 || ny <0 || nx >= r || ny >= c ) continue;
                        if ( v[nx][ny]) continue;
                        v[nx][ny] = true;
                        q.push({nx, ny});
                        tmp += a[nx][ny] == 'R';
                        ans[nx][ny] = tik;


                        if (tmp == div + (rem>0)) 
                        {
                            rem--;
                            while(!q.empty()) q.pop();
                            break;
                        }
                    }
                }
            }
        }


        for (int i=0; i<r; i++)
        {
            for (int j=0 ;j<c; j++)
            {
                if ( ans[i][j] >0) continue;
                int color = -1;

                for (int l =0; l<4; l++)
                {
                    int x = i, y=j;
                    bool find = false;
                    while(true)
                    {
                        int nx = x + dx[l], ny = y + dy[l];
                        if ( nx <0 || ny <0 || nx>=r || ny >=c) break;
                        if ( ans[nx][ny] >0 ) 
                        {
                            find = true;
                            color = ans[nx][ny];
                            break;
                        }
                    }
                    if ( color > 0) break;
                }

                queue<pair<int, int>> q;
                q.push({i, j});
                v[i][j] = true;

                while(!q.empty())
                {
                    auto cur = q.front();
                    ans[cur.first][cur.second] = color;
                    q.pop();

                    for (int l=0; l<4; l++)
                    {
                        int nx = cur.first + dx[l], ny = cur.second + dy[l];
                        if ( nx < 0 || ny < 0 || nx >= r || ny >= c ) continue;
                        if ( v[nx][ny] ) continue;
                        v[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if ( ans[i][j] <=26) cout << (char)('a' +ans[i][j]-1);
                else if( ans[i][j] <=52) cout << (char)('A' + ans[i][j]-27);
                else cout << (char)('0'+ans[i][j]-53);
            }
            cout << "\n";
        }
    }
}