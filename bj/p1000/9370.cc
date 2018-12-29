#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
struct Vertex
{
  int cost, u;
  Vertex(int cost, int u ) : cost(cost), u(u) {};
  bool operator<(const Vertex& v) const { return cost < v.cost; }
};

struct Edge
{
  int v, w;
  Edge(int v, int w) : v(v), w(w) {};
};

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    int s, g, h;
    scanf("%d%d%d", &s, &g, &h);

    vector<Edge> e[(int)2e3+1];

    while(m--)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v,&w);
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }

    vector<bool> ans(2e3+1, false);
    for (int i=0; i<t; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      ans[tmp]=true;
    }

    priority_queue<Vertex> pq;
    pair<int, bool> dist[(int)2e3+1];
    for (int i=1; i<=n; i++ ) dist[i].first = 1e9, dist[i].second=0;
    dist[s] = {0, 0};

    pq.push(Vertex(0, s));
    while(!pq.empty())
    {
      auto now = pq.top(); pq.pop();
      int cost = -now.cost;
      if (cost > dist[now.u].first ) continue;

      for (auto i : e[now.u] )
      {
        if (dist[i.v].first >= dist[now.u].first + i.w)
        {
          if ( dist[i.v].first == dist[now.u].first + i.w)
          {
            dist[i.v].second |= dist[now.u].second;
          }
          else dist[i.v].second = dist[now.u].second;

          dist[i.v].first = dist[now.u].first + i.w;
          dist[i.v].second |= 
            ((g==now.u) &&(h==i.v)) || ((g==i.v) && (h==now.u));
          pq.push({-dist[i.v].first, i.v});
        }
      }
    }

    for (int i=1; i<=n; i++)
    {
      if ( dist[i].second && ans[i] ) printf("%d ", i);
    }
    printf("\n");
  }
}
