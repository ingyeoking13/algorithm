#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector< pair<int, int> > e[(int)3e5+1];
int a[(int)3e5+1];
long long ans=0;

long long dfs(int now, int bef)
{
  long long ret = a[now];
  ans = max(ans, ret);
  for (auto i : e[now] )
  {
    if ( i.first == bef ) continue;

    long long tmp = dfs(i.first, now) - i.second;
//    printf("%d ~ %d : %lld\n", now, i.first, tmp);

    ans = max(ans, ret+tmp);
    ret = max(ret, tmp+a[now]);
  }

 // printf("%d %lld\n",now, ans);
  return ret;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
  }
  for (int i=0; i<n-1; i++)
  {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  dfs(n, 0);
  printf("%lld\n", ans);

}
