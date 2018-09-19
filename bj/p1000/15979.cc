#include <stdio.h>

int abs(int x) { return x>0?x:-x; }
int gcd(int a, int b ) { return b?gcd(b, a%b):a; }
int main()
{
  int x, y;
  scanf("%d %d", &x, &y);
  x = abs(x), y= abs(y);
  if (x==0 && y==0) return !printf("0\n");
  if (gcd(x, y) != 1 ) return !printf("2\n");
  else return !printf("1\n");
}
