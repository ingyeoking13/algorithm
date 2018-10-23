#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
vector<int> e[(int)1e5+1];
int p[(int)1e5+1];
int sz[(int)1e5+1];
set<int> s;
vector<int> city_ally;

int pfind(int u)
{
    if (p[u] == u) return u;
    else return p[u] = pfind(p[u]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) p[i]=i;
    for (int i=1; i<=n; i++) sz[i]=1;
    for (int i=0 ; i<m; i++)
    {
        int u,  v;
        scanf("%d %d", &u, &v );
        e[u].push_back(v);
    }

    int CTP, HAN, k;
    scanf("%d %d %d", &CTP, &HAN, &k);

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<e[i].size(); j++)
        {
            int u = i, v = e[i][j];
            int pu = pfind(u), pv = pfind(v);
            if (pu== pv) continue;

            if (pu == CTP || pu == HAN )
            {
                p[pv] = pu;
                sz[pu] += sz[pv];
            }
            else if ( pv == CTP || pv == HAN)
            {
                p[pu] = pv;
                sz[pv] += sz[pu];
            }
            else p[pu] = pv, sz[pv] += sz[pu];
        }
    }
    for (int i=1; i<=n; i++) pfind(i);
    for (int i=1; i<=n; i++)
    {
        if (p[i] == HAN || p[i] == CTP) continue;
        if (s.find(p[i])== s.end())
        {
            city_ally.push_back(sz[p[i]]);
            s.insert(p[i]);
        }
    }
    sort(city_ally.begin(), city_ally.end());

    int ans = sz[CTP];
    while(k-- && city_ally.size() >0)
    {
        ans += city_ally.back();
        city_ally.pop_back();
    }
    printf("%d\n", ans);
}