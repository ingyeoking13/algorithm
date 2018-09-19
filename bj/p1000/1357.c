#include <stdio.h>

int rev(int now)
{
  int tmp = now;
  int ret =0;
  while(tmp)
  {
    ret *= 10;
    ret += (tmp%10);
    tmp /= 10;
  }
  return ret;
}

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%d\n", rev(rev(x)+rev(y)));

}
