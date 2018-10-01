#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct edge{
    int v, w;
    edge(int v, int w): v(v), w(w){}
};

struct wolf_state{
    long long dist; 
    int u;
    char st;
    wolf_state(long long d, int u, char st) : dist(d), u(u), st(st) {}
    bool operator < (const wolf_state& b) const { return dist < b.dist; }
};

vector<long long> d_fox;
vector<vector<long long>> d_wolf;
vector<vector<edge>> e;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    d_fox.resize(n+1, 1LL<<60); d_wolf.resize(n+1, vector<long long>(2));
    e.resize(n+1);

    for(int i=0; i< d_wolf.size(); i++) 
    {
        for (int j=0 ;j<2; j++) d_wolf[i][j] = 1LL<<60;
    }
    d_fox[1]=0, d_wolf[1][0]=0;

    for (int i=0; i<m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }

    priority_queue<pair<int ,int>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto now = pq.top();
        int dist = -now.first, u = now.second;
        pq.pop();
        if ( dist > d_fox[u]) continue;
        for (auto i : e[u])
        {
            int next = i.v, w = i.w;
            if ( d_fox[u] + w*2 < d_fox[next])
            {
                d_fox[next] = d_fox[u] + w*2;
                pq.push({-d_fox[next], next});
            }
        }
    }

    priority_queue<wolf_state> pqw;
    pqw.push({0, 1, 0});

    while(!pqw.empty())
    {
        auto now = pqw.top();
        pqw.pop();

        int dist = -now.dist, u = now.u; 
        char st= now.st;

        if ( dist > d_wolf[u][st]) continue;

        for (auto i : e[u])
        {
            int next = i.v, w = i.w;
            if ( d_wolf[u][(st)%2] + w*((st==0)?1:4) < d_wolf[next][(st+1)%2])
            {
                d_wolf[next][(st+1)%2] = d_wolf[u][st] + w*((st==0)?1:4);
                pqw.push({-d_wolf[next][(st+1)%2], next, (char)((st+1)%2)});
            }
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        if (d_fox[i] < d_wolf[i][0] && d_fox[i] < d_wolf[i][1]) {
            ans++;
        }
    }
    printf("%d\n", ans);

}