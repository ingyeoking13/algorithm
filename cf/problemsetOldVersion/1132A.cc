#include <stdio.h>

int main()
{
  int a[4];
  for (int i=0; i<4; i++)
  {
    scanf("%d", &a[i]);
  }

  long long b=0, c=0;
  b += 2*a[0];
  b -= 2*a[3];

  if ( a[2] >0 )
  {
    int open = 2*a[0] - a[2];
    if ( open <0) return !printf("0\n");

    open+= a[2];
    open-= 2*a[3];

    if( open !=0 ) printf("0\n");
    else printf("1\n");

  }
  else 
  {
    if ( b == 0) printf("1\n");
    else printf("0\n");

  }

}
