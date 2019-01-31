#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  long long ans=0;
  for (int i=1; i<=n-1; i++)
  {
    ans += (long long)n*i+i;
  }
  printf("%lld\n", ans);
}
