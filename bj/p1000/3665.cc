#include <bits/stdc++.h>
using ll = long long;

using namespace std;
int a[(int)5e2];
int o[(int)5e2+1];
int ccur[(int)5e2+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        for (int i=0; i<n; i++)
        {
            cin >> a[i];

            o[a[i]] = i;
            ccur[a[i]] = i;
        }

        vector<int> e[(int)5e2+1];

        int m;
        cin >> m;
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            if ( o[u] < o[v]) 
            {
                int tmp  = u;
                u = v;
                v = tmp;
            }
            e[u].push_back(v);
        }

        bool exist = true;
        for (int i=0; i<n; i++)
        {
            if( !exist ) continue;

            int cur = a[i];
            sort(e[cur].begin(), e[cur].end(), [](int x, int y) 
            {
                return ccur[x]  > ccur[y];
            });

            for (int target : e[cur])
            {
                if ( o[cur] < o[target] ) 
                {
                    exist = false;
                    break;
                }
                if ( ccur[target]+1 != ccur[cur])
                {
                    exist = false;
                    break;
                }

                ccur[cur]--;
                ccur[target]++;

            }
            if ( !exist ) break;
        }

        if ( !exist ) 
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<int> ans(n);
        for (int i=1; i<=n; i++)
        {
            ans[ccur[i]] = i;
        }

        for (int a : ans)
            cout << a << " ";
        cout << "\n";

    }
}