#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
    bool operator<(Edge b) { return w < b.w; }
};

vector<int> p;
int ufind(int u)
{
    if (p[u] == u ) return u;
    return p[u] = ufind(p[u]);
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<Edge> e; 

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n-1; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    sort(e.begin(), e.end());
    p.resize(n+1);

    vector<long long>cnt(n+1);
    vector<long long>ans((int)2e5+1);

    for (int i=1; i<=n; i++) 
        p[i] = i, cnt[i]=1;

    for (auto edge : e)
    {
        int u = edge.u, v = edge.v, w = edge.w;
        u = ufind(u), v = ufind(v);
        p[v] = u;
        ans[w] += ((cnt[u]+cnt[v])*(cnt[u]+cnt[v]-1))/2;
        ans[w] -= (cnt[u]*(cnt[u]-1))/2;
        ans[w] -= (cnt[v]*(cnt[v]-1))/2;
        cnt[u] += cnt[v];
    } 

    for (int i=1; i<=2e5; i++)
    {
        ans[i] += ans[i-1];
    }

    while ( m-- )
    {
        int cost;
        cin >> cost;
        cout << ans[cost] << " ";
    }
}