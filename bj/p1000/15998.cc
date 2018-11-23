#include <string.h>
#include <algorithm>
#include <string>

using namespace std;
long long gcd(long long a, long long b)
{ return b?gcd(b, a%b):a; }

int main()
{
  int n;
  scanf("%d", &n);
  long long now=0;
  long long step=-1;
  long long minrem=0;

  for (int i=0; i<n; i++)
  {
    char act[25], rem[25];
    scanf("%s %s", act, rem);

    long long actl, reml;
    actl = stoll(act, (size_t)0, 0);
    reml = stoll(rem, (size_t)0 ,0);

    if (actl>0) 
    {
      if ( now + actl != reml) return !printf("-1\n");
      now= reml;
    }
    else if (now >= -actl) {
      if (now + actl != reml ) return !printf("-1\n");
      now= reml;
    }
    else // abs(a) > abs(now)
    {
      actl = -actl;
      if (step ==-1)
      {
        step = actl -now + reml;
        minrem = reml;
        now = reml;
      }
      else 
      {
        minrem = max(minrem, reml);
        long long tmp = gcd(step, reml+actl-now);

        if (tmp > minrem) step = min(tmp, step);
        else return !printf("-1\n");
        now = reml;
      }
    }
  }
  printf("%lld\n", step==-1?1:step);
}
