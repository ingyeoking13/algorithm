#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge
{
  int v, w;
  Edge(int v, int w ) : v(v), w(w) {};
};

int main()
{
  int n, r;
  scanf("%d%d", &n, &r);

  vector<pair<int, int> > d(100);
  for (int i=0; i<100; i++ ) d[i]= make_pair(0x7f7f7f7f, 0x7f7f7f7f);

  vector<Edge> e[100];

  while (r--)
  {
    int u, v, c, add, take;
    scanf("%d%d%d%d%d", &u, &v, &c, &add, &take);
    u--, v--;
    e[u].push_back( Edge(v, max(take-10,0)*add+c)); 
  }

  priority_queue<pair<int, int> > pq;
  d[0] = make_pair(0, 1);
  pq.push({0, 0});

  while(!pq.empty())
  {
    auto now =  pq.top();
    int dist = -now.first;
    int u = now.second;
    pq.pop();

    if ( dist > d[u].first ) continue;

    for (auto i : e[u] )
    {
      int v= i.v, w = i.w;
      if ( dist + w < d[v].first ) 
      {
        d[v].first = dist + w;
        d[v].second = d[u].second+1;
        pq.push({-d[v].first, v});
      }
      else if ( dist + w == d[v].first) 
      {
        if ( d[v].second > d[u].second+1) 
        {
          d[v].second = d[u].second+1;
          pq.push({-d[v].first, v});
        }
      }
    }
  }

  if ( d[n-1].first ==  0x7f7f7f7f ) printf("It is not a great way.\n");
  else printf("%d %d\n", d[n-1].first, d[n-1].second);
}
