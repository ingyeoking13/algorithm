#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
  long long n, p;
  scanf("%lld %lld", &n, &p);
  if (n == 1) 
  {
    printf("%lld\n", p);
    return 0;
  }

  long long ans=0;
  for (long long i=2; pow(i, n)<=p; i++)
  {
    if (p%i == 0)
    {
      int tmpcnt=0;
      long long tmp = p;
      while(tmp%i == 0)
      {
        tmp/=i;
        tmpcnt++;
        if (tmpcnt>=n ) break;
      }
      if (tmpcnt >= n) ans = i;
    }
  }

  if (ans == 0) printf("1\n");
  else printf("%lld\n", ans);
}
