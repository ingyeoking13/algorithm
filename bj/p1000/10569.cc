#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  while( T-- )
  {
    int v, e;
    scanf("%d %d", &v, &e);
    printf("%d\n", 2-v+e);
  }
}
