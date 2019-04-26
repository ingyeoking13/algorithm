#include <stdio.h>

int main()
{
  int T=1;
  while(1)
  {
    int l, p, v;
    scanf("%d%d%d", &l, &p, &v);
    if (l == 0 && p == 0 && v == 0 ) break;

    long long ans=0;

    ans +=  ( v/p )*l; 
    long long rem = v%p;
    if ( rem > l ) rem = l;
    ans += rem;

    printf("Case %d: %lld\n", T++, ans);
  }
}
