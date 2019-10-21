#include <iostream>
#include <vector>
#include <string.h>

#define mod 2520

using namespace std;
int a[(int)1e3+1], d[1001][2520], v[1001];
int n, c;
vector<vector<int>> e;

int go(int x, int y)
{
    y = ((y%mod)+mod)%mod;
    if ( d[x][y] > 0) return d[x][y];
    if ( d[x][y] < 0)
    {
        int res = 0;
        for (int i=1; i<=n; i++ )
        {
            if( v[i] <= d[x][y]) res++;
        }
        return res;
    }
    d[x][y] = v[x] = --c;
    int next = ((y+a[x])%e[x].size()+ e[x].size())%e[x].size();
    return d[x][y] = go( d[x][next],y+a[x]);
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    e.resize(n+1);

    for (int i=1;i<=n;i++)
    {
        int m;
        cin >> m;
        for (int j=0; j<m; j++)
        {
            int tmp;
            cin >> tmp;
            e[i].push_back(tmp);
        }
    }

    int q;
    cin >> q;
    while( q-- )
    {
        int x, y;
        cin >> x >> y;
        memset(v, 0, sizeof(v));
        c= 0;
        cout << go(x, y) <<"\n";
    }
}