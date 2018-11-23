#include <stdio.h>

int main()
{
  double a, b;
  while(~scanf("%lf%lf", &a, &b))
  {
    printf("%0.2lf\n", a/b);
  }
}

