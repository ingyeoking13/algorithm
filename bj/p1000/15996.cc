#include <stdio.h>

int main()
{
  int n, a;
  scanf("%d%d", &n, &a);

  int ans=0;
  for (long long i=a;i<=n ; i*=a)
  {
    ans += n/i;
  }
  printf("%d\n", ans);

}

