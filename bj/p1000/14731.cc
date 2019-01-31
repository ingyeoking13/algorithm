#include <stdio.h>
#define MOD (int)(1e9+7)

long long power(int num, int pow)
{
  long long ret = 1;

  while ( pow > 0 )
  {

    if ( pow % 2 == 1 ) 
    {
      ret = ( ret * num )% MOD;
    }

    pow/=2;
    num = ((long long)num*num)%MOD;
  }

  return ret;
}

int main()
{
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i=0; i<n; i++)
  {
    int c, k;
    scanf("%d %d", &c, &k);

    long long cc = ((long long)c)*k;
    k--;

    ans += (((power(2, k))*(cc%MOD))%MOD); 
    ans %= MOD;
//    printf("%d\n", ans);
  }
  printf("%d\n", ans);
}
