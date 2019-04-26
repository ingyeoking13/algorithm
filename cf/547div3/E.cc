#include <stdio.h>
#include <algorithm>

using namespace std;

long long d[(int)2e5];
int main()
{
  long long HP;
  int n;
  scanf("%lld%d", &HP, &n);

  long long mn =0;
  long long round_hit = 0;
  for (int i=0; i<n; i++)
  {
    scanf("%lld", &d[i]);
    round_hit += d[i];
    mn = min(mn, round_hit);
  }

  bool chk= (HP+mn<=0);
  if (round_hit>=0 && (HP+mn)>0) 
  {
    return !printf("-1\n");
  }

  round_hit = -round_hit;

  long long repeat; 

  if ( round_hit <= 0) repeat = 0;
  else repeat = (HP+mn+round_hit-1)/round_hit;
  if (chk == true) repeat =0; 

  HP += (repeat*(-round_hit));

  long long ans = repeat * n;
  for (int i=0; i<n; i++)
  {
    HP += d[i];
    if ( HP <= 0)
    {
      ans += (i+1);
      break;
    }
  }

  printf("%lld\n", ans);
}
