#include <stdio.h>

bool p[(int)1e6+1];
bool v[(int)1e6+1];
int main()
{
  long long l, r;
  scanf("%lld %lld", &l, &r);

  // 없어도됨//
  for (long long i=2; i<=1e6; i++)
  {
    if(!p[i])
    {
      for (long long j = i*i; j<=1e6; j+=(i*i))
      {
        p[j]=1;
      }
    }
  }
  // 없어도됨 //

  for (long long i=2; i<=1e6; i++)
  {
    if ( p[i] ) continue;
    if ( l%(i*i) == 0)
    {
      for (long long j = l; j<=r; j+=(i*i))
      {
        v[j-l] =1;
      }
    }
    else
    {
      for (long long j = l -(l%(i*i))+i*i; j<=r; j+= (i*i))
      {
        v[j-l]=1;
      }
    }
  }

  int ans=0;
  for (long long i=l; i<=r; i++)
  {
    if (!v[i-l]) ans++;
  }
  printf("%d\n", ans);
}
