#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  if ( n == 1 || n == 5)
  {
    if ( n == 1 )
    {
      printf("%lld\n", ((long long)8)*m);
    }
    else printf("%lld\n", ((long long)8)*m+4);
  }
  else printf("%lld\n", ((long long)5)*m - (m-1)+ (m%2==0?n-2:5-n-1));
}
