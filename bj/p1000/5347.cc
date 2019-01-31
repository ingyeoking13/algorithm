#include <stdio.h>

int gcd(int a, int b)
{
  return b?gcd(b,a%b):a;
}

int main()
{
  int T;
  scanf("%d", &T); 

  while(T--)
  {
    int a, b;
    scanf("%d%d", &a, &b);

    int g = gcd(a, b);
    printf("%lld\n", (long long)a*b/g);
  }
}
