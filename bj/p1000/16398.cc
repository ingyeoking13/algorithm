#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
  int u, v;
  int cost;
  Edge(int u, int v, int c) : u(u), v(v), cost(c){}
  bool operator<(Edge a) { return cost < a.cost; }
};
vector<Edge> v;

int p[1000];

int ufind(int x)
{
  if (p[x] == x) return x;
  else return p[x] = ufind(p[x]);
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    p[i]=i;
    for (int j=0; j<n; j++)
    {
      int d;
      scanf("%d", &d);
      if (i==j) continue;
      v.push_back(Edge(i, j, d));
    }
  }

  sort(v.begin(), v.end());
  long long ans=0;
  int cnt=0;
  for (auto e : v)
  {
    int pu = ufind(e.u), pv = ufind(e.v);
    if (pu == pv) continue;

    p[pv] =pu;
    ans= ans + e.cost;
    cnt++;
    if (cnt == n-1) break;

  }
  printf("%lld\n", ans);

}
