#include <stdio.h>
#define MOD (int)(1e9+7)

long long d[(int)2e5][3];
int base[3];
int main()
{
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);

  int gap = (r-l+1)/3;
  int rem = (r-l+1)%3;

  for (int i=0; i<3; i++)
  {
    d[0][i] += gap;
  }

  for (int i=l%3; i<(l%3)+rem; i++)
  {
    d[0][i%3]++;
//    printf("%lld\n", d[0][i]);
  }


  for (int i=1; i<n; i++)
  {
    for (int j=0; j<3; j++)
    {
      for (int k=0; k<3; k++)
      {
        d[i][(j+k)%3] = d[i][(j+k)%3]+ (((long long)(d[i-1][j])%MOD)*((d[0][k])%MOD))%MOD;
        d[i][(j+k)%3]%=MOD;
      }
    }
  }

  printf("%lld\n", d[n-1][0]);
}
