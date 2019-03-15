#include <stdio.h>

int main()
{
  long long n;
  scanf("%lld", &n);

  n = ((n+1)*n)/2;

  if (n%2 == 0) printf("0");
  else printf("1");
}
