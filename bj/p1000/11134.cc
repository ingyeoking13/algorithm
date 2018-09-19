#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    long long n, c;
    scanf("%lld %lld", &n, &c);
    printf("%lld\n", n/c + (n%c?1:0));
  }

}
