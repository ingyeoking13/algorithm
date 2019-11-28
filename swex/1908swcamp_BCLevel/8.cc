#include <iostream> 
#include <string.h>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
    Edge() {};
};

ll d[(int)2e5+1];
int f[(int)2e5+1];

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int tc=1; tc<=T; tc++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<Edge>> e;
        e.resize(n+1);

        for (int i=0; i<m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }

        for (int i=1; i<=n ;i++) d[i] = 2e14+1;

        priority_queue<pair<ll, int>> pq;
        pq.push({0, 1});
        d[1] = 0;

        while(!pq.empty())
        {
            auto cur = pq.top();
            ll dist = -cur.first;
            int u =  cur.second;
            pq.pop();

            if ( d[u] < dist ) continue;

            for (Edge edge : e[u])
            {
                int next = edge.v;
                if ( d[next] < d[u] + edge.w) continue;

                if ( d[next] > d[u] + edge.w )
                {
                    d[next] = d[u] + edge.w;
                    f[next] = edge.w;
                    pq.push({-d[next], next});
                }
                else 
                {
                    if (f[next] > edge.w)
                        f[next] = edge.w;
                }
            }
        }

        ll ans =0 ;
        for (int i=2; i<=n; i++)
        {
            ans += f[i];
        }

        cout << "#" << tc << " " << ans <<"\n";
    }
}