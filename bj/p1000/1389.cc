#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
bool e[100][100]; 
int d[100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u ,v ;
        cin >> u >> v;
        --u, --v;

        e[u][v] = e[v][u] = true;
    }

    int ans =0, mn = 1e9;
    for (int me=0; me<n; me++)
    {
        queue<pair<int, int>> q ;
        memset(d, -1, sizeof(d));

        q.push({me, 0});
        d[me] = 0;

        while(!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int now = cur.first, depth = cur.second;

            for (int i=0; i<n; i++)
            {
                if (!e[now][i]) continue;
                if ( d[i] >= 0 ) continue;

                int next = i;
                d[next] = d[now]+1;
                q.push({next, depth+1});
            }
        }

        int cnt = 0;
        for (int i=0; i<n; i++) 
        {
            cnt += d[i];
        }

        if ( cnt < mn)
        {
            ans = me;
            mn = cnt;
        }
    }
    cout << ans+1 <<"\n";
}