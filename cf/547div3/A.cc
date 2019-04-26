#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int div = m/n;
  if( m%n > 0) return !printf("-1\n");

  int ans=0;
  while(div)
  {
    if ( div%2 != 0 && div%3 != 0 )
    {
      if ( div == 1) 
      {
        break;
      }
      else 
      {
        ans=-1;
        break;
      }
    }
    if ( div%2 == 0) 
    {
      div/=2;
      ans++;
    }
    if ( div%3 == 0) 
    {
      div/=3;
      ans++;
    }
  }
  printf("%d\n", ans);
}
