#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  int d[251][251];
  memset(d, 0x7f, sizeof(d));
  for (int i=0; i<=n;i++) d[i][i]=0;

  while(m--)
  {
    int u, v, w, st;
    scanf("%d%d%d", &u, &v, &st);
    if (st) d[u][v] = d[v][u]=0;
    else
    {
      d[u][v]=0;
      d[v][u]=1;
    }
  }

  int k;
  scanf("%d", &k);

  for (int k=1; k<=n; k++)
  {
    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=n; j++)
      {

        if (d[i][k] == 0x7f7f7f7f || d[k][j] == 0x7f7f7f7f) continue;
        if ( d[i][j] > d[i][k] + d[k][j] )
        {
          d[i][j] = d[i][k] + d[k][j];
        }

      }
    }
  }

  while(k--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", d[u][v]);
  }
}
