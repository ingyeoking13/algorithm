#include <stdio.h>

int a[2001], b[2001];
int prea[2001], preb[2001];
int row[2001], col[2001];
int min(int x, int y ) { return x>y?y:x; }
int main()
{
  int n, m, x;
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  for (int i=1; i<=m; i++) scanf("%d", &b[i]);
  scanf("%d", &x);

  for (int i=0; i<=n; i++)
  {
    prea[i] = prea[i-1]+a[i];
  }
  for (int i=0; i<=m; i++)
  {
    preb[i] = preb[i-1]+b[i];
  }

  for (int i=1; i<=n; i++ ) row[i] = 4e6;
  for (int j=1; j<=m; j++) col[j] = 4e6;

  for (int i=1; i<=n; i++)
  {
    for (int j=1; j<=i; j++)
    {
      row[j] = min(row[j], prea[i] - prea[i-j]);
    }
  }

  for (int i=1; i<=m; i++)
  {
    for (int j=1; j<=i; j++)
    {
      col[j] = min(col[j], preb[i] - preb[i-j]);
    }
  }


  int ans=0;
  for (int i=0; i<=n; i++)
  {
    for (int j=0; j<=m; j++)
    {
      if ( ans < i*j && (long long)row[i]*col[j] <=x ) 
      {
        ans = i*j;
      }
    }
  }
  printf("%d\n", ans);

}
