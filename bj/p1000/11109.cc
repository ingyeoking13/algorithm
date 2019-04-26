#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int d, n, s, p;
    scanf("%d%d%d%d", &d, &n,&s, &p);
    p = p*n + d;
    s = s*n;

    if( p == s)
    {
      printf("does not matter\n");
    }
    else if ( p> s )
    {
      printf("do not parallelize\n");
    }
    else printf("parallelize\n");
  }
}
