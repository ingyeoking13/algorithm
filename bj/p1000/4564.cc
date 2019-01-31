#include <stdio.h>

int main()
{
  int n;
  while(scanf("%d",&n))
  {
    if (n == 0) break;

    while(n>=10)
    {
      printf("%d ", n);
      int now = n;
      int ret = 1;

      while(now>0)
      {
        ret *= (now%10);
        now/=10;
      }
      n = ret;
    }

    printf("%d\n", n);
  }


}
