#include <stdio.h>

int a[8];

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
    a[cnt]=i;
    go(n, m, cnt+1);
  }
}

int main()
{
  int n, m ;
  scanf("%d%d", &n, &m);
  go(n, m, 0);
}

