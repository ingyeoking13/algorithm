#include <stdio.h>

int a, b;
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x> y) a++;
    else if (x<y) b++;
  }
  printf("%d %d\n", a, b);

}
