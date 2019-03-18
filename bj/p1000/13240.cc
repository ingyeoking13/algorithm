#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      if ( (i+j)%2 == 0 ) printf("*");
      else printf(".");
    }
    printf("\n");
  }
}
