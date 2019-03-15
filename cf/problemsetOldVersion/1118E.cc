#include <stdio.h>

int main()
{

  int n, k;
  scanf("%d%d", &n, &k);

  long long kk = ((long long)k)*(k-1);

  if ( n<=kk )
  {
    printf("YES\n");
    int cnt =0;
    for (int j=1; j<=k-1; j++)
    {
      for (int l=j+1; l<=k; l++)
      {
        printf("%d %d\n", j, l);
        cnt++;

        if ( cnt == n) return 0;

        printf("%d %d\n", l, j);
        cnt++;
        if ( cnt == n) return 0;
      }
    }
  }
  else printf("NO\n");


}
