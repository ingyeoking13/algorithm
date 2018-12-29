#include <stdio.h>
#define MOD ((int)1e9+9)
int main()
{
  int n;
  scanf("%d", &n);
  int d[(int)5e4+1];

  d[1] =1, d[2] = 1, d[3]=2;
  for (int i=4; i<=n; i++)
  {
    d[i] = (d[i-3] + d[i-1])%MOD;
  }
  printf("%d\n", d[n]);
}
