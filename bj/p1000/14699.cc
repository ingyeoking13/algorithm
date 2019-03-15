#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int h[5001];
vector<int> e[5001];
int ans[(int)5e3+1];

int go(int u, int dist )
{
  if (ans[u] >=1 ) return ans[u];
  ans[u] = 1;
  int ret = 1;

  for ( auto v : e[u] ) ret = max(ret, go(v, dist)+1);
  return ans[u]=ret;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=1; i<=n; i++) scanf("%d", &h[i]);

  while(m--)
  {
    int u,v;
    scanf("%d%d", &u, &v);

    if (h[u] == h[v]) continue;

    if (h[u] > h[v]) e[v].push_back(u);
    else e[u].push_back(v);
  }

  for (int i=1; i<=n; i++)
  {
    printf("%d\n", go(i, 1));
  }

}
