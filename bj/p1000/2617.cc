#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
bool d[100][100];
bool invd[100][100];

int main()
{
  int n, m;
  scanf("%d%d", &n,&m);

  while(m--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    d[u][v] =true;
    invd[v][u] =true;
  }

  for (int k=1; k<=n; k++)
  {
    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=n; j++)
      {
        if (i==j) continue;
        if (d[i][k]  == true && d[k][j] == true)
        {
          d[i][j]=true;
        }
        if (invd[i][k] == true && invd[k][j] ==true)
        {
          invd[i][j]=true;
        }
      }
    }
  }

  int ans=0;
  for (int i=1; i<=n; i++)
  {
    int tmp=0;
    for (int j=1; j<=n; j++) 
    {
      if (d[i][j]) tmp++;
    }
    if (tmp > n/2) ans++;

    tmp=0;
    for (int j=1; j<=n; j++) 
    {
      if (invd[i][j]) tmp++;
    }
    if (tmp > n/2) ans++;

  }

  printf("%d\n", ans);
}
