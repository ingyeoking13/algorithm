#include <stdio.h>

int main()
{
  int a, b; scanf("%d %d", &a, &b);
  if (a<b || (a+b)%2 || (a-b)%2) return !printf("-1\n");
  printf("%d %d\n", (a+b)/2, (a-b)/2);

}
