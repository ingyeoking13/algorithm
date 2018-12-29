#include <stdio.h>
#include <math.h>

int main()
{
  int T=1;
  while(1)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ( a== 0 && b== 0 && c== 0) break;

    if (T>=2) printf("\n");
    printf("Triangle #%d\n", T++);

    if (a== -1)
    {
      int aa = c*c- b*b;
      if ( aa > 0) printf("a = %.3lf\n", sqrt(aa));
      else printf("Impossible.\n");
    }
    else if (b==-1)
    {
      int bb = c*c- a*a;
      if ( bb > 0) printf("b = %.3lf\n", sqrt(bb));
      else printf("Impossible.\n");
    }
    else 
    {
      int cc = a*a + b*b;
      printf("c = %.3lf\n", sqrt(cc));
    }
  }

}
