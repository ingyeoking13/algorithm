#include <stdio.h>

int a[(int)4e5];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    a[n+i] = a[i];
  }

  int ans=0;
  for (int i=1; i<2*n; i++)
  {
    if (a[i] == 0) continue;
    a[i] = a[i-1]+ a[i];
    if ( a[i] > ans ) ans = a[i];
  }
  printf("%d\n", ans);
}
