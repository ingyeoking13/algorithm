#include <stdio.h>

int main()
{
  int n, h, w;
  scanf("%d%d%d", &n, &h, &w);

  int ans=0;
  while(n--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if ( a>= h && b >= w ) ans++;
  }
  printf("%d\n", ans);
}
