#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int n, dest;
    scanf("%d %d", &n, &dest);

    int ans=0;
    for (int i=0; i<n; i++)
    {
      int v, fuel, perhour;
      scanf("%d %d %d", &v, &fuel, &perhour);

      double hour = ((double)fuel)/perhour;

      if ( v*hour >= dest) 
      {
        ans++;
      }
    }
    printf("%d\n", ans);

  }


}
