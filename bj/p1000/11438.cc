#include <stdio.h>
#include <vector>

using namespace std;
vector<int> e[(int)1e5+1];
int p[(int)1e5+1][18];
int d[(int)1e5+1];
bool visit[(int)1e5+1];

void go(int now, int cnt)
{
  visit[now]=1;
  d[now]=cnt++;

  for (int i=1; i<=17; i++)
  {
    p[now][i] = p[p[now][i-1]][i-1];
  }

  for (auto i : e[now])
  {
    if (visit[i]) continue;
    p[i][0] = now;
    go(i, cnt);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }

  go(1, 1);
  int m;
  scanf("%d", &m);

  while(m--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    if ( d[u] < d[v] ) { u^=v; v^=u; u^=v; }

    for (int i=17; i>=0; i--)
    {
      if ( d[v] <= d[p[u][i]] ) u= p[u][i];
    };
    if ( u == v ) 
    {
      printf("%d\n", u);
      continue;
    }

    for (int i=17; i>=0; i--) 
    {
      if ( p[u][i] != p[v][i] ) u = p[u][i], v=p[v][i];
    }
    printf("%d\n", p[u][0]);
  }
}


