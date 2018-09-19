#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int m = n/2;
  n -=m;
  printf("%d\n", (n+1)*(m+1));
}
