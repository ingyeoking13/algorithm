#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
vector<int> e[(int)1e2+1];
int main()
{

  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);
  int n;
  scanf("%d", &n);

  for (int i=0; i<n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    e[v].push_back(u);
  }

  queue<int> q;
  for (int i=1; i<=n; i++)
  {
    int d[(int)1e2+1];
    memset(d, 0, sizeof(d));
    d[i] = 1;
    q.push(i);

    while( !q.empty())
    {
      int cur = q.front();
      q.pop();

      for (int j=0; j<e[cur].size(); j++)
      {

        int next = e[cur][j];
        if ( d[next] ) continue;
        d[next] =1;
        q.push( next );
      }
    }

    bool ans = true;

    for (int j=1; j<=n; j++)
    {
      if ( d[j] == 0 ) ans =false;
    }
    if (ans ) return !printf("%d\n", i);
  }
  printf("-1\n");

}
