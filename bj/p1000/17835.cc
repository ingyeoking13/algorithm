#include <bits/stdc++.h>
using ll = long long;

using namespace std;
struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {};
    Edge() {};
};

vector<Edge> e[(int)1e5+1];
ll d[(int)1e5+1];
priority_queue<pair<ll,int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[v].push_back({u,w});
    }

    for (int i=1; i<=n; i++) d[i] = 1LL<<61;
    for (int i=0; i<k; i++) 
    {
        int tmp;
        cin >> tmp;
        d[tmp] = 0;
        pq.push({d[tmp], tmp});
    }

    while(!pq.empty())
    {
        pair<ll, int> cur  = pq.top();
        pq.pop();
        ll dist = -cur.first;
        ll u = cur.second;

        if ( d[u] < dist ) continue;

        for (Edge edge : e[u])
        {
            int next = edge.v;
            if ( d[next] > d[u] + edge.w )
            {
                d[next] = d[u] + edge.w;
                pq.push({-d[next], next});
            }
        }
    }

    int ans;
    ll mx = -1;
    for (int i=1; i<=n; i++)
    {
        if ( d[i] == 1LL<<61) continue;
        if ( mx < d[i] ) mx = d[i], ans =i;
    }
    cout << ans << "\n" << mx <<"\n";
}