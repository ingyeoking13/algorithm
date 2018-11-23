#include <stdio.h>

int a[500][500];
long long row[500], col[500], diag, diag2;
int main()
{
  int n; scanf("%d", &n);
  int x, y;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      scanf("%d", &a[i][j]);
      if (!a[i][j]) x=i, y=j;
    }
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      row[i] += (long long)a[i][j];
      col[i] += (long long)a[j][i];
    }
  }



  long long samer = row[(x==0)];
  long long samec = col[(y==0)];
  for (int i=1; i<n; i++)
  {
    if (samec != row[i])
    {
      if (i ==x);
      else return !printf("-1\n");
    }
    if (samec != col[i])
    {
      if (i==y);
      else return !printf("-1\n");
    }
  }

  long long ans=0;
  if ( samer - row[x] == samec - col[y])
  {
    ans = samer - row[x];
    a[x][y] =ans;
  }
  else return !printf("-1\n");

  for (int i=0; i<n; i++)
  {
    diag += (long long)a[i][i];
    diag2 += (long long)a[i][n-1-i];
  }
  if (diag == diag2) printf("%lld\n", ans);
  else printf("-1\n");


}
