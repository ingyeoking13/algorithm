#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int st[1001][501];
int dist[1001], cost[1001];

int main()
{
  int c, e, d;
  scanf("%d%d%d", &c, &e, &d);
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &dist[i]);
  for (int i=1; i<=n; i++) scanf("%d", &cost[i]);

  memset(st, -1, sizeof(st));
  st[0][c]=0;

  for (int i=0; i<=n; i++)
  {
    for (int j=0; j<=500; j++)
    {
      if (st[i][j] >= 0)
      {
        for (int k=i+1; k<=n; k++)
        {
          int fuel = (dist[k] - dist[i])*e;
          if ( j - fuel <0 ) break;

          if (st[k][i] ==-1 ) st[k][i] = 
          st[k][i] = 
        }


      }

    }

  }


}
