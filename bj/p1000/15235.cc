#include <stdio.h>

int a[1000], ans[1000];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int t=0;
  while(1)
  {
    int bef = t;

    for (int i=0; i<n; i++)
    {
      a[i]--;
      if ( a[i] >= 0) t++;
      if ( a[i] == 0) ans[i] = t;
    }
    if ( t == bef ) break;
  }
  for (int i=0; i<n; i++) printf("%d ", ans[i]);
  printf("\n");
}
