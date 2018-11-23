#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> in[300];
int path[300];

bool gyup(int u, int v)
{
  if (in[u].second >= in[v].first  && in[u].first <= in[v].second)
  {
    return true;
  }
  else if (in[v].second >= in[u].first && in[v].first <= in[u].second)
  {
    return true;
  }
  return false;
}

int go(int u, int dest, int n, bool* visit, int cnt)
{
  int ret=305;
  if (u==dest){
    return cnt;
  }
  else if (gyup(u,dest)) return cnt+1;

  for (int i=0; i<n ;i++)
  {
    if (gyup(u, i))
    {
      if (visit[i]==0)
      {
        visit[i]=1;
        int tmp =  go(i, dest, n, visit, cnt+1);
        if (tmp){
          ret = min(ret, tmp);
        }
        visit[i]=0;
      }
    }
  }
  return ret;
}

int ans(int u, int dest, int n)
{
  int ret = 301;
  bool visit[300];

  for (int i=0; i<n; i++)
  {
    if (gyup(u, i))
    {
      memset(visit, 0,sizeof(visit));
      visit[i]=1;
      int tmp = go(i, dest, n, visit, 1);
      visit[i]=0;
      if (tmp ==0) continue;
      ret =min(tmp, ret);
    };
  }

  return ret<=300?ret:-1;
}


int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    int f, t;
    scanf("%d%d", &f, &t);
    in[i] ={f, t};
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
