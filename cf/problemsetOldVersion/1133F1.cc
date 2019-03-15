#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> cnt[(int)2e5+1];
int p[(int)2e5+1];
vector<int> e[(int)2e5+1];

vector<pair<int, int>> ans;

int ufind(int a)
{
  if ( a == p[a] ) return a;
  return p[a] = ufind(p[a]);
}
int main()
{
  int n, m;
  scanf("%d%d", &n,&m);
  for (int i=1; i<=n; i++) cnt[i].second=i;

  while(m--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    cnt[u].first ++;
    cnt[v].first ++;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  for (int i=1; i<=2e5; i++) p[i] = i;

  sort(cnt+1, cnt+n+1);

  for (int i=n; i>=1; i--)
  {
    int u = cnt[i].second;
    for (auto v : e[u] )
    {
      int pu = ufind(u), pv = ufind(v);
      if ( pu == pv ) continue;
      p[pu] =pv;
      ans.push_back({u, v});
    }
  }

  for (auto a : ans)
  {
    printf("%d %d\n", a.first, a.second);
  }
}
