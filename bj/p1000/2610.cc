#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int ufind(int a, vector<int>& p)
{
  if ( a == p[a] ) return p[a];
  return p[a] = ufind(p[a], p);
};

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> p(n+1);
  for (int i=1; i<=n; i++) p[i] = i;

  vector<int> e[101];

  while (m--)
  {
    int u,v;
    scanf("%d%d", &u, &v);

    e[u].push_back(v);
    e[v].push_back(u);

    int pu = ufind(u, p), pv= ufind(v, p);

    if ( pu == pv ) continue;
    p[pu] = pv;
  }

  for (int i=1; i<=n; i++) ufind(i, p);

  vector<vector<int>> set;
  vector<int> chk(n+1, -1);
  int size=0;

  for (int i=1; i<=n; i++)
  {
    if ( chk[ p[i] ] < 0 )  
    {
      chk[ p[i] ] = size++;
      set.push_back(vector<int>());
    }
    set[ chk[ p[i] ] ].push_back(i);
  }
  printf("%lu\n", set.size());

  vector<int> ansv;

  for (int i=0; i<set.size(); i++)
  {
    int mn =(int)1e4, ans = -1;
    for (int j=0; j<set[i].size(); j++)
    {
      int vertex = set[i][j];
      vector<int> d(n+1, (int)1e4);
      d[vertex] = 0;
      // dijkstra 
      priority_queue<pair<int, int> > pq;
      pq.push({0, vertex});

      while(!pq.empty())
      {
        auto now = pq.top();
        pq.pop();
        int dist = -now.first;
        int u = now.second;

        if ( d[ u ]  < dist ) continue;

        for (auto v : e[ u ] )
        {
          if ( d[ u ] + 1 < d[ v ] )
          {
            d[ v ] = d[ u ] + 1;
            pq.push({-d[v], v});
          }
        }
      }

      int mx = 0;
      for (int k=0; k<set[i].size(); k++)
      {
        if ( d[ set[i][k] ] > mx ) mx = d[ set[i][k] ];
      }
      if ( mx < mn ) ans = vertex, mn = mx;
    }
    ansv.push_back(ans);
  }
  sort(ansv.begin(), ansv.end());
  for ( auto a : ansv)
  {
    printf("%d\n", a);
  }

}
