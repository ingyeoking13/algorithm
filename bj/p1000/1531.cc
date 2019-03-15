#include <stdio.h>

int map[101][101];
int main()
{

  int n, m;
  scanf("%d%d", &n, &m);

  while(n--)
  {
    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);

    for (int i=sx; i<=ex; i++)
    {
      for (int j=sy; j<=ey; j++)
      {
        map[i][j]++;
      }
    }
  }

  int ans=0;
  for (int i=1; i<=100; i++)
  {
    for (int j=1; j<=100; j++)
    {
      if( map[i][j] > m) ans++;
    }
  }
  printf("%d\n", ans);
}
