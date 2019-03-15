// (i^2 + j^2) mod m == 0
// (i^2 mod m + j^2 mod m  ) mod m  == 0
// (( i mod m )^2 + ( j mod m )^2 ) mod m == 0
#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans=0;
  for (int i=1; i<=m; i++)
  {
    for (int j=1; j<=m; j++)
    {
      if (( i*i + j*j)%m == 0)
      {
        ans += 1LL*(n+m-j)/m*((n+m-i)/m);
      }
    }
  }
  printf("%lld\n", ans);

}
