#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


struct Edge
{
  int u, v;  long long w;
  Edge(int u, int v, long long w) :u(u), v(v), w(w){};
  bool operator<(const Edge& e) const { return w<e.w; }
};
vector<Edge> e;
vector<pair<long long, int> > cost;

vector<int> p;
int ufind(int now)
{
  if (now == p[now] ) return now;
  else return p[now] = ufind(p[now]);
}
int main()
{
  int n, m;
  scanf("%d%d", &n,&m);
  cost.resize(n);
  p.resize(n);

  for (int i=0; i<n; i++) p[i]=i;

  for (int i=0; i<n; i++)
  {
    scanf("%lld", &cost[i].first);
    cost[i].second = i;
  }
  sort(cost.begin(), cost.end());

  for (int i=1; i<n; i++)
  {
    e.push_back({cost[0].second, cost[i].second, cost[0].first+cost[i].first});
  }

  while(m--)
  {
    int u,v; long long w;
    scanf("%d%d%lld",&u, &v, &w);
    u--, v--;
    e.push_back({u, v, w});
  }

  sort(e.begin(), e.end());
  long long ans=0;

  for (int i=0; i<e.size(); i++)
  {
    Edge nowEdge = e[i];
    int uu = ufind(nowEdge.u);
    int vv = ufind(nowEdge.v);
    if (uu == vv) continue;

    ans += nowEdge.w;
    p[uu] = vv;
  }
  printf("%lld\n", ans);
}
