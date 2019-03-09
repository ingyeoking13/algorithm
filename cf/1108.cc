#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
  int u, v, w;
  edge(int u, int v, int w) : u(u), v(v), w(w) {};
  bool operator< (edge e) { return w < e.w; };
};
vector<int> p;
int ufind(int u)
{
  if (u == p[u] ) return u;
  return u = ufind(p[u]);
}

int main()
{
  vector<edge> e;
  vector<int> cost;
  vector<int> rank;

  int n, m;
  scanf("%d%d", &n, &m);

  p.resize(n+1);
  cost.resize(n+1);
  rank.resize(n+1);

  for (int i=0; i<p.size(); i++) p[i]=i, rank[i]=1;

  while(m--)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e.push_back( edge(u, v, w) );
  }

  sort(e.begin(), e.end());

  int ans=0;
  for (int i=0; i<e.size(); i++)
  {
    int cost = e[i].w;

    int j;
    for (j=i+1; j<e.size(); j++)
    {
      if ( e[j].w != cost) break;
    }
    int cnt = j-i;

    for (int k=i; k<j; k++)
    {
      int u = e[k].u, v = e[k].v; 
      u = ufind(e[k].u), v = ufind(e[k].v);
      if ( u == v) cnt--;
    }

    for (int k=i; k<j; k++)
    {
      int u = e[k].u, v = e[k].v; 
      u = ufind(e[k].u), v = ufind(e[k].v);
      if ( u!= v)
      {
        cnt--;
        if ( rank[u] < rank[v] ) swap(v, u);
        rank[u] += rank[v];
        p[v] = u;
      };
    }
    ans += cnt;
    i = j-1;
  }
  printf("%d\n", ans);
}

