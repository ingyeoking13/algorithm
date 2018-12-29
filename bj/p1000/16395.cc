#include <stdio.h>

long long d[31][32];
int main()
{
  int n, k; 
  scanf("%d%d",&n, &k);

  d[1][1]=1;
  for (int i=1; i<=n; i++)
  {
    for (int j=1; j<=i; j++)
    {
      d[i][j] += d[i-1][j-1];
      d[i][j] += d[i-1][j];
    }
  }
  printf("%lld\n", d[n][k]);

}
