#include <stdio.h>
#include <string.h>

int v[1<<26];
int main()
{
  int n;
  scanf("%d", &n);
  memset(v, -1, sizeof(v));

  for (int i=0; i<n; i++)
  {
    int a;
    scanf("%d", &a);

    int aa = a/(1<<5);
    int aaa = 1<<(a%(1<<5));
    v[aa] ^= aaa;
  }

  for (long long i=1; i<1LL<<32; i++)
  {
    if ( (1<<(i%(1<<5)) & v[i>>5]) ) 
    {
      return !printf("%lld\n", i);
    }
  }


}
