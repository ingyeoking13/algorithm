#include <stdio.h>
#define MOD ((int)1e9+7)

int div[(int)1e6+1];
int main()
{
  int n;
  scanf("%d", &n);

  div[0] =1;
  for (int i=0; i<n; i++)
  {
    int now;
    scanf("%d", &now);

    int j;
    for (j=1; j*j<=now; j++)
    {
      if ( now%j== 0)
      {
        div[now/j]  = (div[now/j] + div[now/j -1] ) %MOD;
      }
    }

    for (j--;j>=1; j--)
    {
      if (j*j == now) continue;
      if ( now%j == 0) div[j] = (div[j] + div[j-1]) % MOD;
    }
  }

  int ans=0;
  for (int i=1; i<=1e6; i++)
  {
//    if (div[i] == 0) continue;
//    printf("%d : %d\n", i, div[i]); 
    ans = (ans + div[i])%MOD;
  }
  printf("%d\n" ,ans);


}
