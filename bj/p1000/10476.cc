#include <stdio.h>
#include <algorithm>

using namespace std;

int d[(int)2e2][(int)2e2+1][3];
int a[200][2];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
  {
      scanf("%d %d", &a[i][0], &a[i][1]);
  }
  int x, y;
  scanf("%d %d", &x, &y);

  d[0][0][0] = a[0][0] + a[0][1];
  d[0][1][1] = a[0][1];
  d[0][1][2] = a[0][0];

  for (int i=1; i<n; i++)
  {
    for (int j=0; j<=m; j++)
    {
      d[i][j][0] = max(d[i-1][j][0], d[i-1][j][1]);
      d[i][j][0] = max(d[i][j][0], d[i-1][j][2]);
      if (d[i][j][0] >0 ) d[i][j][0] += a[i][0] + a[i][1];

      if (j>0) d[i][j][1] = max(d[i-1][j-1][0], d[i-1][j-1][1]);
      if (d[i][j][1] >0 ) d[i][j][1] += a[i][1];

      if (j>0) d[i][j][2] = max(d[i-1][j-1][0], d[i-1][j-1][2]);
      if (d[i][j][2] > 0) d[i][j][2] += a[i][0];
    }
  }

  int ans=0;
  for (int i=0; i<=m; i++)
  {
    ans = max(d[n-1][i][0], d[n-1][i][1]);
    ans = max(ans, d[n-1][i][2]);
  }
  printf("%d\n", ans);
}
