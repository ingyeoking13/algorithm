#include <stdio.h>

int main()
{
  int x;
  scanf("%d", &x);

  int a=x;

  for (int b=1; b<=x; b++)
  {
    if ( a*b > x && a%b==0 && a/b <x )
    {
      printf("%d %d\n", a, b);
      return 0;
    }
  }
  printf("-1\n");
}
