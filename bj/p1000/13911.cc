#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge { int v, w; Edge(int v, int w): v(v), w(w) { }; };
struct Dist { int mac, sbuck; Dist(int mac, int sbuck) : mac(mac), sbuck(sbuck) {}; };

vector<Edge> e[(int)1e4+1];
bool nohouse[(int)1e4+1];
int main()
{

  int n, m;
  scanf("%d%d", &n, &m);

  int a[(int)1e4]; 
  int b[(int)1e4];

  while(m--)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[u].push_back(Edge(v, w));
    e[v].push_back(Edge(u, w));
  }

  int mac, macCon;
  scanf("%d%d", &mac, &macCon);
  for (int i=0; i<mac; i++) 
  {
    scanf("%d", &a[i]);
    nohouse[a[i]] =true;
  }

  int sbuck, sbuckCon;
  scanf("%d%d", &sbuck, &sbuckCon);
  for (int i=0; i<sbuck; i++) 
  {
    scanf("%d", &b[i]);
    nohouse[b[i]] =true;
  }

  vector<Dist> d(n+1, Dist((int)1e9+1, (int)1e9+1));

  priority_queue<pair<int, int> > pq;

  for (int i=0; i<mac; i++)
  {
    int start = a[i];
    pq.push({0, start});
    d[start].mac= 0;
  }

  while(!pq.empty())
  {
    auto now =  pq.top();
    int cost = -now.first;
    int u = now.second;
    pq.pop();
    if ( d[u].mac < cost) continue;

    for( auto next : e[u] )
    {
      if ( d[ next.v ].mac > d[u].mac + next.w)
      {
        d[next.v].mac = d[u].mac + next.w;
        pq.push({-d[next.v].mac, next.v});
      }
    }
  }

  for (int i=0; i<sbuck; i++)
  {
    int start = b[i];
    pq.push({0, start});
    d[start].sbuck=0;
  }

  while(!pq.empty())
  {
    auto now =  pq.top();
    int cost = -now.first;
    int u = now.second;
    pq.pop();
    if ( d[u].sbuck < cost) continue;

    for( auto next : e[u] )
    {
      if ( d[ next.v ].sbuck > d[u].sbuck + next.w)
      {
        d[next.v].sbuck = d[u].sbuck + next.w;
        pq.push({-d[next.v].sbuck, next.v});
      }
    }
  }

  int ans =1e9+1, v;
  for (int i=1; i<=n; i++)
  {
    if ( d[i].mac > macCon) continue;
    if ( d[i].sbuck > sbuckCon) continue;
    if ( nohouse[i] ) continue;

    if ( ans > d[i].mac + d[i].sbuck ) ans =  d[i].mac+d[i].sbuck;
  }

  if ( ans == 1e9+1) ans=-1;
  printf("%d\n", ans);
}
