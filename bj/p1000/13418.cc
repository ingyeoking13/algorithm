#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w) {};
  bool operator< (Edge a ) { return w < a.w ;}
};

vector<int> p;
int ufind(int v)
{
  if ( v == p[v] ) return v;
  return p[v] = ufind(p[v]);
};

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  vector<Edge> e;
  for (int i=0; i<m+1; i++)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e.push_back(Edge(u, v, w));
  }
  sort(e.begin(), e.end());

  p.resize(n+1);
  for (int i=0; i<=n; i++) p[i] = i;
  int a=0;
  for (int i=0; i<e.size(); i++)
  {
    int u = e[i].u, v = e[i].v;
    u = ufind(u), v =ufind(v);

    if ( u == v) continue;
    p[u] =v;
    if ( e[i].w == 0) a++;
  }
  for (int i=0; i<e.size(); i++) e[i].w = -e[i].w;

  sort(e.begin(), e.end());
  for (int i=0; i<=n; i++) p[i] = i;

  int b=0;
  for (int i=0; i<e.size(); i++)
  {
    int u = e[i].u, v = e[i].v;
    u = ufind(u), v =ufind(v);

    if ( u == v) continue;
    p[u] =v;
    if ( e[i].w == 0) b++;
  }

  printf("%d\n", abs(a*a- b*b));
}
