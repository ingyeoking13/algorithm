#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

pair<int , int> a[300];
bool gyup(int u, int v)
{
  if ( a[u].first  <=a[v].second && a[u].second >= a[v].first)
  {
    return 1;
  }
  if (a[v].first  <=a[u].second && a[v].second >= a[u].first)
  {
    return 1;
  }
  return 0;
}

int ans(int u, int dest, int n)
{
  bool visit[300];
  int dist[300];
  memset(visit, 0, sizeof(visit));
  memset(dist, 0, sizeof(dist));

  queue<int> q;
  q.push(u);

  visit[u]=1;
  dist[u]=0;

  while(!q.empty())
  {
    int now = q.front();
    q.pop();

    for (int i=0; i<n; i++)
    {
      if (i==now) continue;
      if (gyup(now, i)==0) continue;
      if (visit[i] == 0)
      {
        visit[i]=1;
        dist[i] = dist[now]+1;
        if (i == dest) return dist[dest];
        q.push(i);
      }
    }
  }

  return -1;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    int f, t;
    scanf("%d %d", &f, &t);
    a[i]= {f, t};
  }
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    printf("%d\n", ans(u, v, n)); 
  }

}
