#include <stdio.h>
#include <algorithm>
#define MOD 1234567891

using namespace std;

int f[(int)1e6+1];

int modInversion(int k)
{
  int ret =1;
  int n = MOD-2;
  while(n)
  {
    if ( n%2 == 0) 
    {
      k = ((long long)k*k)%MOD;
      n/=2;
      continue;
    }
    n--;
    ret = ((long long)ret*k)%MOD;
  }
  return ret;
}

int nCr(int n, int r)
{
  f[1]=1;
  for (int i=2; i<=n; i++)
  {
    f[i] = ((long long)f[i-1]*i)%MOD;
  }

  int ret= ((long long)f[n]*modInversion(f[r]))%MOD * modInversion(f[n-r])%MOD;
  return ret;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int test_case=1; test_case<= T; test_case++)
  {
    int n,r, p;
    scanf("%d%d", &n, &r);
    printf("%d\n", nCr(n, min(r, n-r)));
  }
}
