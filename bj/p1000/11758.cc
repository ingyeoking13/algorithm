#include <stdio.h>

int main()
{
  int x1, y1;
  int x2, y2;
  int x3, y3;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

  int ax = x1-x2;
  int ay = y1-y2;

  int bx = x2-x3;
  int by = y2-y3;

  int e = ax*by - bx*ay;
  if (e > 0) printf("1");
  else if ( e==0) printf("0");
  else printf("-1");

}
