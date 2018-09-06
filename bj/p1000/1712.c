#include <stdio.h>

int main()
{
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  long long k=a/(c-b)+1LL;

  /*
  a+b*k < c*k
  a < c*k - b*k
  a/(c-b) < k 
  */
  printf("%lld\n", k);

}
