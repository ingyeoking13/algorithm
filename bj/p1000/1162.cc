#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Edge 
{
  int v, w; 
  Edge(int x, int y) : v(x), w(y) {};
};

struct State
{
  long long cost; 
  int u, k;
  State(long long x, int y, int z) : cost(x), u(y), k(z) {};
};
bool operator < (const State a, const State b) { return a.cost < b.cost; }

vector<vector<Edge>> edge;

int main()
{
  int n, m, mxk;
  scanf("%d %d %d", &n, &m, &mxk);
  edge.resize(n+1);

  while(m--)
  {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[u].push_back({v, w});
    edge[v].push_back({u, w});
  }

  long long d[10001][21];
  memset(d, 0x3f, sizeof(d));
  d[1][0]=0;

  priority_queue<State> pq;
  pq.push(State(0, 1, 0));

  while(!pq.empty())
  {
    State now = pq.top();
    pq.pop();
    long long cost = -now.cost;
    int u = now.u;
    int k = now.k;

    if ( d[u][k] < cost ) continue;

    for (auto i: edge[u])
    {
      if ( d[i.v][k] > i.w + d[u][k] )
      {
        d[i.v][k] = i.w + d[u][k];
        pq.push(State(-d[i.v][k], i.v, k));
      }

      if (k== mxk) continue;
      if ( d[i.v][k+1] > d[u][k] )
      {
        d[i.v][k+1] = d[u][k];
        pq.push(State(-d[i.v][k+1], i.v, k+1));
      }
    }
  }

  long long ans= 1LL<<62;
  for (int i=0; i<=mxk; i++) 
    if (ans > d[n][i] ) ans=d[n][i];
    
  printf("%lld\n", ans);
}
