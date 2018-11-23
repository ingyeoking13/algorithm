#include <stdio.h>

int a[8], v[9];

void go(int n, int m, int cnt)
{
  if (m == cnt)
  {
    for (int i=0; i<cnt; i++)
    {
      printf("%d ", a[i]);
    }
    printf("\n");
    return;
  }

  for (int i=1; i<=n; i++)
  {
    if ( v[i] ) continue;
    a[cnt]=i;
    v[a[cnt]]=1;
    go(n, m, cnt+1);
    v[a[cnt]]=0;
  }
}

int main()
{
  int n, m ;
  scanf("%d%d", &n, &m);
  go(n, m, 0);
}

