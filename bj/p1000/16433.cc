#include <stdio.h>

int main()
{
  int n, r, c;
  scanf("%d%d%d", &n, &r, &c);
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {

      if ((r+c)%2 == (i+j+1)%2)
      {
        printf(".");
      }
      else printf("v");
    }
    printf("\n");
  }
  printf("\n");

}
