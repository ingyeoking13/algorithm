#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int tt=1; tt<=T; tt++)
  {
    bool e[51][51];

    memset(e, 0, sizeof(e));

    int n,m;

    scanf("%d %d", &n, &m);

    while(m--)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u][v]=true;
      e[v][u]=true;
    }

    int ans=0;
    for (int i=1; i<=n; i++)
    {
      for (int j= i+1; j<=n; j++)
      {
        if ( e[i][j] )
        {
          for (int k=j+1; k<=n; k++)
          {
            if ( e[k][j] && e[k][i])
            {
              ans++;
            }
          }
        }
      }
    }
    printf("#%d %d\n", tt, ans);
  }
}
