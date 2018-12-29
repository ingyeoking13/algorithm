#include <stdio.h>

int main()
{

  int n;
  scanf("%d", &n);

  int a[(int)1e5], b[(int)1e5];
  for (int i=0; i<n; i++) 
  {
    scanf("%d%d", &a[i], &b[i]);
  }

  int ans= b[0];
  int buf = 0;
  for (int i=1; i<n; i++)
  {
    if (a[i-1] > b[i] )
    {
      buf += (a[i-1]-b[i]);
    }
    else 
    {
      int rem = buf - (b[i] - a[i-1]);

      if ( rem >=0) buf = rem;
      else ans -= rem, buf=0;
    }
  }
  printf("%d\n", ans);

}
