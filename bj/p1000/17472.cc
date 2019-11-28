#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int n, m;
int a[10][10], p[7];
bool v[10][10];
int island;

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w ) : u(u), v(v), w(w) {};
    Edge(){};
};

vector<Edge> e;
int dx[4] ={-1, 1, 0, 0}, dy[4] ={0, 0, -1, 1};

void go (int x, int y)
{
    if ( x < 0 || x >= n || y < 0 || y >= m ) return;
    if ( v[x][y]) return;
    if ( a[x][y] == 0) return;
    v[x][y] = true;
    a[x][y] = island;
    go(x+1, y); go(x, y+1);
    go(x-1, y); go(x, y-1);
}

int ufind(int x)
{
    if ( x == p[x]) return x;
    return p[x] = ufind(p[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m;j++)
        {
            if ( a[i][j] == 0) continue;
            if ( v[i][j] ) continue;

            island++;
            go(i, j);
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if ( a[i][j] == 0 ) continue;

            int state =a[i][j];
            int x = i, y = j;

            for (int k=0; k<4; k++)
            {
                int nx = x+dx[k], ny = y+dy[k];
                int len = 0;
                int meet =-1;
                while( !(nx <0 || ny <0 || nx>=n || ny >=m ) )
                {
                    if ( a[nx][ny] == state ) break;
                    if ( a[nx][ny] != 0)
                    {
                        meet= a[nx][ny];
                        break;
                    }
                    len++;
                    nx += dx[k], ny += dy[k];
                }
                if  ( meet > 0 && len>=2 )
                {
                    e.push_back({state, meet, len});
                    e.push_back({meet, state, len});
                }
            }
        }
    }

    for (int i=0; i<7; i++) p[i] = i;

    sort(e.begin(), e.end(), [](Edge x, Edge y) 
    {
        return x.w < y.w;
    } );

    int ans = 0;
    for (Edge edge : e)
    {
        int u =  ufind(edge.u), v = ufind(edge.v);
        if ( u == v ) continue;
        p[u] = v;
        ans +=  edge.w;
    }

    int k = ufind(p[1]);
    for (int i=1; i<=island; i++)  if ( k != ufind(p[i])) ans =0;
    cout << (ans==0?-1:ans) << "\n";
}