#include <stdio.h>

int abs(int x) { return x>0?x:-x;}
int max(int x, int y){ return x>y?x:y;}
int main()
{
  int bx, by, dx, dy;
  int jx, jy;
  scanf("%d%d%d%d%d%d", &bx, &by, &dx, &dy, &jx, &jy);

  int bb = max(abs(jx-bx), abs(jy-by));
  int dd = abs(jx-dx) + abs(jy-dy);
  if (bb==dd) printf("tie\n");
  else if (bb> dd) printf("daisy\n");
  else printf("bessie\n");
}
